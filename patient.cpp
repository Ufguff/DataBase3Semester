#include "patient.h"
#include <iostream>
#include <fstream>
using namespace std;

int Patient::Size()
{
   return sizeof(int)*3 + sizeof(bool); // + sizeof(string)*100; // максимальная длина stirng - 100
}

void Patient::ReadData(fstream &f)
{
   /*
   size_t len = 100;
   char buf[len + 1];         // Выделение буфера для чтения
   f.read(buf, len);                   // Чтение (с нулевым байтом)
   buf[len] = 0;
   name = buf;                         // Присвоение считанной строки члену
   */
   f.read((char*)&age, sizeof(age));
   f.read((char*)&weight, sizeof(weight));
   f.read((char*)&height, sizeof(height));
   f.read((char*)&isIll, sizeof(isIll));
}

void Patient::WriteData(fstream &f)
{
   //size_t size = name.size();
   //cout << size << endl;
   //f.write((char*)&size, sizeof(size));
   
   //f.write((char*)name.c_str(), 100); 
   
   
   f.write((char*)&age, sizeof(age));
   f.write((char*)&weight, sizeof(weight));
   f.write((char*)&height, sizeof(height));
   f.write((char*)&isIll, sizeof(isIll));
}