#include<stdio.h>

int calcSum(int *ptr,int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum +=*(ptr+i);
    }
    return sum;
}

int main(){
    int n;
    printf("Enter no of elements :");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d integers : \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",(arr + i));
    }

    int sum = calcSum(arr,n);
    printf("Sum of elements = %d\n",sum);
    return 0;
}