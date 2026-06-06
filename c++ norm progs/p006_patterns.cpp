#include<iostream>
using namespace std;
int main()
{
    int row, col;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of coloumns: ";
    cin>>col;
    //Pattern 1: To create a box structure
    for(int r = 1; r<=row; r++)
    {
        for(int c=1; c<=col; c++)
        {
            cout<<"("<<r<<c<<")"<<" ";
        }
        
        cout<<endl;
    }cout<<endl;
    // Pattern 2: to create a box structure with alphabets
    for(int r = 1; r<=row; r++)
    {
    int q = r + 96;
        for(int c=1; c<=col; c++)
        {
             cout<<"("<<static_cast<char>(q)<<c<<")"<<" ";
        }
        
        cout<<endl;
    }cout<<endl;
    //Pattern 3: To create a star structure from increasing to decreasing
    for(int r = row; r>=1; r--)
    {
        for(int c=1; c<=r; c++)
        {
            cout<<"*"<<" ";
        }
        
        cout<<endl;
    }cout<<endl;
    //Pattern 4: Christmas Tree Pattern with alphabets:
    for (int r = 1; r<=row; r++){
    int q = r + 64;
    for (int s = 1; s <= (row - r); s++) {
            cout << " ";
        }
        for (int c = 1; c<=r; c++){
            cout<<static_cast<char>(q)<<" ";
        }cout<<endl;
    }cout<<endl;
    //Pattern 5: Aplabets from decreasing to increasing, from left side(same letters every line)
    for (int r = 1; r<=row; r++){
    int q = r + 64;
    for (int s = 1; s <= (row - r)*2; s++) {
            cout << " ";
        }
        for (int c = 1; c<=r; c++){
            cout<<static_cast<char>(q)<<" ";
        }cout<<endl;
     }cout<<endl;
     //Pattern 6: Aplabets from decreasing to increasing, from left side(sequencial letters every line)
    for (int r = 1; r<=row; r++){
    for (int s = 1; s <= (row - r)*2; s++) {
            cout << " ";
        }
        for (int c = 1; c<=r; c++){
            int q = c + 64;
            cout<<static_cast<char>(q)<<" ";
        }cout<<endl;
    }cout<<endl;
    //Pattern 7: Same as pattern 6 but different method
    cout<<"Enter the number of input: ";
    int n;
    cin>>n;
    for(row=1; row<=n; row=row+1)
    {
    for(col=1; col<=n-row; col=col+1)
    cout<<" "<<" ";
    for(col=1; col<=row; col=col+1)
    {
        char name = 'A'+col-1;
        cout<<name<<" ";
    }cout<<endl;}  
    //Pattern 8: Same as pattern 7, but from left side and different method
    cout<<"Enter the number of input: ";
    int l;
    cin>>l;
    for(row=1; row<=l; row=row+1)
    {
    for(col=1; col<=l-row; col=col+1)
    cout<<" ";
    for(col=1; col<=row; col=col+1)
    {
        char name = 'A'+col-1;
        cout<<name<<" ";
    }cout<<endl;
}}
//learnt how to print the ASCII value of a given number by static_cast