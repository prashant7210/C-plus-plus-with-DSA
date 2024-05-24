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

// Assuming k<length of ll
node* del_k_fromLast(node* &head, int k){
    node* ptr1=head;
    node* ptr2=head;
    while(--k){
        ptr2=ptr2->next;
    }
    // if ptr2==NULL , then k=length of ll
    if(!ptr2){
        // deleting head node
        node* temp=head;
        head=head->next;
        free(temp);
    }
    // moving pointers
    while(ptr2->next){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    node* temp=ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);
}

int main(){
    linked_list l;
    l.insert(1);
    l.insert(3);
    l.insert(2);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.display();
    del_k_fromLast(l.head,5);
    l.display();
    return 0;
}