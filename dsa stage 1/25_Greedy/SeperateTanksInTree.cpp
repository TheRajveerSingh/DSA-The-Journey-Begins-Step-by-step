// So I came across a question during one of my placement exams (7-11), and here's how it was:
//..........................................................................................
/*
Question:
You are given a map of a country in the form of an acyclic graph with m nodes. 
Each node representing an individual state connected to each other through bidirectional roads. 
During a war, the enemy has occupied the country and placed 1 tank in each of the states
mentioned in the input. The tanks use bidirectional roads to travel to any state. 
If any two tanks reach the same state then, the state will be destroyed. 
You need to stop two tanks from entering the same state, in order to do so, 
you need to eliminate (optimally) the roads connecting any two states in which the tanks are 
placed. You need to find the least amount of time required to eliminate the connecting roads. 
Eliminating each road will take a certain amount of time which is given in the input.

Note:
* No. of states & tanks is always > 1.
* If there are m no. of states, then they are numbered from 0 to m-1, state_0, state_1, upto state_m-1.
* The time required to eliminate the road connecting two states must always be positive and greater than 0.

Constraints:
* 1 < m < 200
* 1 < no. of tanks < 200

Input Format:
* First line contains two space-separated integers, m and n; 
  m = no. of states, n = no. of tanks.
* Each of the following m-1 lines contains 3 space-separated integers denoting two 
  connected states, and time / duration required to eliminate the road connecting 
  "state_1" and "state_2".
* The following n lines each contain an integer denoting the state having a tank.

Output:
Print the least amount of time required to eliminate the connecting roads to 
protect all the states from destruction.

Examples:

Input 1:
6 4
0 4 1
0 5 3
4 2 4
4 3 2
3 1 5
3
1
2
5

Output 1:
8

Input 2:
5 2
1 4 10
1 2 8
4 3 13
4 0 12
0
3

Output 2:
12
*/
//..........................................................................................
/*
On Research, I also got to know similar questions like this in other platforms:
This is a known classic problem on HackerRank called "Cut the Tree" / "Even Tree" variation, 
most identically matching "Roads in HackerLand" / "Red Knight's Shortest Path" style, 
but specifically known in competitive programming platforms as 
"Destroying Roads" or "Disconnect Tanks".
*/
//..........................................................................................