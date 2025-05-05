#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *leftChild;
    TreeNode *rightChild;
    bool leftThread, rightThread;
    
    TreeNode() {
        leftChild = nullptr;
        rightChild = nullptr;
        leftThread = rightThread = true;
    }
    
    TreeNode(int value) {
        data = value;
        leftChild = nullptr;
        rightChild = nullptr;
        leftThread = rightThread = true;
    }
};

void inorderTraversal(TreeNode *root, vector<TreeNode *> &nodes) {
    if (root == nullptr)
        return;
    inorderTraversal(root->leftChild, nodes);
    nodes.push_back(root);
    inorderTraversal(root->rightChild, nodes);
}

void insertTBST(TreeNode *&root, int value) {
    TreeNode *newNode = new TreeNode(value);
    if (root->leftChild == nullptr) {
        root->leftChild = newNode;
        newNode->leftChild = root;
        newNode->rightChild = root;
        return;
    }
    TreeNode *current = root->leftChild;
    while (true) {
        if (current->data > value) {
            if (current->leftThread) {
                newNode->leftChild = current->leftChild;
                current->leftChild = newNode;
                current->leftThread = false;
                newNode->rightChild = current;
                return;
            } else {
                current = current->leftChild;
            }
        } else {
            if (current->rightThread) {
                newNode->rightChild = current->rightChild;
                current->rightChild = newNode;
                current->rightThread = false;
                newNode->leftChild = current;
                return;
            } else {
                current = current->rightChild;
            }
        }
    }
}

TreeNode *findLeftmost(TreeNode *nodePtr, TreeNode *dummy) {
    if (nodePtr == nullptr)
        return nullptr;

    while (!nodePtr->leftThread && nodePtr->leftChild != dummy)
        nodePtr = nodePtr->leftChild;

    return nodePtr;
}

void printInorderTBST(TreeNode *root) {
    TreeNode *dummyNode = root;
    TreeNode *current = findLeftmost(root->leftChild, dummyNode);
    cout << "Inorder traversal of threaded binary tree:" << endl;
    while (current != dummyNode) {
        cout << current->data << " ";
        if (current->rightThread)
            current = current->rightChild;
        else
            current = findLeftmost(current->rightChild, dummyNode);
    }
}

void insertBST(TreeNode *&root, int value) {
    TreeNode *newNode = new TreeNode(value);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    TreeNode *current = root;
    while (true) {
        if (current->data > value) {
            if (current->leftChild == nullptr) {
                current->leftChild = newNode;
                return;
            } else {
                current = current->leftChild;
            }
        } else {
            if (current->rightChild == nullptr) {
                current->rightChild = newNode;
                return;
            } else {
                current = current->rightChild;
            }
        }
    }
}

TreeNode *convertBSTtoTBST(TreeNode *&root, vector<TreeNode *> inorderNodes) {
    TreeNode *dummy = new TreeNode(1000);
    dummy->leftChild = root;
    dummy->rightChild = dummy;
    dummy->leftThread = false;
    int index = 0;

    while (index < inorderNodes.size()) {
        if (inorderNodes[index]->leftChild == nullptr) {
            if (index != 0)
                inorderNodes[index]->leftChild = inorderNodes[index - 1];
            else
                inorderNodes[index]->leftChild = dummy;
        } else {
            inorderNodes[index]->leftThread = false;
        }
        if (inorderNodes[index]->rightChild == nullptr) {
            if (index != inorderNodes.size() - 1)
                inorderNodes[index]->rightChild = inorderNodes[index + 1];
            else
                inorderNodes[index]->rightChild = dummy;
        } else {
            inorderNodes[index]->rightThread = false;
        }
        index++;
    }
    return dummy;
}

int main() {
    // Simple BST example
    TreeNode *bstRoot = nullptr;
    vector<TreeNode *> inorderNodes;

    // Insert nodes: 5, 3, 7 (simple balanced tree)
    insertBST(bstRoot, 5);
    insertBST(bstRoot, 3);
    insertBST(bstRoot, 7);

    // Convert BST to TBST
    inorderTraversal(bstRoot, inorderNodes);
    TreeNode *tbstRoot = convertBSTtoTBST(bstRoot, inorderNodes);
    printInorderTBST(tbstRoot);
    cout << endl;

    // Optional: Test direct TBST insertion
    /*
    TreeNode *tbstDirect = new TreeNode(999); // Dummy node
    insertTBST(tbstDirect, 5);
    insertTBST(tbstDirect, 3);
    insertTBST(tbstDirect, 7);
    printInorderTBST(tbstDirect);
    cout << endl;
    */

    return 0;
}
