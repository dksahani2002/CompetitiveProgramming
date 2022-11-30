#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n;
int v[100100];
struct node{
    int cnt[32]={0};
    node(int val=0){
        for(int i=0;i<32;i++){
            if(val&(1<<i))cnt[i]++;
        }
    }
};
node tree[400100];
node merge(node&a,node&b){
    for(int i=0;i<32;i++){
        a.cnt[i]+=b.cnt[i];
    }
    return a;
}
void build(int index,int l,int r){
    if(l==r){
        tree[index]=node(v[l]);
        return;
    }
    int mid=(l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    tree[index] =merge(tree[2*index],tree[2*index+1]);
}
node query(int index,int l,int r, int lq, int rq){
    if(l>rq || r<lq)return node();
    if(lq<=l && r<=rq)return tree[index];
    int mid=(l+r)/2;
    node left=query(2*index,l,mid,lq,rq);
    node right=query(2*index+1,mid+1,r,lq,rq);
    return merge(left,right);
}
void solve()
{
     int q;cin>>n>>q;
    for(int i=0;i<n;i++)cin>>v[i];
    build(1,0,n-1);
    while(q--){
        int x;cin>>x;
        node ans=query(1,0,n-1,0,n-1);
        for(auto e:ans.cnt){
            cout<<e<<endl;
        }
    }
}
signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}