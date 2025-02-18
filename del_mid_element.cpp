#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

void deleteMiddle(Node*& head) {
   
    if (head == nullptr || head->next == nullptr) {
        cout << "Cannot delete middle element. List too short!" << endl;
        return;
    }

    Node *slow = head, *fast = head, *prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;  
        prev = slow;               
        slow = slow->next;         
    }

    if (prev != nullptr) {
        prev->next = slow->next;  
        delete slow;               
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void append(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

int main() {
    Node* head = nullptr;

   
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Original Linked List: ";
    printList(head);

    deleteMiddle(head);

    cout << "After Deleting Middle Element: ";
    printList(head);

    return 0;
}
