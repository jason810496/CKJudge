#include <stdio.h>
void fraction_adder(int a_numerator, int a_denominator, int b_numerator,int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr);
int main() {
  int a_numerator, a_denominator, b_numerator, b_denominator;
  scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
  int c_numerator, c_denominator;
  fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator,
           &c_denominator);
  printf("%d/%d\n", c_numerator, c_denominator);
}


void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr) {
  long long upper = a_numerator * b_denominator + b_numerator * a_denominator;
  long long lower = a_denominator * b_denominator;

  long long gcd=0;
  long long mx=(upper>lower ? upper:lower);
  long long mn=(upper>lower ? lower:upper);

  while( mn!=0 ){
    int r = mx%mn;
    mx = mn;
    mn = r;
  }

  gcd = mx;

  *c_numerator_ptr = upper/gcd;
  *c_denominator_ptr = lower/gcd;

  return;
}