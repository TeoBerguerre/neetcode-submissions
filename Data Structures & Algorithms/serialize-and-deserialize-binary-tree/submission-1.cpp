class Codec {
    public:
    void ser(TreeNode* n, string& out) {
    if (!n) { out += "N,"; return; }
    out += to_string(n->val) + ",";
    ser(n->left, out); ser(n->right, out);
    }
    string serialize(TreeNode* root) {
    string out;
    ser(root, out);
    return out;
    }
    TreeNode* des(const string& s, size_t& i) {
    size_t j = s.find(',', i);
    string tok = s.substr(i, j - i);
    i = j + 1;
    if (tok == "N") return nullptr;
    TreeNode* n = new TreeNode(stoi(tok));
    n->left = des(s, i);
    n->right = des(s, i);
    return n;
    }
    TreeNode* deserialize(string data) {
    size_t i = 0;
    return des(data, i);
    }
    };