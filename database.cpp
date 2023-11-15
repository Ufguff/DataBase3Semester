#include <fstream>
#include <iostream>
#include "database.h"

using namespace std;

// после написания основных функций узнать, надо ли каждый раз проверять на открытие потока

void DataBase::Open()
{
   fsin.open(nameOfFile + ".db");
   // создание файла
   
   if ( ! fsin.is_open() )        //Проверка, если файл не открыт...
      cout << endl <<"Всё плохо!" << endl;
   else//или
      cout << endl << "Всё хорошо!" << endl;
   
   fsin.close();
}

void DataBase::Close()
{
   if (fsin.is_open())  fsin.close();
   if (fsout.is_open())    fsout.close();      
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
   fsin.seekg((id - 1)*Size(), ios::beg);       // надо доработать + может на 1 чтобы точно считалось ??
}

void DataBase::First()
{
   numberOfRecord = 1;
   //fsin.seekg(0, ios::beg);
   Goto(Id());
}

void DataBase::Next()
{
   if (!Eof()){
      numberOfRecord++;
      Goto(Id());
      //fsin.seekg((Id()) * Size(), ios::beg);
   }
}
// next prev потраить
void DataBase::Prev()
{
   if (!Bof()) {
      numberOfRecord--;
      fsin.seekg((Id() - 1) * Size(), ios::beg);
   }
}

void DataBase::Last()
{
   //fs.seekg((Count() - 1) * Size(), ios::beg);
   Goto(Count());
}

void DataBase::Post()
{
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;
   WriteData(fsout);
}

void DataBase::Readfile()
{
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;
   ReadData(fsin);
}

void DataBase::Cancel() // пока хуйня перечитываю
{
   Close();
   fsin.open(nameOfFile + ".db", ios::in | ios::binary);
   
}

void DataBase::Insert() // goto?? 
{
   //Close();
   if ( ! fsout.is_open() ) Edit();
   //numberOfRecord++;    // отдельный метод
   amountOfRecord++;
   Goto(Count());
}

void DataBase::Edit()
{
   fsout.open(nameOfFile + ".db", ios::out | ios::binary);
   
   //Post();
    if ( ! fsout.is_open() )        //Проверка, если файл не открыт...
      cout << endl <<"Всё плохо!" << endl;
   else//или
      cout << endl << "Всё хорошо!" << endl;
   
}

void DataBase::Delete()
{
   
}

bool DataBase::Eof()
{
   return fsout.eof() || fsin.eof() || Count() == Id();
}

bool DataBase::Bof()
{
   return fsout.eof() || fsin.eof() || Id() == 1;
}