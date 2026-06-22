#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) {

        if(n==0)
            return 1;
        int ans = 0, mul=1, rem;
        while(n)
        {
            rem = n%2;
            rem = rem^1;
            n/=2;
            ans = ans+rem*mul;
            mul*=2;
        }

        return ans;
    }
};
int main(){
    Solution Solver;
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int result = Solver.bitwiseComplement(n);
    cout << result << endl;
    return 0;
}
/* This program finds the bitwise complement of an integer.
It takes a number, converts it to its binary representation, 
flips all the 0s to 1s and 1s to 0s, 
and then outputs the new intege*/