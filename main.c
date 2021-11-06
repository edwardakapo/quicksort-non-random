#include <stdio.h>
#include <math.h>
void swap (int*, int*);
int rearrange(int*, int, int);
int find_median(int, int, int, int);
void quick_sort(int*, int);

int main(void) {

  //int a[7] = {8,7,6,1,0,9,2};
  //int a[] = {8,7,6,1,0,9,2,5,3,4};
   int a[] = {0,1,2,3,4,0,1,2,3,4,5,6,7,8,9,5,6,7,8,9};
 // int *p = a;
  // int index = rearrange(a, 7, 4);
  //  for(int i = 0; i < 7 ; i++)
  //  printf("%d", a[i]);
  quick_sort(a,20);
  for(int i = 0; i < 20 ; i++)
   printf("%d", a[i]);

return 0;
}
void swap (int *a , int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
int rearrange(int* A, int n, int pivot_index){
  int *pivot, *temp;
  int index = 0;
  pivot = A + pivot_index;
  temp = A; 
  swap(pivot, (A + n-1 ));
  pivot =  (A + n-1) ;
  //printf("%d\n",*pivot);
  for(int i = 0; i < n ; i++){
    if(*A < *pivot){
      swap(A,temp);
      index++;
      temp++;
    }
    A++;
  }
  swap((temp) , pivot);
  return index;

}
// int rearrange(int* A, int n, int pivot_index){
//   int *pivot, *temp;
//   int index = 0;
//   pivot = A + pivot_index;
//   int a = 0;
//   int b = n-1;
//   swap(pivot, A);
//   pivot =  A ;
//   for(int i = 0; i < n ; i++)
//    printf("%d", A[i]);

//    printf("\n");
//   for(int i = 0; i < n ; i++){
//     if(A[a] <= *pivot){
//      a++;
//     }
//     if(A[b] > *pivot){
//       b--;
//       index++;
//     }
//     if(a < b){
//       swap(A+a , A+b);
//     }
//   }
//   swap(A+b , pivot);
//   return index; 

// }
int find_median(int a, int b, int c,int n){
  int min = a;
  int med = (a+b+c)/2;
  int index;
  int arr[3] = {a,b,c};
  for(int i = 0 ; i < 3 ; i++){
   if(arr[i] < min){
     min = arr[i];
   }
  }
  for(int i = 0 ; i < 3 ; i++){
    if(arr[i] > min && arr[i] <= med){
      index = arr[i];
    }
  }
  return index;
}

void quick_sort(int* A, int n){
  int *p = A;
  if(n<2){
    return;
  }
  else if(n == 2){
    if(*A > *(A + 1)){
      swap(A, A+1);
    }
  }
  else if( n >=3 ){
   int pivot =  find_median( A[0], A[n/2] , A[n-1],n);
   int pivot_index;
   for(int i = 0 ; i < n ;i++){
     if(pivot == A[i]){
      pivot_index = i;
     }
   }pivot = rearrange(A , n , pivot_index);
   quick_sort(A ,pivot);
   quick_sort(A + pivot+1, n - pivot-1);
  }
}