Okay, so here, We'll try understanding some concepts of functions. <br>
It'll be basic ones, and I'll try explaining them as easy as possible.  <br>
So look,  <br>

# CHAPTER 1: BASICS
Functions are nothing but 'funtions' 😂  <br>
..umm, okay, look, what did we used to do earlier?  <br>
Under int main() itself, we declared variables, and wrote what to do with those variables  <br>
there itself, right?  <br>
But now, what are we doing?  <br>
We are defining the variables under int main(), then to use those variables, we are just   <br>
calling the functions, which then take those variables, and perform the commands under it.  <br>
So once a function is defined, we can use it for alot of variables.  <br>

# CHAPTER 2: DEFINING FUNCTIONS
So, look,  <br>
basically a function in defined as: <br>
return_type function_name(parameter_type parameter) <br>
for example: <br>
bool isEven(int n) -> which determines whether the given number 'n' is even or not <br>
with bool -> return false or return true <br>
with int -> return 0 or return 1 <br>
with void -> If we aren't returning anything, and just printing a value <br>
int n for integer, float n for decimal, vector<int> n for array, and so on. <br>

# CHAPTER 3: CALL BY VALUE & CALL BY REFERENCE
Now, while working with the files '001_MyfirstArray' and '002_SortinganArray' <br>
I came across a question.. <br>
If you go to those files and check, specially in '002_SortinganArray', <br>
you'll see that I have used: const and & in the parameters: <br>
     -> void inputArray(vector<int> &arr) <br>
     -> void arrangeEvenOdd(const vector<int> &arr, vector<int> &result) <br>
But the question was Why? <br>
Why not simply use: (vector<int> arr) ? <br>
..This is where the concept of 'Call by Value' and 'Call by Reference' comes. <br>
..... <br>
Basically, <br>
Call by Value [No &] -> The function copies the value of the parameter from the main() <br>
Call by Reference [With &] -> The function literally takes that same value. <br>
So Now, when a value comes from "Call by Value", even if the function modifies it, <br>
the 'original' value in the main() doesn't change. Because it was just a copy. <br>
But, In Call by Reference, it literally takes up the value from the main() and any modification to  <br>it also changes the original value. <br>
.. <br>
For example: see the following examples: <br>
1. Go to 003_UnderstandingFunctionsProgs.cpp to see better there.<br>
So, as you can see here, the original value of 'a' doesn't change during Call by Value, <br>
but changes during Call by Reference.<br>
..........................<br>
Okay, got this concept.<br>
But still, why did we use (const vector<int> &arr) instead of just (vector<int> arr)?<br>
Its not like we needed to modify the values of arr in the '002_SortinganArray.cpp' file.<br>
True,<br>
We didn't,<br>
but look, using this trick is a better practice.<br>
Look, copying will take more time than taking the original value, right?<br>
Okay, our arr might be small, but what if we're using it for very very large arrays?<br>
It'll take alot of time to copy the original array.<br>
So to not waste that time, we're using Call By Reference().<br>
And to stop any modification by mistake, we put 'const'<br>
So we actually, somewhat, tricked Call by Reference 💀, Lol.<br>
using '&' helped taking the original value instead of copying, and const stopped modification.<br>

# CHAPTER 4: USING CLASSES, PUBLIC & PRIVATE FUNCTIONS, AND USING THEM IN MAIN()
Okay, <br>
Someimes, we might want to define functions, but might not want to use it in main().<br>
And sometimes, we might want to define functions which functions can use 💀.<br>
Yeah, like think about it, if main() can call a function to work with, can't a function call another function to work one part inside it?<br>
Like, to check if a number is prime or not, the main() calls the function isPrime(), but then the isPrime() function also calls the factors() function under it to get the factors of the number. So finally, the isPrime()function does its own work of telling whether the number is prime or not, but also told what factors it had, as it also called the function factors(). <br>
Basically, in simple terms: <br>
Customer called Interior Designer to design the home, and this Interior Desginer called a Painter to paint the walls.<br>
...<br>
Okay now that we have understood this, functions ar of two types:<br>
1. Public: which can be accessed by the main().
2. Private: which cannot be accessed by the main(). These might be used later is the coder puts it under public, or can be used by other functions.<br>
A better way to understand this is to check the file:<br>
'p020_facorialAndprimefunctions.cpp' under 'c++ norm progs'<br>
Look, if you see, <br>
We have created a Class named Solution, right?<br>
Now under Class Solution, we have two functions:<br>
   -> bool isPrime(int p)<br>
   -> void Factorial(int t)<br>
both of them come under public, and so they can also be called from outside the Class Solution.<br>
However, is there was any function under private:<br>
Then it couldn't have been called from outside the class Solution.<br>
But yes, it can be called from any function(public or private) in the Class Solution itself.<br>
....<br>
Then, in the int main(), we define a Class object to get access to the public functions 
under class.<br>
format: Classname Objectname<br>
then whatever function we want to access, we write: Objectname.functionname()<br>
Example:<br>
Solution solver;<br>
solver.isEven(i);<br>
1. To understand this concept better, check out the '003_UnderstandingFunctionsProgs.cpp' file.
That example will also make us understand how one function can call another function.<br>
That is why sometimes, private functions are known as 'helper functions'<br>
...........................................................................................