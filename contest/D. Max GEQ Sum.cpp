#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int arr[100100];
int t[400400];
void build(int index , int l , int r){
    if(l==r){
        t[index]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    // t[index]=t[2*index]+t[2*index+1];
    t[index]=min(t[2*index],t[2*index+1]); 

}
void update(int index,int l , int r , int pos , int val){
    if(pos<l || pos>r){
        return;
    }
    if(l==r){
        t[index]=val;
        arr[l]=val;
        return;
    }
    int mid=(l+r)/2;
    update(index*2,l,mid,pos,val);
    update(index*2+1,mid+1,r,pos,val);
    t[index]=min(t[2*index],t[2*index+1]); 
}
int query(int index, int l , int r, int lq, int rq){
    if(l>rq || lq>r){
        return INT_MAX;
    }
    if(lq<=l && r<=rq){
        return t[index];
    }
    int mid=(l+r)/2;
    return min(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
}
void solve()
{  
    cin>>n;
    //  vector<int>v(n);
     for(int i=0;i<n;i++)cin>>arr[i];
     build(1,0,n-1);
     int q;
     cin>>q;
     for(int i=0;i<q;i++){
         int ch;
         cin>>ch;
         if(ch==1){
             int x,v;
             cin>>x>>v;
             update(1,0,n-1,x,v);
         }else{
             int l,r;
             cin>>l>>r;
            cout<< query(1,0,n-1,l,r);
         }
     }
    return;
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
