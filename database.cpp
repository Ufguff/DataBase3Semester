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
   else
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
   //cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;        // откладка дл€ перемещени€
   if(isChangeable)     {
      cout << "da" << endl;
      WriteData(fs);
   }
}


void DataBase::Cancel() //работает
{
   //cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;
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
   int ukaz = fs.tellg();
   
  if (Id() != Count())
  {
   for(int )
  }     
  else
  {
   fs.write((char*)'\0', 100); 
   fs.write((char*)&age, sizeof(int));
   fs.write((char*)&weight, sizeof(int));
   fs.write((char*)&height, sizeof(int));
   fs.write((char*)&isIll, sizeof(bool));
   fs.flush();

  }     
   amountOfRecord--;
}

bool DataBase::Eof()
{
   return fs.eof() || Count() == Id();
}

bool DataBase::Bof()
{
   return fs.eof() || Id() == 1;
}