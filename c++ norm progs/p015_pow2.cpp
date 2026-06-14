#include <iostream>
#include <vector>
using namespace std;
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    int i=1;
    if(num<1){cout<<num<<" does not come in the power of 2";
        return 0;}
   int current_power = 2; // Starts at 2^1
    while (current_power <= num) {
        if (current_power == num) {
            cout << num << " comes in the power of 2" << endl;
            return 0;  }
        current_power = current_power * 2;
    }
    cout << num << " does not come in the power of 2" << endl;
    return 0;
}
//Just incase if we want to try another approach:
// A property of powers of 2: (num & (num - 1)) is always 0
/*ne more approach can be first converting the number into binary,
and then seeing that if its binary form is 
to the power of 10 or not (Ex: 10, 100, 1000, 1000..)*/
/*
int num2;
    cout << "Enter a number: ";
    cin >> num2;

    // Numbers less than or equal to 0 cannot be powers of 2
    if (num2 <= 0) {
        cout << num2 << " does not come in the power of 2" << endl;
        return 0;
    }

    // A property of powers of 2: (num & (num - 1)) is always 0
    if ((num2 & (num2 - 1)) == 0) {
        cout << num2 << " comes in the power of 2" << endl;
    } else {
        cout << num2 << " does not come in the power of 2" << endl;
    }

    return 0;
*/