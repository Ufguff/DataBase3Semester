#include <fstream>
#include <iostream>
#include "database.h"

using namespace std;

// ����� ��������� �������� ������� ������, ���� �� ������ ��� ��������� �� �������� ������

void DataBase::Open()
{
   fs.open(nameOfFile + ".db", fstream::out | fstream::binary);
   // �������� �����
   
   if ( ! fs.is_open() )        //��������, ���� ���� �� ������...
      cout << endl <<"�� �����!" << endl;
   else//���
      cout << endl << "�� ������!" << endl;
   
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
   return numberOfRecord;   // ���� �� ��� -1 ������?
}

long DataBase::Count()
{
   return amountOfRecord;
}

void DataBase::Goto(long id)
{
   numberOfRecord = id;
   fs.seekg((numberOfRecord - 1)*Size(), ios::beg);       // ���� ���������� + ����� �� 1 ����� ����� ��������� ??
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
// next prev ��������
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
    if ( ! fs.is_open() )        //��������, ���� ���� �� ������...
      cout << endl <<"�� �����!" << endl;
   else//���
      cout << endl << "�� ������!" << endl;
   
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