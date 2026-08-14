#include<iostream>
using namespace std;

int main(){
    int *a = new int;
    int *b = new int;
    cout<<"Enter two integrals : ";
    cin>>*a>>*b;

    cout<<"Sum = "<<(*a + *b)<<"\n";
    cout<<"Difference = "<<(*a - *b)<<"\n";
    cout<<"Product = "<<(*a * *b)<<"\n";

    if(*b != 0){
        cout<<"Quotient = "<<(double)(*a)/ *b<<"\n";
    }else{
        cout<<"Division by zero is not possible"<<"\n";
    }

    delete a;
    delete b;
    return 0;
}

