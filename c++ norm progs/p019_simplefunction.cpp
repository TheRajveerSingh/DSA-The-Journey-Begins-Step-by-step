#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int isPrime(int p) {
    vector<int> fc;
    if(p<2){
        cout<<p<<" is not a prime number."<<endl; return 0;}

    for (int j = p-1; j>=2; j--){
         if(p%j==0){
            fc.push_back(j);}}

    if(fc.empty()){cout<<p<<" is a prime number."<<endl; return 1;}
    else{ cout<<p<<" is not a prime number, with its factors being 1, "<<p<<", ";
    for (int i = 0; i<fc.size(); i++){
        cout<<fc[i]<<", ";
        }
        cout << endl;
        return 0;
    }}
};
int main(){
    Solution Solver;
    int a,b,c;
    cout<<"Enter 1st number: ";
    cin>>a;
    int result = Solver.isPrime(a);
    cout<<"Enter 2nd number greater than 1st number: ";
    cin>>b;
    result = Solver.isPrime(b);
    c = b - a;
    result = Solver.isPrime(c);
    cout << result << endl;
    return 0;
};
/* Here I had a doubt, that why I needed to give 'return 0' and 'return 1' here,
cause last time while doing this same pgoram without functions, I didn't need to.
Here is the answer what I got:
This program doesn't need a return 1; 
because all of the prime-checking code is written directly inside int main(), 
rather than inside a custom function.The rule for return statements in C++ depends entirely
 on whether code is inside main() or inside a regular function.
 Here is the exact breakdown:1. main() has a special exception in C++In C++, 
 the main() function is unique. If execution reaches the very end of main() 
 (the closing brace }) without hitting a return statement, 
 the C++ standard guarantees that the compiler will automatically insert return 0; 
 for you.Because your if(fc.empty()) and else blocks are sitting directly inside main(), 
 the program safely finishes, automatically returns 0 to the operating system, 
 and exits cleanly.2. Custom functions do not get this exceptionWhen 
 you wrote your code inside int isPrime(int p), you created a custom member function. 
 The compiler will not automatically insert a return statement for custom functions.
 If a custom function says it returns an int, you must explicitly write a return 
 statement for every possible path. If you do not, the compiler flags it with the 
 "control reaches end of non-void function" warning you saw earlier.
*/