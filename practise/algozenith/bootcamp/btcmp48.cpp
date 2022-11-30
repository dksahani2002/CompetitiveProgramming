#include <bits/stdc++.h>
using namespace std;

int SuperFrequentElement(vector<int> &v)
{
    // Complete the function

    int candidate=-1,vote=0;
    for(auto x:v){
        if(vote==0){
            candidate=x;
            vote=1;
        }else{
            if(x==candidate)vote++;
            else vote--;
        }
    }
    return candidate;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    cout << SuperFrequentElement(v) << "\n";
}