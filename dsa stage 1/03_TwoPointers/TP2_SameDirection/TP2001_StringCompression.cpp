/*
This question is from LeetCode 443. String Compression
Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of consecutive repeating characters in chars:
If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. 
Note that group lengths that are 10 or longer will be split into multiple characters in chars.
After you are done modifying the input array, return the new length of the array.
You must write an algorithm that uses only constant extra space.
Note: The characters in the array beyond the returned length do not matter and should be ignored.

Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: 6
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
After modifying the input array in-place, the first 6 characters of chars should be ["a","2","b","2","c","3"].
Example 2:
Input: chars = ["a"]
Output: 1
Explanation: The only group is "a", which remains uncompressed since it is a single character.
After modifying the input array in-place, the first character of chars should be ["a"].
Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: 4
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
After modifying the input array in-place, the first 4 characters of chars should be ["a","b","1","2"].
*/
//....................................................................................................................
/*This was the algorithm I thought of first:
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int compress (vector<char>& char1){
        int output = 0;
        int pointer1 = 0;
        char1.push_back('n');
        for (int i = 1; i<char1.size(); i++){
            if (char1[i]!=char1[i-1]){
                int size1 = i - pointer1;
                if (size1 == 1){output += 1;}
                else if (100>size1>=10){output += 3;}
                else if (size1>=100){output += 4;}
                else {output += 2;}
                pointer1 = i;
            }
        }
    return output;
    }
};
Basically, with the help of two pointers, pointer1 on every starting of a group of char, 
while i on the first char of the next group. By calculating the difference between i and pointer1, I get the size of that group.
Now, after getting the size, if its only '1', I'll add only 1. Why? because that the example of [a], it'll show only '1'.
For cases above 10, it'll add '3', why? because [a,a,a,..] 12 a's would give [a12] which would be equal to adding '3'.
For other cases, of group sizes from 2 to 9, for example, [a,a,a,a] would give [a4], so we'll add '2' to the output.
However,
When I ran this on Leetcode, it expected me to show the overwritten array, ex: ['a', '1', 'b', 'b', '2'], and
my code just tried printing the output. So anyways, 
let's try implementing it in the leetcode way, but I'll try to print both the array, and the output number.
..Also, while overwriting the 'char' arrray, if the 'char' elements are larger in size than those elements overriding it,
we simply ignore the characters left at the end of the char array, as they won't matter.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int compress(vector<char>& chars){ //A vector of type char named 'chars' is given to the function 'compress'. Since the return type of this function is 'int',, therefore the type of this function is 'int'.
        int n = chars.size(); //storing the size of the given array
        int read = 0, write =0; //

        while (read<n){ //'read' is a pointer which reads all the elements in the given array till it reaches the end of the array
            char curr = chars[read];  //we store the element being 'read' into curr
            int count = 0;
            //To count the size of the 'group of the same letter'
            while (read<n && chars[read]==curr){ //while read still hasn't reached the end of the array, and the 'char' (character) being read is still equal to 'curr':
                read ++; //We add 1 to read so that it can go to the other element
                count++; //And count is added by 1. So the more each element being read is equal to 'curr', the more 'count' is increased. In the last, count will show the number of elements of that particular letter.
            }
            //Overwriting the character
            chars[write] = curr; //so we overwright the chars array with that 'curr'
            write++; //So that the next thing to be added (either count of again a letter, is overwritten onto the other index)
            //to write the count if >1
            if(count>1){
                string cnt = to_string(count); //We convert the 'count' into a string because double digit numbers are added as different characters
                for (char c: cnt){
                    chars[write] = c;  //This line along with the line below can also be written as: chars[write++] = c;
                    write ++;
                }
            }
        }
        return write; 
    }
};
int main(){
    Solution solver;
    int n;
    cout<<"Enter the size of the vector: ";
    cin>>n;
    cout<<"Enter the values of the array: ";
    vector<char> chars;
    char i;
    for (int x = 0; x<n; x++){
        cin>>i;
        chars.push_back(i);
    }
    int len = solver.compress(chars); 
    cout<<len<<endl;  //if we are returning in the function, we would need 'cout' to catch that return and show it. However, we can just use 'solver.function' if the function has 'cout' in the end of it.
    
    //To also see the overwritten array (This is not part of LeetCode. Its for me to understand the concept of this problem clearly.)
    cout << "Compressed array: ";
    for (int k = 0; k < len; k++) {
        cout << chars[k] << " ";
    }
    cout << "\n";

    cout << "Full array overwritten (with leftovers): ";
    for (int k = 0; k < chars.size(); k++) {
        cout << chars[k] << " ";
    }
    cout << "\n";
    return 0;
}
/*
Result:
Enter the size of the vector: 7 
Enter the values of the array: a a b b c c c
6
Compressed array: a 2 b 2 c 3 
Full array overwritten (with leftovers): a 2 b 2 c 3 c 
..
Enter the size of the vector: 1
Enter the values of the array: a
1
Compressed array: a 
Full array overwritten (with leftovers): a 
..
Enter the size of the vector: 13 
Enter the values of the array: a b b b b b b b b b b b b
4
Compressed array: a b 1 2 
Full array overwritten (with leftovers): a b 1 2 b b b b b b b b b 
*/