#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
bool isBst(Node* root,int mn=INT_MIN, int mx=INT_MAX) {
    //Complete the function
    if(!root)return 1;
    if(root->val<mn || root->val>mx)return 0;
    return (isBst(root->left,mn,root->val-1) & isBst(root->right,root->val+1,mx));
}
Node* getBinaryTree(vector<int> &num, int*ind) {
    if(num[*ind] == -1)
        return NULL;
    Node* node = new Node(num[*ind]);
    (*ind)++;
    node->left = getBinaryTree(num,ind);
    (*ind)++;
    node->right = getBinaryTree(num,ind);
    return node;
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
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ind = 0;
        Node* tree = getBinaryTree(arr,&ind);
        if(isBst(tree)){
            cout<<"yes\n";
        } else {
            cout<<"no\n";
        }
    }
    return 0;
}