#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node* prev;
    node(int data){
        this->val=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class Deque{
    node* head;
    node* tail;
    public:
    Deque(){
        this->head=NULL;
        this->tail=NULL;
    }

    void pushFront(int data){
        node* newNode=new node(data);
        if(!this->head){
            this->head=newNode;
            this->tail=newNode;
            return;
        }
        this->head->prev=newNode;
        newNode->next=this->head;
        this->head=newNode;
    }

    void pushBack(int data){
        node* newNode=new node(data);
        if(!this->head){
            this->head=newNode;
            this->tail=newNode;
            return;
        }
        this->tail->next=newNode;
        newNode->prev=this->tail;
        this->tail=newNode;
    }

    void popFront(){
        if(!this->head) return;
        if(this->head==this->tail){
            node* temp=this->head;
            this->tail=NULL;
            this->head=NULL;
            free(temp);
            return;
        }
        node* temp=this->head;
        this->head=this->head->next;
        free(temp);
    }

    void popBack(){
        if(!this->head) return;
        if(this->head==this->tail){
            node* temp=this->head;
            this->tail=NULL;
            this->head=NULL;
            free(temp);
            return;
        }
        node* temp=this->tail;
        this->tail=this->tail->prev;
        free(temp);
    }

    int getFront(){
        if(!this->head){
            cout<<"Empty"<<endl;
            return INT16_MIN;
        }
        return this->head->val;
    }

    int getLast(){
        if(!this->head){
            cout<<"Empty"<<endl;
            return INT16_MIN;
        }
        return this->tail->val;
    }

    bool isEmpty(){
        return this->head==NULL;
    }
};

int main(){
    Deque dq;
    dq.pushFront(1);
    dq.pushFront(0);
    dq.pushBack(2);
    dq.pushBack(3);
    dq.pushBack(4);
    dq.pushBack(5);
    
    while(not dq.isEmpty()){
        cout<<dq.getFront()<<" ";
        dq.popFront();
    }
    return 0;
}