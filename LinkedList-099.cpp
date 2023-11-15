//adding header files 
#include <iostream>
using namespace std;

// Node class to create nodes for the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// LinkedList class to perform operations on the linked list
class LinkedList {
private:
    Node* head; // Points to the head of the linked list
public:
    // Constructor to initialize an empty linked list
    LinkedList() {
        head = NULL;
    }

    // Function to insert a node at the beginning of the list
    void insertAtStart(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a node at a specific position in the list
    void insertAtPoint(int position, int data) {
        if (position == 0) {
            insertAtStart(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* current = head;
        for (int i = 0; i < position - 1; ++i) {
            if (current == NULL) {
                cout << "Position out of bounds." << endl;
                return;
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to delete a node from the beginning of the list
    void deleteFromStart() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from beginning." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete a node from the end of the list
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from end." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    }

    // Function to delete a node from a specific position in the list
    void deleteAtPoint(int position) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from position." << endl;
            return;
        }
        if (position == 0) {
            deleteFromStart();
            return;
        }
        Node* current = head;
        for (int i = 0; i < position - 1; ++i) {
            if (current == NULL || current->next == NULL) {
                cout << "Position out of bounds." << endl;
                return;
            }
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Function to search for a specific data and update it
    void searchAndUpdate(int searchData, int newData) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == searchData) {
                current->data = newData;
                cout << "Data updated successfully." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data not found." << endl;
    }

    // Function to search for a specific data in the list
    bool search(int searchData) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == searchData) {
                cout << "Data found in the list." << endl;
                return true;
            }
            current = current->next;
        }
        cout << "Data not found in the list." << endl;
        return false;
    }

    // Function to display the elements of the list
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Main function to test the LinkedList operations
int main() {
    int n1, n2, n3, n5, n6, n7, n8, opp, num;
    num = 1;
    LinkedList List;

    // Adding initial elements to the list
    List.insertAtStart(20);
    List.insertAtStart(30);
    List.insertAtStart(40);
    List.insertAtStart(60);
    List.insertAtStart(70);
    cout << "Original List: ";
    List.display();

    // Menu-driven loop to perform various operations on the list
    while (num <= 3) {
        cout << "1 To perform insert operations :" << endl;
        cout << "2 To perform delete operations :" << endl;
        cout << "3 To search and update:" << endl;
        cout << "4 To display:" << endl;
        cout << "5 To search element:" << endl;
        cout << "6 Exit:" << endl;
        cout << "Enter option :" << endl;
        cin >> opp;
// using switch statement 
        switch (opp) {
            case 1: {
                cout << "Enter Position to insert data " << endl;
                cin >> n1;
                cout << "Enter data to insert at position " << endl;
                cin >> n2;
                List.insertAtPoint(n1, n2);
                cout << "List after inserting at position " << ": ";
                List.display();
                cout << "Enter data to insert at start " << endl;
                cin >> n3;
                List.insertAtStart(n3);
                List.display();
                break;
            }
            case 2: {
                List.deleteFromStart();
                cout << "List after deleting from beginning: ";
                List.display();
                List.deleteFromEnd();
                cout << "List after deleting from end: ";
                List.display();
                cout << "Enter Position to Delete data " << endl;
                cin >> n5;
                List.deleteAtPoint(n5);
                cout << "List after deleting from position 1: ";
                List.display();
                break;
            }
            case 3: {
                cout << "Enter number to search " << endl;
                cin >> n6;
                cout << "Enter number to update " << endl;
                cin >> n7;
                List.searchAndUpdate(n6, n7);
                cout << "List after searching and updating " << " to " << endl;
                List.display();
                break;
            }
            case 4: {
                cout << "Display Of Final linklist:" << endl;
                List.display();
                break;
            }
            case 5: {
                cout << "Enter number to search: ";
                cin >> n8;
                List.search(n8);
                break;
            }
            case 6: {
                cout << "Exit";
                break;
            }
        }
        num++;
    }
    return 0;
}