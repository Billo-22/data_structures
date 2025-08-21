#include <iostream>
using namespace std;

class Array{
protected:
    int size;
    int length;

public:
    int *array;
 
    Array (int arrSize){
        size = arrSize;
        length = 0;
        array = new int[arrSize];
    }
    //! Destructor : Frees the dynamically allocated memory for the array to prevent memory leaks when the object is destroyed.
    ~Array(){
        delete[] array;
    }
    void fill(){
        int numberofElements;
        cout << "Enter the array length : ";
        cin >> numberofElements;

        if (numberofElements > size){
            cout << "The array length exceeds the maximum size";
            return;
        }
        else{
            for (int i=0; i<numberofElements; i++){
                cout << i+1 << ". Element : ";
                cin >> array[i];
                length++;
            }
        }
    }
    void display(){
        for (int i=0; i<length; i++){
            cout << array[i] << " ";
        }
        cout << endl << endl;
    } 

    int getLength(){
        return length;
    }

    int getSize(){
        return size;
    }
    void search(int key){
        bool found = false;
        for (int i=0; i<length; i++){
            if (array[i] == key){
                cout << "found at position " << i+1 <<" (index : "<< i <<")" <<endl;
                found = true;
                break;
            }
        }
        if (!found){
            cout << "Couldnt find" << endl;
        }
    }

    void append(int newElement){
        if (length > size){
            cout << "The array length exceeds the maximum size" << endl;
            return;
        }
        else{
            array[length] = newElement;
            length++;
        }
    }

    void insert(int index, int newElement) {
        if (index > length){
            cout << "Oops! The index you entered doesnt exist." << endl;
            return;
        }
        else{
            for (int i=length; i>index; i--){
                array[i] = array[i-1];
            }
            array[index] = newElement;
            length++;
        }
    }
    void deleting(int index){
        index--;
        if ( index > length){
            cout << "Oops! The index you entered doesnt exist." << endl;
            return;
        }
        for (int i=index; i<length; i++){
            array[i] = array[i+1];
        }
        length--;
    }
    void enlarge(int newSize){
        if (newSize <= size) {
            cout << "The new size must be larger then the old one.";
            return;
        }
        else{
            size = newSize;
            int *temp = array;
            array = new int[newSize];

            for (int i=0; i<size; i++){
                array[i] = temp[i];
            }
            delete[]temp;
        }
    }
    void merge(Array other){
        int newSize = size+other.getSize();
        size = newSize;
        int *temp = array;
        array = new int[newSize];
        int i;

        for (i=0; i<length; i++){
            array[i] = temp[i];
        }
        delete []temp;
        int j=i;

        for (i=0; i<other.getLength(); i++){
            if (j < size){
                array[j++] = other.array[i];
            }
        }
        
        length = j;
    }
};

int main(){

    int arrSize;
    int key;
    int newElement;
    int index;
    int newSize;

    cout << "Enter the array size : ";
    cin >> arrSize;
    Array obj(arrSize);
    obj.fill();

    while(true){
        int choice;
        char again;

        cout << "\n----- Dynamic Array Operations -----" <<endl<<endl;
        cout << "1- Append.      5- Enlarge.\n2- Insert.      6- Merge.\n3- Delete.      7- Get Size.\n4- Search.      8- Get Length.\n";
        cout << "Operation : ";
        cin >> choice;

        //! ----- APPENDING OPERATION -----
        if (choice == 1){
            cout << "Enter the new element :";
            cin >> newElement;
            obj.append(newElement);
            cout << "...... Array after appending ......"<<endl;
            obj.display();
        }
        //! ----- INSERTING OPERATION -----
        else if (choice == 2){
            cout << "Which index do you wanna insert at : ";
            cin >> index;
            cout << "Enter the new element : ";
            cin >> newElement;
            obj.insert(index,newElement);
            cout << "...... Array after inserting ......"<<endl;
            obj.display();
        }
        //! ----- DELETING OPERATION -----
        else if (choice == 3){
            cout << "Enter the index you wanna delete : ";
            cin >> index;
            obj.deleting(index);
            cout << "...... Array after deleting ......"<<endl;
            obj.display();
        }
        //! ----- SEARCHING OPERATION -----
        else if (choice == 4){
            cout << "Enter the number you are searching for : ";
            cin >> key;
            obj.search(key);
        }
        //! ----- ENLARGING OPERATION -----
        else if (choice == 5){
            cout << "Your array's current size is : "<<obj.getSize()<<endl;
            cout << "Enter the new size : ";
            cin >> newSize;
            obj.enlarge(newSize);
            cout << "Your array's size now is : "<<obj.getSize()<<endl;

        }
        //! ----- MERGING OPERATION -----
        else if (choice == 6){
            cout << "Enter the second array's size : ";
            cin >> arrSize;
            Array other(arrSize);
            other.fill();
            obj.merge(other);
            cout << "...... Array after merging ......"<<endl;
            obj.display();
        }
        //! ----- GET SIZE OPERATION -----
        else if (choice == 7){
            cout << "Your array's current size is : "<< obj.getSize() <<endl;
        }
        //! ----- GET LENGTH OPERATION -----
        else if (choice == 8){
            cout << "Your array's current length is : "<< obj.getLength() <<endl;
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