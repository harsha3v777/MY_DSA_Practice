#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Stack{
    list<int> ll;

    public:

    void push(int val){
        ll.push_front(val);
    }

    void pop(){
        ll.pop_front();
    }

    int top(){
        return ll.front();
    }

    bool empty(){
        return ll.size()==0;
    }
};

int main(){
    Stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }cout<<endl;

    return 0;
}