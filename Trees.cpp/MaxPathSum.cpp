/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int maxpath(BinaryTreeNode<int> *root, int& maxi) {
  if (root == NULL)
    return 0;

  int left_mps = max(0,maxpath(root->left,maxi));
  int right_mps = max(0,maxpath(root->right,maxi));

  maxi = max(maxi,root->data+left_mps+right_mps);

  return root->data + max(left_mps, right_mps);
}

int maxPathSum(BinaryTreeNode<int> *root)
{
    int maxi=INT_MIN;
    maxpath(root, maxi);
    return maxi;

}