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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> bfs;
        vector<vector<int>> res;
        if(!root){
            return res;
        }

        bfs.push(root);
        while(!bfs.empty()){
            vector<int> level;
            int size = bfs.size();
            for(int i = bfs.size(); i > 0; i--){
                TreeNode* node = bfs.front();
                bfs.pop();
                if(node){
                    level.push_back(node->val);
                    bfs.push(node->left);
                    bfs.push(node->right);
                }
            }
            if(!level.empty()){
                res.push_back(level);
            }
        }
        return res;
    }
};
