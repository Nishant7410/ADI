#include<iostream>
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
int lowestCommonAncestor(struct tree* root, int k1, int k2)
{
if(root==NULL)
  return -1;
  if(root->data>k1 && root->data>k2)
    return lowestCommonAncestor(root->left,k1,k2);
  if(root->data<k1 && root->data<k2)
    return lowestCommonAncestor(root->right,k1,k2);
  return root->data;
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
    int k1,k2;
    cin>>k1>>k2;
    int c=lowestCommonAncestor(root,k1,k2);
    cout<<c;

}



