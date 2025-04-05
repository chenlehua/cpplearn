#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <list>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
private:
    const string SEP = ",";
    const string NULL_Str = "#";

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "";
        stringstream ss;
        _serialize(root, ss);
        return ss.str();
    }

    void _serialize(TreeNode *node, stringstream &ss)
    {
        if (node == nullptr)
        {
            ss << NULL_Str << SEP;
            return;
        }
        ss << node->val << SEP;
        _serialize(node->left, ss);
        _serialize(node->right, ss);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;

        list<string> nodes;
        stringstream ss(data);
        string buf;
        while (getline(ss, buf, ','))
        {
            nodes.push_back(buf);
        }
        return _deserialize(nodes);
    }

    TreeNode *_deserialize(list<string> &nodes)
    {
        if (nodes.empty())
            return nullptr;

        string first = nodes.front();
        nodes.pop_front();
        if (first == NULL_Str)
            return nullptr;
        TreeNode *root = new TreeNode(stoi(first));

        root->left = _deserialize(nodes);
        root->right = _deserialize(nodes);

        return root;
    }
};

int main()
{
    Codec codec;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string s = codec.serialize(root);
    cout << s << endl;

    TreeNode *a = codec.deserialize(s);
    string s1 = codec.serialize(a);
    cout << s1 << endl;

    printf("hello..\n");
}
