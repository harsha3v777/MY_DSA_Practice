#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> vec;

    public:

    void push(int val){
        vec.push_back(val);
    }

    void pop(){
        vec.pop_back();
    }

    int top(){
        return vec[vec.size()-1];
    }

    bool empty(){
        return vec.size()==0;
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