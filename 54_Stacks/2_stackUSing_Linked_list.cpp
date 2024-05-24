#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class Stack{
    int capacity;
    int currSize;
    node* head;
    public:
    Stack(int c){
        capacity=c;
        currSize=0;
        head=NULL;
    }
    bool isEmpty(){
        return this->head==NULL;
    }
    bool isFull(){
        return this->currSize==this->capacity;
    }
    //Inserting at head
    void push(int data){
        if(this->currSize==this->capacity){
            cout<<"Overflow"<<endl;
            return;
        }
        node* newNode=new node(data);
        newNode->next=this->head;
        this->head=newNode;
        this->currSize++;
    }
    // Removing head
    void pop(){
        if(this->head==NULL){
            cout<<"Underflow"<<endl;
            return;
        }
        node* temp=this->head;
        head=head->next;
        free(temp);
        this->currSize--;
    }
    int getTop(){
        if(!head){
            cout<<"Underflow"<<endl;
            return INT8_MIN;
        }
        return this->head->data;
    }
    int size(){
        return this->currSize;
    }
};

int main(){
    Stack st(5);
    cout<<st.isEmpty()<<endl;
    st.pop();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.getTop()<<endl;
    cout<<st.size()<<endl;
    cout<<st.isFull()<<endl;
    st.push(5);
    st.push(6);
    cout<<st.isFull()<<endl;
    cout<<st.getTop()<<endl;
    st.pop();
    cout<<st.getTop()<<endl;
    return 0;
}