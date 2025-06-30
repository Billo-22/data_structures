#include <iostream>
using namespace std;

class Node {
public:    
    int data;
    Node* next;
};

class LinkedList {

    
public:
    Node* head;

    LinkedList() {           
        head = NULL;
    }

    void pushFront(int element) {         
        Node* node = new Node;
        node->data = element;
        node->next = head;
        head = node;

    }

    void pushBack(int element){                              //? Insert at Tail
        if (head == NULL){
            pushFront(element);
            return;
        }
        Node* node = new Node;
        node->data = element;

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
        node->next = NULL;
    }

    void insertBefore(int before,int element) {
        if (!search(before)){
            cout <<"Couldnt find"<<endl;
            return;
        }

        if (head == NULL || head->data == before){
            pushFront(element);
            return;
        }

        Node* node = new Node;
        node->data = element;

        Node* temp = head;
        while(temp != NULL && temp->next->data != before){
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL){
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << endl;
    }

    int count(){
        Node* temp = head;
        int counter = 0;
        
        while (temp != NULL){
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool search(int key) {
        Node* temp = head;
        int counter = 0;
        bool found = false;

        while (temp != NULL){
            if(temp->data == key){
                counter++;
                found = true;
                cout <<"found it at node number "<< counter <<endl;
            }
            temp = temp->next;
            counter++;
        }
        if (!found){
            cout <<"Couldnt find"<<endl;
        }

        return found;
    }
};

int main (){
    int element;
    int key;
    int before;
    LinkedList obj;


    while (true){
        int choice;
        char again;

        
        cout << "\n----- Dynamic Array Operations -----" <<endl<<endl;
        cout << "1- Insert at Tail.      5- Delete Head.\n2- Insert Before.       6- Delete Tail.\n3- Insert At Head.      7- Delete specific element.\n4- Search.              8- Count.\n";
        cout << "Operation : ";
        cin >> choice;

        //! ----- PUSH BACK OPERATION -----
        if (choice == 1){
            cout << "Enter the element : ";
            cin >> element;
            obj.pushBack(element);
            cout << "...... List after inserting at tail ......"<<endl;
            obj.display();
        }
        //! ----- INSERTING BEFORE OPERATION -----
        else if (choice == 2){
            cout << "Before which node you wanna insrt your element : ";
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
            obj.pushFront(element);
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
            cout << obj.count();
        }
        //! ----- DELETING TAIL OPERATION -----
        else if (choice == 6){
            
        }
        //! ----- DELETING SPECIFIC ELEMENT OPERATION -----
        else if (choice == 7){
            
        }
        //! ----- COUNTING OPERATION -----
        else if (choice == 8){
            obj.count();
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
    cout << "Have a nice day then .";

    
    return 0;
}