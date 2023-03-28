#include <iostream>

using namespace std;

/*int main( )
{
   char a[4] = "abc";
   for (char *cp = a; (*cp) != '\0'; cp++) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
}*/

/*int main( )
{
   int a[4] = {1, 2, 3};
   for (int *cp = a; (*cp) != 0; cp++) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
}*/

int main( )
{
   double a[4] = {1.2, 2.4, 5.7};
   for (double *cp = a; (*cp) != 0; cp+=2) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
}



