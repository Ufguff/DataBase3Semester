


using namespace std;

int Patient::Size()
{
   return sizeof(int) * 3 + sizeof(bool) + sizeof(char)*100; // максимальная длина stirng - 100
}

void Patient::ReadData(fstream &f)
{
   size_t len = 100;
   char buf[len + 1];         // Выделение буфера для чтения
   f.read(buf, len);                   // Чтение (с нулевым байтом)
   buf[len] = 0;
   name = buf;                         // Присвоение считанной строки члену
   
   f.read((char*)&age, sizeof(int));
   f.read((char*)&weight, sizeof(int));
   f.read((char*)&height, sizeof(int));
   f.read((char*)&isIll, sizeof(bool));
   _abracadabra_cast(f);