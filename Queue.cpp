#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (!q.empty()) {
        cout << "Front of queue: " << q.front() << endl;
    } else {
        cout << "Queue is empty. No front element.\n";
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
    
    return 0;
}