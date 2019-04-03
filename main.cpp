#include <iostream>

using namespace std;

class Data{
public:
    int num;
    Data(int num): num(num){}
};

class SharedPtr{
    Data* ptrD;
    int* counter;
    
public:
    SharedPtr() {
        cout << "call shrdptr default constructor" << endl;
        counter = NULL;
        ptrD = NULL;
    };
    
    SharedPtr(Data* newPtr): ptrD(newPtr){
        cout << "call shrdptr init constructor" << endl;
        counter = new int(1);
    }
    SharedPtr(SharedPtr const & newPtr): ptrD(newPtr.ptrD), counter(newPtr.counter){
        cout << "call shrdptr copy constructor" << endl;
        (*counter)++;
    }
    SharedPtr &operator= (SharedPtr & exPtr) {
        cout << "call shrdptr operator=" << endl;
        
        this->~SharedPtr();
        
        counter = exPtr.counter;
        ptrD = exPtr.ptrD;
        (*counter)++;
        
        return *this;
    }
    
    ~SharedPtr() {
        if (counter == NULL)
            return;
        
        cout << "call shrdptr destructor" << endl;
        
        
        (*counter)--;
        cout << "update counter:" << *counter<< endl;
        
        
        if((*counter)== 0){
            cout << "delete data" << endl;
            delete ptrD;
            delete counter;
        }
    }
};

int main() {
    
    {
        SharedPtr p1(new Data(1));
        SharedPtr p2(new Data(2));
        SharedPtr p3(p1);
        p2 = p1;
    }
    SharedPtr p3;
    
    
    
    
    
    return 0;
}
