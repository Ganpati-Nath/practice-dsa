#include <iostream>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int val;
    Node* next;
};

// Function to insert a node at the end of the linked list
void insert_end(Node** head, int value) {
    Node* newNode = new Node();
    newNode->val = value;
    newNode->next = nullptr;
    if (*head == nullptr) { // If the list is empty
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete the last node in the linked list
void delete_last(Node** head) {
    if (*head == nullptr) {
        // If the list is empty, nothing to delete
        return;
    }
    if ((*head)->next == nullptr) {
        // If there's only one node, delete it and set head to null
        delete *head;
        *head = nullptr;
        return;
    }
    // Traverse to the second last node
    Node* temp = *head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next; // Delete the last node
    temp->next = nullptr;
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    int n;
    cin >> n; // Input the size of the list
    Node* myList = nullptr; // Initialize the linked list
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value; // Input list elements
        insert_end(&myList, value);
    }
    delete_last(&myList); // Delete the last node
    print(myList); // Print the modified list
    return 0;
}