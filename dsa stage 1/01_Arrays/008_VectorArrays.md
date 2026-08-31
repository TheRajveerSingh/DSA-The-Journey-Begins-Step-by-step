##### Vectors and its types
There are three ways to create an array with a given size.
Let's go through each type, know how to define them, when to use them, and what's the difference between them.
Firstly, we take a size from the user:
int size;
cout<< "Enter the size of the array: ";
cin>>size;
...
Now, what's the difference between:
1. vector<int>array(n)
2. vector<int> array; array.reserve(n);
3. vector<int> array;
...
1. vector<int>array(n):
This actually creates a vector with n elements in it.
Its just that the array will contain 0s.
Ex:
If we give: 
vector<int>array(5);
and print this array, it'll show: [0,0,0,0,0]
and its size is also 'n' (5).
Now, to put elements into this array, we can immidiately do:
array[0] = 10;
array[1] = 20;
and the array will become: [10,20,0,0,0] with size still 5.
...
2. vector<int> array; array.reserve(n);
This creates a vector with 0 actual elements, but reserves memory for at least n elements.
Basically, the array doesn't yet exist, but it reserves memory for an array for atleast n elements.
As we keep adding elements, its size will increase, but will only be able to reach its max capacity 'n'.
To put elements into this array, we have to do:
array.push_back(10);
array.push_back(20);
because: array[0] = 10; won't work.
(The index doesn't exist unless an element is already there, so we have to use push_back to insert elements. We can't take the help of indexes.)
Now, for this array, after adding elements, we see:
array = [10, 20]
size = 2 (because only 2 have been added)
capacity >= 5 (max it can take 'n' elements)
In short, reserve(n) prepares memory, but does not create elements. 
reserve() affects capacity, not size.
Ex:
vector<int> a;
a.reserve(5);
cout << a.size();      // 0
cout << a.capacity();  // at least 5
a.push_back(10);
a.push_back(20);
cout << a.size();      // 2
cout << a.capacity();  // at least 5
...
3. vector<int> array;
Here, an array is made, with no 'capacity' already given.
basically here, we keep inserting elements, and when it reaches its default 'limit',
i.e, when the vector runs out of capacity, it allocates a larger block of memory and moves/copies the existing elements there.
As you can see, doing this takes time, as for larger arrays, as we keep inserting elements, whenever it reaches its max capacity, it moves all the elements into a larger storage.
To put elements into this array, we have to do:
array.push_back(10);
array.push_back(20);
where, afterwards we see:
array = [10, 20, 30]
size = 3
capacity >= 3
.............
One thing to remember is that:
-> size = How many elements actually exist.
-> capacity = How many elements can fit in the currently allocated memory before another allocation is needed.
.........................................
##### When to use which one?
To use: vector<int> array(n);
When we know that we exactly need 'n' elements;
Ex:
for(int i = 0; i < n; i++) {
    cin >> array[i];}
...
To use: vector<int> array; array.reserve(n);
When we know approximately how many elements we'll add, but we're adding them dynamically..
Ex:
int x; 
for(int i = 0; i < n; i++) {
    cin >> x;
    array.push_back(x);
}
This avoids unnecessary reallocations as the vector grows.
...
To use: vector<int> array;
If we don't know how many elements we'll have.
Or, we're using a small array.
Ex: array.push_back(x);
The vector handles the growing automatically.
........
Question: What will happen if we did puch_back on: vector<int> a(n); ?
For ex:
vector<int> a(n);
a.push_back(10);
that'll also be correct, but now size becomes n+1. (because 5 0s where already there existing.)
........................................................................................
