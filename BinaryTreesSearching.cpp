#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert into a normal Binary Tree (level order)
Node* insertNode(Node* root, int val) {
    if (!root) return new Node(val);
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if (!temp->left) {
            temp->left = new Node(val);
            break;
        } else {
            q.push(temp->left);
        }
        
        if (!temp->right) {
            temp->right = new Node(val);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// Insert into a BST
Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Search in BST
bool searchBST(Node* root, int val) {
    if (!root) return false;
    if (root->data == val) return true;
    return val < root->data ? searchBST(root->left, val) : searchBST(root->right, val);
}

// Find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

// Delete a node from BST
Node* deleteBST(Node* root, int val) {
    if (!root) return nullptr;
    if (val < root->data)
        root->left = deleteBST(root->left, val);
    else if (val > root->data)
        root->right = deleteBST(root->right, val);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

// Preorder Traversal
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Level Order Traversal
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

// Clone Tree
Node* cloneTree(Node* root) {
    if (!root) return nullptr;
    Node* newNode = new Node(root->data);
    newNode->left = cloneTree(root->left);
    newNode->right = cloneTree(root->right);
    return newNode;
}

// Check if Two Trees are Equal
bool isEqual(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return (root1->data == root2->data && isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right));
}

// Create Mirror Image
Node* mirrorImage(Node* root) {
    if (!root) return nullptr;
    Node* newNode = new Node(root->data);
    newNode->left = mirrorImage(root->right);
    newNode->right = mirrorImage(root->left);
    return newNode;
}

// Find Height of Tree
int treeHeight(Node* root) {
    if (!root) return 0;
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

// Create BST from an array
Node* createBST(int arr[], int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);
    root->left = createBST(arr, start, mid - 1);
    root->right = createBST(arr, mid + 1, end);
    return root;
}

// Menu-driven program
int main() {
    Node* root = nullptr;
    Node* bstRoot = nullptr;
    int choice, val, arr[] = {1, 2, 3, 4, 5, 6, 7};
    
    do {
        cout << "\n------------- Menu -------------\n";
        cout << "1. Insert into Binary Tree\n";
        cout << "2. Insert into BST\n";
        cout << "3. Search in BST\n";
        cout << "4. Delete from BST\n";
        cout << "5. Create BST from Array\n";
        cout << "6. Preorder Traversal\n";
        cout << "7. Inorder Traversal\n";
        cout << "8. Postorder Traversal\n";
        cout << "9. Level Order Traversal\n";
        cout << "10. Clone Tree\n";
        cout << "11. Check if Two Trees are Equal\n";
        cout << "12. Create Mirror Image\n";
        cout << "13. Find Tree Height\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert in Binary Tree: ";
                cin >> val;
                root = insertNode(root, val);
                break;
            case 2:
                cout << "Enter value to insert in BST: ";
                cin >> val;
                bstRoot = insertBST(bstRoot, val);
                break;
            case 3:
                cout << "Enter value to search in BST: ";
                cin >> val;
                cout << (searchBST(bstRoot, val) ? "Found\n" : "Not Found\n");
                break;
            case 4:
                cout << "Enter value to delete from BST: ";
                cin >> val;
                bstRoot = deleteBST(bstRoot, val);
                break;
            case 5:
                bstRoot = createBST(arr, 0, 6);
                cout << "BST Created from Array.\n";
                break;
            case 6:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;
            case 7:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 8:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;
            case 9:
                cout << "Level Order: ";
                levelOrder(root);
                cout << endl;
                break;
            case 10:
                cout << "Cloned Tree (Inorder): ";
                inorder(cloneTree(root));
                cout << endl;
                break;
            case 13:
                cout << "Height of tree: " << treeHeight(root) << endl;
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}