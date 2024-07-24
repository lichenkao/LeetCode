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
    vector<int> ans;
    int size;
    void inorder(TreeNode* root){
        if(root == NULL)
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* buildBalancedBST(const vector<int>& elements, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(elements[mid]);
        node->left = buildBalancedBST(elements, start, mid - 1);
        node->right = buildBalancedBST(elements, mid + 1, end);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        size = ans.size();
        return buildBalancedBST(ans, 0, ans.size() - 1);
    }
};