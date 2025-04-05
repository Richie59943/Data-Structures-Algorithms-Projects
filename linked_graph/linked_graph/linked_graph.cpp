/*
Programmer Name: Ricardo Ramirez
Class:  CS M135
Date:02/19/24
Version: 2.1
    
    The code will display a linked list graphically
*/

#include <iostream>

using namespace std;

// Define a Node class
class Node {
public:
    int data;
    Node* next;

    // Parameterized Constructor
    Node(int value) { next = nullptr; data = value; }
};

// Function to display the linked list graphically
void displayLinkedList(Node* node1) {
    Node* current = node1;

    //while loop that outputs the linked list 
    while (current != nullptr)
    {
        cout << " [DATA] " << current->data;

        if (current->next != nullptr)
        {
            cout << " -> ";

        }
        else {
            cout << " -> NULL " << endl;
        }
        current = current->next;
    }
}

int main() {
    //ask the user how many nodes they would like 
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    //data validation 
    if (numNodes <= 0) {
        cout << "Invalid number of nodes." << endl;
        return 1;
    }

    //creating a new nodes
    Node* head = nullptr;
    Node* tail = nullptr;

    //for loop that stores the value that the user inputs and moves down until it reaches the total amount of nodes user specified (dynamically allocates memory)
    for (int i = 0; i < numNodes; ++i) {
        int value;
        cout << "Enter value for node " << i + 1 << " (numbers) : ";
        cin >> value;

    //gets the value and creates nodes adjusting in order to keep linked list
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }

        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    //calls the function to print the contents of the linked list
    displayLinkedList(head);

    // Free allocated memory
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}