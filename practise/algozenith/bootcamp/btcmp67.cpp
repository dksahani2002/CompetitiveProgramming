#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> getZigzagLevelorderTraversal(Node* root) {
  // Complete the function.
    queue<Node*>q;
    q.push(root);
    vector<vector<int>>ans;
    if(!root)return ans;
    int rev=0;
    while(!q.empty()){
        vector<int>temp;
        int sz=q.size();
        while(sz--){
            auto nod=q.front();q.pop();
            temp.push_back(nod->val);
            if(nod->left){
                q.push(nod->left);
            }
            if(nod->right){
                q.push(nod->right);
            }
        }
        if(rev){
            reverse(temp.begin(),temp.end());
        } 
        rev=1-rev;
        ans.push_back(temp);
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
        vector<vector<int>> ans = getZigzagLevelorderTraversal(tree);
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