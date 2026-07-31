#include<stdio.h>

void calcStats(int arr[],int n){
    int max = arr[0];
    int min = arr[0];
    int sum = 0;

    for(int i = 0;i<n;i++){
        if(arr[i]>max) max = arr[i];
        if(arr[i]<min) min = arr[i];
        sum += arr[i];
    }

    int average = (int)sum/n;
    printf("Largest element : %d\n",max);
    printf("Smallest element : %d\n",min);
    printf("Average : %d\n",average);
}

int main(){
    int n;
    printf("Enter no of elements in array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements : \n",n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    calcStats(arr,n);
    return 0;
}