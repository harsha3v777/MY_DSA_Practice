#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL; 
    }
};

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head=tail=NULL;
    }

    void push_front(int val){//0(1)
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }

    void push_back(int val){//0(1)
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void pop_front(){ //o(1)
        if(head==NULL){
            cout<<"The linked list is empty\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;

        if(head==NULL){
            tail=NULL;
        }
    }

    void pop_back(){ //o(n)
        if(head==NULL){
            cout<<"The linked list is empty\n";
            return;
        }

        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }

        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }

    void insert(int val,int pos){ //o(n)
        if(pos<0){
            cout<<"invaild position\n";
            return;
        }
        if(pos==0){
            push_front(val);
            return;
        }

        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp->next==NULL){
                cout<<"index out of bound\n";
                return;
            }
            temp=temp->next;
        }

        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void printLL(){ //o(n)
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    int search(int val){ //o(n)
        Node* temp=head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==val){
                return idx;
            }
            temp=temp->next;
            idx++;
        }

        return -1;
    }
};

int main(){
    List l1;

    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(1);

    l1.push_front(8);
    l1.push_front(7);

    l1.printLL();

    l1.pop_back();
    l1.pop_front();
    l1.printLL();

    l1.insert(9,2);
    l1.printLL();

    cout<<"search : "<<l1.search(3)<<endl;
}