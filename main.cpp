#include "patient.h"

int main()
{
   setlocale(LC_ALL, "ru");
   Patient *obj1 = new Patient("hospital1");
   obj1->Open();
   obj1->Close();
   return 0;
}
