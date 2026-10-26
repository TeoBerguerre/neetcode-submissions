class Solution {
    int best;
    int gain(TreeNode* n) {
        if (!n) return 0;
        int l = max(0, gain(n->left)), r = max(0, gain(n->right));
        best = max(best, n->val + l + r);
        return n->val + max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) { best = INT_MIN; gain(root); return best; }
};