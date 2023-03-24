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

//  TreeNode *maketree(vector<int>& preorder, vector<int>& postorder,int &preidx,int left,int right,int size)
// {
//     if(left>right || preidx>=size)
//         return NULL;
    
//     TreeNode *root=new TreeNode(preorder[preidx]);
//     preidx++;
//     if(left==right)
//         return root;
//     int i=0;
//     for(i=left;i<=right;i++)
//     {
//         if(preorder[preidx]==postorder[i])
//             break;
//     }
//     if(i<=right)
//     {
//         root->left=maketree(preorder,postorder,preidx,left,i,size);
//         root->right=maketree(preorder,postorder,preidx,i+1,right-1,size);
//     }
//     return root;
// }

// TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
// {
//     int preidx=0;
//     return maketree(preorder,postorder,preidx,0,preorder.size()-1,preorder.size());    
// }
class Solution {
public:
 TreeNode *maketree(vector<int>& preorder, vector<int>& postorder,int &preidx,int left,int right,int size)
{
    if(left>right || preidx>=size)
        return NULL;
    
    TreeNode *root=new TreeNode(preorder[preidx]);
    preidx++;
    if(left==right)
        return root;
    int i=0;
    for(i=left;i<=right;i++)
    {
        if(preorder[preidx]==postorder[i])
            break;
    }
    if(i<=right)
    {
        root->left=maketree(preorder,postorder,preidx,left,i,size);
        root->right=maketree(preorder,postorder,preidx,i+1,right-1,size);
    }
    return root;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
{
    int preidx=0;
    return maketree(preorder,postorder,preidx,0,preorder.size()-1,preorder.size());    
}
    // int findPosition(vector<int> &postorder,int element,int last,int first){
    //     for(int i=first;i<=last;i++){
    //         if(postorder[i]==element){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    // TreeNode *solve(vector<int> &preorder,vector<int> &postorder,int &index,int first,int last,int n){
    //     //base case
    //     if(first>last || index>=n){
    //         return NULL;
    //     }
        
    //     TreeNode *temp=new TreeNode(preorder[index++]);
    //     if(left==right){
    //         return temp;
    //     }
    //     int element=preorder[index];
    //     // int position=findPosition(postorder,element,last,first);
    //     int position=0;
    //     for(position=first;position<=last;position++){
    //         if(element==postorder[position]){
    //             break;
    //         }
    //     }

    //     if(position<=last){
    //         temp->left=solve(preorder,postorder,index,first,position,n);
    //         temp->right=solve(preorder,postorder,index,position+1,last-1,n);
    //     }
    //     return temp;
    // }

    // TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    //     int index=0;
    //     int first=0;
    //     int last=postorder.size()-1;
    //     int n=preorder.size();
    //     TreeNode *ans=solve(preorder,postorder,index,first,last,n);
    //     return ans;
    // }
};
