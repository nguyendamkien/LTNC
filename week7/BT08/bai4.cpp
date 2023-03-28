#include <iostream>

using namespace std;

int main()  {
   char *s;
   char foo[] = "Hello World";
   s = foo;
   printf("s is %s\n",s);
   //*(s) = foo[0];
   printf("s[0] is %s\n", foo[1]);
   return(0);
}

