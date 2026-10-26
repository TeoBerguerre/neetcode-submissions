class Solution {
    pair<int, int> go(TreeNode* n) { // (with n, without n)
        if (!n) return {0, 0};
        auto [lw, lo] = go(n->left);
        auto [rw, ro] = go(n->right);
        return {n->val + lo + ro, max(lw, lo) + max(rw, ro)};
    }
public:
    int rob(TreeNode* root) { auto [a, b] = go(root); return max(a, b); }
};