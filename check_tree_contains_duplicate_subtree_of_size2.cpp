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
unordered_set<string> subtrees; 
char MARKER='$';
string dupSubUtil(node *root) 
{ 
    string s = ""; 
   
    if (root == NULL) 
        return s + MARKER; 
   
    string lStr = dupSubUtil(root->left); 
    if (lStr.compare(s) == 0) 
       return s; 
    string rStr = dupSubUtil(root->right); 
    if (rStr.compare(s) == 0) 
       return s; 
  
    s = s + to_string(root->data) + lStr + rStr; 
  
    if (s.length() > 3 && 
        subtrees.find(s) != subtrees.end()) 
       return ""; 
  
    subtrees.insert(s); 
  
    return s; 
} 
bool dupSub(node *root)
{
    subtrees.clear();
    bool f;
     string str=dupSubUtil(root);
     (str.compare("") == 0) ? f=true: f=false; 
     if(f)
     return true;
     return false;
}
int main()
{
    node *root=new node(30);
    root->left=new node(20);
    root->right=new node(50);
    root->left->left=new node(10);
    root->right->left=new node(40);
    root->right->right=new node(60);
    root->right->right->right=new node(70);
    if(dupSub(root))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}