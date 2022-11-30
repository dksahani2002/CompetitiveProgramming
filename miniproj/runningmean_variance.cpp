#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
class RunningMeanVariance{
    double sum=0,sqsum=0;
    int count=0;
    public:
    void add(int x);
    double mean();
    double variance();
};
void RunningMeanVariance::add(int x){
    sum+=x;
    sqsum+=x*x;
    count+=1;
}
double RunningMeanVariance::mean(){
    return sum/count;
}
double RunningMeanVariance::variance(){
    double x=mean();
    return sqsum/count-x*x;
}
void solve()
{
    RunningMeanVariance obj;
    obj.add(5);
    obj.add(4);
    obj.add(5);
    cout<<obj.mean()<<endl;
    cout<<obj.variance()<<endl;
}
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}