#include <iostream>
#include <vector>
using namespace std;
int main(){
   int i = 1;
   while(i<=50){
    if(i==26)
    break;
    cout<<i<<" ";
    i++;
   } cout<<endl;
// To print only odd nubers between 1 to 50
 int j = 1;
    while (j <= 50) {
        if (j % 2 == 0) {
            j++;        // 1. Increment first so we don't get stuck
            continue;   // 2. Skip the rest of the loop for even numbers
        }
        cout << j << " "; 
        j++;            // 3. Increment odd numbers too
    }
    return 0;
 
}