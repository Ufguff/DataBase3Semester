#include <fstream>
#include <iostream>
#include "database.h"

using namespace std;

// изолировать number и amount, дописать отдельные функции дл€ инкапсул€ции

void DataBase::Open()
{
   ifstream check(nameOfFile + ".db");
   if (! check.is_open())
      fs.open (nameOfFile + ".db", std::fstream::in | std::fstream::out | std::fstream::binary | fstream::app);
   
   Close();
   fs.open (nameOfFile + ".db", std::fstream::in | std::fstream::out | std::fstream::binary);
   
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

void DataBase::Goto(long id)
{
   numberOfRecord = id;
   fs.seekg((id - 1)*Size(), ios::beg);
}

void DataBase::First()
{
   int id = 1;
   numberOfRecord = 1;
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;        // откладка дл€ перемещени€
   Goto(id);
   ReadData(fs);
   cout << is_deleted << endl;
   while(is_deleted != false)        {Goto(id);     ReadData(fs);      id++;}
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;        // откладка дл€ перемещени€
   
}

void DataBase::Next()
{
   if (!Eof()){
      int id = ++numberOfRecord, count = 0;
      cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;        // откладка дл€ перемещени€
      Goto(id);
      ReadData(fs);
      //cout << is_deleted << endl;
      while(is_deleted != false)        {Goto(id);  ReadData(fs);     id++; count++;}
      if (count != 0)numberOfRecord--;
   }
 //cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;        // откладка дл€ перемещени€
   
}

void DataBase::Prev()
{
   if (!Bof()) {
      int id = --numberOfRecord;
      cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;        // откладка дл€ перемещени€
      Goto(id);
      ReadData(fs);
      while(is_deleted != false)        {Goto(id);  ReadData(fs);     id--;}
      //numberOfRecord++;
   }
}

void DataBase::Last()
{
   int id = Count();
   numberOfRecord = Count();
   Goto(id);
   ReadData(fs);
   while(is_deleted != false)        {Goto(id);  ReadData(fs);    id++;}
}

void DataBase::Post()
{   
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;        // откладка дл€ перемещени€
   if(isChangeable)     {
      cout << "da" << endl;
      Goto(Id());
      WriteData(fs);
   }
}


void DataBase::Cancel() //работает
{
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;
   Goto(Id());
   ReadData(fs);
}

void DataBase::Insert() // goto?? 
{
   Edit();      // надо разобратьс€ когда отключать и включать
   amountOfRecord++;
   numberOfRecord = amountOfRecord;
   Goto(Count());
}

void DataBase::Edit()
{
   isChangeable = true;
}

void DataBase::Delete()
{
   ReadData(fs);
   is_deleted = true;
   Goto(Id());
   WriteData(fs);
   amountOfRecord--;
   
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;
   
   if ((numberOfRecord - 1) <= amountOfRecord)        Prev();
   else         Next();
}

bool DataBase::Eof()
{
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;
   return fs.eof() || Count() == Id();
}

bool DataBase::Bof()
{
   return fs.eof() || Id() == 1;
}