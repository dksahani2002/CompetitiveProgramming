// #include <bits/stdc++.h>
// using namespace std;

// #define ll int64_t
// #define endl '\n'
// void rec(int i,vector<vector<int>>&ans, vector<int>temp,int k , int n,int sum){
//     if(sum>n  ){
//         return;
//     }
//     if( i==10  ){
//         if(temp.size()==k && sum==n)
//             ans.push_back(temp);
//         return;
//     }
//     rec(i+1,ans,temp,k,n,sum);

//     temp.push_back(i);
//     rec(i+1,ans,temp,k,n,sum+i);
//     temp.pop_back();
// }

// vector<vector<int>> combinationSum(int k, int n) {
//     // write code here.
//     vector<vector<int>>ans;
//     vector<int>temp;
//     rec(1,ans,temp,k,n,0);
//     return ans;
// }
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'
vector<vector<int>>ans;
vector<int>temp;
void rec(int i, int k , int n,int sum){
    if(sum>n){
        return;
    }
    if( i==10){
        if(temp.size()==k && sum==n)
        	ans.push_back(temp);
        return;
    }
    temp.push_back(i);
    rec(i+1,k,n,sum+i);
    temp.pop_back();
    rec(i+1,k,n,sum);
}

vector<vector<int>> combinationSum(int k, int n) {
    // write code here.
    
    rec(1,k,n,0);
    sort(ans.begin(),ans.end());
    return ans;
}


int main(){
    int k,n;
    cin>>k>>n;
    vector<vector<int>>res=combinationSum(k,n);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}