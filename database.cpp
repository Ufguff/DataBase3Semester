#include <fstream>
#include <iostream>
#include <filesystem>
#include "database.h"
using namespace std;

bool debugOn = false;    // true - включает вывод текущей записи и всех записей | false - отключает данную возможность


void PrintNums(int m, int n)
{
   if (debugOn) cout << m << "- num | amout - " << n << endl;        // откладка для перемещения
}

// изолировать number и amount, дописать отдельные функции для инкапсуляции (если надо??)

void DataBase::Open()
{
   bool is_new = false;
   filesystem::create_directory(filesystem::current_path().string() + "\\DataBases");
   string path = filesystem::current_path().string() + "\\DataBases\\" + nameOfFile + ".db";
   if (debugOn) cout << path << endl;
   ifstream check(path);
   if (! check.is_open()){
      fs.open (path, std::fstream::in | std::fstream::out | std::fstream::binary | fstream::app);
      is_new = true;
   }
   
   Close();
   fs.open (path, std::fstream::in | std::fstream::out | std::fstream::binary);
  
   if(is_new)   WriteTitle(fs);
   else ReadTitle(fs);   
  
   // хранить в самом начале сколько записей и какой класс скажем сколько весит записьы
   
   // общее количество записей, если файл уже создан
   
   //cout << amountOfRecord << endl;
   //cout << nameOfClass << endl;
   
   if (amountOfRecord == 0) {BofF = true; EofF = true;}
   else {BofF = true; EofF = false;}
}

void DataBase::Close()
{
   if (fs.is_open())  fs.close();
}

long DataBase::Id()
{
   return numberOfRecord;
}

long DataBase::Count()
{
   return amountOfRecord;
}

void DataBase::GotoInProg(long id)
{
   numberOfRecord = id;
   fs.seekg((id - 1)*Size() + SizeTitle() + sizeof(bool)*(id - 1), ios::beg);
}

void DataBase::Goto(long id)
{
   GotoInProg(id);
   is_deleted = ReadDelete(fs);
   ReadData(fs);
   while(is_deleted != false)      {is_deleted = ReadDelete(fs);        ReadData(fs);}
   
   if (amountOfRecord == numberOfRecord) {BofF = true; EofF = false;}
   else if (1 == numberOfRecord)        {BofF = false; EofF = true;}
   else {BofF = true; EofF = true;}
   
}

void DataBase::First()
{
   
   int id = 1;
   numberOfRecord = 1;
   PrintNums(numberOfRecord, amountOfRecord);         //
   GotoInProg(id);
   is_deleted = ReadDelete(fs);
   ReadData(fs);
   while(is_deleted != false)        {GotoInProg(id);       is_deleted = ReadDelete(fs);     ReadData(fs);      id++;}
   
   BofF = false; EofF = true;
   
   PrintNums(numberOfRecord, amountOfRecord);         //
   
}

void DataBase::Next()
{
   if (Eof()){
      int id = ++numberOfRecord, count = 0;
      PrintNums(numberOfRecord, amountOfRecord);         //
      GotoInProg(id);
      is_deleted = ReadDelete(fs);
      ReadData(fs);
      while(is_deleted != false)        {GotoInProg(id);       is_deleted = ReadDelete(fs);  ReadData(fs);     id++; count++;}
      if (count != 0)numberOfRecord--;
      
      if (amountOfRecord == numberOfRecord) {BofF = true; EofF = false;}
      else {BofF = true; EofF = true;}
      
   }
PrintNums(numberOfRecord, amountOfRecord);         //   
}

void DataBase::Prev()
{
   if (Bof()) {
      int id = --numberOfRecord, count = 0;
      PrintNums(numberOfRecord, amountOfRecord);         //
      GotoInProg(id);
      is_deleted = ReadDelete(fs);
      ReadData(fs);
      while(is_deleted != false)        {GotoInProg(id);       is_deleted = ReadDelete(fs);  ReadData(fs);     id--; count++;}
      if (count != 0)   numberOfRecord++;
      
      if (1 == numberOfRecord) {BofF = false; EofF = true;}
      else {BofF = true; EofF = true;}
   }
}

