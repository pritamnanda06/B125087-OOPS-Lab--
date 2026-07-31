#include<stdio.h>

void swap(int *a,int *b){
   int temp = *a;
   *a = *b;
   *b = temp; 
}

int main(){
    int x,y;
    printf("Enter two integers :\n");
    scanf("%d %d",&x,&y);

    printf("before swapping : x=%d and y=%d",x,y);
    swap(&x,&y);
    printf("after swapping : x=%d and y=%d",x,y);
}