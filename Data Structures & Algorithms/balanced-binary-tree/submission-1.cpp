class Solution {
    public:
    int h(TreeNode* n) {
    if (!n) return 0;
    int l = h(n->left), r = h(n->right);
    if (l < 0 || r < 0 || abs(l - r) > 1) return -1;
    return 1 + max(l, r);
    }
    bool isBalanced(TreeNode* root) {
    return h(root) >= 0;
    }
    };