


using namespace std;

void Patient::ReadData(fstream &f)
{
   
   
   
}

void Patient::WriteData(fstream &f)
{
   size_t size = name.size();
   f.write((char*)&size, sizeof(size));
   f.write((char*)&_abracadabra_cast(name);