/*
I came through this problem while giving the TCS-NQT Exam, known as the
"Ranking Element" or "Coordinate Compression" problem.
Basically, an array of integers will be given, and then we would need print their 'status' or 'level' in that array.
For example:
Input: 23 6 12 6 4
Output: 4 2 3 2 1
Input: -10 -8 16 16 18 -6 -18 4 16 -2
Output: 2 3 7 7 8 4 1 6 7 5
*/
//.............................................................................
/*
This is the stratergy which I had in my mind:
(Since I'm just starting arrays, I don't know much, but I guess this is logical)
1. The size of array is given by the user
2. The array of numbers is given by the user
3. A new array with all unique numbers is created (by going through the original array, and skipping those numbers already there)
4. Sorting this new array
5. Comparing each item of the original array, and finding that same number in this new array, and printing its index [i +1}..
...
So it would look something like:
1. size = 5
2. 23, 6, 12, 6, 4
3. 23, 6, 12, 4
4. 4, 6, 12, 23
5. Comparing with original array: 23 -> [i+1] -> [3+1] -> 4 | then 6 -> 2 | 12 -> 3 | 6 -> 2 | 4-> 1.
*/
#include <iostream>
#include <algorithm> // For sort()

using namespace std;

int main() {
    // 1. Get the size
    int size;
    cout << "Enter size: ";
    cin >> size;

    // 2. Get the original array
    int original[size];
    cout << "Enter numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> original[i];
    }

    // 3. Create a new array with all UNIQUE numbers
    int uniqueArr[size]; // Can hold up to 'size' elements maximum
    int uniqueSize = 0;  // Keeps track of how many unique numbers we actually find

    for (int i = 0; i < size; i++) {
        bool alreadyExists = false;
        
        // Look through our uniqueArr to see if we've already added this number
        for (int j = 0; j < uniqueSize; j++) {
            if (uniqueArr[j] == original[i]) {
                alreadyExists = true;
                break; // Found a duplicate, stop looking
            }
        }
        
        // If it's a brand new number, add it to uniqueArr
        if (!alreadyExists) {
            uniqueArr[uniqueSize] = original[i];
            uniqueSize++; // Grow the unique array size tracker
        }
    }

    // 4. Sort this new unique array
    sort(uniqueArr, uniqueArr + uniqueSize);

    // 5. Compare original array with unique array and print (index + 1)
    cout << "Output: ";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < uniqueSize; j++) {
            if (original[i] == uniqueArr[j]) {
                cout << (j + 1) << " "; // j is the index, so we print j + 1
                break; 
            }
        }
    }
    cout << endl;

    return 0;
}