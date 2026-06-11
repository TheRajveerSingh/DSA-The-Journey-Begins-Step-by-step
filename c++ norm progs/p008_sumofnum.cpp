#include <iostream>
#include <vector>
using namespace std;
int main(){
int num;
cout<<"Enter a number: ";
cin>>num;
int c1 = num;
while (num>9){
    int rem, a=0;
    int c2 = num;
while(c2!=0){
    rem = c2%10;
    a = a + rem;
    c2 = c2/10;
}num = a;
}
cout<<"Sum of digits of the given number is: "<<num<<endl;

//Alternate way
int digitalRoot = (c1 == 0) ? 0 : (c1 % 9 == 0 ? 9 : c1 % 9);
cout<<"Sum by using digitalRoot function: "<<digitalRoot;
return 0;}
