#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left,*right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};


class Solution {
    public:
    
    Node* findLCA(Node* root, int v1, int v2) {
        // If root is null, return null
        if (root == NULL) {
            return NULL;
        }

        // If both v1 and v2 are smaller than root data LCA going in the left subtree
        if (v1 < root->data && v2 < root->data) {
            return findLCA(root->left, v1, v2);
        }
        
        // If both v1 and v2 are greater than root data LCA going in the right subtree
        if (v1 > root->data && v2 > root->data) {
            return findLCA(root->right, v1, v2);
        }
        
        // If one of v1 or v2 is smaller and the other is larger root is the LCA
        return root;
    }
    
    // Pre-order traversal
    void preOrder(Node *root) {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);  // Create a new node if root is NULL
        }
        if (data < root->data) {
            root->left = insert(root->left, data);  // Insert in the left subtree
        } else {
            root->right = insert(root->right, data);  // Insert in the right subtree
        }
        return root;  // Return the root after insertion
    }
};

int main() {
    Solution myTree;
    Node* root = NULL;
    
    int t, data;
    cin >> t;//Input number of nodes
    
    // Insert nodes into the binary search tree
    for (int i = 0; i < t; ++i) {
        cin >> data;
        root = myTree.insert(root, data);
    }

    int v1, v2;
    cin >> v1 >> v2;

    // Find and print the LCA of v1 and v2
    Node* lca = myTree.findLCA(root, v1, v2);
    cout << lca->data << endl;

    return 0;
}
