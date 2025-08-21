#include <iostream>
using namespace std;

class Stack{
protected:
    int size;
    int top;
public:
    int *stack;
 
    Stack (int stackSize){
        size = stackSize;
        top = -1;
        stack = new int[stackSize];
    }
    //! Destructor : Frees the dynamically allocated memory for the array to prevent memory leaks when the object is destroyed.
    ~Stack(){
        delete[] stack;
    }

    bool isEmpty(){
        if (top < 0){
            return true;
        }
        
        return false;
    }

    bool isFull(){
        if (top >= size-1){
            return true;
        }

        return false;
    }

    void push(int element){
        if (isFull()){
            cout << "Stack overflow" <<endl;
            return;
        }

        top++;
        stack[top] = element;
    }

    void pop(){
        if (isEmpty()){
            cout << "The Stack is empty." <<endl;
            return;
        }

        top--;
    }

    int peek(){
        if (isEmpty()){
            cout << "The Stack is empty." <<endl;
            return -1;
        }

        return stack[top];
    }

    int count(){
        return top+1;
    }

    void search(int key){
        int counter = 0;
        bool found = false;

        for(int i=top; i>=0; i--){
            counter++;
            if (stack[i] == key){
                found = true;
                cout << "Found it at position number : " << counter <<endl;
                
            }
        }

        if (!found){
            cout << "Couldnt find." <<endl;
        }
    }

    void display(){
        for(int i=top; i>=0; i--){
            cout << stack[i] <<endl;
        }
    }


};

int main(){
    int element;
    int size;
    int key;

    cout <<"Enter the Stack's size : ";
    cin >> size;
    Stack obj(size);

    while (true){
        int choice;
        char again;

        cout << "\n----- Stack Operations Using Array  -----" <<endl<<endl;
        cout << "1- Inserting at Top.     4- Search.\n2- Delete Top.           5- Count.\n3- Current Top.\n\n";
        cout << "Operation : ";
        cin >> choice;

        //! ----- INSERTIN AT TOP OPERATION -----
        if (choice == 1){
            cout << "Enter the element : ";
            cin >> element;
            obj.push(element);
            if (!obj.isFull()){
                cout << "...... Stack after inserting at the top ......"<<endl;
                obj.display();
            }
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

            else {
                cout << "The stack is empty."<<endl;
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