#include<stdio.h>

void linSearch(int arr[],int n,int target){
    int foundIndex = -1;
    for(int i = 0;i<n;i++){
        if(arr[i] == target){
            foundIndex = i;
            break;
        }
    }

    if(foundIndex != -1){
        printf("Element %d found at : %d\n",target,foundIndex +1);
    }else{
        printf("Element not found");
    }
}

int main(){
    int n;
    int arr[n];
    int key;
    printf("Enter no of elements :");
    scanf("%d",&n);
    printf("Enter %d integers :\n",n);
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Element to search : ");
    scanf("%d",&key);
    linSearch(arr,n,key);
    return 0;
}