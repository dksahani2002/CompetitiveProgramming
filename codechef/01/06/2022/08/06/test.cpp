#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    int v[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             v[i][j]+=v[i][j-1];
        }
    }
    
    int sum=0;
    for(int l=0;l<n;l++){
        for(int r=l;r<m;r++){
            int temp=0; 
            for(int k=0;k<n;k++){
                temp+=v[k][r]-v[k][l];
                if(temp<0){
                    temp=0;
                }else{
                    sum=max( sum,temp);
                }
            }
        }
    }  
    cout<<sum<<endl;    
     
}
int main() {
	int t;cin>>t;
	while(t--)solve();
	return 0;
}