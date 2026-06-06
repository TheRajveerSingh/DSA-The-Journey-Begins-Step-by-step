#include<iostream>
using namespace std;
int main()
{
    int row, col;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of coloumns: ";
    cin>>col;
    for(int r = 1; r<=row; r++)
    {
        for(int c=1; c<=col; c++)
        {
            cout<<"("<<r<<c<<")"<<" ";
        }
        
        cout<<endl;
    }cout<<endl;
    for(int r = 1; r<=row; r++)
    {
    int q = r + 96;
        for(int c=1; c<=col; c++)
        {
             cout<<"("<<static_cast<char>(q)<<c<<")"<<" ";
        }
        
        cout<<endl;
    }cout<<endl;
    for(int r = row; r>=1; r--)
    {
        for(int c=1; c<=r; c++)
        {
            cout<<"*"<<" ";
        }
        
        cout<<endl;
    }cout<<endl;
    //Christmas Tree Pattern:
    for (int r = 1; r<=row; r++){
    int q = r + 64;
    for (int s = 1; s <= (row - r); s++) {
            cout << " ";
        }
        for (int c = 1; c<=r; c++){
            cout<<static_cast<char>(q)<<" ";
        }cout<<endl;
    }cout<<endl;
    for (int r = 1; r<=row; r++){
    int q = r + 64;
    for (int s = 1; s <= (row - r)*2; s++) {
            cout << " ";
        }
        for (int c = 1; c<=r; c++){
            cout<<static_cast<char>(q)<<" ";
        }cout<<endl;
     }cout<<endl;
    for (int r = 1; r<=row; r++){
    for (int s = 1; s <= (row - r)*2; s++) {
            cout << " ";
        }
        for (int c = 1; c<=r; c++){
            int q = c + 64;
            cout<<static_cast<char>(q)<<" ";
        }cout<<endl;
}}
//learnt how to print the ASCII value of a given number by static_cast