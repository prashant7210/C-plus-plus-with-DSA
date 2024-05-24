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

void ins_at_head(node* &head, int val){
    node* new_node=new node(val);
    new_node->next=head;
    head=new_node;
}

void ins_at_tail(node* &head, int val){
    node* new_node=new node(val);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

void ins_at_kth(int k, node* &head, int val){
    if(k==0){
        ins_at_head(head,val);
        return;
    }
    node* new_node=new node(val);
    node* temp=head;
    k--;
    while(k--){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

void update_at_kth(node* &head, int n, int k){
    node* temp=head;
    while(k--){
        temp=temp->next;
    }
    temp->val=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void del_at_head(node* &head){
    node* temp=head;
    head=head->next;
    free(temp);
}

void del_at_tail(node* &head){
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node* last=temp->next;
    temp->next=NULL;
    free(last);
}

void del_at_kth(node* &head, int k){
    if(k==0){
        del_at_head(head);
        return;
    }
    node* temp=head;
    k--;
    while(k--){
        temp=temp->next;
    }
    node* a;
    a=temp->next;
    temp->next=temp->next->next;
    free(a);
}

int main(){
    node* head=NULL;
    display(head);
    ins_at_head(head,3);
    display(head);
    ins_at_head(head,2);
    display(head);
    ins_at_head(head,1);
    display(head);

    ins_at_tail(head,4);
    display(head);
    ins_at_tail(head,5);
    display(head);

    ins_at_head(head,0);
    display(head);

    ins_at_kth(2,head,-1);
    display(head);
    ins_at_kth(0,head,-2);
    display(head);

    update_at_kth(head,9,3);
    display(head);

    del_at_head(head);
    display(head);

    del_at_tail(head);
    display(head);

    del_at_kth(head,2);
    display(head);
    
    return 0;
}