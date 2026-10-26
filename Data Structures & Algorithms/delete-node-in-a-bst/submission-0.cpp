class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode* s = root->right;
            while (s->left) s = s->left;
            root->val = s->val;
            root->right = deleteNode(root->right, s->val);
        }
        return root;
    }
};