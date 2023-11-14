#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value)
	{
        data = value;
        next = NULL;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList()
	{
        head = NULL;
    }
    void insertAtStart(int data)
	{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtPoint(int position, int data)
	{
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
    void deleteFromStart()
	{
        if (head == NULL) {
            cout << "List is empty. Cannot delete from beginning." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteFromEnd()
	{
        if (head == NULL)
		{
            cout << "List is empty. Cannot delete from end." << endl;
            return;
        }
        if (head->next == NULL)
		{
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        while (current->next->next != NULL)
		{
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    }
    void deleteAtPoint(int position)
	{
        if (head == NULL)
		{
            cout << "List is empty. Cannot delete from position." << endl;
            return;
        }
        if (position == 0)
		{
            deleteFromStart();
            return;
        }
        Node* current = head;
        for (int i = 0; i < position - 1; ++i)
		{
            if (current == NULL || current->next == NULL)
			{
                cout << "Position out of bounds." << endl;
                return;
            }
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    void searchAndUpdate(int searchData, int newData)
	{
        Node* current = head;
        while (current != NULL)
		{
            if (current->data == searchData)
			{
                current->data = newData;
                cout << "Data updated successfully." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data not found." << endl;
    }
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
    void display()
	{
        Node* current = head;
        while (current != NULL)
		{
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
	int n1,n2,n3,n5,n6,n7,n8,opp,num;
    num=1;
    LinkedList List;
    List.insertAtStart(20);
    List.insertAtStart(30);
    List.insertAtStart(40);
    List.insertAtStart(60);
    List.insertAtStart(70);
    cout << "Original List: ";
    List.display();
    while(num<=3)
    {
    cout<<"1 To Insert at start , end and at point:"<<endl;
    cout<<"2 To delete at start ,end and at point:"<<endl;
    cout<<"3 To search and update:"<<endl;
    cout<<"4 To display:"<<endl;
    cout<<"5 To search element:"<<endl;
    cout<<"6 Exit:"<<endl;
    cout<<"Enter option :"<<endl;
    cin>>opp;
    switch(opp)
    {
    case 1:
    {
    cout<<"Enter Position to insert data "<<endl;
    cin>>n1;
    cout<<"Enter data to insert at position "<<endl;
    cin>>n2;
    List.insertAtPoint(n1,n2);
    cout << "List after inserting at position "<<": ";
    List.display();
    cout<<"Enter data to insert at start "<<endl;
    cin>>n3;
    List.insertAtStart(n3);
    List.display();
    break;}
    case 2:
    {
    List.deleteFromStart();
    cout << "List after deleting from beginning: ";
    List.display();
    List.deleteFromEnd();
    cout << "List after deleting from end: ";
    List.display();
    cout<<"Enter Position to Delete data "<<endl;
    cin>>n5;
    List.deleteAtPoint(n5);
    cout << "List after deleting from position 1: ";
    List.display();
    break;}
    case 3:
    {
    cout<<"Enter number to search "<<endl;
    cin>>n6;
    cout<<"Enter number to update "<<endl;
    cin>>n7;
    List.searchAndUpdate(n6,n7);
    cout << "List after searching and updating "<<" to "<<endl;
    List.display();
    break;}
    case 4:
    {
    cout<<"Display Of Final linklist:"<<endl;
    List.display();
    break;}
    case 5:
{
    cout << "Enter number to search: ";
    cin >> n8;
    List.search(n8);
    break;
}
case 6:
    {
    cout<<"Exit";
    break;}
    }
    num++;}
    return 0;
}