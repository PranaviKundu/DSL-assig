#include <iostream>
using namespace std;

// Node structure for Threaded BST
struct Node {
    int key;
    Node *left, *right;
    bool isThreaded;

    Node(int val) {
        key = val;
        left = right = nullptr;
        isThreaded = false;
    }
};

class ThreadedBST {
    Node* root;

public:
    ThreadedBST() { root = nullptr; }

    // Insert function that correctly maintains threading
    void insert(int key) {
        Node* newNode = new Node(key);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* curr = root;
        Node* parent = nullptr;

        while (curr) {
            parent = curr;
            if (key < curr->key) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    newNode->right = curr; // Threading
                    newNode->isThreaded = true;
                    return;
                }
                curr = curr->left;
            } else {
                if (curr->isThreaded || curr->right == nullptr) {
                    newNode->right = curr->right; // Maintain threading
                    newNode->isThreaded = true;
                    curr->right = newNode;
                    curr->isThreaded = false;
                    return;
                }
                curr = curr->right;
            }
        }
    }

    // Inorder traversal using threading
    void inorder() {
        Node* curr = root;
        if (!curr) {
            cout << "Tree is empty.\n";
            return;
        }

        // Move to leftmost node
        while (curr && curr->left)
            curr = curr->left;

        cout << "Inorder Traversal: ";
        while (curr) {
            cout << curr->key << " ";
            if (curr->isThreaded) {
                curr = curr->right; // Follow thread
            } else {
                curr = curr->right;
                while (curr && curr->left) // Move to leftmost node
                    curr = curr->left;
            }
        }
        cout << endl;
    }

    // Preorder traversal (recursive)
    void preorder(Node* node) {
        if (!node) return;
        cout << node->key << " ";
        if (node->left) preorder(node->left);
        if (!node->isThreaded) preorder(node->right);
    }

    void preorder() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    // Function to convert a normal BST to a Threaded BST
    void convertToThreaded() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }

        Node* prev = nullptr;
        convertToThreadedUtil(root, prev);
        cout << "The tree has been converted to a Threaded Binary Search Tree.\n";
    }

private:
    void convertToThreadedUtil(Node* curr, Node*& prev) {
        if (!curr) return;

        // Convert left subtree
        convertToThreadedUtil(curr->left, prev);

        // Process current node
        if (prev && prev->right == nullptr) {
            prev->right = curr;
            prev->isThreaded = true;
        }
        prev = curr;

        // Convert right subtree only if it's not already threaded
        if (!curr->isThreaded)
            convertToThreadedUtil(curr->right, prev);
    }

public:
 
    void menu() {
        int choice, value;
        do {
            cout << "\nMenu:\n";
            cout << "1. Insert a node\n";
            cout << "2. Inorder Traversal\n";
            cout << "3. Preorder Traversal\n";
            cout << "4. Convert to Threaded BST\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    insert(value);
                    break;
                case 2:
                    inorder();
                    break;
                case 3:
                    preorder();
                    break;
                case 4:
                    convertToThreaded();
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 5);
    }
};


int main() {
    ThreadedBST tbst;
    tbst.menu();  
    return 0;
}