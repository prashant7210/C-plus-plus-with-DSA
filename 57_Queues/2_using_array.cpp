#include <iostream>
#include <vector>
using namespace std;

class Queue{
    vector<int> v;
    int back;
    int front;
public:
    Queue(){
        this->front=this->back=-1;
    }

    void enqueue(int data){
        v.push_back(data);
        this->back++;
        if(this->back==0)  this->front=0;
    }

    void dequeue(){
        if(this->front==this->back){
            this->front=this->back=-1;
            this->v.clear();
            return;
        }
        this->front++;
    }

    int getfront(){
        if(this->front==-1)  return -1;
        return v[this->front];
    }

    bool isEmpty(){
        return this->front==-1;
    }

};

int main(){
    Queue qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    qu.enqueue(5);
    qu.enqueue(6);

    while(not qu.isEmpty()){
        cout<<qu.getfront()<<" ";
        qu.dequeue();
    }
    cout<<endl;

    qu.enqueue(400);
    cout<<qu.getfront()<<endl;
    qu.dequeue();
    cout<<qu.getfront();
    return 0;
}