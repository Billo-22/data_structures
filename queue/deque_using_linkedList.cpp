#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
};

class Queue{
    Node* front;
    Node* rear;
public:
   
    Queue(){
        front = rear = NULL;
    }
     
    ~Queue(){
        while(front != NULL){
            dequeue();
        }
    }

    bool isEmpty(){
        if (front == NULL){
            return true;
        }
    
        return false;
    }

    void enqueue(int element){
        Node* node = new Node;
        node->data = element; 
        node->next = NULL;
        node->prev = NULL;

        if (isEmpty()){
            front = rear = node;
        }

        else{
            rear->next = node;
            node->prev = rear;
            rear = node;
        }
    }  

    void dequeue(){
        if (isEmpty()){
            cout <<"The Queue is empty."<<endl;
            return;
        }

        Node* delptr = front;
        front = front->next;

        if (!isEmpty()){
            front->prev = NULL;
        }

        delete delptr;
    }

    void pushFront(int element){
        Node* node = new Node;
        node->data = element;
        node->next = front;
        node->prev = NULL;

        if (!isEmpty()){
            front->prev = node;
        }

        front = node;
    }

    void popRear(){
        if (isEmpty()){
            cout << "The queue is empty." <<endl;
            return;
        }
        Node* delptr = rear;
        rear = rear->prev;
        rear->next = NULL;

        delete delptr;
    }

    int peekFront(){
        if (isEmpty()){
            cout <<"The Queue is empty."<<endl;
            return -1;
        }

        return front->data;
    }

    int peekRear(){
        if (isEmpty()){
            cout <<"The Queue is empty."<<endl;
            return -1;
        }

        return rear->data;
    }

    int count(){
        Node* temp = front;
        int counter = 0;

        while(temp != NULL){
            counter++;
            temp = temp->next;
        }

        return counter;
    }

    void search(int key){
        Node* temp = front;
        bool found = false;
        int counter = 1;
        
        while(temp != NULL){
            if (temp->data == key){
                cout << "Found it at position number "<< counter <<endl;
                found = true;
            }
            temp = temp->next;
            counter++;
        }
        if (!found){
            cout <<"Couldnt find."<<endl;
        }
    }
    
    void clear(){
        while(front != NULL){
            dequeue();
        }
    }

    void display(){
        Node* temp = front;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    int element;
    int key;
    Queue obj;

    while (true){
        int choice;
        char again;

        cout << "\n----- Queue Using Linked List Operations -----" <<endl<<endl;
        cout << "1- Inserting at Rear.     4- Delete Rear.     7- Search.\n2- Insert at Front.       5- Current Front.   8- Count.\n3- Delete Front.          6- Current Rear.    9- Clear the Queue.\n\n";
        cout << "Operation : ";
        cin >> choice;

        //! ----- INSERTIN AT REAR OPERATION -----
        if (choice == 1){
            cout << "Enter the element : ";
            cin >> element;
            obj.enqueue(element);
            cout << "...... Queue after inserting at rear ......"<<endl;
            obj.display();
        }

        //! ----- INSERTING AT FRONT OPERATION -----
        else if (choice == 2){
            cout << "Enter the element : ";
            cin >> element;
            obj.pushFront(element);
            cout << "...... Queue after inserting at front ......"<<endl;
            obj.display();
        }

        

        //! ----- DELETING FRONT OPERATION -----
        else if (choice == 3){
            obj.dequeue();

            if (!obj.isEmpty()){
                cout << "...... Queue after deleting the front ......"<<endl;
                obj.display();
            }
        }

        //! ----- DELETING REAR OPERATION -----
        else if (choice == 4){
            obj.popRear();

            if (!obj.isEmpty()){
                    cout << "...... Queue after deleting the rear ......"<<endl;
                    obj.display();
                }
        }

        //! ----- PEEK FRONT OPERATION -----
        else if (choice == 5){
            if (!obj.isEmpty()){
                cout << "The current Front elemnt is "<< obj.peekFront() <<endl;
            }
            else {
                cout << "The Queue is empty."<<endl;
            }
        }

        //! ----- PEEK REAR OPERATION -----
        else if (choice == 6){
            if (!obj.isEmpty()){
                cout << "The current Rear elemnt is "<< obj.peekRear() <<endl;
            }
            else {
                cout << "The Queue is empty."<<endl;
            }
        }

        //! ----- SEARCHING OPERATION -----
        else if (choice == 7){
            cout << "Enter the number you are searching for : ";
            cin >> key;
            obj.search(key);
        }
        
        //! ----- COUNTING OPERATION -----
        else if (choice == 8){
           cout <<"The Queue has "<< obj.count() <<" elements." << endl;
        }

        //! ----- CLEARING OPERATION -----
        else if (choice == 9){
            obj.clear();
            cout <<"The Queue has been cleared." << endl;
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
    
    return 0;
}