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
    void del_at_head(){
        if(!head)  return;
        node* temp=head;
        head=head->next;
        if(!head) tail=NULL;
        else head->prev=NULL;
        free(temp);
        return;
    }
    void del_at_tail(){
        if(!tail)  return;
        node* temp=tail;
        tail=tail->prev;
        if(!tail)  head=NULL;
        else  tail->next=NULL;
        free(temp);
        return;
    }
    void del_k_node(int k){
        if(k==1){
            del_at_head();
            return;
        }
        node* temp=head;
        int counter=1;
        while(counter<k){
            temp=temp->next;
            counter++;
        }
        if(temp==tail){
            del_at_tail();
            return;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        return;
    }
};

int main(){
    linked_list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.insert(7);
    l.insert(8);
    l.insert(9);
    l.insert(10);
    l.display();
    l.del_at_head();
    l.display();
    l.del_at_tail();
    l.display();

    l.del_k_node(4);
    l.display();

    return 0;
}