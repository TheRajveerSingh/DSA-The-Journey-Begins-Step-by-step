#include <iostream>
#include <vector>
using namespace std;

int main(){
int i = 1;
do {
    cout<<i<<" ";
    i++;
}while(i<=10); //break condition 
cout<<endl;
int j, k= 1;
cout<<"Enter a number: ";
cin>>j;
do{
   cout<<k*j<<endl;  //First program is done, then condition is seen
   k++;
}while(k<=10);
}