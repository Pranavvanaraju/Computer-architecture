#include <stdio.h>
void printBinary(int n, int i)
{
 int k;
 for (k = i - 1; k >= 0; k--) {
  if ((n >> k) & 1)
   printf("1");
  else
   printf("0");
 }
}
typedef union {
 float f;
 struct
 {
  unsigned int mantissa : 23;
  unsigned int exponent : 8;
  unsigned int sign : 1;
 } raw;
} myfloat;
void printIEEE(myfloat var)
{
 printf("%d | ", var.raw.sign);
 printBinary(var.raw.exponent, 8);
 printf(" | ");
 printBinary(var.raw.mantissa, 23);
 printf("\n");
}
int main()
{
myfloat var;
var.f = 1259.125;
printf("IEEE 754 representation of %f is : \n",
  var.f);
 printIEEE(var);
 return 0;
}
/*
IEEE 754 representation of 1259.125000 is : 
0 | 10001001 | 00111010110010000000000

SINGLE PRECISION FORMAT
