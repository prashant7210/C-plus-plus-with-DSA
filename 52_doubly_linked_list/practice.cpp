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
        if(!tail){
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

bool isCritical(node* currptr){
    if(currptr->val>currptr->next->val && currptr->val>currptr->prev->val)  return true;
    if(currptr->val<currptr->next->val && currptr->val<currptr->prev->val)  return true;
    return false;
}

vector<int> distance_max_min(node* head, node* tail){
    vector<int> ans(2,INT16_MAX);
    node* currnode=tail->prev;
    if(!currnode){
        ans[0]=ans[1]=-1;
        return ans;
    }
    int first=-1;
    int last=-1;
    int currpos=0;
    while(currnode->prev){
        if(isCritical(currnode)){
            if(first==-1){
                first=last=currpos;
            }
            else{
                ans[0]=min(ans[0],currpos-last);
                ans[1]=currpos-first;
                last=currpos;
            }
        }
        currpos++;
        currnode=currnode->prev;
    }

    // For only one critical point........
    if(ans[0]==INT16_MAX){
        ans[0]=ans[1]=-1;
        return ans;
    }
    return ans;
}

int main(){
    linked_list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(1);
    l.display();
    vector<int> ans=distance_max_min(l.head,l.tail);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}