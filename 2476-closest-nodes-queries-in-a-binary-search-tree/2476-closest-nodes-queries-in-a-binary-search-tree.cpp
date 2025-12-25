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
    vector<int> inorder;

    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        // Step 1: Inorder traversal
        inorderTraversal(root);

        vector<vector<int>> result;

        // Step 2: Answer queries
        for (int q : queries) {
            int floor = -1, ceil = -1;
            int left = 0, right = inorder.size() - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (inorder[mid] == q) {
                    floor = ceil = inorder[mid];
                    break;
                }
                else if (inorder[mid] < q) {
                    floor = inorder[mid];
                    left = mid + 1;
                }
                else {
                    ceil = inorder[mid];
                    right = mid - 1;
                }
            }

            result.push_back({floor, ceil});
        }

        return result;
    }
};
