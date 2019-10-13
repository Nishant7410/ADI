#include<iostream>
#include<queue>
using namespace std;
struct tree
{
    int data;
    tree *left;
    tree *right;
};
void insert(tree* &root,tree *temp)
    {
      if(root==NULL)
      {
          root=temp;
          temp->right=NULL;
          temp->left=NULL;
          return;
      }
         else if(temp->data>root->data)
          {
            if(root->right==NULL)
                root->right=temp;
            else
              insert(root->right,temp);
          }
          else
          {
            if(root->left==NULL)
                root->left=temp;
            else
              insert(root->left,temp);
          }
    }
void findMirror(struct tree* root)
{
    queue<struct tree*>q;
    if(root==NULL)
    return;
    q.push(root);
    while(!q.empty())
    {
    struct tree *temp=q.front();
    q.pop();
    struct tree *temp1=temp->right;
    temp->right=temp->left;
    temp->left=temp1;
    if(temp->left)
      q.push(temp->left);
    if(temp->right)
      q.push(temp->right);
    }
}

int main()
{
    tree *root=NULL;
    while(1)
    {
        int n;
        cin>>n;
        if(n==-1)
            break;
        else
        {
           tree *temp=new tree();
           temp->data=n;
            insert(root,temp);
        }
    }
    findMirror(root);
}



