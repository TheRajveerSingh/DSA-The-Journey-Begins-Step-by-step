#include <iostream>
#include <vector>
using namespace std;
int main(){
int i;
cout<<"Enter a number: ";
cin>> i;
int b=i;
int a;
if (b==0){
    cout<<"Factorial of "<<i<<" = 1";
}
else{
for (a = b-1; a>=1; a=a-1){b=b*a;} 
cout<<"Factorial of "<<i<<" = "<<b;}
}