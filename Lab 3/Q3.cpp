#include<iostream>
using namespace std;

int main(){
    int n,even = 0,odd = 0;
    cout<<"Enter size :";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter "<<n<<" Elements :";

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if(arr[i]%2 == 0){
            even++;
        }else{
            odd++;
        }
    }   
    cout<<"No of even elements :"<<even<<"\n";
    cout<<"No of odd elements :"<<odd<<"\n";
    delete[] arr;
    return 0;
}