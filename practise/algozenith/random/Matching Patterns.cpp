#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p)
{    
    int l=0,r=0;
    int sidx=-1,tidx=-1;
    while(l<s.size()){
        if(p[r]=='*' &&r<p.size()){ 
            sidx=r;
            tidx=l;
            r++;
        }
        else if((p[r]=='?' || p[r]==s[l]) &&r<p.size()){
            l++;
            r++;
        }
        else if(sidx==-1){
             return false;
        }else{
            r=sidx+1;
            l=tidx+1;
            tidx=l;
        }
    }
    for(int i=r;i<p.size();i++){
        if(p[i]=='*')return false;
    }
    return true;
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