#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* prev;
    node* next;
    node(int n){
        val=n;
        prev=NULL;
        next=NULL;
    }
};

class d_linked_list{
    public:
    node* head;
    node* tail;
    d_linked_list(){
        head=NULL;
        tail=NULL;
    }
    void insert_at_head(int val){
        node* new_node=new node(val);
        if(!head){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return;
    }
    void insert_at_tail(int val){
        node* new_node=new node(val);
        if(!tail){
            tail=new_node;
            head=new_node;
            return;
        }
        new_node->prev=tail;
        tail->next=new_node;
        tail=new_node;
        return;
    }
    void insert_at_k(int val, int k){
        node* new_node=new node(val);
        if(!head){
            head=new_node;
            tail=new_node;
            return;
        }
        node* temp=head;
        k--;
        while(--k && temp->next){
            temp=temp->next;
        }
        // temp is pointing towards teh prior element to kth node
        // nextptr
        new_node->next=temp->next;
        temp->next=new_node;
        //prevptr
        new_node->next->prev=new_node;
        new_node->prev=temp;

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

int main(){
    d_linked_list l;
    l.insert_at_tail(3);
    l.insert_at_tail(4);
    l.insert_at_tail(5);
    l.insert_at_head(2);
    l.insert_at_head(1);
    l.display();

    l.insert_at_k(9,3);
    l.display();
    return 0;
}