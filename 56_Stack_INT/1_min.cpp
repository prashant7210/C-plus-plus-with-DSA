#include <iostream>
#include <algorithm>
using namespace std;

class stack{
    int capacity;
    int* arr;
    int* minArr;
    int top;
    int minTop;
    public:
    stack(int c){
        this->capacity=c;
        this->arr=new int[c];
        this->minArr=new int[c];
        this->top=-1;
        this->minTop=-1;
    }
    void push(int data){
        if(this->top==this->capacity-1){
            cout<<"Stack Overflow\n";
            return;
        }
        this->top++;
        this->arr[this->top]=data;
        if(this->top>0){
            this->minArr[this->top]=min(this->minArr[this->minTop-1],this->arr[this->top]);
            this->minTop++;
        }
        else this->minArr[0]=this->arr[0];
        this->minTop++;
        return;
    }
    void pop(){
        this->top--;
    }
    int getTop(){
        return this->arr[this->top];
    }
    int getMin(){
        return this->minArr[this->minTop];
    }
};

int main(){
    stack st(6);
    // st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout<<st.getMin();
    return 0;
}