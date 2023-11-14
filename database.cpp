#include <fstream>
#include <iostream>
#include "database.h"

using namespace std;

// ����� ��������� �������� ������� ������, ���� �� ������ ��� ��������� �� �������� ������

void DataBase::Open()
{
   fs.open(nameOfFile + ".db", fstream::out | fstream::binary);
   // �������� �����
   
   if ( ! fs.is_open() )//��������, ���� ���� �� ������...
      cout << endl <<"�� �����!" << endl;
   else//���
      cout << endl << "�� ������!" << endl;
   
   //fs.close();
}

void DataBase::Close()
{
   if (fs.is_open())    {cout << "�� ���";  fs.close();}
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
   fs.seekg((id - 1)*Size());       // ���� ���������� + ����� �� 1 ����� ����� ��������� ??
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
// next prev ��������
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