#include <bits/stdc++.h>
using namespace std;

bool StringCompare(string s, string t) {
	stack<char>st;
    for(int i=0;i<s.size();i++){
        if(!st.empty() && s[i]=='#')st.pop();
        if(s[i]!='#')st.push(s[i]);
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();st.pop();
    }
     for(int i=0;i<t.size();i++){
        if(!st.empty() && t[i]=='#')st.pop();
        if(t[i]!='#')st.push(t[i]);
    }
    string res="";
    while(!st.empty()){
        res+=st.top();st.pop();
    }
    return (res==ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	if (StringCompare(s, t))
		cout << "Yes";
	else
		cout << "No";
}