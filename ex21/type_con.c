#include<stdio.h>

void main(){
  
  float a =10.2934;
  int b;
  
  long long int k= 99999999999999999999; //https://www.geeksforgeeks.org/data-types-in-c/
  
  int s;
  s= k;

  b = a ;
  printf("Float size: %d \n",sizeof(float));
  printf("logn long int  size: %d \n",sizeof(long long));

  printf("this is const int %f \n",a);
  printf("this is const int %d \n",b);

  printf("long long int %d \n",s);

} 
//https://www.geeksforgeeks.org/data-types-in-c/