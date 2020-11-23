#include <iostream>
using namespace std;

template <typename T>


class stack
{
public:
    int top;
    T *arr;
    size;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void isEmpty()
    {
        return size == top - 1;
    }
    void push(T data)
    {
        if (isEmpty())
        {
            printf("Stack overflow");
        }
        arr[++top] = data;
    }
    void pop(){
        if(!isEmpty())
            printf("Stack underflow");
        else{
            stop--;
        }   
    }
    T peek() {
        return arr[top];
    }

    void display(){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
    
};

int main()
{
    


}