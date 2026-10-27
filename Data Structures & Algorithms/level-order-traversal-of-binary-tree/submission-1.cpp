class Solution {
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
    int sz = q.size();
    res.push_back({});
    while (sz--) {
    TreeNode* n = q.front(); q.pop();
    res.back().push_back(n->val);
    if (n->left) q.push(n->left);
    if (n->right) q.push(n->right);
    }
    }
    return res;
    }
    };