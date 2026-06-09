#include <iostream>
#include <vector>
using namespace std;
int main() {
int i = 1, n;
int j = 1;
cout<<"Enter a Number: ";
cin>>n;
while (i<=10){
    cout<<n<<"*"<<i<<"="<<n*i<<" "<<endl;
    i=i+1;
}
//To print factors of a given number
cout<<"Factors of "<<n<<" are: ";
while (j<=n){
    if (n%j==0){
        cout<<j<<" ";
    } j++;
}
}