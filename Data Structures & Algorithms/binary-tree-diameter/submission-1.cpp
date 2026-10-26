class Solution {
    public:
    int best = 0;
    int h(TreeNode* n) {
    if (!n) return 0;
    int l = h(n->left), r = h(n->right);
    best = max(best, l + r);
    return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
    h(root);
    return best;
    }
    };