void DataBase::Last()
{
   int id = Count();
   numberOfRecord = Count();
   GotoInProg(id);
   is_deleted = ReadDelete(fs);
   ReadData(fs);
   while(is_deleted != false)        {GotoInProg(id);       is_deleted = ReadDelete(fs);  ReadData(fs);    id++;}
   
   BofF = true; EofF = false;
}

void DataBase::Post()
{   
   if (isChangeable || isInserted)              // если режимы не выставлены
   {
      if(isChangeable)     
      {
         GotoInProg(Id());
      }
      else if (isInserted)
      {
         amountOfRecord++;
         numberOfRecord = amountOfRecord;
      }
      GotoInProg(Id());
      WriteDelete(fs, false);
      WriteData(fs);
      
      
      if (amountOfRecord == numberOfRecord) {BofF = true; EofF = false;}
      else if (1 == numberOfRecord)        {BofF = false; EofF = true;}
      else {BofF = true; EofF = true;}
      
      WriteTitle(fs);
      
      isChangeable = false;
      isInserted = false;
   }
   PrintNums(numberOfRecord, amountOfRecord);         //
}


void DataBase::Cancel() //работает здесь флажок просто
{
   if (isChangeable || isInserted)
   {
      isChangeable = false;
      isInserted = false;
      
      numberOfRecord = lastRecord;
      GotoInProg(Id());
      ReadData(fs);
   }
   PrintNums(numberOfRecord, amountOfRecord);         //
}

void DataBase::Insert() // goto?? 
{
   // запоминает что мы вошли в такой режим
   lastRecord = numberOfRecord;
   isInserted = true;
   // сохранение номер апрошлой для cancel чтобы перечитать
}

void DataBase::Edit()
{
   lastRecord = numberOfRecord;
   isChangeable = true;
}

void DataBase::Delete()
{
   PrintNums(numberOfRecord, amountOfRecord);   //
   if (debugOn)cout << "del" << endl;         //ть
   
   GotoInProg(Id());
   WriteDelete(fs, true);
   amountOfRecord--;
   WriteTitle(fs);
   PrintNums(numberOfRecord, amountOfRecord);         //
   
   if (amountOfRecord == 0) {numberOfRecord = 0; return;}
   else if ((numberOfRecord - 1) <= amountOfRecord)        Prev();
   else         Next();
}

bool DataBase::Eof()
{
   return EofF;
   // если дальше нет записи то то мы выставляем флажок
}

bool DataBase::Bof()
{
   return BofF;
}

void DataBase::WriteDelete(fstream& f, bool is_deleted)
{
   f.write((char*)&is_deleted, sizeof(bool));
}

bool DataBase::ReadDelete(fstream& f)
{
   f.read((char*)&is_deleted, sizeof(bool));
   return is_deleted;
}

void DataBase::WriteTitle(fstream& f)
{
   f.seekg(0, ios::beg);
   int size = Size();
   f.write((char*)nameOfClass.c_str(), 15);
   f.write((char*)&size, sizeof(int));
   f.write((char*)&amountOfRecord, sizeof(int));
   f.flush();
}

int DataBase::SizeTitle()
{
   return sizeof(int)*2 + sizeof(char)*15 ;     // для названия класса длина 15
}

void DataBase::ReadTitle(fstream& f)
{
   f.seekg(0, ios::beg);
   int size;
   size_t len = 15;
   char buf[len + 1];         // Выделение буфера для чтения
   f.read(buf, len);                   // Чтение (с нулевым байтом)
   buf[len] = 0;
   nameOfClass = buf;     
   f.read((char*)&size, sizeof(int));
   f.read((char*)&amountOfRecord, sizeof(int));
   f.flush();
}