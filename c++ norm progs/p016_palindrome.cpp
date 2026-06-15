#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return 0;}
        int c = x; //we have copied value of x to compare later
        long long ans = 0, rem ;
        while(x!=0){
            rem = x%10;
            x/=10;
            ans = (ans*10)+rem;}
        if (ans == c){ return 1;}
        else {return 0;}
         }
};
int main(){
    Solution Solver;
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    bool result = Solver.isPalindrome(num);
    cout << result << endl;
    return 0;
}
//another appropriate approach can be to only go till half of the number and check:
/*The half-reversal method is highly optimized for memory efficiency
 because it keeps all operations strictly within standard 32-bit limits.*/
//Here is that code:
/*
if (x < 0 || (x % 10 == 0 && x != 0)) {return 0; }

int reversedHalf = 0;
// Loop runs only until the middle of the number
while (x > reversedHalf) {
reversedHalf = (reversedHalf * 10) + (x % 10);
    x /= 10;}

// Check for even length (x == reversedHalf) 
// OR odd length (x == reversedHalf / 10)
if (x == reversedHalf || x == reversedHalf / 10) { return 1;}
 else { return 0;}

*/