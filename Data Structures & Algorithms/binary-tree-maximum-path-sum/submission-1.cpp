class Solution {
    public:
    int best = INT_MIN;
    int gain(TreeNode* n) {
    if (!n) return 0;
    int l = max(0, gain(n->left)), r = max(0, gain(n->right));
    best = max(best, n->val + l + r);
    return n->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
    gain(root);
    return best;
    }
    };