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