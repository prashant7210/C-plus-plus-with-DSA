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

node* reverse_ll(node* head){
    node* prevptr=NULL;
    node* currptr=head;
    while(currptr){
        node* nextptr=currptr->next;
        currptr->next=prevptr;
        // Moving pointers
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

bool is_palindrome(node* head){
    // Finding middle element
    node* slow=head;
    node* fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    // Now, slow is pointing towards middle element
    // Reverse the second half of the linked list
    node* r_head=reverse_ll(slow->next);
    slow=NULL;

    // checking first and second half linked list
    while(head && r_head){
        if(r_head->val!=head->val) return false;
        head=head->next;
        r_head=r_head->next;
    }
    return true;
}

int main(){
    linked_list l;
    l.insert(1);
    l.insert(2);
    // l.insert(3);
    // l.insert(3);
    // l.insert(2);
    // l.insert(1);
    l.display();
    
    cout<<is_palindrome(l.head);
    return 0;
}