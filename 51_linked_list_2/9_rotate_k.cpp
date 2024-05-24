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

node* k_rotate(node* &head, int k){
    // Finding length of ll and storing tail node;
    node* tail=head;
    int length=0;
    while(tail->next){
        length++;
        tail=tail->next;
    }
    length++; // for last node

    // Connecting nodes
    k=k%length;
    if(k==0)  return head;
    tail->next=head;
    node* temp=head;
    for(int i=1; i<length-k; i++){
        temp=temp->next;
    }
    node* new_head=temp->next;
    temp->next=NULL;
    return new_head;
}

int main(){
    linked_list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.insert(6);
    l.insert(6);
    l.insert(6);
    l.display();

    l.head=k_rotate(l.head,9);
    l.display();
    return 0;
}