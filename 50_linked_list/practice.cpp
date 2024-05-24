#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(int n){
        val=n;
        next=NULL;
    }
};

class linked_list{
    public:
    node* head;
    linked_list(){
        head=NULL;
    }

    void insert(int val){
        node* new_node=new node(val);
        if(!head){
            head=new_node;
            return;
        }
        node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=new_node;
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

node* reverse(node* &head){
    if(!head || !head->next) return head;
    node* currptr=head;
    node* prevptr=NULL;
    while(currptr){
        node* nextptr=currptr->next;
        currptr->next=prevptr;
        // Moving pointers
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* rev_rec(node* &head){
    // base case
    if(!head || !head->next)  return head;
    // recurssive case
    node* new_head=rev_rec(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
}

node* rev_k_rec(node* head, int k){
    // base case
    if(!head || !head->next)  return head;
    // reverse kth node
    node* prevptr=NULL;
    node* currptr=head;
    int counter=0;
    while(currptr && counter<k){
        node* nextptr=currptr->next;
        currptr->next=prevptr;
        // moving pointers
        prevptr=currptr;
        currptr=nextptr;
        counter++;
    }
    //recursive case
    if(currptr){
        node* new_head=rev_k_rec(currptr,k);
        head->next=new_head;
    }
    return prevptr;
}

int main(){
    linked_list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.display();

    // Iteratuvely
    l.head=reverse(l.head);
    l.display();

    // Recursively
    l.head=rev_rec(l.head);
    l.display();

    // Rev_k_recursively
    l.head=rev_k_rec(l.head,2);
    l.display();
    return 0;
}