#include<iostream>
using namespace std;

class Node{
    public:
    
    int data;
    Node* next;
    public:
    Node(int val){
        data=val;
        next=NULL;
    }
};

class circularList{
    Node* head;
    Node* tail;

    public:
    circularList(){
        head=tail=NULL;
    }

    void insertAtHead(int val){
        Node* newNode=new Node(val);
        if(tail==NULL){
            head=tail=newNode;
            tail->next=head;
        }else{
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }

    void insertAtTail(int val){
        Node* newNode=new Node(val);
        if(tail==NULL){
            head=tail=NULL;
            tail->next=head;
        }else{
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }

    void deleteAtHead(){
        if(head==NULL){
            return;
        }else if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            Node* temp=head;
            head=head->next;
            tail->next=head;

            temp->next=NULL;
            delete temp;
        }
    }

    void deleteAtTail(){
        if(head==NULL){
            return;
        }else if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            Node* temp=tail;
            Node* prev=head;
            while(prev->next!=tail){
                prev=prev->next;
            }
            tail=prev;
            tail->next=head;

            temp->next=NULL;
            delete temp;
        }
    }

    void printCLL(){
        Node* temp=head;
        cout<<temp->data<<"->";
        temp=temp->next;
        while(temp!=head){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
};

int main(){
    circularList cll1;

    cll1.insertAtHead(3);
    cll1.insertAtHead(4);
    cll1.insertAtHead(7);
    cll1.insertAtTail(2);
    cll1.insertAtTail(9);

    cll1.printCLL();

    cll1.deleteAtHead();
    cll1.deleteAtHead();
    cll1.deleteAtTail();

    cll1.printCLL();

    return 0;
}