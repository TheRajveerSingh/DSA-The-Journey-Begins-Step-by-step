//Ways to delete elements from a vector.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> vec = {10, 20, 30, 40, 50};
    cout<<"Original Array: ";
    for (int i : vec){ cout<< i <<" ";}

    // Delete the element at index 2 (the value 30)
    vec.erase(vec.begin() + 2);   // {10, 20, 40, 50}
    cout<<endl<<"After removing 2nd index: "<<endl;
    for (int i : vec){ cout<< i <<" ";}

    // Delete the very last element (50)
    vec.pop_back();               // {10, 20, 40}
    cout<<endl<<"After removing the last index: "<<endl;
    for (int i : vec){ cout<< i <<" ";}

    vector<int> vecc = {1, 2, 3, 3, 4, 3, 5};
    cout<<endl<<"Original Array: ";
    for (int i : vecc){ cout<< i <<" ";}   

    // Remove all instances of the value 3
    erase(vecc, 3);               // {1, 2, 4, 5}
    cout<<endl<<"After removing all '3s' in the array: "<<endl;
    for (int i : vecc){ cout<< i <<" ";}

    // Condition  -  Remove all odd numbers
    erase_if(vecc, [](int x) {
        return x % 2 != 0;
    });
    cout<<endl<<"After removing all Odd numbers in the array: "<<endl;
    for (int i : vecc){ cout<< i <<" ";}


    vector<int> veccc = {1, 2, 3, 3, 4, 3, 5};
    cout<<endl<<"Original Array: ";
    for (int i : veccc){ cout<< i <<" ";}   
    // Erase-Remove Idiom
    veccc.erase(
        remove(veccc.begin(), veccc.end(), 3),
        veccc.end()
    );                            // {1, 2, 4, 5}
    cout<<endl<<"After removing all '3s' in the array: "<<endl;
    for (int i : veccc){ cout<< i <<" ";}
}
/*
Result:
Original Array: 10 20 30 40 50 
After removing 2nd index: 
10 20 40 50 
After removing the last index: 
10 20 40 
Original Array: 1 2 3 3 4 3 5 
After removing all '3s' in the array: 
1 2 4 5 
After removing all Odd numbers in the array: 
2 4 
Original Array: 1 2 3 3 4 3 5 
After removing all '3s' in the array: 
1 2 4 5 
*/