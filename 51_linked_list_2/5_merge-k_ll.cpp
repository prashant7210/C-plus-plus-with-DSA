#include <iostream>
#include <vector>
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
        node*temp=head;
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

node* merge_ll(node* &head1, node* &head2){
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
    // Now, either ptr1 or ptr2 pointing to NULL
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

node* merge_k_ll(vector<node*> &heads){
    if(!heads.size()){
        return NULL;
    }
    while(heads.size()>1){
        heads.push_back(merge_ll(heads[0],heads[1]));
        heads.erase(heads.begin());
        heads.erase(heads.begin());
    }
    return heads[0];
}

int main(){
    linked_list l1;
    l1.insert(1);
    l1.insert(7);
    l1.insert(12);
    l1.insert(15);
    l1.display();

    linked_list l2;
    l2.insert(5);
    l2.insert(8);
    l2.insert(13);
    l2.display();

    linked_list l3;
    l3.insert(2);
    l3.insert(3);
    l3.insert(11);
    l3.insert(14);
    l3.display();

    linked_list l4;
    l4.insert(4);
    l4.insert(6);
    l4.insert(9);
    l4.insert(10);
    l4.display();

    vector<node*> heads(3);
    heads.push_back(l1.head);
    heads.push_back(l2.head);
    heads.push_back(l3.head);
    heads.push_back(l4.head);

    l1.head=merge_k_ll(heads);
    l1.display();

    return 0;
}