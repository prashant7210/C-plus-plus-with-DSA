#include <iostream>
using namespace std;

class Stack{
    int capacity;
    int* arr;
    int top;
    public:
    Stack(int c){
        this->capacity=c;
        arr=new int[c];
        this->top=-1;
    }
    void push(int data){
        // Overflow
        if(this->top==this->capacity-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        this->top++;
        this->arr[this->top]=data;
    }
    void pop(){
        // Underflow
        if(this->top==-1){
            cout<<"Underflow"<<endl;
            return;
        }
        this->top--;
    }
    int getTop(){
        // If no element present in stack i.e, Underflow
        if(this->top==-1){
            cout<<"Underflow ";
            return INT8_MIN;
        }
        return this->arr[this->top];
    }
    bool isEmpty(){
        return this->top==-1;
    }
    bool isFull(){
        return this->top==this->capacity-1;
    }
    int size(){
        return this->top+1;
    }
};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.getTop()<<endl;
    st.push(4);
    st.push(5);
    st.push(5);
    st.pop();
    st.pop();
    cout<<st.getTop()<<endl;
    cout<<st.isEmpty()<<endl;
    cout<<st.isFull()<<endl;
    return 0;
}