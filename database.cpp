#include <fstream>
#include <iostream>
#include "database.h"

using namespace std;

// ����������� number � amount, �������� ��������� ������� ��� ������������

void DataBase::Open()
{
   ifstream check(nameOfFile + ".db");
   if (! check.is_open())
      fs.open (nameOfFile + ".db", std::fstream::in | std::fstream::out | std::fstream::binary | fstream::app);
   
   Close();
   fs.open (nameOfFile + ".db", std::fstream::in | std::fstream::out | std::fstream::binary);
   
   // ����� ���������� �������, ���� ���� ��� ������
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
   Goto(id);
   ReadData(fs);
   cout << is_deleted << endl;
   while(is_deleted != false)        {Goto(id);     ReadData(fs);      id++;}
   
}

void DataBase::Next()
{
   if (!Eof()){
      int id = numberOfRecord;
      Goto(id);
      ReadData(fs);
      //cout << is_deleted << endl;
      while(is_deleted != false)        {Goto(id);  ReadData(fs);     id++; }
   }
   else {return;}
   numberOfRecord++;
}

void DataBase::Prev()
{
   if (!Bof()) {
      int id = numberOfRecord;
      Goto(id);
      ReadData(fs);
      while(is_deleted != false)        {Goto(id);  ReadData(fs);     id--;}
   }
   else {return;}
   numberOfRecord--;
}

void DataBase::Last()
{
   int id = Count();
   numberOfRecord = Count();
   Goto(id);
   ReadData(fs);
   while(this->is_deleted != false)        {Goto(id);      id++;}
}

void DataBase::Post()
{   
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;        // �������� ��� �����������
   if(isChangeable)     {
      cout << "da" << endl;
      WriteData(fs);
   }
}


void DataBase::Cancel() //��������
{
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;
   Goto(Id());
   ReadData(fs);
}

void DataBase::Insert() // goto?? 
{
   Edit();      // ���� ����������� ����� ��������� � ��������
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
   is_deleted = true;
   Goto(Id());
   WriteData(fs);
   amountOfRecord--;
   cout << numberOfRecord << "-num | amout" << amountOfRecord << endl;
   
   if ((numberOfRecord - 1) == amountOfRecord)        Prev();
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