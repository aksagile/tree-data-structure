#include <iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};



node* insert(int data){
    node* newnode  =new node();
    newnode->data = data;
    newnode->left =NULL;
    newnode->right = NULL;
    return newnode;
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    node * curr = root;
    stack<node*> s;
    while(!s.empty()||curr!=NULL){
        if(curr!=NULL){
        s.push(curr);
        curr= curr->left;}
        else{
            curr = s.top();
            s.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
    cout<<"executedin";
}

void preorder( node* root){
    if(root==NULL){
        return;
    }
    
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node * curr= s.top();
        cout<<curr->data<<" ";
        s.pop();
        
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
        
    }
    cout<<"executedpre";
    
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    
    stack<node*> s;
    stack<int > out;
    s.push(root);
    while(!s.empty()){
        node * curr= s.top();
        s.pop();
        out.push(curr->data);
        if(curr->left){
            s.push(curr->left);
        }
        if(curr->right){
            s.push(curr->right);
        }
    }
    
    while(!out.empty()){
        cout<<out.top()<<" ";
        out.pop();
    }
    cout<<"executedpost";
}

int main() {
    node* root =insert(1) ;
    
    root->left        = insert(2);
    root->right       = insert(3);
    root->left->left  = insert(4);
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
}
