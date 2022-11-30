#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int dp[1001][1001];
bool rec(int i,int j){
    if(i>=s1.size() && j>=s2.size())return true;
    if(j>=s2.size())return false;
    if(i>=s1.size()){
        while(j<s2.size()){
            if(s2[j]!='*')return false;
            j++;
        }
        return true;

    }
    if(dp[i][j]!=-1)return dp[i][j];
    bool ans=false;
    if(s1[i]==s2[j] || s2[j]=='?'){
        ans= rec(i+1,j+1);
    }else if(s2[j]=='*'){
        ans= rec(i+1,j)||rec(i,j+1);
    }else ans= false;
    return  dp[i][j]=ans;
}
bool isMatch(string s, string p)
{
 s1=s,s2=p;

    for(int i=0;i<s.size();i++){
        for(int j=0;j<p.size();j++)dp[i][j]=-1;
    }
    return rec(0,0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, p;
	getline(cin, s);
	getline(cin, p);

	if (isMatch(s, p))
		cout << "Yes\n";
	else
		cout << "No\n";
}