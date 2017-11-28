#include <iostream>
using namespace std;

class ArrayList{
private:
    const int ARRAY_SIZE = 10;

    int* array;
    int currentSize;
    int allocatedSize;
    int size = ARRAY_SIZE;

    void fillNewArray(int* newArray){
        for(int i = 0; i < currentSize; i++){
            newArray[i] = array[i];
        }
    }
    void addToNotFullArray(int n){
        array[currentSize] = n;
        currentSize++;
    }
    void addToFullArray(int n){
        int* newArray = new int[allocatedSize * 2];
        allocatedSize *= 2;
        fillNewArray(newArray);
        delete []array;
        array = newArray;
        addToNotFullArray(n);
    }

public:
    ArrayList(){
        array = new int [ARRAY_SIZE];
        currentSize = 0;
        allocatedSize = ARRAY_SIZE;
    }

    //madding new element by value
    void add(int n){
        if (currentSize < allocatedSize){
            addToNotFullArray(n);
        } else{
            addToFullArray(n);
        }
    }

    //madding new element by index
    void add (int valueForAdd, int index){
        if (index >= currentSize){
            cout<<"you went beyond the array"<<endl;
            return;
        }
          if (currentSize >= allocatedSize) {
            int* newArray = new int (allocatedSize  *2);
            allocatedSize *= 2;
            fillNewArray(newArray);
            delete []array;
            array = newArray;
        }

        //shift array
        for (int i = currentSize; i > index; i--) {
            array[i] = array[i-1];
        }
        array[index] = valueForAdd;
        currentSize++;
    }
    //trim array size
    void trimToSize(){

        int* tmpArray = new int[currentSize];
        for(int i = 0; i < currentSize; i++){
            tmpArray[i] = array[i];
        }
        delete[] array;
        array = new int[currentSize];
        for(int i = 0; i < currentSize; i++){
            array[i] = tmpArray[i];
        }
        delete []tmpArray;
    }
     int get(int index){

        if (index >= currentSize){
            cout<<"Error!!! Index is out"<<endl;
            return -1;
        }
        return array[index];
    }

    //removing array elements
    void remove(int index){

        for (int i = 0; i < currentSize; i++){
            if (array[i] == index)
            {
                for (int i = 0; i < currentSize - 1; i++){
                    // assign the next element to current location.
                    array[i] = array[i + 1];
                }
                 // remove the last element as it has been moved to previous index.
                array[currentSize - 1] = 0;
                currentSize = currentSize - 1;
            }
        }
    }

    //print array
    void print(){
        for (int i = 0; i < currentSize; i++){
            cout<<array[i]<<" ";
        }
    }
};

int main(){
 ArrayList* list = new ArrayList();
    for (int i = 0; i < 10; i++){
        list->add(i);
    }
    list->print();
    cout<<endl;
    list->remove(3);
    list->print();
    list->trimToSize();
    list->add(19, 2);
    cout<<endl;
    list->print();
    cin.get(); return 0;
}
