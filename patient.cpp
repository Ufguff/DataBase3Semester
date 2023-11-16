#include "patient.h"
#include <iostream>
#include <fstream>
using namespace std;

int Patient::Size()
{
   return sizeof(int) * 3 + sizeof(bool) + sizeof(char)*100; // ������������ ����� stirng - 100
}

void Patient::ReadData(fstream &f)
{
   size_t len = 100;
   char buf[len + 1];         // ��������� ������ ��� ������
   f.read(buf, len);                   // ������ (� ������� ������)
   buf[len] = 0;
   name = buf;                         // ���������� ��������� ������ �����
   
   f.read((char*)&age, sizeof(int));
   f.read((char*)&weight, sizeof(int));
   f.read((char*)&height, sizeof(int));
   f.read((char*)&isIll, sizeof(bool));
}

void Patient::WriteData(fstream &f)
{
   f.write((char*)name.c_str(), 100); 
   f.write((char*)&age, sizeof(int));
   f.write((char*)&weight, sizeof(int));
   f.write((char*)&height, sizeof(int));
   f.write((char*)&isIll, sizeof(bool));
}