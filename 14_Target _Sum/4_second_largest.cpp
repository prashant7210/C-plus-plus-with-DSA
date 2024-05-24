#include <iostream>
using namespace std;
int max_index(int a[] , int size){
    int max = INT16_MIN , index;
    for(int i=0; i<size; i++){
        if(a[i]>max){
            max = a[i];
            index = i;
        }
    }
    return index;
}
      // OR

int second_largest(int a[] , int size){
    int max = INT16_MIN , second_max = INT16_MIN;
    for(int i=0; i<size; i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    for(int i=0; i<size; i++){
        if((a[i]>second_max)&&(a[i]!=max)){
            second_max = a[i];
        }
    }
    return second_max;
}
int main(){
    int array[] = {2,3,5,6,7,1,7,3,7};
    int n=9;
    int largest_element = array[max_index(array,n)];
    for(int i=0; i<n; i++){
        if(array[i]==largest_element){
            array[i] = INT16_MIN;
        }
    }
    int second_largest_element_index = max_index(array,n);
    int second_largest_element = array[second_largest_element_index];
    cout<<"Second Largest Element = "<<second_largest_element;
    cout<<"Second Largest Element = "<<second_largest(array,n);
    return 0;
}