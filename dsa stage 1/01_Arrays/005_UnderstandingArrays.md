Okay,<br>
hmm, so now, its time to start arrays..<br>
basically, the first step towards real DSA<br>
For the readers, I just want to say, that I don't know alot about arrays yet. <br>
Unintentionally, I started using the concept of arrays in the last 3-4 programs, if you can see.<br>
But anyways, let's see how it does.<br>
In this md file, I'll start with very basic knowledge about arrays, and as I go further,<br> I'll try to keep adding new stuff about arrays as I learn.<br>
Thuough I have my copy, if everything is here together, I feel as if it would be easier to revise when I need to..<br>
So Let's get started..<br>
............<br>
So what are arrays?<br>
As a person who studied python before, if I had to compare, it was something like 'lists'<br>
but after some research, I found some basic differences:<br>
1. The Fixed Size Rule:<br>
Python List: We can start with an empty list my_list = [] and use .append() to add 100 items later. Python automatically resizes it for us.<br>
C++ Array: We must declare the exact size upfront (e.g., int arr[5]). Once created, that array is exactly 5 slots forever. We cannot make it size 6, and we cannot shrink it.<br>
2. Data Types:<br>
Python List: Can hold completely different things at the same time: my_list = [3, "apple", True, 4.5].<br>
C++ Array: Is strictly uniform. If we declare an int arr[5], every single slot must hold an integer. We cannot mix strings and numbers in a standard array.<br>
3. Behind the Scenes (Memory):<br>
In Python, lists are actually collections of pointers scattered around our computer's memory.<br>
In C++, an array is a single, uninterrupted chunk of physical memory. If we make an array of 5 integers, C++ sets aside 5 exact memory slots right next to each other. This makes C++ arrays incredibly fast and efficient for the computer to read, but it's the reason why we can't dynamically change their size.<br>
4. About VECTORS:
A Vector is just a smart, dynamic array.<br>
To declare: vector<type> name;<br>
To push an item in it: .push_back() function<br>
When we use .push_back(), here is what the vector does behind the scenes:<br>
a. It checks if it has an empty slot left.<br>
b. If it is full, it automatically creates a brand new array that is double the size of the old one.<br>
c. It copies the old data into the new, larger array.<br>
d. It deletes the old, small array to free up memory.<br>
e. It drops the new item into the next slot.<br>

Because vectors do this automatic resizing, they keep track of two different numbers:<br>
Size: How many items are actually inside the vector right now (accessible via .size()).<br>
Capacity: How many items the vector can hold before it is forced to grow and allocate more memory (accessible via .capacity()).<br>
....................<br>
Now, time for some Basic Array Formats:<br>

1. How to Define (Declare) an Array:<br>
// Method A: Declare an empty array of size 5 (will contain random junk memory initially)<br>
int numbers[5]; <br>
// Method B: Declare and initialize it with values immediately<br>
int scores[5] = {92, 85, 74, 99, 88}; <br>
// Method C: Let C++ figure out the size automatically based on your values<br>
int ages[] = {16, 17, 18}; // This is automatically size 3<br>
2. How to Traverse (Loop) Through an Array:<br>
int items[4] = {10, 20, 30, 40};<br>
// We start i at index 0, and stop BEFORE index 4 (since the last slot is 3)<br>
for (int i = 0; i < 4; i++) {<br>
    cout << "Value at index " << i << " is: " << items[i] << endl;<br>
}<br>
3. How to Calculate the Size of an Array<br>
Unlike modern languages, a primitive C++ array doesn't have a .length() or .size() command built into it. If we have passed an array and don't know how big it is, we have to calculate it using the sizeof() operator.<br>
The sizeof() measures memory size in bytes. An integer (int) usually takes up 4 bytes of memory.<br>
int data[] = {5, 10, 15, 20, 25}; // 5 integers total<br>
// 1. Calculate total bytes of the entire array (5 integers * 4 bytes = 20 bytes)<br>
int totalBytes = sizeof(data); <br>
// 2. Calculate bytes of just ONE single element (1 integer = 4 bytes)<br>
int oneElementBytes = sizeof(data[0]); <br>
// 3. Total Bytes / One Element Bytes = Total Number of Elements (20 / 4 = 5)<br>
int arraySize = sizeof(data) / sizeof(data[0]);<br>
cout << "The array has " << arraySize << " elements." << endl;<br>
..................<br>

So Sort an Arrray: There are many types of sorting, the basic one being bubble sort.<br>
All types of sorting in array and their concept:<br>
1. Bubble Sort:<br>

........<br>
Next, we would learn about:<br>
1. Multi-Dimensional Arrays (Arrays Inside Arrays)<br>
2. Passing Arrays to Functions<br>
3. The Modern Alternative: std::array<br>
4. Range-Based for Loops (The "For-Each" Loop)<br>

.........................................................<br>
NOTE:<br>
To find the size or length of a:<br>
1. string: word.length() or word.size()<br>
2. number: first convert it into a string: to_string(num).length()<br>
3. array: modern c++ allows this: size(arr)<br>