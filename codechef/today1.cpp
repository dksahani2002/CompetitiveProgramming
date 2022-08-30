#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans;
int isMatching(char a, char b)
{
    if (  (a == '(' && b == ')') || a == '?')
        return 1;
    return 0;
}
 
int isBalanced(string s, stack<char> ele, int ind)
{
 
    
    if (ind == s.length()) {
        ans++;
        return ele.empty(); }
    char topEle; 
    int res; 
    if ( s[ind] == '('  ) {
        ele.push(s[ind]);
        return isBalanced(s, ele, ind + 1);
    } 
    else if (  s[ind] == ')'  ) { 
        if (ele.empty()) return 0;
 
        topEle = ele.top();
        ele.pop(); 

        if (!isMatching(topEle, s[ind])) return 0;
         
        return isBalanced(s, ele, ind + 1);
    } 
    else if (s[ind] == '?') {
        stack<char> tmp = ele;
        tmp.push(s[ind]);
        res = isBalanced(s, tmp, ind + 1);
        if (res) return 1;
        if (ele.empty())  return 0;
        ele.pop();
        return isBalanced(s, ele, ind + 1);
    }
}
void solution(){
 string s; cin>>s;
    if(s[0]=='?') s[0] = '(';
    if(s[s.size()-1]=='?') s[s.size()-1]=')';
    int c =0;
    for(auto x:s){
        if(x=='?') c++;
    }
    if(c<=1) cout<<"YES\n";
    else cout<<"NO\n";
}
signed main()
{ 
    int t=1;
    cin >> t;
    while (t--)
    {
        ans=0;
         string s;
         cin>>s;
        stack<char> ele;
        if(s.length()%2==0){
            if (isBalanced(s, ele, 0))
               if(ans==1) cout << "YES\n";   
               else{
                cout << "NO\n";

               }
            else
                cout << "NO\n";
        }
        else{
            cout << "No\n";
        } 
         

       
    } 
}

