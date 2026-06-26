#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }

    return root;
}

Node* buildBST(vector<int> vec){
    Node* root=NULL;
    for(int val : vec){
        root=insert(root,val);
    }

    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool search(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
       return search(root->left,key);
    }else{
       return search(root->right,key);
    }
}

Node* getInorderSuccessor(Node* root){
    while(root!=NULL && root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* delNode(Node* root,int key){
    if(root==NULL){
        return NULL;
    }

    if(key < root->data){
        root->left=delNode(root->left,key);
    }else if(key > root->data){
        root->right=delNode(root->right,key);
    }else{
        //key==root->data
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }else{
            Node* IS=getInorderSuccessor(root->right);
            root->data=IS->data;
            root->right=delNode(root->right,IS->data);
        }
    }
    return root;
}

Node* buildBSTFromSortedArr(vector<int>& vec,int st,int end){
    if(st>end){
        return NULL;
    }
    int mid=st+(end-st)/2;
    Node* root=new Node(vec[mid]);
    root->left=buildBSTFromSortedArr(vec,st,mid-1);
    root->right=buildBSTFromSortedArr(vec,mid+1,end);

    return root;
}

void treeToInorderArr(Node* root,vector<int>& arr){
    if(root==NULL){
        return;
    }
    treeToInorderArr(root->left,arr);
    arr.push_back(root->data);
    treeToInorderArr(root->right,arr);
}

Node* merge2BST(Node* root1,Node* root2){  // T.C - O(m+n)
    vector<int> arr1,arr2;
    treeToInorderArr(root1,arr1);
    treeToInorderArr(root2,arr2);

    vector<int> temp; //final BST of 2 merged arrays
    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            temp.push_back(arr1[i]);
            i++;
        }else{
            temp.push_back(arr2[j]);
            j++;
        }
    }
    while(i<arr1.size()){
        temp.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size()){
        temp.push_back(arr2[j]);
        j++;
    }

    return buildBSTFromSortedArr(temp,0,temp.size()-1);
}

int main(){
    // vector<int> vec={3,2,1,5,6,4};
    // Node* root=buildBST(vec);
    // inorder(root);
    // cout<<endl;
    // cout<<"1 means true : "<<search(root,5)<<endl;

    // cout<<"before : ";
    // inorder(root);
    // cout<<endl;

    // delNode(root,2);

    // cout<<"after : ";
    // inorder(root);
    // cout<<endl;

    vector<int> arr1={8,2,1,10};
    vector<int> arr2={5,3,0};

    Node* root1=buildBST(arr1);
    Node* root2=buildBST(arr2);

    Node* root=merge2BST(root1,root2);
    inorder(root);
    return 0;
}


