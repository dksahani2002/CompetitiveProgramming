#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
map<int,vector<int>>mp;
void rec(Node* root, int x, int y){
    if(!root)return;
    mp[x-y].push_back(root->val);
    rec(root->left,x-1,y+1);
    rec(root->right,x+1,y+1);
}
vector<vector<int>> getDiagonalLevelorderTraversal(Node* root) {
    mp.clear();
    rec(root,0,0);
    vector<vector<int>>ans;
    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
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
        vector<vector<int>> ans = getDiagonalLevelorderTraversal(tree);
        for(auto u:ans){
            for(auto v:u){
                cout<<v<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}