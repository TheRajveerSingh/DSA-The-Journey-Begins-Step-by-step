//During the exam today, I got a sum of converting "hindu Arabic Numerals" into their respectful "Roman Numerals"
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