#include <bits/stdc++.h>
using namespace std;
#define int long long


// Computes time difference of two time period
// Time periods are entered by the user
 
struct TIME
{
  int seconds;
  int minutes;
  int hours;
};

void computeTimeDifference(struct TIME, struct TIME, struct TIME *);

int main()
{
    struct TIME t1, t2, difference;

    cout << "Enter start time." << endl;
    cout << "Enter hours, minutes and seconds respectively: ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    cout << "Enter stop time." << endl;
    cout << "Enter hours, minutes and seconds respectively: ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    computeTimeDifference(t1, t2, &difference);

    cout << endl << "TIME DIFFERENCE: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds;
    cout << " - " << t2.hours << ":" << t2.minutes << ":" << t2.seconds;
    cout << " = " << difference.hours << ":" << difference.minutes << ":" << difference.seconds;
    return 0;
}
void computeTimeDifference(struct TIME t1, struct TIME t2, struct TIME *difference){
    
    if(t2.seconds > t1.seconds)
    {
        --t1.minutes;
        t1.seconds += 60;
    }

    difference->seconds = t1.seconds - t2.seconds;
    if(t2.minutes > t1.minutes)
    {
        --t1.hours;
        t1.minutes += 60;
    }
    difference->minutes = t1.minutes-t2.minutes;
    difference->hours = t1.hours-t2.hours;
}
void solve()
{
    int n,h,t;
    cin>>n>>h>>t;
    // int tot=h*60+t;
    vector<pair<int,int>>v(n);
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
            int hr,min;
            cin>>hr>>min;
            // v[i]=hr*60+min;
            if(hr>=h){
                if(min>=t){
                    v[i]={hr-h,min-t};
                }else{
                    v[i]={hr-h-1,min+60-t};
                }
            }else{

                int ti=60-t;
                int hi=23-h; 
                // cout<<ti<<" "<<min<<endl;
                // cout<<hi<<" "<<t<<endl;
                 v[i]={hi+hr+(ti+min)/60,ti+min};
                 
            }
    }
    sort(v.begin(),v.end());
     
    cout<<v[0].first<<" "<<v[0].second<<endl;

}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}