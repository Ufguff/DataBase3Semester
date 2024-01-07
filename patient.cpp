#include "patient.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int Patient::Size()
{
   return sizeof(int) * 3 + sizeof(bool) + sizeof(char)*100; // ������������ ����� stirng - 100
   // ����� ������ ����� 114 ������, ��� ����������� ��������������� hex ����������
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
   f.flush();
}

void Patient::WriteData(fstream &f)
{
   char buf[100];
   memset(buf, 0, sizeof(buf));
   strncpy(buf, name.c_str(), sizeof(buf) - 1);
   
   f.write((char*)&buf, sizeof(buf)); 
   f.write((char*)&age, sizeof(int));
   f.write((char*)&weight, sizeof(int));
   f.write((char*)&height, sizeof(int));
   f.write((char*)&isIll, sizeof(bool));
   f.flush();
}

