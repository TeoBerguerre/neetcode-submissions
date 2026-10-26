class Solution {
    public:
    bool same(TreeNode* p, TreeNode* q) {
    if (!p || !q) return p == q;
    return p->val == q->val && same(p->left, q->left) && same(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return !subRoot;
    return same(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    };