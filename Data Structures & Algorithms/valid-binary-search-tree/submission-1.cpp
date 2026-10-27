class Solution {
    public:
    bool ok(TreeNode* n, long long lo, long long hi) {
    if (!n) return true;
    if (n->val <= lo || n->val >= hi) return false;
    return ok(n->left, lo, n->val) && ok(n->right, n->val, hi);
    }
    bool isValidBST(TreeNode* root) {
    return ok(root, LLONG_MIN, LLONG_MAX);
    }
    };