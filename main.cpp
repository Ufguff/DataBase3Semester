#include "patient.h"

using namespace std;
int main()
{
   setlocale(LC_ALL, "ru");
   Patient *obj1 = new Patient("hospital1");
   
   obj1->SetName("Timofei");
   obj1->SetAge(19);
   obj1->SetWeight(65);
   obj1->SetHeight(190);
   obj1->SetIsIll(true);
   
   obj1->Open();
   
   obj1->SetName("Ivan");
   obj1->SetAge(13);
   obj1->SetWeight(100);
   obj1->SetHeight(2000);
   obj1->SetIsIll(false);
   
   obj1->Close();
   
   cout << obj1->GetName();
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl;
   return 0;
}
