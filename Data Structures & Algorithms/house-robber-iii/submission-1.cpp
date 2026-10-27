class Solution {
    public:
    pair<int,int> go(TreeNode* n) {
    if (!n) return {0, 0};
    auto l = go(n->left), r = go(n->right);
    int take = n->val + l.second + r.second;
    int skip = max(l.first, l.second) + max(r.first, r.second);
    return {take, skip};
    }
    int rob(TreeNode* root) {
    auto p = go(root);
    return max(p.first, p.second);
    }
    };