

using namespace std;

void test1()
{
   
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
   obj1->SetIsIll(true);
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
   
   
   cout << "Count - " << obj1->Count() << endl;
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
   obj1->First();       // проверка 1 записи
   obj1->Cancel();

   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
  
   obj1->Next();       // проверка 1 записи
   obj1->Cancel();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
   
   obj1->Last();       // проверка последней записи
   obj1->Cancel();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
   
   obj1->Goto(2);               // произвольное передвижение
   obj1->Cancel();
   
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
   
   obj1->Prev();               // произвольное передвижение
   obj1->Cancel();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
   obj1->Close();
}



void test2()
{
   Patient *obj1 = new Patient("changeN");
   obj1->Open();
   
   obj1->Insert();
   
   obj1->SetName("Timofei");
   obj1->SetAge(19);
   obj1->SetWeight(65);
   obj1->SetHeight(190);
   obj1->SetIsIll(true);
   obj1->Post();
   
   obj1->Insert();
   
   obj1->SetName("Ivan");
   obj1->SetAge(13);
   obj1->SetWeight(100);
   obj1->SetHeight(2000);
   obj1->SetIsIll(true);
   obj1->Post();


   obj1->First();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->SetName("Sofia");
   obj1->SetAge(15);
   obj1->SetWeight(50);
   obj1->SetHeight(160);
   obj1->SetIsIll(false);
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Post();
   obj1->Cancel();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
}

void test3()
{
   Patient *obj1 = new Patient("delProb");
   obj1->Open();
   /*
   obj1->Insert();
   
   obj1->SetName("Timofei");
   obj1->SetAge(19);
   obj1->SetWeight(65);
   obj1->SetHeight(190);
   obj1->SetIsIll(true);
   obj1->Post();
   
   obj1->Insert();
   
   obj1->SetName("Ivan");
   obj1->SetAge(13);
   obj1->SetWeight(100);
   obj1->SetHeight(2000);
   obj1->SetIsIll(true);
   obj1->Post();
   
   
   obj1->Insert();
   obj1->SetName("Sofia");
   obj1->SetAge(15);
   obj1->SetWeight(50);
   obj1->SetHeight(160);
   obj1->SetIsIll(false);
   obj1->Post();
   */
   
 
   obj1->Goto(2);
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   obj1->Delete();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
 
   _abracadabra_cast(*(obj1));