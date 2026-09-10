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
    int goodNodes(TreeNode* root) {
        // Node, max value we've seen so far
        queue<pair<TreeNode*, int>> bfs;
        int res = 0;

        bfs.push({root, -INT_MAX});
        while(!bfs.empty()){
            auto [node, maxval] = bfs.front();
            bfs.pop();
            if(node->val >= maxval){
                res++;

            }
            if(node->left){
                bfs.push({node->left, max(maxval, node->val)});
            }
            if(node->right){
                bfs.push({node->right, max(maxval, node->val)});
            }
        }
        return res;
    }
};
