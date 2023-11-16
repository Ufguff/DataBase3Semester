#include <fstream>
#include <iostream>
#include "database.h"

using namespace std;

// после написания основных функций узнать, надо ли каждый раз проверять на открытие потока

void DataBase::Open()
{
   fs.open (nameOfFile + ".db", std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::app);       // пошамань с параметрами
   
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
   numberOfRecord = 1;
   Goto(Id());
}

void DataBase::Next()
{
   if (!Eof()){
      numberOfRecord++;
      Goto(Id());
   }
}

void DataBase::Prev()
{
   if (!Bof()) {
      numberOfRecord--;
      fs.seekg((Id() - 1) * Size(), ios::beg);
   }
}

void DataBase::Last()
{
   Goto(Count());
}

void DataBase::Post()
{
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;
   if(isChangeable)     {
      cout << "da" << endl;
      WriteData(fs);
   }
}


void DataBase::Cancel() //работает
{
   //cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;
   ReadData(fs);
}

void DataBase::Insert() // goto?? 
{
   Edit();      // надо разобраться когда отключать и включать
   amountOfRecord++;
   numberOfRecord = amountOfRecord;
   Goto(Count());
   if(isChangeable)     WriteData(fs);
}

void DataBase::Edit()
{
   isChangeable = true;
}

void DataBase::Delete()
{
   
}

bool DataBase::Eof()
{
   return fs.eof() || Count() == Id();
}

bool DataBase::Bof()
{
   return fs.eof() || Id() == 1;
}