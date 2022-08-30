#include <bits/stdc++.h>
using namespace std;
 

int main()
{
    int n;
    cin >> n ; 
    vector<int>v(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){ 
        cin>>v[i];
        mp[v[i]]++;
    }
    if(mp.size()==n){ 
        cout<<-1<<endl;
        return 0;
    }
    for(auto i:v){
        if(mp[i]==1)mp.erase(i);
    }
    int last=0;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(mp.find(v[i])!=mp.end()){
            if(v[i]<last){
                cout<<-1<<endl;
                return 0;
            }
            last=v[i];
            mp[v[i]]--;
            ans.push_back(v[i]);
            if(mp[v[i]]==1){ 
                mp.erase(v[i]); 
            }
        } 
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}