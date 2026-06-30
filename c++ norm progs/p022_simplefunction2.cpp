#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
bool isEven(int p){
    if (p%2==0) {return true;}
    else {return false;}
}
};
int main(){
    Solution solver;
    int i;
    cout<<"Enter a number: "<<endl;
    cin>>i;
    cout<<solver.isEven(i);
}
//Now let's see if we put cout in the function:
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
void isEven(int p){
    if (p%2==0) {cout<<p<<" is even";}
    else {cout<<p<<" is odd";}
}
};
int main(){
    Solution solver;
    int i;
    cout<<"Enter a number: "<<endl;
    cin>>i;
    solver.isEven(i);
}
//As you can see here, now, since the cout is already being used
//in the function, no need to use it in the main().
//Also, when printing something in the function, better to use 'void'.
//.................
//Just for knowledge, here is the code for using 'String' as the function type, as that is what
//I used before:
#include <iostream>
#include <vector>
#include <string> // Required header
using namespace std;

class Solution {
public:
    // Returns a string instead of printing it directly
    string isEven(int p) {
        if (p % 2 == 0) {
            return to_string(p) + " is even";
        }
        else {
            return to_string(p) + " is odd";
        }
    }
};

int main() {
    Solution solver;
    int i;
    cout << "Enter a number: " << endl;
    cin >> i;
    // Print the string returned by the function
    cout << solver.isEven(i) << endl;
    return 0;
}
/*
to_string(p) is a built-in C++ function that converts
a numerical value (like an int, float, or double) into its equivalent text string.
It is part of the standard library and requires the <string> header.
*/