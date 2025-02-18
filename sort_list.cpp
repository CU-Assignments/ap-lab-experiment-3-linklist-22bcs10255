#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

Node* split(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* middle = slow->next;
    slow->next = nullptr;
    return middle;
}

Node* merge(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* result = new Node(0);
    Node* current = result;

    while (left != nullptr && right != nullptr) {
        if (left->data <= right->data) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    if (left != nullptr) current->next = left;
    if (right != nullptr) current->next = right;

    Node* head = result->next;
    delete result; 
    return head;
}

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    
    Node* middle = split(head);
   
    Node* left = mergeSort(head);
    Node* right = mergeSort(middle);

    // Merge the two sorted halves
    return merge(left, right);
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

    append(head, 40);
    append(head, 10);
    append(head, 30);
    append(head, 20);
    append(head, 50);

    cout << "Original Linked List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}
