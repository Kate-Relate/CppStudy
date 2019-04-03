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
    SharedPtr(Data* newPtr): ptrD(newPtr){
        counter = new int{1};
    }
    SharedPtr(SharedPtr const & newPtr): ptrD(newPtr.ptrD), counter(newPtr.counter){
        (*counter)++;
    }
    SharedPtr &operator= (SharedPtr const & exPtr){
        this->ptrD = exPtr.ptrD;
        this->counter = exPtr.counter;
        (*counter)++;
        return *this;
    }
    ~SharedPtr(){
        if((*counter)== 1){
            free(ptrD);
            delete(counter);
        } else (*counter)--;
    }
};

int main() {


    Data newD(3);
    SharedPtr p1(&newD);
    Data newD2(2);
    SharedPtr p2(&newD2);
    p2 = p1;
    Data newD4(4);
    SharedPtr p3(&newD4);






    return 0;
}