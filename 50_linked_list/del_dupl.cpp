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

void del_dup(node* &head){
    node* current_node=head;
    while(current_node){
        while(current_node->next && current_node->val==current_node->next->val){
            node* temp=current_node->next;
            current_node->next=current_node->next->next;
            free(temp);
        }
        current_node=current_node->next;
    }
}

int main(){
    linked_list l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(2);
    l1.insert(3);
    l1.insert(3);
    l1.insert(3);
    l1.display();
    del_dup(l1.head);
    l1.display();
    return 0;
}