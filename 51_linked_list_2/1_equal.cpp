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
        node* new_head= new node(val);
        if(!head){
            head=new_head;
            return;
        }
        node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=new_head;
    }
    void display(){
        if(!head || !head->next) return;
        node* temp=head;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

bool check(node* ptr1, node* ptr2){
    while(ptr1 && ptr2){
        if(ptr1->val!=ptr2->val)  return false;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return (!ptr1 && !ptr2);
}

int main(){
    linked_list l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.display();

    linked_list l2;
    l2.insert(1);
    l2.insert(2);
    l2.insert(3);
    l2.insert(4);
    l2.insert(5);
    l2.display();

    cout<<check(l1.head,l2.head);
    return 0;
}