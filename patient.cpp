#include "patient.h"
#include <iostream>
#include <fstream>
using namespace std;

// удалена или нет нужно реализовать через database и отдельно

int Patient::Size()
{
   return sizeof(int) * 3 + sizeof(bool) + sizeof(char)*100; // максимальная длина stirng - 100
   // всего запись весит 114 байтов, для наглядности воспользоваться hex редактором
}

void Patient::ReadData(fstream &f)
{
   //f.read((char*)&is_deleted, sizeof(bool));
   
   size_t len = 100;
   char buf[len + 1];         // Выделение буфера для чтения
   f.read(buf, len);                   // Чтение (с нулевым байтом)
   buf[len] = 0;
   name = buf;                         // Присвоение считанной строки члену
   
   f.read((char*)&age, sizeof(int));
   f.read((char*)&weight, sizeof(int));
   f.read((char*)&height, sizeof(int));
   f.read((char*)&isIll, sizeof(bool));
   f.flush();
}

void Patient::WriteData(fstream &f)
{
   //f.write((char*)&is_deleted, sizeof(bool));
   f.write((char*)name.c_str(), 100); 
   f.write((char*)&age, sizeof(int));
   f.write((char*)&weight, sizeof(int));
   f.write((char*)&height, sizeof(int));
   f.write((char*)&isIll, sizeof(bool));
   f.flush();
}

