#include <iostream>
#include <queue>
using namespace std;

class bst{
    public:
    int data;
    bst* left;
    bst* right;
    bst(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};


bst* insert(bst* root,int d){
    if(root==NULL){
        bst* newnode = new bst(d);
        return newnode;
    }
    if(d<root->data){
        root->left   = insert(root->left,d);
        
    }
    if(d>=root->data){
        root->right = insert(root->right,d);
    }
    return root;
    
}
void inorder(bst* root){
    if (root == NULL){
        return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void levelorder(bst* root){
    if (root == NULL){
        return;
	}
	queue <bst*> q;
	q.push(root);
	while(!q.empty()){
	    bst* top = q.front();
	    cout<<top->data<<" ";
	    q.pop();
	    if(top->left){
	        q.push(top->left);
	    }
	    if (top->right) {
			q.push(top->right);
		}
	}
}

bst* insuc(bst* root){
    bst* curr  = root;
    while(curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}

bst* del(bst* root, int d){
    if(root==NULL) return root;
   
    if(d<root->data){
        root->left=del(root->left,d);
    }
    else if(d>root->data){
        root->right = del(root->right,d);
    }
    else{
        if(root->left==NULL){
            bst* temp =root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            bst* temp = root->left;
            free(root);
            return temp;
        }
        
        //inorder succesor
        
        bst* temp = insuc(root->right);
        root->data = temp->data;
        root->right  = del(root->right,temp->data);
            
        
    }
    return root;
}
int main() {

    bst * root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);
    cout<<endl;
    levelorder(root);
    root = del(root,80);
    cout<<endl<<"after deletion"<<endl;
    inorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl<<"after deletion"<<endl;
    root = del(root,50);
    inorder(root);
    cout<<endl;
    levelorder(root);
    
    
}    
