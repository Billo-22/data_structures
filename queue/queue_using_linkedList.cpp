#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
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

        if (isEmpty()){
            front = rear = node;
        }

        else{
            rear->next = node;
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
        delete delptr;
    }

    int peek(){
        if (isEmpty()){
            cout <<"The Queue is empty."<<endl;
            return -1;
        }

        return front->data;
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
        cout << "1- Inserting at Rear.     4- Search.\n2- Delete Front.           5- Count.\n3- Current Front.          6- Clear The Queue.\n\n";
        cout << "Operation : ";
        cin >> choice;

        //! ----- INSERTIN AT REAR OPERATION -----
        if (choice == 1){
            cout << "Enter the element : ";
            cin >> element;
            obj.enqueue(element);
            cout << "...... Queue after inserting at the rear ......"<<endl;
            obj.display();
        }

        //! ----- DELETING FRONT OPERATION -----
        else if (choice == 2){
            obj.dequeue();

            if (!obj.isEmpty()){
                cout << "...... Queue after deleting front ......"<<endl;
                obj.display();
            }
        }

        //! ----- PEEK OPERATION -----
        else if (choice == 3){
            if (!obj.isEmpty()){
                cout << "The current front elemnt is "<< obj.peek() <<endl;
            }
            else {
                cout << "The Queue is empty."<<endl;
            }
        }

        //! ----- SEARCHING OPERATION -----
        else if (choice == 4){
            cout << "Enter the number you are searching for : ";
            cin >> key;
            obj.search(key);
        }
        
        //! ----- COUNTING OPERATION -----
        else if (choice == 5){
           cout <<"The Queue has "<< obj.count() <<" elements." << endl;
        }

        //! ----- CLEARING OPERATION -----
        else if (choice == 6){
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