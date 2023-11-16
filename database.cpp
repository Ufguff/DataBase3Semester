#include <fstream>
#include <iostream>
#include "database.h"

using namespace std;

// после написания основных функций узнать, надо ли каждый раз проверять на открытие потока

void DataBase::Open()
{
   //fsin.open(nameOfFile + ".db");
   
   fs.open (nameOfFile + ".db", std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::app);       // пошамань с параметрами
   
   // общее количество записей, если файл уже создан
   fs.seekg(0, ios::end);
   amountOfRecord = fs.tellg() / Size();
   
   
   //cout << fs.is_open() << endl;
   
}

void DataBase::Close()
{
   if (fs.is_open())  fs.close();
   
   /*
   if (fsin.is_open())  fsin.close();
   if (fsout.is_open())    fsout.close();      
   */
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
   //fsin.seekg((id - 1)*Size(), ios::beg);       // надо доработать + может на 1 чтобы точно считалось ??
   fs.seekg((id - 1)*Size(), ios::beg);       // надо доработать + может на 1 чтобы точно считалось ??
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
      //fsin.seekg((Id() - 1) * Size(), ios::beg);
      fs.seekg((Id() - 1) * Size(), ios::beg);
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
   
   //WriteData(fsout);
   
   WriteData(fs);
}


void DataBase::Cancel() // пока хуйня перечитываю
{
   //Close();
   //fsin.open(nameOfFile + ".db", ios::in | ios::binary);
   // надо ли переоткрывать
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;
   ReadData(fs);
}

void DataBase::Insert() // goto?? 
{
   //Close();
   //if ( ! fsout.is_open() ) Edit();
   //numberOfRecord++;    // отдельный метод
   
   amountOfRecord++;
   Goto(Count());
   if(isChangeable)     WriteData(fs);
}

void DataBase::Edit()
{
   isChangeable = true;
   
   /*
   fsout.open(nameOfFile + ".db", ios::out | ios::binary);
   Post();
    if ( ! fs.is_open() )        //Проверка, если файл не открыт...
      cout << endl <<"Всё плохо!" << endl;
   else//или
      cout << endl << "Всё хорошо!" << endl;
   */
}

void DataBase::Delete()
{
   
}

bool DataBase::Eof()
{
   //return fsout.eof() || fsin.eof() || Count() == Id();
   return fs.eof() || Count() == Id();
}

bool DataBase::Bof()
{
   //return fsout.eof() || fsin.eof() || Id() == 1;
   return fs.eof() || Id() == 1;
}