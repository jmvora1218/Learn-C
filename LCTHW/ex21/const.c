#include<stdio.h>

int main(){
  char *s_test="test";

  const int x=10;
  int y=90,z=10;
  //x=(y*z)*z;

  //char s_test="xgat";
  printf("this is const int %d and char is: %s\n",x,s_test);

} 
/*

[root@Fedora-35 Basic-C-main]# make const
cc     const.c   -o const
const.c: In function ‘main’:
const.c:8:4: error: assignment of read-only variable ‘x’
    8 |   x=(y*z)*z;
      |    ^
make: *** [<builtin>: const] Error 1
*/