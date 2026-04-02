#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *deleteNode(Node *head, int key)
    {
        if (head == NULL)
        {
            return NULL;
        }

        // If head needs to be deleted
        if (head->data == key)
        {
            Node *last = head;

            // Find last node
            while (last->next != head)
            {
                last = last->next;
            }

            // If only one node
            if (head->next == head)
            {
                delete head;
                return NULL;
            }

            last->next = head->next;
            Node *temp = head;
            head = head->next;
            delete temp;

            return head;
        }

        Node *prev = head;
        Node *curr = head->next;

        while (curr != head)
        {
            if (curr->data == key)
            {
                prev->next = curr->next;
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};

class Eighteen
{
public:
    // Insert at end
    static Node *insert(Node *head, int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            newNode->next = newNode;
            return newNode;
        }

        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;

        return head;
    }

    // Print circular linked list
    static void printList(Node *head)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)" << endl;
    }
};

int main()
{
    Node *head = NULL;

    // Creating circular linked list: 10 -> 20 -> 30 -> 40 -> 50
    head = Eighteen::insert(head, 10);
    head = Eighteen::insert(head, 20);
    head = Eighteen::insert(head, 30);
    head = Eighteen::insert(head, 40);
    head = Eighteen::insert(head, 50);

    cout << "Original Circular List:" << endl;
    Eighteen::printList(head);

    Solution obj;
    int key = 30;

    head = obj.deleteNode(head, key);

    cout << "\nAfter deleting " << key << ":" << endl;
    Eighteen::printList(head);

    return 0;
}