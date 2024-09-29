#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void displayList() {
        if (head == nullptr) {
            cout << "Linked list is empty." << endl;
            return;
        }

        Node* current = head;
        cout << "Linked list contains: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        
    }

    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            int currentPosition = 1;
            while (current != nullptr && currentPosition < position - 1) {
                current = current->next;
                currentPosition++;
            }

            if (current == nullptr) {
                cout << "Invalid position." << endl;
                return;
            }

            newNode->next = current->next;
            current->next = newNode;
        }

        cout << value << " inserted at position " << position << " in the linked list." << endl;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "Linked list is empty. Nothing to delete." << endl;
            return;
        }

        if (position <= 0) {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node at position 1 deleted." << endl;
            return;
        }

        Node* current = head;
        int currentPosition = 1;
        while (current != nullptr && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr || current->next == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Node at position " << position << " deleted." << endl;
    }
};

int main() {
    LinkedList linkedList{};
    int choice, value, position;

    do {
        cout << "1.List all data in the Linked List" << endl;
        cout << "2.Add data into the end of the Linked List" << endl;
        cout << "3.Insert data into specific location of the Linked List" << endl;
        cout << "4.Delete data of specific location of the Linked List" << endl;
        cout << "5.End program" << endl;
        cout << "Enter your choice :";
        cin >> choice;
        switch (choice) {
        case 1:
            linkedList.displayList();
            break;
        case 2:
            cout << "Please input the data that you want to add into the Linked List:";
            cin >> value;
            linkedList.insertAtEnd(value);
            linkedList.displayList(); 
            break;
        case 3:
            cout << "Please input the data and the location that you want to insert into the Linked List:";
            cin >> value >> position;
            linkedList.insertAtPosition(value, position);
            linkedList.displayList();
            break;
        case 4:
            cout << "Please input the location of the data that you want to delete from the Linked List: ";
            cin >> position;
            linkedList.deleteAtPosition(position);
            linkedList.displayList();
            break;
        case 5:
            cout << "Bye!." << endl;

            break;
        default:
            cout << "error" << endl;
        }

        cout << endl;
    } while (choice != 5);
}