



using namespace std;

// ����� ��������� �������� ������� ������, ���� �� ������ ��� ��������� �� �������� ������

void DataBase::Open()
{
   int size = 0;
   //fsin.open(nameOfFile + ".db");
   fs.open (nameOfFile + ".db", std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::app);       // �������� � �����������
   fs.seekg(0, ios::end);
   size = _abracadabra_cast(fs);