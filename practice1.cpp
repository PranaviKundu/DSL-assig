#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val){
        data= val;
        left = nullptr;
        right = nullptr;
    }
};
Node * insertNode(Node* root, int val){
    if(!root)return new Node(val);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(!temp->left){
        temp->left= new Node(val);
        break;
        }
        else{
            q.push(temp->left);
        }
        if(!temp->right){
            temp->right = new Node(val);
            break;
        }
        else{
            q.push(temp->right);
        }
    }
    return root;
    
}
//insert a node in binary search tree
Node* insertBST(Node* root, int val){
    if(!root)return new Node(val);
    if(val < root->data){
        root->left = insertBST(root->left, val);
    }
    else{
        root->right = insertBST(root->right, val);
    }
    return root;
} 
bool searchBST(Node* root, int val){
    if(!root)return false;
    if(root->data == val)return true;
    return val < root->data ? searchBST(root->left, val) : searchBST(root->right, val);
}
Node* findmin(Node* root){
    while(root->left!= nullptr) root = root->left;
    return root;
}
Node* deleteBST(Node* root, int val){
    if(!root) return nullptr;
    if(val < root->data){
        root->left = deleteBST(root->left, val);
    }
    else if(val> root->data){
        root->right = deleteBST(root->right, val);
    }
    else{
        if(!root->left){
            return root->right;
        }
        if(!root->right){
            return root->left;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}
//tree traversal
void preorder(Node* root){
    if(!root)return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
//root->left->right
void inorder(Node* root){
    if(!root)return;
    inorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}
//left-.root->right
void postorder(Node* root){
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
//left->right->root


//Level Order traversing
    // It is traversing the tree from top to bottom and fro left to right, it is done using queue as queue follows FIFO structure.
void levelOrder(Node* root){
    if(!root)return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
} 
Node* clonetree(Node* root){
    if(!root){
        return nullptr;
    }
    Node* newNode= new Node(root->data);
    newNode->left = cloneTree(root->left);
    newNode->right = cloneTree(root->right);
    return newNode;
}
bool isEqual(Node* root1, Node* root2){
    if(root1==nullptr && root2==nullptr){
        return true;
    }
    else if(root1==nullptr || root2==nullptr){
        return  false;
    }
    else if(root1->data == root2->data){
        if(isEqual(root1->left, root2->left)){
            if(isEqual(root1->right, root2->right)){
                return true;
            }
        }
        else{return false;}
    }
    return false;
}
//tree hight
int treeHight(Node* root){
    if(!root)return 0;
    return 1+max(treeHeight(root->left), treeHeight(root->right));
}

//mirror image of the tree
Node* mirrorImage(Node* root){
    if(!root)return nullptr;
    Node* newNode= new Node(root->data);
    newNode->left = mirrorImage(root->right);
    newNode->right = mirrorImage(root->left);
    return newNode;
}