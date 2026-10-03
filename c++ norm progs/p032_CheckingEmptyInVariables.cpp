/*
How to Check whether a variable is empty:
-> .empty() - For containers and collections.
    Ex: String, vector, list, map.
    It means that "This collection has 0 elements inside it."
-> optional and .has_value() - For any single variable.
    Ex: optional(double), optional(int), optional(char).
    It means that "This box is completely empty; no value exists yet."
-> nan("") and .isnan() - For Floating-point numbers only.
    Ex: double, float.
    It means that "This is a number, but its value is mathematically undefined."
    The difference between optional and isnan is that, isnan() exists as "not a number", 
    but (optional) doesn't exist unless used.
*/
#include <iostream>
#include <vector>
#include <optional>
#include <cmath> // Required for nan and isnan
using namespace std;

int main() {
    // ==========================================
    // 1. Using .empty() for Containers
    // ==========================================
    vector<int> numbers; // An empty collection of integers

    cout << "--- 1. Container Check ---" << endl;
    if (numbers.empty()) {
        cout << "The vector is currently empty (contains 0 elements)." << endl;
    }


    // ==========================================
    // 2. Using optional & .has_value() for Single Variables
    // ==========================================
    optional<int> userAge; // Starts completely empty (like 'None' in Python)
    //Optional means the variable doesn't exist unless used/put value in it.

    cout << "\n--- 2. Optional Check ---" << endl;
    if (!userAge.has_value()) {
        cout << "User age has not been set yet." << endl;
    }

    userAge = 21; // Assign a value

    if (userAge.has_value()) {
        cout << "User age is now: " << userAge.value() << endl;
    }


    // ==========================================
    // 3. Using nan("") & isnan() for Floating-Point Numbers
    // ==========================================
    double temperature = nan(""); // Initialised to mathematically undefined

    cout << "\n--- 3. Floating-Point NaN Check ---" << endl;
    if (isnan(temperature)) {
        cout << "Temperature data is missing or empty." << endl;
    }

    temperature = 36.6; // Assign a real number

    if (!isnan(temperature)) {
        cout << "Temperature is now recorded as: " << temperature << " C" << endl;
    }

    return 0;
}
/*
Result:
--- 1. Container Check ---        
The vector is currently empty (contains 0 elements).

--- 2. Optional Check ---
User age has not been set yet.
User age is now: 21

--- 3. Floating-Point NaN Check ---
Temperature data is missing or empty.
Temperature is now recorded as: 36.6 C
*/