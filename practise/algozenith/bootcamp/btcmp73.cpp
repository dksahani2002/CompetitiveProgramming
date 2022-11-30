#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int>pr;
int id;
map<int,int>mp;
Node* rec(int l,int r){
    if(id<0 || l>r)return NULL;
    int root_val=pr[id--];
    Node* root= new Node(root_val);
    int i=mp[root->val];
    root->right=rec(i+1,r);
    root->left=rec(l,i-1);
    return root;
}
Node* getBinaryTree(vector<int>&inorder,vector<int>&postorder)
{
  // Complete the function.
     
    pr=postorder;
    id=inorder.size()-1;
    mp.clear(); 
    for(int i=0;i<=id;i++)mp[inorder[i]]=i;
    return rec(0,id);
}
void generateArray(Node* root, vector<int>&ans){
    if(root==NULL){
        ans.push_back(-1);
        return;
      }
    ans.push_back(root->val);
    generateArray(root->left,ans);
    generateArray(root->right,ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        assert(n<=1000000);
        vector<int>arr1(n);
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        vector<int>arr2(n);
        for(int i=0;i<n;i++)
            cin>>arr2[i];
        Node* tree = getBinaryTree(arr1,arr2);
        vector<int>ans;
        generateArray(tree,ans);
        for(auto v:ans)cout<<v<<" ";
        cout<<"\n";
    }
    return 0;
}