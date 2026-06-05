#include <vector>
#include <iostream>
using namespace std;
int main(){
    int p;
    vector<int> fc;
    cout<<"Enter a number: ";
    cin>>p;
    if(p<2){cout<<p<<" is not a prime number."<<endl;
        return 0;}
    for (int j = p-1; j>=2; j--){
         if(p%j==0){
            fc.push_back(j);}}
    if(fc.empty()){cout<<p<<" is a prime number.";}
    else{ cout<<p<<" is not a prime number, with its factors being 1, "<<p<<", ";
    for (int i = 0; i<fc.size(); i++){
        cout<<fc[i]<<", ";
        }
    }}
    //learnt to use vector, and instead of append in python, here we can use push_back()