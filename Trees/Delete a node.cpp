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

 struct tree* minValueNode(struct tree* node)
{
  struct tree* current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

 struct tree* deleteNode(struct tree* root, int key)
{
  if (root == NULL)
  {
    cout<<"Node not found"<<endl;
    return NULL;
  }
  if (key < root->data)
    root->left = deleteNode(root->left, key);

  else if (key > root->data)
   root->right = deleteNode(root->right, key);

 else
  {
    struct tree *temp = NULL;
    if (root->left == NULL && root->right == NULL)
    {
      delete(root);
      return NULL;
    }
    else if(root->left == NULL)
    {
      temp = root->right;
      delete(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      temp = root->left;
      delete(root);
      return temp;
    }

    temp = minValueNode(root->right);

    root->data = temp->data;

    root->right = deleteNode(root->right, temp->data);

  }
  return root;
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
    int key;
    cin>>key;
    deleteNode(root,key);
}



