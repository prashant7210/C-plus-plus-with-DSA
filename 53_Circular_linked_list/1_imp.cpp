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

class circular_linked_list{
    public:
    node* head;
    circular_linked_list(){
        head=NULL;
    }
    void insert_at_head(int val){
        node* new_node=new node(val);
        if(!head){
            head=new_node;
            new_node->next=head;
            return;
        }
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=head;
        head=new_node;
        return;
    }
    void insert_at_tail(int val){
        node* new_node=new node(val);
        if(!head){
            head=new_node;
            new_node->next=head;
            return;
        }
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=head;
        return;
    }
    void insert_at_kfromhead(int val, int k){
        node* new_node=new node(val);
        if(!head){
            head=new_node;
            new_node->next=head;
            return;
        }
        node* temp=head;
        // assuming k<1cycle length of ll
        if(k==1){
            insert_at_head(val);
            return;
        }
        k--;
        while(--k){
            temp=temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
        return;
    }
    void display(){
        node* temp=head;
        do{
            cout<<temp->val<<" ";
            temp=temp->next;
        } while(temp!=head);
        cout<<endl;
    }
};

int main(){
    circular_linked_list l;
    l.insert_at_tail(1);
    l.insert_at_tail(2);
    l.insert_at_tail(3);
    l.insert_at_tail(4);
    l.insert_at_tail(5);
    l.insert_at_kfromhead(0,4);
    l.display();
    return 0;
}