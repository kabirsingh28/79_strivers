/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int find_height(TreeNode<int>* curr, int &dia){
    if(curr==NULL) return 0;

    int left_height=find_height(curr->left, dia);
    int right_height=find_height(curr->right, dia);

    dia=max(dia,left_height+right_height);
    
    return 1+max(left_height,right_height);
}


int diameterOfBinaryTree(TreeNode<int> *root){
	int dia=0;
    int final_height=find_height(root,dia);
    return dia;
}
