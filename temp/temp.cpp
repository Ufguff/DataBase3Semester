


using namespace std;

int Patient::Size()
{
   return sizeof(int) * 3 + sizeof(bool) + sizeof(char)*100; // ������������ ����� stirng - 100
}

void Patient::ReadData(fstream &f)
{
   size_t len = 100;
   char buf[len + 1];         // ��������� ������ ��� ������
   f.read(buf, len);                   // ������ (� ������� ������)
   buf[len] = 0;
   name = buf;                         // ���������� ��������� ������ �����
   
   f.read((char*)&age, sizeof(int));
   f.read((char*)&weight, sizeof(int));
   f.read((char*)&height, sizeof(int));
   f.read((char*)&isIll, sizeof(bool));
   _abracadabra_cast(f);