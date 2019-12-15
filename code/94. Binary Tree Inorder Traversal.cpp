//
// Created by bin gao on 2019-10-25.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;

        auto p = root;
        while(p || stk.size()){
            while(p){
                stk.push(p);
                p = p -> left;
            }
            p = stk.top();
            res.push_back(p -> val);
            stk.pop();
            p = p -> right;
        }
        return res;

    }
};