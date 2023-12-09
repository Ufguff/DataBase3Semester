#ifndef PAT
#define PAT

#include <iostream>
#include "database.h"

class Patient : public DataBase
{
   // поля Parent для сохранения
   std::string name;    // имя пациента
   int age;     // возраст пациента
   int weight;	//  вес пациента (измерения проходят в килограммах)
   int height;	// рост пациента (измерения проходят в сантиметрах)
   bool isIll;  // болен ли пациент
   // определения виртуальных методов класса DataBase
   void ReadData(std::fstream& f);
   void WriteData(std::fstream& f);
   int Size();
   void Recalc(){}
   
public:
   Patient(std::string filename) : DataBase(filename, "Patient") {}
   
   void SetName(std::string t)  {name = t;}
   std::string GetName()        {return name;}
   
   void SetAge(int t)   {age = t;}
   int GetAge() {return age;}
   
   void SetWeight(int t)        {weight = t;}
   int GetWeight()      {return weight;}
   
   void SetHeight(int t)        {height = t;}
   int GetHeight()      {return height;}
   
   void SetIsIll(bool t)        {isIll = t;}
   bool GetIsIll()      {return isIll;}
};

#endif