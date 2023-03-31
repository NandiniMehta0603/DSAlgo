// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size=0;
    
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
            }
            else{
                return ;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    //deletion in a max heap means deleting the maxi element
//deleting in a min heap means deleting the mini element
//ie always the root node 
//deleting an intermediate element is a costly task so we swap the element to be deleted by the last element of the heap and then simply arrange the rest of the elements accoding to their order ie heapify it

    void deletefromHeap(){
        if(size==0){
            cout<<"nothing to delete "<<endl;
            return ;
        }
        arr[1]=arr[size];
        size--;
        
        //take root node to its correct position
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{
                return ;
            }
        }
    }
};




int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    
    h.deletefromHeap();
    h.print();

    return 0;
}
