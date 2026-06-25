#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int isPrime(int p) {
    vector<int> fc;
    if(p<2){
        cout<<p<<" is not a prime number."<<endl; return 0;}
    for (int j = p-1; j>=2; j--){
         if(p%j==0){
            fc.push_back(j);}}
    if(fc.empty()){cout<<p<<" is a prime number."<<endl; return 1;}
    else{ cout<<p<<" is not a prime number, with its factors being 1, "<<p<<", ";
    for (int i = 0; i<fc.size(); i++){
        cout<<fc[i]<<", ";
        }
        cout << endl;
        return 0;
    }}
};
int main(){
    Solution Solver;
    int a,b,c;
    cout<<"Enter 1st number: ";
    cin>>a;
    int result = Solver.isPrime(a);
    cout<<"Enter 2nd number greater than 1st number: ";
    cin>>b;
    result = Solver.isPrime(b);
    c = b - a;
    result = Solver.isPrime(c);
    cout << result << endl;
    return 0;
};