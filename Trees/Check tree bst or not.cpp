#include<iostream>
#include<limits.h>
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
 int bst(struct tree* root,int min,int max)
{
  if(root==NULL)
    return 1;
  if(root->data<min||root->data>max)
    return 0;
  return bst(root->left,min,root->data)&& bst(root->right,root->data,max);
}
int isBinarySearchTree(struct tree* t1)
{
if(t1==NULL)
  return 1;
  return bst(t1,INT_MIN,INT_MAX);
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
    if(isBinarySearchTree(root))
        cout<<"BST";
    else
        cout<<"No BST";
}



