class Solution {
    int h(TreeNode* n) {
        if (!n) return 0;
        int l = h(n->left); if (l < 0) return -1;
        int r = h(n->right); if (r < 0) return -1;
        if (abs(l - r) > 1) return -1;
        return 1 + max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) { return h(root) >= 0; }
};