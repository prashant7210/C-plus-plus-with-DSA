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

bool check_palindrome(node* head, node* tail){
    while(head!=tail && tail!=head->prev){
        if(head->val!=tail->val) return false;
        head=head->next;
        tail=tail->prev;
    }
    return true;
}

int main(){
    linked_list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(5);
    l.insert(4);
    l.insert(3);
    l.insert(2);
    l.insert(1);
    l.display();

    cout<<check_palindrome(l.head,l.tail);
    return 0;
}