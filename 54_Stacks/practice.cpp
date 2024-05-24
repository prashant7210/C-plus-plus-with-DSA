#include <iostream>
using namespace std;

template <typename T>

class stack{
    T top;
    T capacity;
    T* arr;
    public:
    stack(T c){
        this->capacity=c;
        arr=new T[c];
        this->top=-1;
    }
    // isEmpty
    bool isEmpty(){
        return this->top==-1;
    }
    // isFull
    bool isFull(){
        return this->top==this->capacity-1;
    }
    // push function
    void push(T data){
        if(this->top==this->capacity-1){
            cout<<"Overflow"<<endl;
            return;
        }
        this->top++;
        this->arr[this->top]=data;
    }
    // pop function
    void pop(){
        if(this->top==-1){
            cout<<"Underflow"<<endl;
            return;
        }
        this->top--;
    }
    // getTop
    T getTop(){
        if(this->top==-1){
            cout<<"Underflow"<<endl;
            return INT8_MIN;
        }
        return this->arr[this->top];
    }
};

int size(stack<int> st){
    int counter=0;
    while(!st.isEmpty()){
        st.pop();
        counter++;
    }
    return counter;
}

void display(stack<int> st){
    while(!st.isEmpty()){
        cout<<st.getTop()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> st(5);
    cout<<st.isEmpty()<<endl;
    cout<<st.isFull()<<endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.getTop()<<endl;
    cout<<size(st)<<endl;
    display(st);
    st.pop();
    display(st);
    st.push(5);
    st.push(6);
    display(st);
    cout<<st.isEmpty()<<endl;
    cout<<st.isFull()<<endl;
    st.push(7);
    return 0;
}