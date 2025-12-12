#include <iostream>
using namespace std;

class ArrayStack {
private:
    int *arr;
    int top;
    int size;

public:
    ArrayStack(int size) {
        arr=new int[size];
        top = -1;
        this->size=size;
        
    }
    
    void push(int x) {
        if(top < size - 1){
            top++;
            arr[top]=x;
        }
        else{
            cout<<"Stackoverflow"<<endl;
        }
   
    }
    
    int pop() {
        if(top>=0){
            int val = arr[top];
            top--;
            return val;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
        
  
    }
    
    int top() {
        if(top>=0){
            return arr[top];
        }
        else{
            return -1;
        }
    
    }
    
    bool isEmpty() {
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
  
    }
};