#include <fstream>
#include <iostream>
#include <filesystem>
#include <cstring>
#include "database.h"
using namespace std;

bool debugOn = false;    // true - включает вывод текущей записи и всех записей | false - отключает данную возможность

constexpr int SizeTitle = sizeof(int)*3 + sizeof(char)*15;

void PrintNums(int m, int n)
{
   if (debugOn) cout << m << "- num | amout - " << n << endl;        // откладка для перемещения
}
bool DataBase::Check(int id)
{if (id <= amountOfRecord) return false; else return true;}

void DataBase::Open()
{
   bool is_new = false;
   filesystem::create_directory(filesystem::current_path().string() + "\\DataBases");
   string path = filesystem::current_path().string() + "\\DataBases\\" + nameOfFile + ".db";
   if (debugOn) cout << path << endl;
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
   ReadData(fs);
   while(is_deleted != false)      {is_deleted = ReadDelete(fs);        ReadData(fs);}
}

void DataBase::First()
{
   int id = 1;
   if (Check(id))       return;
   numberOfRecord = 1;
   PrintNums(numberOfRecord, amountOfRecord);         //
   do
   {
      GotoInProg(id);
      is_deleted = ReadDelete(fs);
      id++;
   }while(is_deleted);
   ReadData(fs);
   
   if (Count() == 0) {BofF = true; EofF = true;}
   else {BofF = false; EofF = false;}
   
   PrintNums(numberOfRecord, amountOfRecord);         //
}

void DataBase::Next()
{
   if (Eof()){
      int id = ++numberOfRecord;
      if (Check(id))       return;
      PrintNums(numberOfRecord, amountOfRecord);         //
      do
      {
         GotoInProg(id);
         is_deleted = ReadDelete(fs);
         id++;
      }while(is_deleted);
      ReadData(fs);
      
      if (amountOfRecord == numberOfRecord) {BofF = true; EofF = false;}
      else {BofF = true; EofF = true;}
   }
PrintNums(numberOfRecord, amountOfRecord);         //   
}

void DataBase::Prev()
{
   if (Bof()) {
      int id = --numberOfRecord;
      if (Check(id))       return;
      PrintNums(numberOfRecord, amountOfRecord);         //
      do
      {
         GotoInProg(id);
         is_deleted = ReadDelete(fs);
         id--;
      }while(is_deleted);
      ReadData(fs);
      
      if (1 == numberOfRecord) {BofF = false; EofF = true;}
      else {BofF = true; EofF = true;}
   }
}

void DataBase::Last()
{
   int id = allRecords;
   numberOfRecord = Count();
   do
   {
      GotoInProg(id);
      is_deleted = ReadDelete(fs);
      id--;
   }while(is_deleted);
   ReadData(fs);
   
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
         numberOfRecord = amountOfRecord;
         allRecords++;
         WriteTitle(fs);
      }
      GotoInProg(numberOfRecord);
      WriteDelete(fs, false);
      WriteData(fs);
      /*
      if (amountOfRecord == numberOfRecord) {BofF = true; EofF = false;}
      else if (1 == numberOfRecord)        {BofF = false; EofF = true;}
      else {BofF = true; EofF = true;}
      */
      BofF = true;      EofF = true;    // ?????????????
      
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
      numberOfRecord = lastRecord;
      GotoInProg(Id());
      ReadData(fs);
   }
   PrintNums(numberOfRecord, amountOfRecord);         //
}

void DataBase::Insert()
{
   lastRecord = numberOfRecord;
   isInserted = true;
}

void DataBase::Edit()
{
   lastRecord = numberOfRecord;
   isChangeable = true;
}

void DataBase::Delete()
{
   PrintNums(numberOfRecord, amountOfRecord);   //
   if (debugOn)cout << "del" << endl;         //
   
   GotoInProg(Id());
   WriteDelete(fs, true);
   amountOfRecord--;
   WriteTitle(fs);
   PrintNums(numberOfRecord, amountOfRecord);         //
   
   if (amountOfRecord == 0) {numberOfRecord = 0; return;}
   else if ((numberOfRecord - 1) <= amountOfRecord)        Prev();
   else         Next();
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
   char buf[len + 1];         // Выделение буфера для чтения
   f.read(buf, len);                   // Чтение (с нулевым байтом)
   buf[len] = 0;
   nameOfClass = buf;     
   f.read((char*)&size, sizeof(int));
   f.read((char*)&allRecords, sizeof(int));
   f.read((char*)&amountOfRecord, sizeof(int));
   f.flush();
}