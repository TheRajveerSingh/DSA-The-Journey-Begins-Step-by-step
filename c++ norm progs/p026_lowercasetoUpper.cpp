#include <iostream>
#include <vector>
#include <string>
using namespace std;

char lowertoUpper(char lower){
    char upper = lower - 'a' + 'A';
    return upper;
}

string lowertoUpper(string word){
    for (int i=0; i<word.length(); i++){
        word[i] = word[i] - 'a' + 'A'; 
    }
    return word; 
}

int main(){
    cout<<"Enter a lower case alphabet: ";
    char lower;
    cin>>lower;
    cout<<lowertoUpper(lower)<<endl;
    cout<<"Enter a word in lower case: ";
    string word;
    cin>>word;
    cout<<lowertoUpper(word)<<endl;
    return 0; //Its just like telling our compiler that it has reached the end of code without any problem.
}
/*
Result:
Enter a lower case alphabet: j
J
Enter a word in lower case: everyone
EVERYONE
*/