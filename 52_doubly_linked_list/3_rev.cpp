#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node* prev;
    node(int n){
        val=n;
        next=NULL;
        prev=NULL;
    }
};

class linked_list{
    public:
    node* head;
    node* tail;
    linked_list(){
        head=NULL;
        tail=NULL;
    }
    void insert(int val){
        node* new_node=new node(val);
        if(!head){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->prev=tail;
        tail->next=new_node;
        tail=new_node;
        return;
    }
    void display(){
        node* temp=head;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

void reverse(node* &head, node* tail){
    node* currptr=head;
    while(currptr){
        node* nextptr=currptr->next;
        currptr->next=currptr->prev;
        currptr->prev=nextptr;
        // Moving currrptr
        currptr=nextptr;
    }
    node* temp=head;
    head=tail;
    tail=temp;
    return;
}

int main(){
    linked_list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.insert(7);
    l.insert(8);
    l.insert(9);
    l.insert(10);
    l.display();

    reverse(l.head,l.tail);
    l.display();
    return 0;
}