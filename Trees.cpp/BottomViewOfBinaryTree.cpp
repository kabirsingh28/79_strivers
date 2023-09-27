#include<bits/stdc++.h>
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

vector<int> bottomView(TreeNode<int> * root){
    vector<int> ans;
    map<int,int> m;
    queue<pair<TreeNode<int>*,int>> q; // root,line
    q.push({root,0}); 

    while(!q.empty()){
        TreeNode<int> * temp = q.front().first;
        int line = q.front().second;
        m[line] = temp->data;
        if(temp->left!=NULL) q.push({temp->left,line-1});
        if(temp->right!=NULL) q.push({temp->right,line+1});
        q.pop();
    }

    for(auto it: m){
        ans.push_back(it.second);
    }

    return ans;
}
