//NOTE: BEFORE RUNNING A BLOCK, COMMENT THE ONES NOT NEEDED.
//................................................................................
//I. UNDERSTANDING CALL BY VALUE

#include <iostream>
using namespace std;

void change(int x)
{
    x = 100;
    cout<<"x = "<<x<<endl;
}

int main()
{
    int a = 10;

    change(a);

    cout <<"a = "<<a;
}
/*
Result:
x = 100        
a = 10
Inference: As you can see, the value of original 'a' did not change. 
This is because the Call by Value function just copied the value of a.
*/
//................................................................................
//II.NOW, CALL BY REFERENCE:
//THIS TIME, we will use (int &a)
#include <iostream>
using namespace std;

void change(int &x)
{
    x = 100;
    cout<<"x = "<<x<<endl;
}

int main()
{
    int a = 10;

    change(a);

    cout <<"a = "<<a;
}
/*
Result:
x = 100        
a = 100
Inference: As you can see, the value of original 'a' did not change. 
This is because the Call by Value function just copied the value of a.
*/
//................................................................................
