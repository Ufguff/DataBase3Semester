#include "patient.h"


using namespace std;

void test1()    // ���� ���������� � ����������� �� ����� (�� ���������� �������� ������)
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
   
  // system("pause");
   
   obj1->Insert();
   
   obj1->SetName("Ivan");
   obj1->SetAge(13);
   obj1->SetWeight(100);
   obj1->SetHeight(2000);
   obj1->SetIsIll(true);
   obj1->Post();

   //system("pause");
   
   obj1->Insert();
   obj1->SetName("Sofia");
   obj1->SetAge(15);
   obj1->SetWeight(50);
   obj1->SetHeight(160);
   obj1->SetIsIll(false);
   obj1->Post();
   
  // system("pause");
   
   
   cout << "Count - " << obj1->Count() << endl;
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
   obj1->First();       // �������� 1 ������
   //obj1->Cancel();

   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
  
   obj1->Next();       // �������� 1 ������
   //obj1->Cancel();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
   
   obj1->Last();       // �������� ��������� ������
   //obj1->Cancel();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
   
   obj1->Goto(2);               // ������������ ������������
   //obj1->Cancel();
   
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
   
   obj1->Prev();               // ������������ ������������
   //obj1->Cancel();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
   obj1->Close();
}



void test2()    // ���������� ������
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

void test3()    // ���� �������� ������ � ����������� � ��������� �������
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
   
   // ���������������� �������� ������
 
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


void test4()    // ���� goto � ��������� ��������
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
   
   //system("pause");
   
   obj1->Prev();
   
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   
   obj1->Delete();      // �������� 3 ������
   //obj1->Prev();      �� ������ ���������� ������ ��� Delete ������������� ��������� ������ �� -1 (����� �� ��� ������ ������ Delete ��� ������)
   obj1->Delete();      // �������� 2 ������
   
   obj1->First();
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Next();
   cout << obj1->GetName() << endl;
   cout << obj1->GetAge() << endl;
   cout << obj1->GetWeight() << endl << endl;
   
   obj1->Goto(2);
   //obj1->Next();
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
   
  // system("pause");
   
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
   //system("pause");
   
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
   
   
   return 0;
}