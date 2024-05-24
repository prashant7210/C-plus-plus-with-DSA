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

class Linked_list{
    public:
    node* head;
    Linked_list(){
        head=NULL;
    }
    void insert(int val){
        node* new_node=new node(val);
        if(head==NULL){
            head=new_node;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

void alt_del(node* &head){
    node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        node* a=temp->next;
        temp->next=temp->next->next;
        free(a);
        temp=temp->next;
    }
}

int main(){
    Linked_list l1;
    for(int i=0; i<=10; i++){
        l1.insert(i);
    }
    l1.display();
    alt_del(l1.head);
    l1.display();
    return 0;
}