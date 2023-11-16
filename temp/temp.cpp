



using namespace std;

// после написания основных функций узнать, надо ли каждый раз проверять на открытие потока

void DataBase::Open()
{
   int size = 0;
   //fsin.open(nameOfFile + ".db");
   fs.open (nameOfFile + ".db", std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::app);       // пошамань с параметрами
   fs.seekg(0, ios::end);
   size = _abracadabra_cast(fs);