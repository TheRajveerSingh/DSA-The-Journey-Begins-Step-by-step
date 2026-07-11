/*
================================================================================
PROBLEM DESCRIPTION:
Given the position of a Bishop on a standard 8x8 chessboard at coordinates (A, B),
where 'A' represents the 1-indexed row number and 'B' represents the 1-indexed 
column number, calculate the total number of squares the Bishop can visit or attack.
A Bishop can only move diagonally any number of squares, provided it stays on the board.

SAMPLE INPUT & OUTPUT:
Input:  Row (A) = 4, Column (B) = 4
Output: Total Squares = 13
Explanation: From (4,4), the bishop can move to 3 squares top-right, 3 squares 
             top-left, 3 squares bottom-left, and 4 squares bottom-right. 
             3 + 3 + 3 + 4 = 13.

STRATEGY / LOGIC:
A bishop moves along four distinct diagonal paths from its current square:
1. Top-Right: Distance to the boundaries is restricted by (8 - A) and (8 - B).
2. Top-Left: Distance to the boundaries is restricted by (8 - A) and (B - 1).
3. Bottom-Left: Distance to the boundaries is restricted by (A - 1) and (B - 1).
4. Bottom-Right: Distance to the boundaries is restricted by (A - 1) and (8 - B).

Because a diagonal step requires moving exactly one unit both horizontally and 
vertically simultaneously, the bishop's reach in any direction is blocked as soon 
as it hits the closest board edge. Therefore, the maximum squares it can move in 
any of the 4 directions is the minimum of the remaining steps to the respective edges.
================================================================================
*/
//Let's take the counting of the board increasing from top to bottom, and left to right
#include <iostream>
using namespace std;

int Solution(int A, int B) {

    int count = 0;

    count+= min(8-A,8-B); //Top-Right
    count+= min(8-A,B-1); //Top-Left
    count+= min(A-1,B-1); //Bottom-Left
    count+= min(A-1,8-B); //Bottom-Right

    return count;
}

int main(){
    cout<<"Enter the row of the bishop: ";
    int A;
    cin>>A;
    cout<<"Enter the coloumn of the bishop: ";
    int B;
    cin>>B;
    cout<<"The total number of steps the Bishop take take from box ("<<A<<","<<B<<") is: "<<Solution(A,B);
}
/*
Result:
Enter the row of the bishop: 5
Enter the coloumn of the bishop: 6
The total number of steps the Bishop take take from box (5,6) is: 11
Enter the row of the bishop: 1
Enter the coloumn of the bishop: 1
The total number of steps the Bishop take take from box (1,1) is: 7
*/