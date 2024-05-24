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

bool isCritical(node* currnode){
    if(currnode->val>currnode->next->val && currnode->val>currnode->prev->val) return true;
    if(currnode->val<currnode->next->val && currnode->val<currnode->prev->val) return true;
    return false;
}

vector<int> distance_bw_critical_points(node* head, node* tail){
    vector<int> ans(2,INT8_MAX);
    int first=-1, last=-1;

    node* currnode=tail->prev;
    if(!currnode){
        ans[0]=ans[1]=-1;
        return ans;
    }

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
    if(ans[0]==INT8_MAX){ // Only 1 critical point or no CP
        ans[0]=ans[1]=-1;
    }
    return ans;
}

int main(){
    linked_list l;
    l.insert(1);
    l.insert(2);
    l.insert(0);
    l.insert(4);
    l.insert(1);
    l.insert(6);
    l.display();

    vector<int> ans=distance_bw_critical_points(l.head,l.tail);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}