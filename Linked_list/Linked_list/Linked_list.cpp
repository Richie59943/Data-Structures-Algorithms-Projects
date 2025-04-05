#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


class Node {
public:
    char data;
    Node* next;
    Node(char c, Node* n)
    {
        data = c;
        next = n;
    }
};


void main()
{

    Node* s = nullptr;
    char c = ' ';

    while (c != 'q')
    {
        // Read the user input
        c = _getch();
        cout << c;

        // If first character make a start point to it
        // If not then find a lset node and link it
        if (!s)
        {
            Node* p = new Node(c, nullptr);
            s = p;
        }
        else
        {
            Node* newnode = new Node(c, nullptr);
            Node* p;
            p = s;

            while (p->next)
            {
                p = p->next;
            }
            p->next = newnode;
        }

    }
    // Print linked list
    Node* p = s;
    p = s;
    int total_num = 0;

    cout << "\nPrinting the linked list through a loop\n" << endl;
    while (p != nullptr)
    {
        cout << p->data << " -> ";
        p = p->next;
        total_num++;
    }
    cout << "nullptr" << endl;
    cout << "Number of Nodes: " << total_num << endl;

    
    int middle = total_num / 2; 
   

    p = s;
    while (middle--)
    {
        p = p->next;
        middle -= 1;
    }
    cout << "middle of the node is: " << p->data << endl;;

}