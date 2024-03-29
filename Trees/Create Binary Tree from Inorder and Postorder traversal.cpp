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
 //steps: as postorder is LRN and inorder is LNR, so travelling in reverse direction will give the root nodes 
class Solution {
public:
    int findPosition(vector<int> inorder,int element,int n){
        for(int i=0;i<n;i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode *solve(vector<int> &inorder,vector<int> &postorder,int &index,int inorderStart,int inorderEnd,int n){
        //base case
        if(index<0 || inorderStart>inorderEnd){
            return NULL;
        }

        int element=postorder[index--];
        TreeNode *root=new TreeNode(element);
        int position=findPosition(inorder,element,n);

        //recursive call
        root->right=solve(inorder,postorder,index,position+1,inorderEnd,n);
        root->left=solve(inorder,postorder,index,inorderStart,position-1,n);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int index=n-1;
        TreeNode *ans=solve(inorder,postorder,index,0,n-1,n);
        return ans;
    }
};
