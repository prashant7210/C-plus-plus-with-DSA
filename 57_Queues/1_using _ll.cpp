#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(int data){
        this->val=data;
        this->next=NULL;
    }
};

class Queue{
    int size;
    node* head;
    node* tail;
    public:
    Queue(){
        this->size=0;
        this->head=NULL;
        this->tail=NULL;
    }

    void enqueue(int data){
        node* newNode=new node(data);
        if(!this->head){
            this->head=newNode;
            this->tail=newNode;
            return;
        }
        this->tail->next=newNode;
        this->tail=newNode;
        this->size++;
    }

    void dequeue(){
        if(!this->head){
            cout<<"Empty Queue";
            return;
        }
        node* temp=this->head;
        this->head=this->head->next;
        if(!head)  this->tail=NULL;
        free(temp);
        this->size--;
    }

    bool isEmpty(){
        return this->head==NULL;
    }

    int getSize(){
        return this->size;
    }

    int front(){
        if(!this->head)  return -1;
        return this->head->val;
    }
};

int main(){
    Queue qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    qu.enqueue(5);
    qu.enqueue(6);

    while(not qu.isEmpty()){
        cout<<qu.front()<<" ";
        qu.dequeue();
    }
    return 0;
}