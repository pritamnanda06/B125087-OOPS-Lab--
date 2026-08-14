#include<iostream>
using namespace std;

int main(){
    int n,search,position = -1;
    cout<<"Enter size :";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter "<<n<<" Elements :";

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter elements to search :";
    cin>>search;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] == search){
            position = i;
            break;
        }
    }

    if(position!= -1){
        cout<<"element is present"<<"\n";
        cout<<"Position = "<<position + 1<<"\n";
    }
        else{
            cout<<"element is not present"<<"\n";
        }
    delete[] arr;
    return 0;
}
    