#ifndef DATA
#define DATA

#include <iostream>
#include <fstream>

class DataBase {
protected:
   // ����������� ������
   virtual void ReadData(std::fstream& f) = 0;
   virtual void WriteData(std::fstream& f) = 0;
   virtual int Size() = 0;
   virtual void Recalc() = 0;
   std::string nameOfClass;

private:
   long amountOfRecord = 0;    // ��������� ���������� ������������ �������
   long numberOfRecord = 0;    // ������� ������
   long allRecords = 0; //      ���������� ��������� � ������������ �������
   bool isChangeable = false, isInserted = false;  // ��� Edit() | ��� Insert()
   std::string nameOfFile;     // �������� ����� ��� ������ � ���
   std::fstream fs;  // ����� ��� �����
   void GotoInProg(long id); // ������� �� ������ � ��������������� id (��� ������� ����������)
   bool EofF, BofF;     // ����� ��� ����������� ������/����� �����
   bool is_deleted;     // ���������� ��� ����������� ����� �� ����
   bool Check(int);     // �������� ������ �� ������� �������
   
   void WriteDelete(std::fstream& fs, bool is_del);     // ������ is_deleted
   bool ReadDelete(std::fstream& fs);   // ������ is_deleted
   void WriteTitle(std::fstream& fs);   // ������ ��������� ���� ������
   void ReadTitle(std::fstream& fs);    // ������ ��������� ���� ������

public:
   DataBase(std::string obj, std::string nOfClass) : nameOfFile(obj), nameOfClass(nOfClass) {}  // �����������
   ~DataBase(){}        // ����������
   void Open(); // �������� �����
   void Close(); // �������� �����
   long Id(); // ������������� ������ (�������� � �����)
   void Goto(long id);  // ������� �� ������ � ��������������� id 
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
};
#endif