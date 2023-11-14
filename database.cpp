#include <fstream>
#include <iostream>
#include "database.h"

using namespace std;

// после написания основных функций узнать, надо ли каждый раз проверять на открытие потока

void DataBase::Open()
{
   fs.open(nameOfFile + ".db", fstream::out | fstream::binary);
   // создание файла
   
   if ( ! fs.is_open() )        //Проверка, если файл не открыт...
      cout << endl <<"Всё плохо!" << endl;
   else//или
      cout << endl << "Всё хорошо!" << endl;
   
   //int age = 19;
   //fs.write((char*)&age, sizeof(age));
   
   fs.close();
}

void DataBase::Close()
{
   if (fs.is_open())    {fs.close();}
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
   numberOfRecord = id;
   fs.seekg((numberOfRecord - 1)*Size(), ios::beg);       // надо доработать + может на 1 чтобы точно считалось ??
}

void DataBase::First()
{
   fs.seekg(0, ios::beg);
}

void DataBase::Next()
{
   //if (Eof()){
      numberOfRecord++;
      fs.seekg((Id()) * Size(), ios::beg);
   //}
}
// next prev потраить
void DataBase::Prev()
{
   if (Bof()) {
      numberOfRecord--;
      fs.seekg((Id() - 1) * Size(), ios::beg);
   }
}

void DataBase::Last()
{
   fs.seekg((Count() - 1) * Size(), ios::beg);
}

void DataBase::Post()
{
   WriteData(fs);
   //Next();
}

void DataBase::Cancel()
{
   if( fs.is_open() )   Close();
   //cout << numberOfRecord << endl;
   fs.open(nameOfFile + ".db", fstream::in | fstream::binary);
   ReadData(fs);
   //Close();
}

void DataBase::Insert() // goto?? 
{
   Edit();
   fs.seekp(Id()*Size(), ios::beg);
   numberOfRecord++;
   amountOfRecord++;
   
}

void DataBase::Edit()
{
   fs.open(nameOfFile + ".db", fstream::out | fstream::binary);
   
   //Post();
    if ( ! fs.is_open() )        //Проверка, если файл не открыт...
      cout << endl <<"Всё плохо!" << endl;
   else//или
      cout << endl << "Всё хорошо!" << endl;
   
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