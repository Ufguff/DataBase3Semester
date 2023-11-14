



using namespace std;

// ����� ��������� �������� ������� ������, ���� �� ������ ��� ��������� �� �������� ������

void DataBase::Open()
{
   fs.open(nameOfFile + ".db", fstream::out | fstream::binary);
   // �������� �����
   
   if ( ! fs.is_open() )//��������, ���� ���� �� ������...
      cout << endl <<"�� �����!" << endl;
   else//���
      cout << endl << "�� ������!" << endl;
   
   fs.close();
}

void DataBase::Close()
{
   if (fs.is_open())    {cout << "�� ���";  fs.close();}
}

long DataBase::Id()
{
   return numberOfRecord;   // ���� �� ��� -1 ������?
}

long DataBase::Count()
{
   return amountOfRecord;
}

void DataBase::Goto(long id)
{
   fs.seekg((id - 1)*Size());       // ���� ���������� + ����� �� 1 ����� ����� ��������� ??
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
// next prev ��������
void DataBase::Prev()
{
   if (_abracadabra_cast(fs);