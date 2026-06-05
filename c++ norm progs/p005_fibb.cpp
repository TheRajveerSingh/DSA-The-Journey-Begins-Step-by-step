#include<iostream>
#include<vector>
using namespace std;
int main() {
int limit;
cout<<"Enter the maximum limit for Fibonacci series: ";
cin>>limit;
int a = 0;
int b = 1;
while (a<=limit){
    cout<<a<<" ";
    int nxtterm = a + b;
    a = b;
    b = nxtterm;
}
cout<<endl;
a = 0;
b = 1;
int tillstep;
cout<<"Enter the step till which you need to print the series: ";
cin>>tillstep;
for (int i=1; i<=tillstep; i++){
    cout << a << " ";      
    int nextTerm = a + b;  
    a = b;                 
    b = nextTerm;
}
}
//learnt use of while loop