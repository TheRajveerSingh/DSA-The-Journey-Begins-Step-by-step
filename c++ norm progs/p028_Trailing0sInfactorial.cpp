/*
Question: Trailing Zeroes in a Factorial
Basically, a number is given by th user, and its factorial is taken out.
We need to find how many zeroes does that factorial end with.
For example:
5! = 120, so trailing zeroes = 1;
27! = 10,888,869,450,418,352,160,768,000,000, so trailing zeroes = 6;
..........
My first approach was to find the value of the whole factorial, 
and divide it by 10 unless I don't find any other number as the remainder other than 0...
But this method fails completely for larger numbers because of integer overflow...
1. The Problem: Integer OverflowA standard 64-bit integer (like long long in C++) 
can only hold numbers up to about 9 x 10^18.
20! is roughly 2.4 x 10^18 (This is the absolute limit for standard integers).
21! overflows the memory, turning into a corrupted, garbage number.
100! has 158 digits. No standard numeric data type can hold this.
If the problem asks us to find the trailing zeroes for N = 1000 or N = 10^5, 
calculating the actual factorial value is mathematically impossible on a standard machine 
without specialized BigInt libraries, which are highly inefficient for this task.

2. The Logic: Why Continuously Divide by 5 is a better approach?
A trailing zero is created whenever a 2 is multiplied by a 5 (2 x 5 = 10).
To find the number of trailing zeroes in N!, we need to count how many pairs of 2s and 5s exist 
in its prime factorization.
In any sequential list of numbers (like 1 x 2 x 3 x 4 x 5...), multiples of 2 appear far more often 
than multiples of 5.
Because 2s are abundant, every single 5 we find is guaranteed to pair up with an existing 2
to make a 10.
Therefore, the number of trailing zeroes is exactly equal to the number of times 5 appears 
as a prime factor.
Why do we divide continuously?
Take N = 30.
Divide by 5: (30 / 5 = 6). 
This counts numbers that have at least one factor of 5 (5, 10, 15, 20, 25, 30).
Divide by 25 (5^2): (30 / 25  = 1). 
This counts numbers that have an extra factor of 5 (25 is 5 x 5, so it contributes two 5s).
Total zeroes: (6 + 1 = 7).
Instead of dividing by 25, 125, etc., the easiest way to write this in code is to 
continuously divide N itself by 5 in a loop until it hits 0.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int trailingZeroes(int N)
    {
        int count = 0;

        while(N>=5)
        {
            count+= N/5;
            N/=5;
        }

        return count;
    }
};
int main(){
    Solution solver;
    cout<<"Enter a number: "<<endl;
    int N;
    cin>>N;
    cout<<solver.trailingZeroes(N);
}
/*
Result:
Enter a number: 34
7
Enter a number: 5
1
*/