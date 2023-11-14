#include <fstream>
#include <iostream>
#include "database.h"

using namespace std;

// после написания основных функций узнать, надо ли каждый раз проверять на открытие потока

void DataBase::Open()
{
   fs.open(nameOfFile + ".db", fstream::out | fstream::binary);
   // создание файла
   
   if ( ! fs.is_open() )//Проверка, если файл не открыт...
      cout << endl <<"Всё плохо!" << endl;
   else//или
      cout << endl << "Всё хорошо!" << endl;
   
   //fs.close();
}

void DataBase::Close()
{
   if (fs.is_open())    {cout << "всё гуд";  fs.close();}
}

long DataBase::Id()
{
   return numberOfRecord;   // надо ли рил -1 делать?
}

long DataBase::Count()
{
   return amountOfRecord;
}

void DataBase::Goto(long id)
{
   fs.seekg((id - 1)*Size());       // надо доработать + может на 1 чтобы точно считалось ??
}

void DataBase::First()
{
   fs.seekg(0);
}

void DataBase::Next()
{
   if (fs.Eof()){
      numberOfRecord++;
      fs.seekg((Id() - 1) * Size());
   }
}
// next prev потраить
void DataBase::Prev()
{
   if (fs.Bof()) {
      numberOfRecord--;
      fs.seekg((Id() - 1) * Size());
   }
}

void DataBase::Last()
{
   fs.seekg((Count() - 1) * Size());
}

void DataBase::Post()
{
   WriteData(fs);
}

void DataBase::Cancel()
{
   
}

void DataBase::Insert() // goto?? 
{
   amountOfRecord++;
   Edit();
}

void DataBase::Edit()
{
   fs.open(nameOfFile + ".db", fstream::out | fstream::binary);
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
   return fs.eof() || Count() == 1;
}