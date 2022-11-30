#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
map<string,int>mp;
struct trie{
    trie* child[26];
    bool isend;
    trie(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        isend=false;
    }
};  
trie* root;
void insert(string &word){
    trie* temp=root;
    for(int i=0;i<word.size();i++){
        int id=word[i]-'a';
        if(!temp->child[id]){
            temp->child[id]= new trie();
        }
        temp=temp->child[id];
    }
    temp->isend=true;
}
bool search(string &word){
    trie* temp=root;
    for(int i=0;i<word.size();i++){
        int id=word[i]-'a';
        if(!temp->child[id]){
            return false;
        }
        temp=temp->child[id];
    }
    return (temp->isend && temp);
}
string s;
int dp[301];
int rec(int i){
    if(i>=s.size()){
        return  1;
    }
    if(dp[i]!=-1)return dp[i];
    string t="";
    for(int j=i;j<s.size();j++){
        t+=s[j];
        if(search(t)){
            if(rec(j+1))return  dp[i]= 1;
        }
    }
    return  dp[i]=0;
}
void solve()
{
    mp.clear();
    root=new trie();
    int n;cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        string t;cin>>t;
        // mp[t]++;
        insert(t);
    }
    memset(dp,-1,sizeof(dp));
    if(rec(0)){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}