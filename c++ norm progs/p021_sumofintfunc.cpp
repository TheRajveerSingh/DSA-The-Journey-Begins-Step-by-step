#include <iostream>
using namespace std;
class Solution{
public:
int CalcSum(int a, int b){
int ans = a + b;
return ans;
}
};
int main(){
    Solution Solver;
    int m,n;
    cout<<"Enter first number: "<<endl;
    cin>>m;
    cout<<"Enter second number: "<<endl;
    cin>>n;
    cout<<Solver.CalcSum(m,n); //Either put cout here, or in the functions place.
    return 0; //This thing is optional these days, but better to put it. As it is, it doesn't make any difference here, and the program will still work.
}
/*
 * WHY WE USE 'return 0;' IN THE MAIN FUNCTION:
 * 
 * 1. THE EXIT CODE CONCEPT:
 *    Every program sends a final status code back to the Operating System (OS)
 *    when it finishes running. This is called an "Exit Code" or "Return Code".
 * 
 * 2. THE SIGNAL MEANING:
 *    - 0 = SUCCESS: Tells the OS that the program ran perfectly without errors.
 *    - Non-Zero (e.g., 1, 2, -1) = FAILURE: Tells the OS something went wrong.
 * 
 * 3. PRACTICAL USAGE:
 *    Automated scripts, terminal command lines, and IDEs look at this number 
 *    to determine if it is safe to proceed to the next automated task.
 * 
 * 4. WHY IT IS CHOSEN BY DEFAULT:
 *    Modern C++ standards (C++99 onwards) automatically inject 'return 0;' 
 *    if omitted from main(). Explicitly writing it is considered a best 
 *    practice for clarity, cross-compiler safety, and readability.
 */
