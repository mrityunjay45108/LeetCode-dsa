/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // Step 1: Find the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Found the node to delete

            // Case 1 & 2: node has 0 or 1 child
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Case 3: node has 2 children
            // Find inorder successor (minimum in right subtree)
            TreeNode* succ = findMin(root->right);
            root->val = succ->val;

            // Delete the successor
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) node = node->left;
        return node;
    }
};
