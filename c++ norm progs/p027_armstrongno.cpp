#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution{
private:
int no_of_digits(int num){
    string num1 = to_string(num); //To use to convert an int to a string
    int j = 0;
    for (char digit : num1) { // This is similar to 'for i in num' in python, and is called a range-based for loop in C++. It automatically grabs each character from the string one by one. 
        if (isdigit(digit)) {j = j+1;}
    }
    return j;
}
public:
void armstrong(int num){
int p = no_of_digits(num);
int copy = num;
int sum = 0; 
while (num!=0){    
    int q = num/10; 
    int rem = num%10; 
    int j = pow(rem, p); 
    sum = sum + j; 
    num = q; 
}
if (copy==sum){cout<<copy<<" is an armstrong number. ";}
else {cout<<copy<<" is not an armstrong number. ";}
}
};

int main(){
    Solution solver;
    cout<<"Enter a number: ";
    int num;
    cin>>num;
    solver.armstrong(num);
    return 0;
}
/*
Result:
Enter a number: 153
153 is an armstrong number.                       
Enter a number: 1634
1634 is an armstrong number. 
Enter a number: 678
678 is not an armstrong number. 
*/