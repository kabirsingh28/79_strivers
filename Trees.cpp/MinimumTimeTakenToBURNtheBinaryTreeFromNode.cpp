/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

map<BinaryTreeNode<int>* , BinaryTreeNode<int>* > mpp;

BinaryTreeNode<int>* startNode=NULL;

 

void dfs(BinaryTreeNode<int>* Node, BinaryTreeNode<int>* para ,int start){

 

    if(Node == NULL)return ;

    //find parent Node

    if(Node->data == start){

        startNode = Node;

    }

    //map Node ---> parent

    mpp[Node] = para;

    dfs(Node->left , Node ,start);

    dfs(Node->right , Node ,start); 

}

 

int timeToBurnTree(BinaryTreeNode<int>* root, int start)

{

    // Write your code here

    dfs(root,NULL,start);

    //map Node -->parent tree

    // for(auto val:mpp){

    //     if(val.second!=NULL)

    //     cout<<val.first->data<<" "<<val.second->data<<"\n";

    // }

    //t -->time

    int t=0;

    map<BinaryTreeNode<int>*,int> visit;

    queue<BinaryTreeNode<int>*> q;

    q.push(startNode);

    visit[startNode]=1;

    while(q.size()){

        vector<BinaryTreeNode<int>*> temp;

        while(q.size()){

            temp.push_back(q.front());

            q.pop();

        }

        t++;

        for(auto Node:temp){

            

            if(Node->left!=NULL && visit[Node->left]==0){

                q.push(Node->left);

                visit[Node->left]=1;

            }

            if(Node->right!=NULL && visit[Node->right]==0){

                q.push(Node->right);

                visit[Node->right]=1;

            }

            if(mpp[Node]!=NULL && visit[mpp[Node]]==0){

                q.push(mpp[Node]);

                visit[mpp[Node]]=1;

            }

        }

    }

    return t-1;

}