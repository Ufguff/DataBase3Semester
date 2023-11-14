



using namespace std;

// после написания основных функций узнать, надо ли каждый раз проверять на открытие потока

void DataBase::Open()
{
   fs.open(nameOfFile + ".db", fstream::out | fstream::binary);
   // создание файла
   
   if ( ! fs.is_open() )//Проверка, если файл не открыт...
      cout << endl <<"Всё плохо!" << endl;
   else//или
      cout << endl << "Всё хорошо!" << endl;
   
   fs.close();
}

void DataBase::Close()
{
   if (fs.is_open())    {cout << "всё гуд";  fs.close();}
}

long DataBase::Id()
{
   return numberOfRecord;   // надо ли рил -1 делать?
}

long DataBase::Count()
{
   return amountOfRecord;
}

void DataBase::Goto(long id)
{
   fs.seekg((id - 1)*Size());       // надо доработать + может на 1 чтобы точно считалось ??
}

void DataBase::First()
{
   fs.seekg(0);
}

void DataBase::Next()
{
   if (fs.Eof()){
      numberOfRecord++;
      fs.seekg((Id() - 1) * Size());
   }
}
// next prev потраить
void DataBase::Prev()
{
   if (_abracadabra_cast(fs);