#include <bits/stdc++.h>
using namespace std;

struct Response
{
    bool isValid;
    long long int integer;

    Response() : isValid(true), integer(0) {}
    Response(bool isValid, long long int integer) : isValid(isValid), integer(integer){};
};

Response STOI(string s)
{
    // Complete the function
    Response ans(true,0);
    int i=0;
    if(s[i]=='+' || s[i]=='-')i++;
    for(;i<s.size();i++){
        if(s[i]<'0' || s[i]>'9'){
            ans.isValid=false;
            return ans;
        }
    }
    i=0;
    int sign=0;
    if(s[i]=='+' || s[i]=='-'){
        if(s[i]=='+')sign=1;
        if(s[i]=='-')sign=-1;
        i++;
    }
    for(;i<s.size();i++){
        ans.integer*=10;
        ans.integer+=s[i]-'0';
    }
    if(sign)ans.integer*=sign;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        string s;
        cin >> s;

        Response response = STOI(s);

        if (!response.isValid)
            cout << "Invalid\n";
        else
            cout << response.integer << "\n";
    }
}