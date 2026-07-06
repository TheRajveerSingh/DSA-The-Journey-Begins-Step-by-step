#include <iostream>
using namespace std;

class Solution{
public:
void swap1(int &a, int &b){
    int c;
    c = a;
    a = b;
    b = c;
}
void swap1(float &a, float &b){
    float c;
    c = a;
    a = b;
    b = c;
}
};
int main(){
    Solution solver;
    int a,b;
    cout<<"Enter a number 'a' : ";
    cin>>a;
    cout<<"Enter a number 'b' : ";
    cin>>b;
    cout<<"Initially, a = "<<a<<", b = "<<b<<endl;
    solver.swap1(a,b);
    cout<<"Now, a = "<<a<<", b = "<<b<<endl;
    float c,d;
    cout<<"Enter a float number 'c' : ";
    cin>>c;
    cout<<"Enter a float number 'd' : ";
    cin>>d;
    cout<<"Initially, c = "<<c<<", d = "<<d<<endl;
    solver.swap1(c,d);
    cout<<"Now, c = "<<c<<", d = "<<d<<endl;
}
/*Initially something funny happened..
So basically I forgot putting the: solution solver; and solver.swap() in the main() function
and it worked. But later on, I realised I forgot putting them, so the question was, how did it still work?
Answer was since I used: #include <vector>, it just used the 'swap' function already in c++.
So now, I'll just change the program, will remove <vector>, rename function as swap1, 
and create the class object. Let's see how it goes.*/
/*
Result:
Enter a number 'a' : 32
Enter a number 'b' : 67
Initially, a = 32, b = 67
Now, a = 67, b = 32
Enter a float number 'c' : 98.55
Enter a float number 'd' : 34.77
Initially, c = 98.55, d = 34.77
Now, c = 34.77, d = 98.55
*/
//.............................................................................
/*
SOMETHING TO LEARN:
Okay, here's what I found:
So, we know how we always create that class object (solver), right?
Thing is,
Right now, our swap1 functions do not use or modify any data members inside the Solution class.
They only look at the arguments passed directly into them.
Because of this, we could make them static. 
This allows us to call them without creating the Solution solver; object line in your main function at all.
This is how it would look like:
*/
class Solution {
public:
    // Adding 'static' means this function belongs to the class, not an object
    static void swap1(int &a, int &b) {
        int c = a; a = b; b = c;
    }
    static void swap1(float &a, float &b) {
        float c = a; a = b; b = c;
    }
};

int main() {
    int a = 5, b = 10;
    // We can call it directly using the class name and :: scope resolution operator
    Solution::swap1(a, b); 
}
/*
But the question is: why?
Why go for extra work of adding 'static void' and Solution::swap1(a,b);
when literally just writing solver.swpa1(a,b) takes lesser time?
.....
The reason developers use static with Solution:: isn't to save typing time in main. 
It is to save computer memory and write cleaner code architecture.
1. It Saves Memory (No Object Allocation):
When we write Solution solver;, we are telling the computer to allocate space in memory for 
an object.
If our class gets larger later with many variables, creating that object just to use 
one simple utility function wastes system memory.
The 'static' functions do not require us to create an object, 
keeping our computer's memory footprint clean.
2. Logical Accuracy:
A standard member function implies that the action depends on a specific object's state 
(like car.accelerate() depends on that specific car's fuel).
Our swapping function is a pure utility. It only cares about the two numbers we pass into it.
Making it static tells anyone reading our code: "This function is a self-contained tool. 
It does not change or rely on any hidden class data."
*/