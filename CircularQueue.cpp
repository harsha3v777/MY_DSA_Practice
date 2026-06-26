#include<iostream>
using namespace std;

class CircularQueue{
    int* arr;
    int currSize,cap;
    int f,r; 

    public:

       CircularQueue(int size){  //r -rear , f - front
          cap=size;
          arr=new int[cap];
          f=0;
          r=-1;
          currSize=0;
       }

       void push(int data){  //o(1)
        if(currSize==cap){
            cout<<"CQ is Full\n";
            return;
        }
        r=(r+1)%cap;
        arr[r]=data;
        currSize++;
       }

       void pop(){
        if(empty()){
            cout<<"CQ is Empty\n";
            return;
        }
        f=(f+1)%cap;
        currSize--;
       }

       int front(){
        if(empty()){
            cout<<"CQ is Empty\n";
            return -1;
        }
        return arr[f];
       }

       bool empty(){
        return currSize==0;
       }

       void printArr(){
        for(int i=0;i<cap;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
       }

       void printArrCircularlyCorrect(){
        cout<<"Queue : ";
        for(int i=0;i<cap;i++){
            cout<<arr[(f+i)%cap]<<" ";
        }cout<<endl;
       }
};

int main(){
    CircularQueue CQ(3);

    CQ.push(1);
    CQ.push(2);
    CQ.push(3);
    CQ.printArr();
    CQ.pop();
    CQ.push(4);
    CQ.printArr();

    CQ.printArrCircularlyCorrect();

    return 0;
}