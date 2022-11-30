#include <bits/stdc++.h>

using namespace std;
int k;
int partition(vector<int>&A,int l, int r){
    int i=l,j=l;
    for(;i<r;i++){
        if(A[i]<=A[r])
            swap(A[i],A[j++]);
    }
    swap(A[r],A[j]);
    return j;
}
int rec(vector<int>&A,int l, int r){
    int id=partition(A,l,r);
    if(id==k)return A[id];
    else if(k>id)return rec(A,id+1,r);
    return rec(A,l,id-1);
}
int quickselect(vector<int> A, int kk) 
{
    // Complete the function
    k=kk-1;
    return rec(A,0,A.size()-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> A;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    cout << quickselect(A, k) << "\n";

    return 0;
}