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
    void insert(int n){
        node* new_node=new node(n);
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
        }cout<<endl;
    }
};

bool detect_cycle(node* head){
    if(!head)  return false;
    node* slow=head;
    node* fast=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void remove_cycle(node* &head){
    if(!detect_cycle) return;
    node* slow=head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    } while(slow!=fast);

    fast=head;

    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
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
    l.display();

    l.head->next->next->next->next->next->next->next->next=l.head->next->next;
    cout<<detect_cycle(l.head)<<endl;

    remove_cycle(l.head);
    l.display();

    return 0;
}