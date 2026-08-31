/*
Question:
An array of numbers are given. 
Our job is to return an array with all the unique numbers in it.
Basically to remove all duplicate values in the given list.
...
Stratergy:
We take an array of elements from the user.
And then we'll pass it to a function (A function which can return a vector).
Now, the function will traverse through our given array.
And will have 2 things:
1. An new array to store the unique values.
2. A hash map(unordered list) which can also store the unique values coming along, 
   but this is used to check whether a value is already been stored in the new array or not.
   Cause if its already stored, then it'll not be added.
(We are checking unique values by the hashmap due to its .find() feature. And this gives
speed, something which would take alot of time if we tried checking with a vector or array.)
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
    public:
    vector<int> removeDuplicates(const vector<int>&inputlist){ //The function that takes in the input list of numbers.
        vector<int> result; //The new vector to store the unique numbers.
        unordered_set<int> seen;

        for(int num : inputlist){  //For each num in the array inputlist
            if (seen.find(num) == seen.end()){  //If through the whole 'seen' hashmap, we reached to the end ( == seen.end()) without finding the num in between
                seen.insert(num);  //Then we insert this number into our hashmap, as its new
                result.push_back(num); //And then we also insert it into our new array
            }
        } return result; //To return the 'result' array with the unique numbers
    } 
};

int main(){
    
    //To ask for the size of the array and create it.
    int size;
    cout<<"Enter size of the array: ";
    cin>> size;
    vector<int> inputlist;
    inputlist.reserve(size);
    //To ask for the elements to put into the array
    int element;
    for (size_t i = 0; i<size; i++){
        cout<<"Enter "<<i<<" element: ";
        cin>> element;
        inputlist.push_back(element);
    }

    Solution solver;
    //Now we create another array named 'printans'.
    //Now, just calling the function removeDuplicates() and sending it with the inputlist array won't do. 
    //Because in c++, if a vector is returned by a function (here 'result'), 
    //to print its elements, you'll again have to store it into another vector, 
    //and then traverse through this vector.
    vector<int> printans = solver.removeDuplicates(inputlist);

    cout<<"The original array: ";
    for (int j : inputlist){
        cout<<j<<" ";
    } cout<<endl;

    cout<<"The array without duplicates: ";
    for (int num : printans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
/*
Result:
Enter size of the array: 17         
Enter 0 element: 1
Enter 1 element: 3
Enter 2 element: 56
Enter 3 element: 43
Enter 4 element: 56
Enter 5 element: 8
Enter 6 element: 9
Enter 7 element: 3
Enter 8 element: 2
Enter 9 element: 67
Enter 10 element: 43
Enter 11 element: 67
Enter 12 element: 3
Enter 13 element: 23
Enter 14 element: 23
Enter 15 element: 2
Enter 16 element: 9
The original array: 1 3 56 43 56 8 9 3 2 67 43 67 3 23 23 2 9 
The array without duplicates: 1 3 56 43 8 9 2 67 23 
*/
/*
LEARNING:
Okay, there's a difference between unordered_set and unordered_map:
1. #include <unordered_set>
-> defined by: unordered_set<int> name;
-> The unordered_set only stores unique elements (just keys)
-> Its mainly used for checking the existence or uniqueness.
-> It cannot modify elements directly.
-> Common use case is tracking visited IDs, removing Duplicates.
2. #include <unordered_map>
-> defined by: unordered_map<keytype, valuetype> name; 
   ex: unordered_map<int, string> name;
-> The unordered_map stores key-value pairs
-> its maily used for mapping a unique identifier to data.
-> It can read/modify values using the [] operator.
-> Common use case is counting frequencies, dictionaries, caches.
Both use a hash table under the hood, meaning they both offer lightning-fast O(1) 
average time complexity for insertions, lookups, and deletions.
...........................................................................
*/
/*
# While iterating through the Map:
When we loop through an unordered_map, each item is treated as a std::pair.
We can access them using .first and .second.
Ex: unordered_map<int, int> name;
where,
pair.first refers to the key (the first int)
pair.second refers to the Value (the second int)
Iteration Code:
for (const auto& pair : myMap){
    std::cout<< "Key: " << pair.first << "Value: " <<pair.second <<"\n";}
*/
/*
Next Learn: What is Auto? (Automatic type detuction)
*/