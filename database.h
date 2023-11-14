#ifndef DATA
#define DATA

#include <iostream>
#include <fstream>
// #include <string>

class DataBase {
protected:
   // виртуальные методы
   virtual void ReadData(std::fstream& f) = 0;
   virtual void WriteData(std::fstream& f) = 0;
   virtual int Size() = 0;
   virtual void Recalc() = 0;
private:
   long amountOfRecord;    // суммарное количество записей
   long numberOfRecord;    // текущая запись
   bool isChangeable;  // можно ли изменять базу данных
   std::string nameOfFile;     // название файла для работы с ним
   std::fstream fs;  // поток для файла
public:
   DataBase(std::string obj) : nameOfFile(obj) {}  // подумать надо ли строку и параметр какой то 
   ~DataBase(){}
   void Open();
   void Close();
   long Id(); // идентификатор записи (смещение в файле)
   void Goto(long id); // перейти на запись с идентификатором id
   void First(); // перейти на первую запись в файле
   void Next(); // перейти на следующую запись в файле
   void Prev(); // перейти на предыдущую запись в файле
   void Last(); // перейти на последнюю запись в файле
   void Post(); // записать изменения
   void Cancel(); // отменить изменения, перечитать запись
   void Insert(); // добавить новую запись, войти в режим изменения
   void Edit(); // войти в режим изменений 
   void Delete(); // удалить запись
   bool Eof(); // файл пуст или обнаружен конец файла при выполнении Next() 
   bool Bof(); // файл пуст или обнаружено начало файла при выполнении Prev() 
   long Count();  // количество записей
   
};

#endif