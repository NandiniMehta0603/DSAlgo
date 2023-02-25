#include <bits/stdc++.h> 
class TwoStack {

//as we want to consume memory of array to the fullest 
//so the strategy is to fill array from both the ends
//first array from the start and second array from the end

public:
    int *arr;
    int top1;
    int top2;
    int size;
    
    TwoStack(int s) {
        this->size=s;
        arr=new int[size];
        top1=-1;
        top2=size;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2-top1>1)
        {
            top1++;
            arr[top1]=num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2-top1>1)
        {   
            top2--;
            arr[top2]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1>=0)
        {
            int val=arr[top1];
            top1--;
            return val;
        }
        else{
            return -1;
        }
        
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2<size)
        {
            int val=arr[top2];
            top2++;
            return val;
        }
        else{
            return -1;
        }
    }
};
