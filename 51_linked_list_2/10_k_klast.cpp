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
    // base case
    if(!head || !head->next) return head;

    // Recursive case
    node * new_head=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
}

void k_klast(node* &head){
    node* og_head=head;
    node* slow=head;
    node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    // Now slow is pointing towards prior to the middle node
    node* ptr2=reverse(slow);
    node* ptr1=head;
    while(ptr1!=ptr2){
        node* temp=ptr1->next;
        ptr1->next=ptr2;
        ptr1=ptr2;
        ptr2=temp;
    }
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
    k_klast(l.head);
    l.display();
    return 0;
}