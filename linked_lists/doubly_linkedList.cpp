#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
};

class LinkedList{
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }

    ~LinkedList(){
        while(head != NULL){
            deleteHead();
        }
    }

    bool isEmpty(){
        if (head == NULL){
            return true;
        }
        
        return false; 
    }

    void insertHead(int element){
        Node* node = new Node;
        node->data = element;
        node->next = head;
        node->prev = NULL;

        if (!isEmpty()){
            head->prev = node;
        }
        head = node;
        
    }

    void insertTail(int element){
        if (isEmpty()){
            insertHead(element);
            return;
        }

        Node* node = new Node;
        node->data = element;
        node->next = NULL;
        
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = node;
        node->prev = temp;
    }

    void insertBefore(int before, int element){
        if (isEmpty() || head->data == before){
            insertHead(element);
            return;
        }

        Node* node = new Node;
        node->data = element;

        Node* temp = head;
        while(temp->next != NULL && temp->next->data != before){
            temp = temp->next;
        }

        if (temp->next == NULL){
            cout << "Couldnt find." <<endl;
            delete node;
            return;
        }

        node->next = temp->next;
        node->prev = temp;
        temp->next->prev = node;
        temp->next = node;
        
    }

    void deleteHead(){
        if (isEmpty()){
            cout << "The list is empty." <<endl;
            return;
        }
        Node* delptr = head;
        head = head->next;
        
        if (!isEmpty()){
            head->prev = NULL;
        }

        delete delptr;
    }

    void deleteTail(){
        if (isEmpty()){
            cout << "The list is empty." <<endl;
            return;
        }

        if (head->next == NULL){
            deleteHead();
            return;
        }

        Node* temp = head;
        
        while(temp->next->next != NULL){
            temp = temp->next;
        }

        Node* delptr = temp->next;
        delete delptr;
        temp->next = NULL;

    }

    void deleteElement(int element){
        if (isEmpty()){
            cout << "The list is empty." <<endl;
            return;
        }

        if (head->data == element){
            deleteHead();
            return;
        }

        Node* temp = head;
        while(temp->next != NULL && temp->next->data != element){
            temp = temp->next;
        }

        if (temp->next == NULL){
            cout << "Couldnt find." <<endl;
            return;
        }

        Node* delptr = temp->next;
        temp->next = delptr->next;
        if (delptr->next != NULL){
            delptr->next->prev = temp;
        }
        delete delptr;
    }

    int count(){
        int counter = 0;
        Node* temp = head;

        while(temp != NULL){
            counter++;
            temp = temp->next;
        }

        return counter;
    }

    void search(int key){
        bool found = false;
        int counter = 0;
        
        Node* temp = head;
        while(temp != NULL){
            counter++;
            if (temp->data == key){
                found = true;
                cout << "Found it at node number " << counter <<endl;
            }
            temp = temp->next;
        }
        if (!found){
            cout << "Couldnt find." <<endl;
            return;
        }

    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    int element;
    int key;
    int before;
    LinkedList obj;

    while (true){
        int choice;
        char again;

        cout << "\n----- Linked List Operations -----" <<endl<<endl;
        cout << "1- Insert at Tail.      5- Delete Head.\n2- Insert Before.       6- Delete Tail.\n3- Insert At Head.      7- Delete specific element.\n4- Search.              8- Count.\n";
        cout << "Operation : ";
        cin >> choice;

        //! ----- PUSH BACK OPERATION -----
        if (choice == 1){
            cout << "Enter the element : ";
            cin >> element;
            obj.insertTail(element);
            cout << "...... List after inserting at tail ......"<<endl;
            obj.display();
        }
        //! ----- INSERTING BEFORE OPERATION -----
        else if (choice == 2){
            cout << "Before which element you wanna insrt your new element : ";
            cin >> before;
            cout << "Enter the element : ";
            cin >> element;
            obj.insertBefore(before,element);
            cout << "...... List after inserting before specific element ......"<<endl;
            obj.display();
        }
        //! ----- PUSH FRONT OPERATION -----
        else if (choice == 3){
            cout << "Enter the element : ";
            cin >> element;
            obj.insertHead(element);
            cout << "...... List after inserting at head ......"<<endl;
            obj.display();
        }
        //! ----- SEARCHING OPERATION -----
        else if (choice == 4){
            cout << "Enter the number you are searching for : ";
            cin >> key;
            obj.search(key);
        }
        //! ----- DELETING HEAD OPERATION -----
        else if (choice == 5){
            obj.deleteHead();

            if (!obj.isEmpty()){
                cout << "...... List after deleting the head ......"<<endl;
                obj.display();
            }
        }
        //! ----- DELETING TAIL OPERATION -----
        else if (choice == 6){
            obj.deleteTail();
            if (!obj.isEmpty()){
                cout << "...... List after deleting the tail ......"<<endl;
                obj.display();
            }
            
        }
        //! ----- DELETING SPECIFIC ELEMENT OPERATION -----
        else if (choice == 7){
            cout << "Enter the element you wanna delete : ";
            cin >> element;
            obj.deleteElement(element);
            if (!obj.isEmpty()){
                cout << "...... List after deleting the element ......"<<endl;
                obj.display();
            }
            
        }
        //! ----- COUNTING OPERATION -----
        else if (choice == 8){
           cout <<"The list has "<< obj.count() <<" nodes." << endl;
        }
        else{
            cout <<"Invalid choice. Please try again." <<endl;
        }

        //! ----- LOOP CONTROL -----
        cout << "You wanna keep going ? (y/n) : ";
        cin >> again;
        if (again == 'y' || again == 'Y'){
            continue;
        }
        else if (again == 'n' || again == 'N'){
            break;
        }
    }
    cout << "Have a nice day then ." << endl;

    return 0;
}