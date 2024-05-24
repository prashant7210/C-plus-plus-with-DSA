#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node* prev;
    node(int n){
        val=n;
        next=NULL;
        prev=NULL;
    }
};

class linked_list{
    public:
    node* head;
    node* tail;
    linked_list(){
        head=NULL;
        tail=NULL;
    }
    void insert(int val){
        node* new_node=new node(val);
        if(!head){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->prev=tail;
        tail->next=new_node;
        tail=new_node;
        return;
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

void del_same_neighbour_node(node* &head, node* &tail){
    node* currptr=tail->prev;
    while(currptr!=head){
        if(currptr->next->val==currptr->prev->val){
            // delete the current node
            currptr->prev->next=currptr->next;
            currptr->next->prev=currptr->prev;
            free(currptr);
        }
        currptr=currptr->prev;
    }
}

int main(){
    linked_list l;
    l.insert(2);
    l.insert(1);
    l.insert(5);
    l.insert(1);
    l.insert(5);
    l.insert(4);
    l.insert(7);
    l.insert(4);
    l.insert(7);
    l.insert(10);
    l.display();

    del_same_neighbour_node(l.head,l.tail);
    l.display();
    return 0;
}