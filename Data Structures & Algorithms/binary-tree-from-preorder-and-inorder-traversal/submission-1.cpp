class Solution {
    public:
    unordered_map<int, int> idx;
    int pre = 0;
    TreeNode* build(vector<int>& preorder, int lo, int hi) {
    if (lo > hi) return nullptr;
    int v = preorder[pre++];
    TreeNode* n = new TreeNode(v);
    int m = idx[v];
    n->left = build(preorder, lo, m - 1);
    n->right = build(preorder, m + 1, hi);
    return n;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < (int)inorder.size(); i++) idx[inorder[i]] = i;
    return build(preorder, 0, (int)inorder.size() - 1);
    }
    };