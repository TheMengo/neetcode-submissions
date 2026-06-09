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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        queue<TreeNode*> tree_q;
        tree_q.push(root);
        while(!tree_q.empty()){
            TreeNode* curr_node = tree_q.front();
            tree_q.pop();
            swap(curr_node->left, curr_node->right);
            if(curr_node->left){
                tree_q.push(curr_node->left);
            }
            if(curr_node->right){
                tree_q.push(curr_node->right);
            }
        }
        return root;
    }
};
