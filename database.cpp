#include <fstream>
#include <iostream>
#include <filesystem>
#include "database.h"
using namespace std;

void PrintNums(int m, int n)
{
   cout << m << "- num | amout - " << n << endl;        // откладка дл€ перемещени€
}




// изолировать number и amount, дописать отдельные функции дл€ инкапсул€ции

void DataBase::Open()
{
   string path = filesystem::current_path().string() + "\\DataBases\\" + nameOfFile + ".db";    // создание папки если нет

   ifstream check(path);
   if (! check.is_open())
      fs.open (path, std::fstream::in | std::fstream::out | std::fstream::binary | fstream::app);
   
   Close();
   fs.open (path, std::fstream::in | std::fstream::out | std::fstream::binary);
   
   // общее количество записей, если файл уже создан
   fs.seekg(0, ios::end);
   amountOfRecord = fs.tellg() / Size();
}

void DataBase::Close()
{
   if (fs.is_open())  fs.close();
}

long DataBase::Id()
{
   return numberOfRecord;
}

long DataBase::Count()
{
   return amountOfRecord;
}

void DataBase::GotoInProg(long id)
{
   numberOfRecord = id;
   fs.seekg((id - 1)*Size(), ios::beg);
}

void DataBase::Goto(long id)
{
   numberOfRecord = id;
   fs.seekg((id - 1)*Size(), ios::beg);
   ReadData(fs);
   while(is_deleted != false)      ReadData(fs);
}

void DataBase::First()
{
   int id = 1;
   numberOfRecord = 1;
   PrintNums(numberOfRecord, amountOfRecord);         //
   GotoInProg(id);
   ReadData(fs);
   cout << is_deleted << endl;
   while(is_deleted != false)        {GotoInProg(id);     ReadData(fs);      id++;}
   PrintNums(numberOfRecord, amountOfRecord);         //
   
}

void DataBase::Next()
{
   if (!Eof()){
      int id = ++numberOfRecord, count = 0;
      PrintNums(numberOfRecord, amountOfRecord);         //
      GotoInProg(id);
      ReadData(fs);
      while(is_deleted != false)        {GotoInProg(id);  ReadData(fs);     id++; count++;}
      if (count != 0)numberOfRecord--;
   }
PrintNums(numberOfRecord, amountOfRecord);         //   
}

void DataBase::Prev()
{
   if (!Bof()) {
      int id = --numberOfRecord, count = 0;
      PrintNums(numberOfRecord, amountOfRecord);         //
      GotoInProg(id);
      ReadData(fs);
      while(is_deleted != false)        {GotoInProg(id);  ReadData(fs);     id--; count++;}
      if (count != 0)   numberOfRecord++;
   }
}

void DataBase::Last()
{
   int id = Count();
   numberOfRecord = Count();
   GotoInProg(id);
   ReadData(fs);
   while(is_deleted != false)        {GotoInProg(id);  ReadData(fs);    id++;}
}

void DataBase::Post()
{   
   PrintNums(numberOfRecord, amountOfRecord);         //
   if(isChangeable)     {
      cout << "da" << endl;
      GotoInProg(Id());
      WriteData(fs);
   }
}


void DataBase::Cancel() //работает
{
   PrintNums(numberOfRecord, amountOfRecord);         //
   GotoInProg(Id());
   ReadData(fs);
}

void DataBase::Insert() // goto?? 
{
   Edit();      // надо разобратьс€ когда отключать и включать
   amountOfRecord++;
   numberOfRecord = amountOfRecord;
   GotoInProg(Count());
}

void DataBase::Edit()
{
   isChangeable = true;
}

void DataBase::Delete()
{
   PrintNums(numberOfRecord, amountOfRecord); cout << "del" << endl;         //
   // проблема в 4 тесте - удаленные записи (3 и 4) имеют данные 4 записи
   //ReadData(fs);      это решает проблему так как мы уже прочитали запись, нужно больше отладить
   is_deleted = true;
   GotoInProg(Id());
   WriteData(fs);
   amountOfRecord--;
   
   PrintNums(numberOfRecord, amountOfRecord);         //
   
   if ((numberOfRecord - 1) <= amountOfRecord)        Prev();
   else         Next();
}

bool DataBase::Eof()
{
   return fs.eof() || Count() == Id();
}

bool DataBase::Bof()
{
   return fs.eof() || Id() == 1;
}