#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;

    dq.push_back(1);  //their is also pop_front() and pop_back() 
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(6);

    cout<<"front ele : "<<dq.front()<<" , back ele : "<<dq.back()<<endl;

    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }cout<<endl;
}