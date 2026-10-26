class Solution {
    public:
    void go(TreeNode* n, vector<int>& out) {
    if (!n) return;
    out.push_back(n->val); go(n->left, out); go(n->right, out);
    }
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int> out;
    go(root, out);
    return out;
    }
    };