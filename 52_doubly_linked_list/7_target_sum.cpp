#include <iostream>
#include <vector>
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
        tail->next=new_node;
        new_node->prev=tail;
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

vector<int> target_sum(node* head, node* tail, int x){
    vector<int> ans(2,-1);
    while(head!=tail){
        if(head->val+tail->val==x){
            ans[0]=head->val;
            ans[1]=tail->val;
            return ans;
        }
        if(head->val+tail->val > x)  tail=tail->prev;
        else head=head->next;
    }
    return ans;
}

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
    l.display();

    vector<int> v=target_sum(l.head,l.tail,5);
    cout<<v[0]<<" "<<v[1];
    return 0;
}