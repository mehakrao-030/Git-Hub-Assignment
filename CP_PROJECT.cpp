#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;;
    return newNode;
}

void insert_begin(Node*& head, int d) {
    Node* newNode = createNode(d);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << d << " at the beginning." << endl;
}

void insert_end(Node*& head, int d) {
    Node* newNode = createNode(d);
    if (head == nullptr) {
        head = newNode;
        cout << "Inserted " << d << " at the end (list was empty)." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    cout << "Inserted " << d << " at the end." << endl;
}

void delete_begin(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted " << temp->data << " from the beginning." << endl;
    delete temp;
}

void delete_end(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted " << head->data << " from the end." << endl;
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    cout << "Deleted " << temp->next->data << " from the end." << endl;
    delete temp->next;
    temp->next = nullptr;
}

void delete_data(Node*& head, int d) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == d) {
        delete_begin(head);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != d)
        temp = temp->next;
    if (temp->next == nullptr) {
        cout << "Value " << d << " not found." << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    cout << "Deleted node with value " << d << "." << endl;
    delete nodeToDelete;
}

void traverse(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << " -> nullptr" << endl;
}

Node* search(Node* head, int d) {
    Node* temp = head;
    int position = 1;
    while (temp != nullptr) {
        if (temp->data == d) {
            cout << "Value " << d << " found at position " << position << "." << endl;
            return temp;
        }
        temp = temp->next;
        position++;
    }
    cout << "Value " << d << " not found." << endl;
    return nullptr;
}

void reverseList(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        cout << "Nothing to reverse." << endl;
        return;
    }
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
    cout << "List has been reversed." << endl;
}

int listSize(Node* head) {
    int count = 0;
    for (Node* temp = head; temp != nullptr; temp = temp->next)
        count++;
    return count;
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

void printMenu() {
    cout << "\n===== LINKED LIST MENU =====\n";
    cout << " 1.  Insert at Beginning\n";
    cout << " 2.  Insert at End\n";
    cout << " 3.  Delete from Beginning\n";
    cout << " 4.  Delete from End\n";
    cout << " 5.  Delete by Value\n";
    cout << " 6.  Traverse / Display\n";
    cout << " 7.  Search\n";
    cout << " 8.  Reverse List\n";
    cout << " 9.  List Size\n";
    cout << " 10. Exit\n";
    cout << "=============================\nEnter your choice: ";
}

int main() {
    Node* head = nullptr;
    int choice, value;
    cout << "Welcome to the Linked List Management Program (CS1410 Project)\n";

    do {
        printMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Value: "; cin >> value;
                insert_begin(head, value);
                break;
            case 2:
                cout << "Value: "; cin >> value;
                insert_end(head, value);
                break;
            case 3:
                delete_begin(head);
                break;
            case 4:
                delete_end(head);
                break;
            case 5:
                cout << "Value: "; cin >> value;
                delete_data(head, value);
                break;
            case 6:
                traverse(head);
                break;
            case 7:
                cout << "Value: "; cin >> value;
                search(head, value);
                break;
            case 8:
                reverseList(head);
                traverse(head);
                break;
            case 9:
                cout << "Size: " << listSize(head) << " element(s)." << endl;
                break;
            case 10:
                cout << "Exiting. Freeing memory...\n";
                freeList(head);
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 10);

    return 0;
}
