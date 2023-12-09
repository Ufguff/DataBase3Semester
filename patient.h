#ifndef PAT
#define PAT

#include <iostream>
#include "database.h"

class Patient : public DataBase
{
   // ���� Parent ��� ����������
   std::string name;    // ��� ��������
   int age;     // ������� ��������
   int weight;	//  ��� �������� (��������� �������� � �����������)
   int height;	// ���� �������� (��������� �������� � �����������)
   bool isIll;  // ����� �� �������
   // ����������� ����������� ������� ������ DataBase
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