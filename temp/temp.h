#ifndef PAT
#define PAT




class Patient : public DataBase
{
   // ���� Parent ��� ����������
   std::string name;    // ��� ��������
   int age;     // ������� ��������
   int weight;	//  ��� �������� (��������� �������� � �����������)
   int height;	// ���� �������� (��������� �������� � �����������)
   bool isIll;  // ����� �� �������
   
   // ����������� ����������� ������� ������ DataBase
   void ReadData(std::fstream& f){}
   void WriteData(std::fstream& f){}
   int Size(){}
   void Recalc(){}
   
public:
   //Patient(std::string filename, std::string name, int age, int weight, int height, bool isIll) : DataBase(filename), name(name), age(age), weight(weight), height(height), isIll(isIll) {}
   Patient(std::string filename) : DataBase(filename) {}
   
   void SetName(std::string t); 
   std::string GetName();
   
   void SetAge(int t); 
   int GetAge() {return _abracadabra_cast(this);