#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
bool search(node* root,int val)
{
    bool flag=false;
    if(root!=NULL)
    {
        if(root->data==val||search(root->left,val)||search(root->right,val))
        flag=true;
    
    }
    return flag;
}
int countPairs(node* root1, node* root2, int x)
{
    if(root1==NULL)
    return 0;
    
    else if(search(root2,x-root1->data))
    return 1+countPairs(root1->left,root2,x)+countPairs(root1->right,root2,x);
    else
    return countPairs(root1->left,root2,x)+countPairs(root1->right,root2,x);
}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    
    node* root1=new node(30);
    root1->left=new node(10);
    root1->right=new node(50);
    root1->left->left=new node(20);

    int ans=countPairs(root,root1,30);
    cout<<ans<<"\n";
}