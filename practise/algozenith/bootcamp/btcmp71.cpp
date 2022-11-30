#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {

public:
	map<int,map<int,vector<int>>>mp;
    void rec(TreeNode* root, int x, int y){
        if(!root)return;
        mp[x][y].push_back(root->data);
        rec(root->left,x-1,y+1);
        rec(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        // write code here.
        mp.clear();
        rec(root,0,0);
        vector<vector<int>>ans;
        for(auto x:mp){
            vector<int>temp;
             for(auto xx:x.second){
                auto t=xx.second;
                sort(t.begin(),t.end());
                for(auto el:t)temp.push_back(el);
             }
             ans.push_back(temp);
        }
        return ans;
    }
};
































TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return nullptr;
    vector<string> dat;
    string t;
    for (auto c : data)
    {
        if (c == ',')
        {
            dat.push_back(t);
            t.clear();
        }
        else
            t.push_back(c);
    }
    dat.push_back(t);
    int i = 0;
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoll(dat[0]));
    q.push(root);
    auto cur = root;
    i++;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        if (dat[i] != "x")
        {
            x->left = new TreeNode(stoll(dat[i]));
            q.push(x->left);
        }
        i++;
        if (dat[i] != "x")
        {
            x->right = new TreeNode(stoll(dat[i]));
            q.push(x->right);
        }
        i++;
    }
    return root;
}

void solve() {
    string tr;
    cin >> tr;
    Solution sol;
    auto root = deserialize(tr);
    auto ans = sol.verticalTraversal(root);
    for (auto x : ans) {
        for (auto y : x)cout << y << " ";
        cout << endl;
    }
    cout << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}