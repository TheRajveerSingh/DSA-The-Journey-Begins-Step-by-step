/*
Okay, so I want to try out solving 'Armstrong' number problem, with using functions.
So first, I normally took the number from the user in the int main().
Now, this time, I had made 2 functions:
The first one was for main one, for telling the whether the number was armstrong or not.
The second one was for calculating the number of digits in the given number.
(Because to calculate armstrong number, that is required too).
So I contained both of these functions in a class 'Solver', 
and made the 'digit counting' function as private (as this function was needed by the main one).
So yes, a revision of oops concept, where I again showed how private and public are different.
Anyway,
So in the function 'no_of_digits', idk why I went through the pain of converting the whole number
into a string, and then trversing through that string. I could've just used:
int no_of_digits(int num) {
        int count = 0;
        while (num > 0) {
            count++;
            num /= 10;
        }
        return count;
    }
But anyway, using this type helped me learn 2 new concepts in c++:
1. to_string(num) : to convert a given 'num' into a string
2. for (char digit : num1) : is just like in python 'for i in string'. This is will very helpful
3. isdigit(i) : to check whether 'i' in string is a digit or not.
One concept I also revised was how to return answers:
The 'no_of_digits' function returned a number, so that function was type 'int'
Now, a returned thing has to be catched from another variable.
so in the main armstrong function, it was catched by variable 'p'
But since the armstrong function only had to print something, it was in type 'void'
that's why even in the main() function, it is just called, and not catched.
....
One last thing I learnt today was that to end the main() with a 'return 0'; 
it'll just tell our compiler that it has reached the end of code.
.....................
I'll just add the above function for counting digits normally too in the private. 
Though both functions give the same thing: number of digits.
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution{
private:

//Two types of functions are given below. We can use any...
int no_of_digits2(int num) {
        int count = 0;
        while (num > 0) {
            count++;
            num /= 10;
        }
        return count;
    }

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
//alternatively, if we want to try, we can also try: no_of_digits2(num); which is actually what we should be using.
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