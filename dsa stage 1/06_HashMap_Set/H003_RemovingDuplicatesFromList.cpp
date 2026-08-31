//Trying the previous program after many days from whatever logic I remember
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
    public:
    vector<int> newarray (const vector<int>& arr, int size){
        vector<int> narr;
        unordered_set<int> check;
        for (int i=0; i<size; i++){
            if (check.find(arr[i])==check.end()){
                narr.push_back(arr[i]);
                check.insert(arr[i]); }};
        return narr;
    }
};
int main(){
    Solution solver;
    int size, element;
    vector<int> arr;
    cout<<"Enter the size of the array: ";
    cin>>size;
    cout<<"Enter the elements of the array: ";
    for (int k=0; k<size; k++){
        cin>>element;
        arr.push_back(element);};
    vector<int> narr = solver.newarray(arr, size);
    cout<<"The new array is: ";
    for (int m: narr) {cout<<m<< " ";}
}
/*
Result:
Enter the size of the array: 12
Enter the elements of the array: 4 5 7 2 78 43 4 67 78 67 4 3
The new array is: 4 5 7 2 78 43 67 3
*/