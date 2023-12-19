#ifndef DATA
#define DATA

#include <iostream>
#include <fstream>

class DataBase {
protected:
   // виртуальные методы
   virtual void ReadData(std::fstream& f) = 0;
   virtual void WriteData(std::fstream& f) = 0;
   virtual int Size() = 0;
   virtual void Recalc() = 0;
   std::string nameOfClass;

private:
   long amountOfRecord = 0;    // суммарное количество существующих записей
   long numberOfRecord = 0;    // текущая запись
   long allRecords = 0; //      количество удаленных и существующих записей
   bool isChangeable = false, isInserted = false;  // для Edit() | для Insert()
   std::string nameOfFile;     // название файла для работы с ним
   std::fstream fs;  // поток для файла
   void GotoInProg(long id); // перейти на запись с идентификатором id (для функций библиотеки)
   bool EofF, BofF;     // флаги для определения начала/конца файла
   bool is_deleted;     // переменная для определения удалён ли файл
   bool Check(int);     // проверка выхода за границу записей
   
   void WriteDelete(std::fstream& fs, bool is_del);     // запись is_deleted
   bool ReadDelete(std::fstream& fs);   // чтение is_deleted
   void WriteTitle(std::fstream& fs);   // запись заголовка базы данных
   void ReadTitle(std::fstream& fs);    // чтение заголовка базы данных

public:
   DataBase(std::string obj, std::string nOfClass) : nameOfFile(obj), nameOfClass(nOfClass) {}  // конструктор
   ~DataBase(){}        // деструктор
   void Open(); // открытие файла
   void Close(); // закрытие файла
   long Id(); // идентификатор записи (смещение в файле)
   void Goto(long id);  // перейти на запись с идентификатором id 
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