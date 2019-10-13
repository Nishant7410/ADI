#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
void insert(Node* &root,Node *temp)
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
  void printlevel(struct Node *root)
{
    if(root==NULL)
        return;
     queue<struct Node*>q;
     struct Node *temp=root;
    while(temp)
    {
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        cout<<temp->data<<" ";
        temp=q.front();
        q.pop();
    }
}
int main()
{
    Node *root=NULL;
    while(1)
    {
        int n;
        cin>>n;
        if(n==-1)
            break;
        else
        {
           Node *temp=new Node();
           temp->data=n;
            insert(root,temp);
        }
    }
    printlevel(root);
}


