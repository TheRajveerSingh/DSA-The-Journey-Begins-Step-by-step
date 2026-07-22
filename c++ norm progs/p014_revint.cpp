#include <iostream>
#include <vector>
#include <climits> //Required for int_max and int_min
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int ans = 0, rem ;
        while(x!=0){
            rem = x%10;
            x/=10;
            if(ans>INT_MAX/10 || ans<INT_MIN/10) //Checks if the next multiplication will exceed the upper limit/will drop below the lower limit.

            {return 0;}
            ans = (ans*10)+rem;}
        
        return ans; }
    };
int main() {
    Solution solver; //solver is an object/instance of Solution function to use it
    int inputNumber;

    cout << "Enter any number, -ve/+ve: ";
    cin >> inputNumber;

    int result = solver.reverse(inputNumber);
    cout << "Reversed number: " << result << endl;

    return 0;
}
//So basically an object gives access to use a class, and the functions inside it
//But, only 'public' functions can be accessed by the object, not private ones.