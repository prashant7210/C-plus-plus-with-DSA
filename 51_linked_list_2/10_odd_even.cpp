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

void separate_odd_even_indices(node* &head){
    if(!head)  return;
    node* even_head=head->next;
    node* odd=head;
    node* even=even_head;
    while(even && even->next){
        odd->next=odd->next->next;
        even->next=even->next->next;

        // Moving pointers
        odd=odd->next;
        even=even->next;
    }
    odd->next=even_head;
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
    l.display();
    separate_odd_even_indices(l.head);
    l.display();
    return 0;
}