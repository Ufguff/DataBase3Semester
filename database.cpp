#include <fstream>
#include <iostream>
#include "database.h"

using namespace std;


void DataBase::Open()
{
   string prog = nameOfFile + ".db";
   fs.open(prog, fstream::out | fstream::binary);

   if ( ! fs.is_open() )//Проверка, если файл не открыт...
        cout << endl <<"Всё плохо!" << endl;
    else//или
        cout << endl << "Всё хорошо!" << endl;
   int age = 19;
    
    fs.write((char*)&age, sizeof(age));
}

void DataBase::Close()
{
   int age2 = 0;
   cout << age2 << endl;
   fs.open(nameOfFile + ".db", fstream::in | fstream::binary);
   fs.read((char*)&age2, sizeof(age2));
   cout << age2 << endl;
   if (fs.is_open())    fs.close();
}