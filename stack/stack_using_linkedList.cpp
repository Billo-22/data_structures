#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Stack{
    Node* top;
public:
    Stack(){
        top = NULL;
    }
    ~Stack(){
        while (top != NULL){
            pop();
        }
    }

    bool isEmpty(){
        if (top == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int element){
        Node* node = new Node;
        node->data = element;
        node->next = top;
        top = node;
    }

    void pop(){

        if (isEmpty()){
            cout <<"The stack is empty."<<endl;
            return;
        }

        Node* delptr = top;
        top = top->next;
        delete delptr;
    }

    int peek(){
        if (isEmpty()){
            cout << "The stack is empty."<<endl;
            return -1;
        }
        return top->data;
    }

    int count(){
        Node* temp = top;
        int counter = 0;

        while (temp != NULL){
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    void search(int element){
        Node* temp = top;
        bool found = false;
        int counter = 0;

        while (temp != NULL){
            counter++;
            if (temp->data == element){
                found = true;
                cout <<"Found it at posistion number "<< counter <<endl;
            }
            
            temp = temp->next;
        }

        if (!found){
            cout <<"couldnt find." <<endl;
        }
    }

    void display(){
        Node* temp = top;
        while (temp != NULL){
            cout << temp->data <<endl;
            temp = temp->next;
        }
        cout << endl;
    }

};

int main(){
    int element;
    int key;

    Stack obj;
    while (true){
        int choice;
        char again;

        cout << "\n----- Stack Operations Using Linked List  -----" <<endl<<endl;
        cout << "1- Inserting at Top.     4- Search.\n2- Delete Top.           5- Count.\n3- Current Top.\n\n";
        cout << "Operation : ";
        cin >> choice;

        //! ----- INSERTIN AT TOP OPERATION -----
        if (choice == 1){
            cout << "Enter the element : ";
            cin >> element;
            obj.push(element);
            cout << "...... Stack after inserting at the top ......"<<endl;
            obj.display();
        }

        //! ----- DELETING TOP OPERATION -----
        else if (choice == 2){
            obj.pop();

            if (!obj.isEmpty()){
                cout << "...... Stack after deleting the top ......"<<endl;
                obj.display();
            }
        }

        //! ----- PEEK OPERATION -----
        else if (choice == 3){
            if (!obj.isEmpty()){
                cout << "The current Top elemnt is "<< obj.peek() <<endl;
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
           cout <<"The stack has "<< obj.count() <<" elements." << endl;
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