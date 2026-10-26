//THis is a menu Driven Program to Understand how Queues work
#include <iostream>
#include <queue>
using namespace std;

void display(queue<int> q) {
    if (q.empty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Front -> ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "<- Back\n";
}

int main() {
    queue<int> q;
    int choice, value;

    do {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Push an element\n";
        cout << "2. Emplace an element\n";
        cout << "3. View front element\n";
        cout << "4. View back element\n";
        cout << "5. Pop front element\n";
        cout << "6. Check size\n";
        cout << "7. Check if empty\n";
        cout << "8. Display queue\n";
        cout << "9. Clear queue\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.push(value);
                cout << "Element pushed.\n";
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                q.emplace(value);
                cout << "Element emplaced.\n";
                break;

            case 3:
                if (!q.empty())
                    cout << "Front: " << q.front() << "\n";
                else
                    cout << "Queue is empty.\n";
                break;

            case 4:
                if (!q.empty())
                    cout << "Back: " << q.back() << "\n";
                else
                    cout << "Queue is empty.\n";
                break;

            case 5:
                if (!q.empty()) {
                    cout << "Removed: " << q.front() << "\n";
                    q.pop();
                } else {
                    cout << "Queue is empty.\n";
                }
                break;

            case 6:
                cout << "Size: " << q.size() << "\n";
                break;

            case 7:
                if (q.empty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;

            case 8:
                display(q);
                break;

            case 9: {
                queue<int> emptyQueue;
                q.swap(emptyQueue);
                cout << "Queue cleared.\n";
                break;
            }

            case 10:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 10);

    return 0;
}
/*
Results:        
--- QUEUE MENU ---
1. Push an element
2. Emplace an element
3. View front element
4. View back element
5. Pop front element
6. Check size
7. Check if empty
8. Display queue
9. Clear queue
10. Exit
Enter choice: 1
Enter value: 5
Element pushed.

Enter choice: 1
Enter value: 6
Element pushed.

Enter choice: 1
Enter value: 7
Element pushed.

Enter choice: 1
Enter value: 8
Element pushed.

Enter choice: 1
Enter value: 9
Element pushed.

Enter choice: 8
Front -> 5 6 7 8 9 <- Back

Enter choice: 2
Enter value: 10
Element emplaced.

Enter choice: 8 
Front -> 5 6 7 8 9 10 <- Back

Enter choice: 3
Front: 5

Enter choice: 4
Back: 10

Enter choice: 5
Removed: 5

Enter choice: 5
Removed: 6

Enter choice: 7
Queue is not empty.

Enter choice: 6
Size: 4

Enter choice: 8
Front -> 7 8 9 10 <- Back

Enter choice: 9
Queue cleared.

Enter choice: 6
Size: 0

Enter choice: 10
Exiting program.
*/
/*
Thing to learn:
Difference between Push and Emplace.
The main difference is that push() adds an existing object to the queue, 
while emplace() constructs an object directly inside the queue.

Suppose we have a class:
class Student {
public:
    string name;
    int age;

    Student(string n, int a) {
        name = n;
        age = a;
    }
};
.......
Now, using push():
Student s("Raj", 20);
queue<Student> q;
q.push(s);
We first create the Student object s, then pass it to the queue. 
The queue constructs its own stored element by copying s 
(or moving it if you explicitly use std::move).
Using emplace():
queue<Student> q;
q.emplace("Raj", 20);
We pass the constructor arguments directly. 
The queue constructs the Student object in its underlying storage 
without needing a separate Student temporary object.
*/