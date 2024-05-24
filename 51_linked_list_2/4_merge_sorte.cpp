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

node* merge_sort_ll(node* &head1, node* &head2){
    node* dummy_head=new node(-1);
    node* ptr1=head1;
    node* ptr2=head2;
    node* ptr3=dummy_head;
    while(ptr1 && ptr2){
        if(ptr1->val<ptr2->val){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    // Now, either ptr1 or ptr2 reached NULL
    if(!ptr1){
        while(ptr2){
            ptr3->next=ptr2;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
    }
    else{
        while(ptr1){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
            ptr3=ptr3->next;
        }
    }
    return dummy_head->next;
}

int main(){
    linked_list l1;
    l1.insert(1);
    l1.insert(3);
    l1.insert(6);
    l1.insert(8);
    l1.insert(8);
    l1.insert(11);
    l1.display();
    linked_list l2;
    l2.insert(2);
    l2.insert(4);
    l2.insert(5);
    l2.insert(7);
    l2.insert(9);
    l2.insert(10);
    l2.insert(10);
    l2.insert(10);
    l2.display();
    linked_list l;
    l.head=merge_sort_ll(l1.head,l2.head);
    l.display();
    return 0;
}