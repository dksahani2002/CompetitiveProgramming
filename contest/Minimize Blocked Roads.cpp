 #include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k; 
// void bfs1(int node ,vector<pair<int,int>>g[],vector<int>&vis,vector<int>&sub){
//     vis[node]=1;
//     sub[node]=1;
//      for(auto v:g[node]){ 
//          int neigh=v.first;
//         int weight=v.second;
//        if(!vis[neigh]) {
//            bfs1(neigh,g,vis,sub);
//             sub[node] += sub[neigh]; 
//        }
//     }
// }
// void bfs(int node , vector<pair<int,int>>g[],vector<int>&vis,int &count , int &viscity,vector<int>&sub){
//     vis[node]=1; 
//     for(auto v:g[node]){
//         int neigh=v.first;
//         int weight=v.second;
//         if(weight==0){
//             if(!vis[neigh]){
//                 viscity++;
//                 bfs(neigh,g,vis,count,viscity,sub);
                
//             }
//         }else{
//             vis[neigh]=1;
//             sub.push_back(neigh);
//             count++;
//         }
//     }
// }
int dfs(int node , int n ,vector<pair<int,int>>g[],vector<int>&infected,vector<int>&uninfected,vector<int>&visited ){
    visited[node]=1;
    int count=1;
    for(auto v:g[node]){
        int neigh=v.first;
        int weight=v.second;
        if(infected[node] && weight==0){
            infected[neigh]=1;
        }
        if(!visited[neigh]){
            int res=dfs(neigh,n,g,infected,uninfected,visited);
            if(weight==1 && infected[node])
             uninfected.push_back(res);
            count+=res;

        }
    }
    return count;
}
void solve()
{ 
    int n,k;
    cin>>n>>k; 
    vector<pair<int,int>>g[n+1];
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w; 
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    vector<int>infected(n+1,0),visited(n+1,0),uninfected;
    infected[1]=1;
    dfs(1,n,g,infected,uninfected,visited);
    int total_infected=accumulate(infected.begin(),infected.end(),0);
    int can_infect=k-total_infected;
    if(can_infect<0){
        cout<<-1<<endl;
        return;
    }
    int open=0;
    sort(uninfected.begin(),uninfected.end() );
    while(open<uninfected.size() && can_infect>=uninfected[open]){
        can_infect-=uninfected[open];
        open++;
    }
    cout<<uninfected.size()-open<<endl;
    // vector<int>vis(n+2,0),vis2(n+2,0);
    // vector<int>sub(n+1 , 0),sub1;
    // bfs1(1,g,vis2,sub);

    // vector<int>city;

    // bfs(1,g,vis,count,viscity,city);
     
    // //    for(int i=0;i<city.size();i++){
    // //        sub1.push_back(sub[city[i]]);
    // //     cout<<"city of i="<<sub1[i]<<endl;
    // // }
    // // cout<<endl;
    // if(viscity>k){
    //     cout<<-1<<endl;
    // }else{
    //     int rem=k-viscity;
    //      sort(sub1.begin(),sub1.end());
    //      int i=0;
    //      while(i<sub1.size() && rem>=sub1[i]){
    //          rem-=sub1[i];
    //          i++;
    //      }
    //      cout<<sub1.size()-i+1<<endl;
    // }
    return;
}

signed main()
{
    int t ;
    cin >> t;
    while (t--)
    {
        solve();
    }
}