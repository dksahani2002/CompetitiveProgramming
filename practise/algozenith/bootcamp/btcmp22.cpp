#include <bits/stdc++.h>
using namespace std;

unsigned int reverseBits(unsigned int n)
{
    //add code here
   unsigned int ans=0;
    for(int i=0;i<32;i++){
        if(n&(1<<i))ans+=pow(2,31-i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        unsigned int n;
        cin >> n;
        cout << reverseBits(n) << '\n';
    }
    return 0;
}