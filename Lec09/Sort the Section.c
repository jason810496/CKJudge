#include <stdio.h>
#define ARR_MAX 1000
void sort_section(int *ptr, int *qtr);
int main() {
  int N, a, b;
  scanf("%d%d%d", &N, &a, &b);
  int arr[ARR_MAX] = {0};
  for (int i = 0; i < N; i++) {
    scanf("%d", arr + i);
  }
  sort_section(&arr[a], &arr[b]);
  for (int i = 0; i < N; i++) {
    printf("%d ", *(arr + i));
  }
}


void sort_section(int *ptr, int *qtr) {
    if( ptr > qtr ){
      int *t = ptr;
      ptr = qtr;
      qtr = t;
    }
    
    for(int *i = ptr ; i<qtr ; i++ ){
      for(int *j = ptr;j<qtr;j++){
        if( *j > *(j+1) ){
          int tmp = *j;
          *j = *(j+1);
          *(j+1) = tmp;
        }
      }

      for(int *k = ptr ;k<=qtr;k++){
        printf("%d " , *k );
      }
      printf("\n");
    }
    
}

