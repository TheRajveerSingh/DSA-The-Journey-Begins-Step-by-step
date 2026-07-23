/*This the the same question as done in '001_MyfirstArray.cpp',
The only difference is that now, we will try using functions for the same problem*/
//..........................
/*
Our Plan:
We'll use only:
       arr → stores the original input.
       result → stores the final output (evens first, then odds).

Step 1: To decide the functions
We can have three functions:
    inputArray() → Reads the array.
    arrangeEvenOdd() → Creates the required order.
    displayArray() → Prints the result.
*/
//............................
#include <iostream>
#include <vector>
using namespace std;

// Function to input the array
void inputArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)  //Or, better: for (size_t i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

// Function to arrange even numbers first, then odd numbers
void arrangeEvenOdd(const vector<int> &arr, vector<int> &result)
{
    // First add even numbers
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {
            result.push_back(arr[i]);
        }
    }

    // Then add odd numbers
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 != 0)
        {
            result.push_back(arr[i]);
        }
    }
}

// Function to display the result
void displayArray(const vector<int> &result)
{
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    int n;
    cout<<"Enter the number of items in the array: ";
    cin >> n;

    vector<int> arr(n);
    vector<int> result;
    
    cout<<"Enter the arrray: "<<endl;
    inputArray(arr);

    arrangeEvenOdd(arr, result);

    cout<<"Sorted Array: "<<endl;
    displayArray(result);

    return 0;
}
/*
Result:
Enter the number of items in the array: 7
Enter the arrray: 
21 44 53 78 32 90 77
Sorted Array: 
44 78 32 90 21 53 77 
*/
//..........................................................................................
/* 
If in future, you forget why you used & and const in functions, 
check its meaning in the next file: Understandingfunctions.md.
*/