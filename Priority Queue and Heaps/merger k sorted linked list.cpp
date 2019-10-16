#include<iostream>
#include<queue>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
  };

struct ListNode * newNode(int data)
{
	ListNode * temp=new ListNode();
	temp->val=data;
	temp->next=NULL;
	return temp;
}


 struct compare{
 bool operator()(const ListNode *lhs, const ListNode *rhs)
{
    return lhs->val > rhs->val;
}
 };

void mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode *,vector<ListNode *>,compare> minHeap;
    for(int i=0;i<A.size();i++)
    {
        minHeap.push(A[i]);
    }
    ListNode *temp;
    ListNode *head=NULL;
    ListNode *tail=NULL;
    while(!minHeap.empty())
    {
        temp=minHeap.top();
        cout<<temp->val<<" ";
        if(temp->next)
        minHeap.push(temp->next);

        minHeap.pop();
    }
}


int main()
{

	   int n;
	   cin>>n;
       vector<ListNode *> arr;
       for(int j=0;j<n;j++)
        {
           int n;
           cin>>n;
           int x;
           cin>>x;
           ListNode* temp=newNode(x);
           arr.push_back(temp);
           ListNode *curr = arr[j];
           n--;
           for(int i=0;i<n;i++)
           {
               cin>>x;
               ListNode *temp = newNode(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		mergeKLists(arr);
}

