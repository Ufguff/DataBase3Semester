#ifndef DATA
#define DATA

#include <iostream>
#include <fstream>
// #include <string>

class DataBase {
protected:
   // ����������� ������
   //virtual void ReadData(std::fstream& f) = 0;
   //virtual void WriteData(std::fstream& f) = 0;
   virtual void ReadData(std::ifstream& f) = 0;
   virtual void WriteData(std::ofstream& f) = 0;
   virtual int Size() = 0;
   virtual void Recalc() = 0;
private:
   long amountOfRecord = 0;    // ��������� ���������� �������
   long numberOfRecord = 0;    // ������� ������
   bool isChangeable = false;  // ����� �� �������� ���� ������
   std::string nameOfFile;     // �������� ����� ��� ������ � ���
   std::fstream fs;  // ����� ��� �����
   std::ifstream fsin;
   std::ofstream fsout;
public:
   DataBase(std::string obj) : nameOfFile(obj) {}  // �������� ���� �� ������ � �������� ����� �� 
   ~DataBase(){}
   void Open();
   void Close();
   long Id(); // ������������� ������ (�������� � �����)
   void Goto(long id); // ������� �� ������ � ��������������� id
   void First(); // ������� �� ������ ������ � �����
   void Next(); // ������� �� ��������� ������ � �����
   void Prev(); // ������� �� ���������� ������ � �����
   void Last(); // ������� �� ��������� ������ � �����
   void Post(); // �������� ���������
   void Cancel(); // �������� ���������, ���������� ������
   void Insert(); // �������� ����� ������, ����� � ����� ���������
   void Edit(); // ����� � ����� ��������� 
   void Delete(); // ������� ������
   bool Eof(); // ���� ���� ��� ��������� ����� ����� ��� ���������� Next() 
   bool Bof(); // ���� ���� ��� ���������� ������ ����� ��� ���������� Prev() 
   long Count();  // ���������� �������
   
   void Readfile();
   
};

#endif