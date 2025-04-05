/*
Programmer: Ricardo Ramirez
Program Name: Stack_Queue_code
Date: 3/1/24
Version: 2.5
Creating a Function that will compare two stacks and siplayy only the items
that exist in stack 1 but not stack 2.
*/

#include <iostream>
#include <stack>


using namespace std;

// Function to display items that exist in stack 1 but not in stack 2
void displayItemsNotInStack1(stack<int>& stack1, stack<int>& stack2) {
    stack<int> tempStack;

    // Iterates over stack 1 to find items not in stack 2
    while (!stack1.empty()) {
        int currentTop = stack1.top();
        stack1.pop();

        // Check if the item is not in stack 2
        bool foundInStack2 = false;
        while (!stack2.empty()) {
            if (stack2.top() == currentTop) {
                foundInStack2 = true;
                break;
            }
            tempStack.push(stack2.top());
            stack2.pop();
        }

        // If the item is not found in stack 2, display it
        if (!foundInStack2) {
            cout << currentTop << " ";
        }

        // Restore stack 2
        while (!tempStack.empty()) {
            stack2.push(tempStack.top());
            tempStack.pop();
        }
    }

    cout << endl;
}

int main() {
    stack<int> stack1, stack2;

    // Push some elements into stack 1
    stack1.push(4);  
    stack1.push(2);
    stack1.push(3);

    // Push some elements into stack 2
    stack2.push(1);
    stack2.push(3);
    stack2.push(4);

    cout << "Items in stack 1 but not in stack 2: ";
    displayItemsNotInStack1(stack1, stack2);

    return 0;
}