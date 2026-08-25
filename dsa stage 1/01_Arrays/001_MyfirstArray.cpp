/* Context:
While giving a test (TCS-NQT), I came across a particular c++ function questions (using vector<int> 
and pushback).. 
The question was simple, first it took 2 things: 
1. The length of an array 
2. The array For example: 7 21 34 67 43 8 2 11 
Now, the output should come like: 34 8 2 21 67 43 11 basically all even numbers first, 
then all odd numbers ...
so what my approach was to first create 2 more vectors to push_back in. 
Then to traverse through the arrray, 
and whatever were divisible by 2 to push into the first vector, 
and whatever were not, to push_back in the 2nd vector. 
Then lastly, in the final 3rd vector 'result', 
first pushback the 1st vector which had even numberrs, 
then pushback the vector with odd numbers...
*/
//.............................................................................................
/*
So, the idea is:
1. Read the array.
2. Create two vectors:
    even for even numbers.
    odd for odd numbers.
3. Traverse the original array once.
    If arr[i] % 2 == 0, push_back() into even.
    Otherwise, push_back() into odd.
4. Create a result vector.
5. Copy all elements of even into result.
   Copy all elements of odd into result.
6. Print result.

For our example:
Input:
7
21 34 67 43 8 2 11

After traversal:
even = {34, 8, 2}
odd  = {21, 67, 43, 11}

After combining:
result = {34, 8, 2, 21, 67, 43, 11}

which is exactly the required output.
*/
//..................................................................................................
//..................................................................................................
// I. LET US FIRST TRY WITHOUT FUNCTIONS:
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of items in the array: ";
    cin >> n;

    //vector<int> is fundamentally a dynamic array, meaning it is used to store a collection of integers in a contiguous block of memory just like a traditional array.
    vector<int> arr(n);
    vector<int> even, odd, result;

    cout<<"Enter the array, with either spaces in between, or one by one: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i]; //Here, we can even put the inputs 1 by 1 by pressing 'enter after each input; or just write all inputs together with just spaces in between, both works.
   
    //Now, we traverse through the array, and push the even items in vector even
    for (int i = 0; i < n; i++) { //He, we could also use ""for (int i = 0; i < arr.size(); i++)"", which is better cause god forbid if we perform arr.pop_back(), then the arr.size()!=n. However, for now its fine as both are same. 
        if (arr[i] % 2 == 0)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }

    //Now, pushing first even items in the result, then odd items in it. Finally printing the result.
    for (int i = 0; i < even.size(); i++)
        result.push_back(even[i]);

    for (int i = 0; i < odd.size(); i++)
        result.push_back(odd[i]);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}
/*Result:
Enter the number of items in the array: 7
Enter the array, with either spaces in between, or one by one: 21 34 6 87 22 56 90
34 6 22 56 90 21 87 
*/
/*
NOTE:
If we want to change from (int i = 0; i < n; i++) -> (int i = 0; i < arr.size(); i++)
we should just have in mind that:
arr.size() returns a value of type size_t, which is an unsigned integer, whereas i is an int.
So,
we should use: for ""(size_t i = 0; i < arr.size(); i++)""
or sometimes, in some cases: for (auto i = 0U; i < arr.size(); i++)
-> This avoids signed/unsigned comparison warnings.
*/
//.............................................................................................
/*
To think whether that was the best approach or not:
Is this the best approach?
It works correctly, but it uses three extra vectors, 
so the extra space is O(n) (actually about 3n elements at most, 
though in Big-O notation it's still O(n)).

We can make it slightly better by not creating the result vector at all. 
After filling even and odd, simply print even first and then odd:*/

for (int i = 0; i < even.size(); i++)
    cout << even[i] << " ";
for (int i = 0; i < odd.size(); i++)
    cout << odd[i] << " ";

/*
This produces the same output while using only two extra vectors.
An even more optimized approach is to use just one result vector:
*/
vector<int> result;

for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0)
        result.push_back(arr[i]);
}

for (int i = 0; i < n; i++) {
    if (arr[i] % 2 != 0)
        result.push_back(arr[i]);
}
/*
Here, we traverse the array twice but use only one additional vector. 
The time complexity is still O(n) because 2n operations are still linear, 
and the extra space is reduced to O(n).
*/