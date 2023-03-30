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

void inorder(TreeNode *root,vector<int> &inord){
    //base case
    if(root==NULL){
        return ;
    }

    inorder(root->left,inord);
    inord.push_back(root->val);
    inorder(root->right,inord);
}

bool validate(vector<int> inorder){
    for(int i=0;i<inorder.size()-1;i++){
        if(inorder[i]>=inorder[i+1]){
            return false;
        }
    }
    return true;
}

bool validateBST(TreeNode *root) {
    //step1: find the inorder traversal
    vector<int> inord;
    inorder(root,inord);

    //validate if the inorder is sorted
    bool ans=validate(inord);

    return ans;
}
    bool isValidBST(TreeNode* root) {
        bool ans=validateBST(root);
        return ans;
    }
};
