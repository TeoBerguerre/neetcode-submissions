class Solution {
    int go(TreeNode* n, int mx) {
        if (!n) return 0;
        int good = n->val >= mx;
        mx = max(mx, n->val);
        return good + go(n->left, mx) + go(n->right, mx);
    }
public:
    int goodNodes(TreeNode* root) { return go(root, INT_MIN); }
};