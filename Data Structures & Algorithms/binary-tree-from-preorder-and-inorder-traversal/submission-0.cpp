class Solution {
    unordered_map<int, int> pos;
    int pi = 0;
    TreeNode* build(vector<int>& pre, int l, int r) {
        if (l > r) return nullptr;
        int v = pre[pi++];
        TreeNode* n = new TreeNode(v);
        int m = pos[v];
        n->left = build(pre, l, m - 1);
        n->right = build(pre, m + 1, r);
        return n;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pos.clear(); pi = 0;
        for (int i = 0; i < (int)inorder.size(); i++) pos[inorder[i]] = i;
        return build(preorder, 0, (int)inorder.size() - 1);
    }
};