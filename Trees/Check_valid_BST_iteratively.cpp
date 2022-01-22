/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct Node{
    long leftBound;
    long rightBound;
    TreeNode *root;
    Node(TreeNode *root, long leftBound, long rightBound) : root(root), leftBound(leftBound), rightBound(rightBound) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        
        queue<Node*>q;
        Node* newnode = new Node(root, LONG_MIN, LONG_MAX);
        q.push(newnode);
        
        while(!q.empty()) {
            Node* p = q.front();
            q.pop();
            
            if(!((p->root->val < p->rightBound) && (p->root->val>p->leftBound))) {
                return false;
            }
            
            if(p->root->left) {
                Node* newnode = new Node(p->root->left, p->leftBound, p->root->val);
                q.push(newnode);
            }
            if(p->root->right) {
                Node* newnode = new Node(p->root->right, p->root->val, p->rightBound);
                q.push(newnode);
            }
        }
        return true;
    }
};