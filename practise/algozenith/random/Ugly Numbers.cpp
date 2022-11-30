#include <bits/stdc++.h>
using namespace std;
#define int long long
int uglyarr[10001];
vector<int>ans(1501);
// int ugly(int n){
//     if(n==1|| n==2|| n==3 || n==4 || n==5)return n;
//     set<int>st;
//     st.insert(1);
//     n--;
//     while(n){
//         int val=*st.begin();
//         ans.push_back(val);
//         st.erase(st.begin());
//         st.insert(2*val);
//         st.insert(3*val);
//         st.insert(5*val);
//         n--;

//     } 
//     return *st.begin();
// }
void ugly(int n){
    int a=1,b=1,c=1;
    uglyarr[0]=1;
    uglyarr[1]=2;
    for(int i=2;i<n;i++){
        uglyarr[i]=min({uglyarr[a]*2,uglyarr[b]*3,uglyarr[c]*5});
        if(uglyarr[i]==uglyarr[a]*2)a++;
        if(uglyarr[i]==uglyarr[b]*3)b++;
        if(uglyarr[i]==uglyarr[c]*5)c++;
    }

}
void solve()
{ 
    int n;
    cin>>n;
    cout<<uglyarr[n-1]<<endl;

}

signed main()
{
    int t=1;
    cin >> t;
    //  memset(uglyarr,0,sizeof(uglyarr));
     ugly(10001);
    ugly(1001);
    while (t--)
    {
        solve();
    }
}