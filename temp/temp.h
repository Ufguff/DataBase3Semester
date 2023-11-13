#ifndef PAT
#define PAT




class Patient : public DataBase
{
   // поля Parent для сохранения
   std::string name;    // имя пациента
   int age;     // возраст пациента
   int weight;	//  вес пациента (измерения проходят в килограммах)
   int height;	// рост пациента (измерения проходят в сантиметрах)
   bool isIll;  // болен ли пациент
   
   // определения виртуальных методов класса DataBase
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