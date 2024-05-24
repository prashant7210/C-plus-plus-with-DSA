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

void reverse(node* &head){
    if(!head)  return;
    reverse(head->next);
    cout<<head->val<<" ";
}

node* reverseLL(node* &head){
    node* currptr=head;
    node* prevptr=NULL;
    while(currptr){
        node* nextptr=currptr->next;
        currptr->next=prevptr;

        // Move all pointers next step
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* reverse_recursively(node* &head){
    //base case
    if(!head || !head->next)  return head;

    // recursive case
    node* new_head=reverse_recursively(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
}

node* reverse_k_rec(node* &head, int k){
    node* currptr=head;
    node* prevptr=NULL;

    // reversing k nodes
    int counter=0;
    while(currptr!=NULL && counter<k){
        node* nextptr=currptr->next;
        currptr->next=prevptr;
        // Moving pointers
        prevptr=currptr;
        currptr=nextptr;
        counter++;
    }

    // current pointer poiting towards k+1 nodes
    if(currptr!=NULL){
        node* new_head=reverse_k_rec(currptr,k);
        head->next=new_head;
    }

    return prevptr;
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
    // only printing in reverse order
    reverse(l.head);
    cout<<endl;

    // reversed LL
    l.head=reverseLL(l.head);
    l.display();

    // reversed using recurssion
    l.head=reverse_recursively(l.head);
    l.display();

    // kth reversed nodes
    l.head=reverse_k_rec(l.head,2);
    l.display();
    return 0;
}