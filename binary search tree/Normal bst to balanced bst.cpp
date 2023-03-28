/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorder(TreeNode<int> *root,vector<int> &ans){
    if(root==NULL){
        return ;
    }

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
TreeNode<int> *convertTobst(int start,int end,vector<int> ans){
    if(start>end){
        return NULL;
    }

    int mid=(end+start)/2;
    TreeNode<int> *temp=new TreeNode<int>(ans[mid]);
    temp->left=convertTobst(start,mid-1,ans);
    temp->right=convertTobst(mid+1,end,ans);
    return temp;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    //step1: find the inorder traversal
    vector<int> inord;
    inorder(root,inord);

    //step2: convert from inorder to bst using binary search method
    return convertTobst(0,inord.size()-1,inord);
}
