/*
The user sends in two strings. 
We need to check whether they are Anagrams or not.
Anagrams are those strings which have the same letters in them, but at different positions.
For example: act and cat
Or: silent and listen
Stratergy 1:
We might think of taking in both strings, sorting them, and then just comparing them.
If they ae equal, they are anagrams!
But, that would take alot of time, to first sort the strings, and will give 
time complexity of O(NLogN).
Stratergy 2:
So a more optimized approach would be to create an array for all the ascii characters,
That is, 256 indexes (because extended ASCII has 256 characters).
And then initially, to put '0' in all the indexes.
Now, we traverse through the first string given, and add a '1' to each index value 
of the ascii array.
Then, we traverse through the second array given, and substract a '1' from each index value
of the ascii array.
...Then finally we check in the last, 
If both strings had all the letters same, then eventually in the last, still all index
values of the ascii array would be 0. 
If all the index values in the array are not 0 in the last, that means the letters in both
strings were different, and hence they weren't anagrams.
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t){
    
    //To check first whether both strings are of the same length or not
    if (s.length() != t.length()){
        return false;
    }

    // Creating a frequency array for all 256 ASCII characters
    int asciiArray[256] = {0};

    // To increment count for string s, decrement count for string t
    for (int i = 0; i<s.length(); i++){
        asciiArray[s[i]]++;
        asciiArray[t[i]]--;
    }

    // If all indexes in the asciiArray are zero, then they are anagrams
    for (int j=0; j<256; j++){
        if (asciiArray[j]!=0)
        {return false;}
    } return true;
}  

int main(){
    string string1, string2;
    cout<<"Enter first string: ";
    getline(cin, string1);
    cout<<"Enter second string: ";
    getline(cin, string2);

    if (isAnagram(string1, string2)==true) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }
    return 0;
}
/*
Results:
Enter first string: listen                                        
Enter second string: silent
The strings are anagrams.
...
Enter first string: cat listen
Enter second string: silent act
The strings are anagrams.
*/