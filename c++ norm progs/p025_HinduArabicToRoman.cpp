/*During the exam today, I got a sum of converting "hindu Arabic Numerals" into their 
respective "Roman Numerals". In this is how I went for it:
.......
.......
#include <iostream>
#include <vector>
using namespace std;
int main(){
long int j;
cout<<"Enter a hindu arabic number: "<<endl;
cin>>j;
int c1 = j;
int re = 1;
while(j!=0){
    long int q = j/10;
    long int r = j%10;
    long int rem = re*r;
    re = re*10;
    j = q;
    if (rem==1){cout<<"I";}
    else if (rem==2){cout<<"II";}
    else if (rem==3){cout<<"III";}
    else if (rem==4){cout<<"IV";}
    else if (rem==5){cout<<"V";}
    else if (rem==6){cout<<"VI";}
    else if (rem==7){cout<<"VII";}
    else if (rem==8){cout<<"VIII";}
    else if (rem==9){cout<<"IX";}
}
}
......
......
Yes, this version is slightly off. 
My logic was to extract digits from right to left (ones place, then tens place, etc.).
However, Roman numerals are read and written from left to right (largest values to smallest values). 
Printing them right-to-left will give us the numerals backwards 
(e.g., 14 would print as IVX instead of XIV).
...
So the next stratergy was to:
Instead of breaking down the number by digits, we can look at the total value and 
repeatedly subtract the largest possible Roman numeral value until we hit 0.
................
................
Roman Numerals Chart
NumberValue	RomanNumerals
1              	I
5              	V
10              X
50	            L
100	            C
500	            D
1,000           M
1,000           _I
5,000	        _V
10,000	        _X
50,000	        _L
100,000	        _C
500,000	        _D
1,000,000       _M
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long j; // Using long long to safely handle large numbers up to millions
    cout << "Enter a Hindu-Arabic number: " << endl;
    cin >> j;
    // Check if the input failed (e.g., user typed a letter) OR if the number is negative/zero
    if (cin.fail() || j <= 0) {
        cout << "Please enter a valid positive number." << endl;
        return 0;
    }

    // Mapping values from 1,000,000 down to 1
    // Using the '_X' notation provided in your image chart
    const vector<long long> values = {
        1000000, 900000, 500000, 400000, 100000, 90000, 
        50000, 40000, 10000, 9000, 5000, 4000, 
        1000, 900, 500, 400, 100, 90, 
        50, 40, 10, 9, 5, 4, 1
    };

    const vector<string> symbols = {
        "_M", "_C_M", "_D", "_C_D", "_C", "_X_C", 
        "_L", "_X_L", "_X", "_I_X", "_V", "_I_V", 
        "M", "CM", "D", "CD", "C", "XC", 
        "L", "XL", "X", "IX", "V", "IV", "I"
    };

    string result = "";

    // Loop through the values from largest to smallest
    for (size_t i = 0; i < values.size(); i++) {
        // While the current value can be subtracted from j
        while (j >= values[i]) {
            result += symbols[i]; // Append the symbol
            j -= values[i];       // Subtract the value
        }
    }

    cout << "Roman Numeral: " << result << endl;

    return 0;
}
/*
Result:
Enter a Hindu-Arabic number: 
456684
Roman Numeral: _C_D_L_VMDCLXXXIV
Enter a Hindu-Arabic number: 
7543
Roman Numeral: _VMMDXLIII
*/