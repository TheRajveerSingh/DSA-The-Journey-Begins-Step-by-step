#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int i;
    for (i=0; i<=n; i=i+2){
        cout<<"Hello"<<i<<" ";
    }cout<<endl;
    for (i=n; i>=1; i=i-2){
        cout<<"Bye"<<i<<" ";
    }
    char alpha;
    cout<<endl;
    for(alpha = 'a'; alpha<='z'; alpha=alpha+1){
        cout<<alpha<<" ";
    }cout<<endl;
    for(alpha = 'z'; alpha>='a'; alpha=alpha-1){
        cout<<alpha<<" ";
    }cout<<endl;
    char alphabet;
    char p;
    cout<<"Enter a letter to see its front and back letters: ";
    cin>>p;
    for (alphabet=p; alphabet<='z'; alphabet++){
        cout<<alphabet<<" ";
    }cout<<endl;
     for (alphabet='a';alphabet<=p; alphabet++){
        cout<<alphabet<<" ";
    }
    int j;
    cout<<endl<<"Enter a number to print its multiplication table: ";
    cin>>j;
    for (int k=1; k<=10; k++){cout<<j<<"*"<<k<<"="<<j*k<<endl;}
    int o;
    cout<<"Enter a number: ";
    cin>>o;
    int poww;
    cout<<"Enter the power: ";
    cin>>poww;
    long long jj=1;
    for (int i=1; i<=poww; i++){
        jj=jj*o; cout<<i<<"th Chain :"<<jj<<endl;} 
        cout<<o<<"^"<<poww<<"="<<jj;
}
