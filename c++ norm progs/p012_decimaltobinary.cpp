#include <iostream>
#include <vector>
using namespace std;

int main(){
    //decimal to binary
    int num, rem, ans = 0, mul=1;
    cout<<"Enter a number: ";
    cin>>num;
    while(num>0){
        rem = num % 2;
        num/=2;
        ans+= rem*mul;
        mul*=10;
    }
    cout<<ans<<endl;
    //binay to decimal
    int bin;
    cout<<"enter the binary number: ";
    cin>>bin;
    int mull=1,anss=0,remm;

    while(bin)
    {
      
        remm = bin%10;

        bin = bin/10;
        
        anss = mull*remm+anss;
        mull*=2;
    }

    cout<<anss<<endl;

}