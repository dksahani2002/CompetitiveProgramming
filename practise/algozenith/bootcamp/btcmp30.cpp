#include <bits/stdc++.h>
using namespace std;

void NearlySort(vector<int> &a, int k)
{
	//Complete the function
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    int i=0;
    for(int j=k;j<a.size();j++){
        pq.push(a[j]);
        a[i++]=pq.top();
        pq.pop();
    }
    while(!pq.empty()){
        a[i++]=pq.top();
        pq.pop();
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);

	for (auto &i : v)
		cin >> i;

	NearlySort(v, k);

	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	cout << "\n";

	return 0;
}