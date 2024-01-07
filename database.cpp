#include <fstream>
#include <iostream>
#include <filesystem>
#include <cstring>
#include "plog/Log.h"
#include "database.hpp"
using namespace std;

constexpr int SizeTitle = sizeof(int)*3 + sizeof(char)*15;

void PrintNums(int m, int n)    {       LOGD << m << "- num | amout - " << n << endl;     }

bool DataBase::Check(int id)    {       return !((id < allRecords + 1) && (1 <= id));       }

void DataBase::Open()
{
   bool is_new = false;
   filesystem::create_directory(filesystem::current_path().string() + "\\DataBases");
   string path = filesystem::current_path().string() + "\\DataBases\\" + nameOfFile + ".db";
   LOGD << path << endl;        //
   ifstream check(path);
   if (! check.is_open()){
      fs.open (path, std::fstream::in | std::fstream::out | std::fstream::binary | fstream::app);
      is_new = true;
   }
   Close();
   fs.open (path, std::fstream::in | std::fstream::out | std::fstream::binary);
  
   if(is_new)   WriteTitle(fs);
   else ReadTitle(fs);
   
   if (Count() == 0) {BofF = true; EofF = true;}
   else {BofF = false; EofF = false;}
}

void DataBase::Close()  { if (fs.is_open())  fs.close(); }

long DataBase::Id()     { return numberOfRecord; }

long DataBase::Count()  { return amountOfRecord; }

void DataBase::GotoInProg(long id)
{
   fs.seekg((id - 1)*(Size() + sizeof(bool)) + SizeTitle, ios::beg);
}

void DataBase::Goto(long id)
{
   if (Check(id))       return;
   numberOfRecord = id;
   GotoInProg(id);
   is_deleted = ReadDelete(fs);
   if (is_deleted)       {cerr << "Deleted record. Exit" << endl; exit(1); }
   ReadData(fs);
   EofF = false;        BofF = false;
}

void DataBase::First()
{
   if (Count() == 0) {BofF = true; EofF = true;}
   int id = 1;
   PrintNums(numberOfRecord, amountOfRecord);         //
   do
   {
      if (Check(id))       return;
      GotoInProg(id);      
      is_deleted = ReadDelete(fs);
      id++;
   }while(is_deleted);
   ReadData(fs);
   
   numberOfRecord = --id;
   
   if (Count() == 0) {BofF = true; EofF = true;}
   else {BofF = false; EofF = false;}
   
   PrintNums(numberOfRecord, amountOfRecord);         //
}

void DataBase::Next()
{
   if (!Eof()){
      int id = numberOfRecord + 1;
      PrintNums(numberOfRecord, amountOfRecord);         //
      do
      {
         if (Check(id))       {BofF = false; EofF = true; return; }
         GotoInProg(id);
         is_deleted = ReadDelete(fs);
         id++;
      }while(is_deleted);
      ReadData(fs);
      
      numberOfRecord = --id;
   }
PrintNums(numberOfRecord, amountOfRecord);         //   
}

void DataBase::Prev()
{
   if (!Bof()) {
      int id = numberOfRecord - 1;
      PrintNums(numberOfRecord, amountOfRecord);         //
      do
      {
         if (Check(id))       { BofF = true; EofF = false;  return;}
         GotoInProg(id);
         is_deleted = ReadDelete(fs);
         id--;
      }while(is_deleted);
      ReadData(fs);
      
      numberOfRecord = ++id;
   }
   PrintNums(numberOfRecord, amountOfRecord);         //   
}

void DataBase::Last()
{
   if (Count() == 0) {BofF = true; EofF = true;}
   int id = allRecords;
   do
   {
      GotoInProg(id);
      is_deleted = ReadDelete(fs);
      id--;
   }while(is_deleted);
   ReadData(fs);

   numberOfRecord = id;
   
   if (Count() == 0) {BofF = true; EofF = true;}
   else {BofF = false; EofF = false;}
}

void DataBase::Post()
{   
   if (isChangeable || isInserted)              // если режимы не выставлены
   {
      if(isInserted)     
      {
         amountOfRecord++;
         allRecords++;
         numberOfRecord = allRecords;
         WriteTitle(fs);
      }
      GotoInProg(numberOfRecord);
      WriteDelete(fs, false);
      WriteData(fs);
      
      BofF = false;      EofF = false;
      
      isChangeable = false;
      isInserted = false;
   }
   PrintNums(numberOfRecord, amountOfRecord);         //
}


void DataBase::Cancel()
{
   if (isChangeable || isInserted)
   {
      isChangeable = false;
      isInserted = false;
      GotoInProg(Id());
      ReadData(fs);
   }
   PrintNums(numberOfRecord, amountOfRecord);         //
}

void DataBase::Insert(){       isInserted = true;       }

void DataBase::Edit(){   isChangeable = true;   }

void DataBase::Delete()
{
   PrintNums(numberOfRecord, amountOfRecord);   //
   LOGD << "del" << endl;         //
   GotoInProg(numberOfRecord);
   if(!ReadDelete(fs))   // ограничение если запись уже удалена
   {
      GotoInProg(numberOfRecord);       // из-за того что прочитали delete записи мы переставл€ем указатель чтобы записать
      WriteDelete(fs, true);
      amountOfRecord--;
      WriteTitle(fs);
      PrintNums(numberOfRecord, amountOfRecord);         //
      Next();
   }
}

bool DataBase::Eof()    { return EofF; }

bool DataBase::Bof()    { return BofF; }

void DataBase::WriteDelete(fstream& f, bool is_deleted) { f.write((char*)&is_deleted, sizeof(bool)); }

bool DataBase::ReadDelete(fstream& f)
{
   f.read((char*)&is_deleted, sizeof(bool));
   return is_deleted;
}

void DataBase::WriteTitle(fstream& f)
{
   f.seekg(0, ios::beg);
   
   char buf[15];
   memset(buf, 0, sizeof(buf));
   strncpy(buf, nameOfClass.c_str(), sizeof(buf) - 1);
   
   int size = Size();
   int allsize = allRecords;
   f.write((char*)&buf, sizeof(buf)); 
   f.write((char*)&size, sizeof(int));
   f.write((char*)&allsize, sizeof(int));
   f.write((char*)&amountOfRecord, sizeof(int));
   f.flush();
}

void DataBase::ReadTitle(fstream& f)
{
   f.seekg(0, ios::beg);
   int size;
   size_t len = 15;
   char buf[len + 1];         // ¬ыделение буфера дл€ чтени€
   f.read(buf, len);                   // „тение (с нулевым байтом)
   buf[len] = 0;
   nameOfClass = buf;     
   f.read((char*)&size, sizeof(int));
   f.read((char*)&allRecords, sizeof(int));
   f.read((char*)&amountOfRecord, sizeof(int));
   f.flush();
}