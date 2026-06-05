#include <iostream>
#include <vector>
using namespace std;
int main(){
    cout<<"Hello Rajveer and Everyone!"<<endl;
    cout<<3*2<<endl;
    int a=10, b=20;
    cout<<a+b<<endl;
    bool g=false;
    cout<<g<<endl;
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout<<"Enter your age: ";
    int age;
    cin >> age;
    cout<<"Hello "<<name<<endl;
    if (age >= 18 && age%2==0){
        cout << "You can vote and your age is even!"<<endl;}
    else if (age >= 18 && age%2!=0){
        cout << "You can vote and your age is odd!"<<endl;}
    else {
        cout<<"You cannot vote!"<<endl;
    }
    }
//learnt about getline feature, helps getting more than 1 word