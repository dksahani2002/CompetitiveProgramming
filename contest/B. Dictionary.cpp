 #include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
      
        vector<int>mp(26);
        // mp[0]=0;
        // for(int i=1;i<=26;i++){
        //     mp[i]=25+mp[i-1];
        // }
        // int i =mp[s[0]-'a'];
        // if(s[0]>s[1])i+=s[1]-'a'+1;
        // else i+=s[1]-'a';
        int ans=0;
        ans=25*(s[0]-'a');
        if(s[0]>s[1])ans+=s[1]-'a'+1;
        else ans+=s[1]-'a';
        cout<<ans<<endl;
        
    }
    return 0;
}