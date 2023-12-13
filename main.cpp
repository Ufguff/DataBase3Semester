#include "patient.h"


using namespace std;

void test1()    // тест добавления и перемещения по файлу (до реализации удалённой записи)
{
   
   Patient *obj1 = new Patient("1");
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
   
   obj1->Insert();
   obj1->SetName("Sofia");
   obj1->SetAge(15);
   obj1->SetWeight(50);
   obj1->SetHeight(160);
   obj1->SetIsIll(false);
   obj1->Post();
   
   cout << "Count - " << obj1->Count() << endl;
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;

   obj1->First();       // проверка 1 записи
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Next();       // проверка 1 записи
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Last();       // проверка последней записи
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;

   obj1->Goto(2);               // произвольное передвижение

   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;

   obj1->Prev();               // произвольное передвижение

   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;

   obj1->Close();
}



void test2()    // перезапись записи
{
   Patient *obj1 = new Patient("2");
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
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
}

void test3()    // тест удалённой записи и перемешения с удаленной записью
{
   Patient *obj1 = new Patient("3");
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
   
   
   obj1->Insert();
   obj1->SetName("Sofia");
   obj1->SetAge(15);
   obj1->SetWeight(50);
   obj1->SetHeight(160);
   obj1->SetIsIll(false);
   obj1->Post();
   
   // перезаписывается удалённая запись
 
   obj1->Goto(2);
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   obj1->Delete();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
 
   obj1->Next();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Next();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Prev();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
}


void test4()    // тест goto с удалёнными записями
{
   Patient *obj1 = new Patient("4");
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
   
   
   obj1->Insert();
   obj1->SetName("Sofia");
   obj1->SetAge(15);
   obj1->SetWeight(50);
   obj1->SetHeight(160);
   obj1->SetIsIll(false);
   obj1->Post();
   
   obj1->Insert();
   obj1->SetName("Mark");
   obj1->SetAge(18);
   obj1->SetWeight(60);
   obj1->SetHeight(180);
   obj1->SetIsIll(true);
   obj1->Post();
   
   obj1->Prev();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Delete();      // удаление 3 записи
   obj1->Delete();      // удаление 2 записи
   
   obj1->First();
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Next();
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Goto(2);
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Close();
}

void test5()
{
   Patient* obj1 = new Patient("5");
   obj1->Open();
   
   obj1->Insert();
   obj1->SetName("Timofei");
   obj1->SetAge(19);
   obj1->SetWeight(65);
   obj1->SetHeight(190);
   obj1->SetIsIll(true);
   obj1->Post();
   
   obj1->Next();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Delete();
   
   obj1->Insert();
   
   obj1->Insert();
   obj1->SetName("Mark");
   obj1->SetAge(18);
   obj1->SetWeight(60);
   obj1->SetHeight(180);
   obj1->SetIsIll(true);
   obj1->Post();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
}


void test6()
{
   Patient * obj1 = new Patient("6");
   obj1->Open();
   
   obj1->Insert();
   
   obj1->SetName("Timofei");
   obj1->SetAge(19);
   obj1->SetWeight(65);
   obj1->SetHeight(190);
   obj1->SetIsIll(true);
   obj1->Post();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   obj1->Insert();
   
   obj1->SetName("Ivan");
   obj1->SetAge(13);
   obj1->SetWeight(100);
   obj1->SetHeight(2000);
   obj1->SetIsIll(true);
   obj1->Post();


   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Insert();
   obj1->SetName("Sofia");
   obj1->SetAge(15);
   obj1->SetWeight(50);
   obj1->SetHeight(160);
   obj1->SetIsIll(false);
   obj1->Post();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->First();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
}


void test7()
{
   Patient * obj1 = new Patient("7");
   obj1->Open();
   
   obj1->Insert();
   
   obj1->SetName("Timofei");
   obj1->SetAge(19);
   obj1->SetWeight(65);
   obj1->SetHeight(190);
   obj1->SetIsIll(true);
   obj1->Post();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Insert();
   
   obj1->SetName("Ivan");
   obj1->SetAge(13);
   obj1->SetWeight(100);
   obj1->SetHeight(2000);
   obj1->SetIsIll(true);
   obj1->Post();


   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Insert();
   obj1->SetName("Sofia");
   obj1->SetAge(15);
   obj1->SetWeight(50);
   obj1->SetHeight(160);
   obj1->SetIsIll(false);
   obj1->Post();
   
   obj1->Insert();
   
   obj1->SetName("Ivan");
   obj1->SetAge(13);
   obj1->SetWeight(100);
   obj1->SetHeight(2000);
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
   
   obj1->SetName("Ivan");
   obj1->SetAge(13);
   obj1->SetWeight(100);
   obj1->SetHeight(2000);
   obj1->SetIsIll(true);
   obj1->Post();
   
   obj1->Delete();
   obj1->Delete();
   obj1->Delete();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Goto(4);
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Close();
}

void test8()
{
   Patient * obj1 = new Patient("8");
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
   
   obj1->Insert();
   obj1->SetName("Sofia");
   obj1->SetAge(15);
   obj1->SetWeight(50);
   obj1->SetHeight(160);
   obj1->SetIsIll(false);
   obj1->Post();
   
   obj1->Insert();
   
   obj1->SetName("Ivan");
   obj1->SetAge(13);
   obj1->SetWeight(100);
   obj1->SetHeight(2000);
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
   
   obj1->SetName("Ivan");
   obj1->SetAge(13);
   obj1->SetWeight(100);
   obj1->SetHeight(2000);
   obj1->SetIsIll(true);
   obj1->Post();
   
   obj1->First();
   cout << "letsgo" << endl;
   while(!obj1->Eof())  
   { 
      cout << obj1->GetName() << endl;
      cout << obj1->GetAge() << endl;
      cout << obj1->GetWeight() << endl << endl;
      obj1->Next();
   }
   cout << "----------" << obj1->Id() << "----------" << endl;
   
   while(!obj1->Bof())  
   { 
      cout << obj1->GetName() << endl;
      cout << obj1->GetAge() << endl;
      cout << obj1->GetWeight() << endl << endl;
      obj1->Prev();
   }
  cout<<obj1->Id() << endl; 
}

int main()
{
   setlocale(LC_ALL, "ru");
   
   test1();
   cout << "--------------------------------------------------------" << endl;
   test2();
   cout << "--------------------------------------------------------" << endl;
   test3();
   cout << "--------------------------------------------------------" << endl;
   test4();
   cout << "--------------------------------------------------------" << endl;
   test5();
   cout << "--------------------------------------------------------" << endl;
   test6();
   cout << "--------------------------------------------------------" << endl;
   test7();
   cout << "--------------------------------------------------------" << endl;
   test8();
   return 0;
}