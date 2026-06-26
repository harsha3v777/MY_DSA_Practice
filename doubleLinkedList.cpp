#include<iostream>
using namespace std;

class Node{
    public:
      int data;
      Node* next;
      Node* prev;

      Node(int val){
        data=val;
        next=prev=NULL;
      }
};

class doubleList{
    Node* head;
    Node* tail;

    public:
    doubleList(){
        head=tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"DLL is empty\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            cout<<"DLL is empty\n";
            return;
        }
        Node* temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
        }
        temp->prev=NULL;
        delete temp;
    }

    void printDLL(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL\n";    
    }
};

int main(){
    doubleList dll1;

    dll1.push_front(1);
    dll1.push_front(2);
    dll1.push_front(9);
    dll1.push_front(5);
    dll1.push_back(4);
    dll1.push_back(3);
    dll1.push_back(6);

    dll1.printDLL();

    dll1.pop_back();
    dll1.pop_front();
    dll1.pop_back();

    dll1.printDLL();
}