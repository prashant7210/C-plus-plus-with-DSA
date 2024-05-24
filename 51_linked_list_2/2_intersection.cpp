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

int getLength(node *head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}

node* getIntersection(node* head1, node* head2){
    // finding length of linked lists
    int k,l1=getLength(head1),l2=getLength(head2);

    // moving k steps
    if(l1>l2){
        k=l1-l2;
        while(k--){
            head1=head1->next;
        }
    }
    else{
        k=l2-l1;
        while(k--){
            head2=head2->next;
        }
    }

    // finding intersection
    while(head1){
        if(head1==head2)  return head1;
        head1=head1->next;
        head2=head2->next;
    }
    return NULL;
}

int main(){
    linked_list l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.display();
    
    linked_list l2;
    l2.insert(7);
    l2.insert(8);
    l2.head->next->next=l1.head->next->next->next;
    l2.display();
    cout<<getIntersection(l1.head,l2.head)->val;
    return 0;
}