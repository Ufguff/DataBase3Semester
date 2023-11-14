

using namespace std;
int main()
{
   setlocale(LC_ALL, "ru");
   Patient *obj1 = new Patient("hospital1");
   obj1->Open();
   
   obj1->Insert();
   
   obj1->SetName("Timofei");
   obj1->SetAge(19);
   obj1->SetWeight(65);
   obj1->SetHeight(190);
   obj1->SetIsIll(true);
   obj1->Post();
   
   system("pause");
   
   obj1->Insert();
   obj1->SetName("Ivan");
   obj1->SetAge(13);
   obj1->SetWeight(100);
   obj1->SetHeight(2000);
   obj1->SetIsIll(false);
   obj1->Post();
   
   system("pause");
   
   obj1->Insert();
   obj1->SetName("Sofia");
   obj1->SetAge(15);
   obj1->SetWeight(50);
   obj1->SetHeight(160);
   obj1->SetIsIll(false);
   obj1->Post();
   
   system("pause");
   
   _abracadabra_cast(*(obj1));