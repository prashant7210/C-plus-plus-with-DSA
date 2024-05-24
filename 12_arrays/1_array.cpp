#include<iostream>
using namespace std;
int main(){
    int array[] = {1,2,3,4};
    cout<<sizeof(array)<<endl;
    cout<<sizeof(array)/sizeof(array[0])<<endl;

    //Printing all elements of the array using for loop
    int size = sizeof(array)/sizeof(array[0]);
    for(int i=0; i<size; i++){
        cout<<array[i]<<endl;
    }

    // for each loop
    for(int i:array){
        cout<<i<<endl;
    }

    // while loop
    int index = 0;
    while(index<size){
        cout<<array[index]<<endl;
        index++;
    }
    return 0;
}