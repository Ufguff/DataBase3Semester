#include "patient.h"
#include <iostream>
#include <fstream>
using namespace std;

void Patient::ReadData(fstream &f)
{
   
   
   
}

void Patient::WriteData(fstream &f)
{
   size_t size = name.size();
   f.write((char*)&size, sizeof(size));
   f.write((char*)&name.c_str(), name); 
   f.write((char*)&age, sizeof(age));
   f.write((char*)&weight, sizeof(weight));
   f.write((char*)&height, sizeof(height));
   f.write((char*)&isIll, sizeof(isIll));
   
}