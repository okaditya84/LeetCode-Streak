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
    int distributeCoins(TreeNode* root) {
        int moves=0;
        //declare a function dfs with return values as [size,coins]
        function<pair<int,int>(TreeNode*)> dfs = [&](TreeNode* root){
            if (root == NULL){
                return make_pair(0,0);
            }
            auto left = dfs(root->left);
            auto right = dfs(root->right);
            int size = left.first + right.first + 1;
            int coins = left.second + right.second + root->val;
            moves += abs(coins - size);
            return make_pair(size,coins);
        };
        dfs(root);
        return moves;
        


    }
};