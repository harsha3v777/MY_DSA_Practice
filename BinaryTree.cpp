#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

static int idx = -1;
Node* BuildTree(vector<int> preorder){  //0(n)
    idx++;
    if(preorder[idx]==-1) {
        return NULL;
    }
    
    Node* root=new Node(preorder[idx]);
    root->left=BuildTree(preorder);
    root->right=BuildTree(preorder);

    return root;
}

//preorder traversel
void preOrder(Node* root){  //o(n) root,left,right  
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//inorder traversel
void inOrder(Node* root){ //o(n) left,root,right
    if(root == NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//postorder traversel
void postOrder(Node* root){  //o(n) left,right,root
    if(root==NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//level order traversel
void levelOrderTra(Node* root){  //o(n) level 
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);

    while(q.size()>0){
        Node* curr=q.front();
        q.pop();

        if(curr==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }
        cout<<curr->data<<" ";

        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }    
    }
    cout<<endl;
}

//height of a tree
int height(Node* root){  //o(n)
    if(root==NULL) return 0;

    int leftHt=height(root->left);
    int rightHt=height(root->right);

    return max(leftHt,rightHt)+1;
}

//no.of nodes
int count(Node* root){  //o(n)
    if(root == NULL) return 0;

    int leftCo=count(root->left);
    int rightCo=count(root->right);
    return leftCo+rightCo+1;
}

//sum of nodes
int sum(Node* root){
    if(root == NULL) return 0;

    int leftSum=sum(root->left);
    int rightSum=sum(root->right);
    
    return root->data+leftSum+rightSum;
}

//top view of a binary tree
void topView(Node* root){ //o(nlog(n))
    queue<pair<Node*,int>> q;  //horizontal distance - HD and here level order traversel is used 
    map<int,int> m;            //same used for bottom view

    q.push({root,0});

    while(q.size() > 0){
        Node* curr=q.front().first;
        int currHD=q.front().second;
        q.pop();

        if(m.find(currHD)==m.end()){
            m[currHD]=curr->data;
        }

        if(curr->left!=NULL){
            q.push({curr->left,currHD-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,currHD+1});
        }
    }

    for(auto it:m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}

//kth level of a tree
void kthLevel(Node* root,int k){
    if(root==NULL){
        return;
    }

    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    kthLevel(root->left,k-1);
    kthLevel(root->right,k-1);
}

//sum tree
int sumTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum=sumTree(root->left);
    int rightSum=sumTree(root->right);

    root->data+=leftSum+rightSum;
    return root->data;
}

int main(){
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=BuildTree(preorder);

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrderTra(root);
    cout<<"height of tree : "<<height(root)<<endl;
    cout<<"no.of nodes in the tree : "<<count(root)<<endl;
    cout<<"sum of nodes : "<<sum(root)<<endl;
    cout<<"top view of a tree : ";
    topView(root);
    cout<<"3rd Level Elements : ";
    kthLevel(root,3);
    cout<<endl;

    cout<<"sum tree : "<<endl;
    cout<<"before conversion : ";
    preOrder(root);
    cout<<endl;
    cout<<sumTree(root)<<endl;
    cout<<"after conversion : ";
    preOrder(root);
    cout<<endl;
    
    return 0;
}