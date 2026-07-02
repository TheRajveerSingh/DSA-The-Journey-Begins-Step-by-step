//NOTE: BEFORE RUNNING A BLOCK, COMMENT THE ONES NOT NEEDED.
//................................................................................
//................................................................................
//I. UNDERSTANDING CALL BY VALUE

#include <iostream>
using namespace std;

void change(int x)
{
    x = 100;
    cout<<"x = "<<x<<endl;
}

int main()
{
    int a = 10;

    change(a);

    cout <<"a = "<<a;
}
/*
Result:
x = 100        
a = 10
Inference: As you can see, the value of original 'a' did not change. 
This is because the Call by Value function just copied the value of a.
*/
//................................................................................
//................................................................................
//II.NOW, CALL BY REFERENCE:
//THIS TIME, we will use (int &a)

#include <iostream>
using namespace std;

void change(int &x)
{
    x = 100;
    cout<<"x = "<<x<<endl;
}

int main()
{
    int a = 10;

    change(a);

    cout <<"a = "<<a;
}
/*
Result:
x = 100        
a = 100
Inference: As you can see, the value of original 'a' did not change. 
This is because the Call by Value function just copied the value of a.
*/
//................................................................................
//................................................................................
//Understanding Classes for Functions:
//If you see here, private functions are being called by public functions
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:

    void inputArray(vector<int> &arr)
    {
        for (size_t i = 0; i < arr.size(); i++)
            cin >> arr[i];
    }
    //Here, this function is calling private functions
    void arrangeEvenOdd(const vector<int> &arr, vector<int> &result)
    {
        addEven(arr, result);
        addOdd(arr, result);
    }

    void displayArray(const vector<int> &result)
    {
        for (size_t i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    }

private:

    void addEven(const vector<int> &arr, vector<int> &result)
    {
        for (size_t i = 0; i < arr.size(); i++)
            if (arr[i] % 2 == 0)
                result.push_back(arr[i]);
    }

    void addOdd(const vector<int> &arr, vector<int> &result)
    {
        for (size_t i = 0; i < arr.size(); i++)
            if (arr[i] % 2 != 0)
                result.push_back(arr[i]);
    }
};

int main()
{
    int n;
    cout<<"Enter the number of items in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    vector<int> result;

    Solution obj;
    cout<<"Enter the array: "<<endl;
    obj.inputArray(arr);
    obj.arrangeEvenOdd(arr, result);
    cout<<"The Sorted array, with even numbers first, then odd, is: "<<endl;
    obj.displayArray(result);

    return 0;
}
/*
Result:
Enter the number of items in the array: 7
Enter the array: 
23
21
77
86
45
76
43
The Sorted array, with even numbers first, then odd, is: 
86 76 23 21 77 45 43 
*/
//................................................................................
//................................................................................