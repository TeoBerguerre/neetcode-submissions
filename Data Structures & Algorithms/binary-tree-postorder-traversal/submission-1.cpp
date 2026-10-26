class Solution {
    public:
    void go(TreeNode* n, vector<int>& out) {
    if (!n) return;
    go(n->left, out); go(n->right, out); out.push_back(n->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
    vector<int> out;
    go(root, out);
    return out;
    }
    };