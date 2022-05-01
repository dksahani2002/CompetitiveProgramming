#include<bits/stdc++.h>
using namespace std;
int arr[]={4,2,1,7,9,0,10};
int main(){ 
    // int arr[7]={4,2,1,7,9,0,10};
    int n=7;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){ 
         for(int j=i+1;j<n;j++){
             if(arr[i]>arr[j]){
                 swap(arr[i],arr[j]);
             }
         }
    }
     for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
     }
    string s="durgeshwarpppp";
    map<char,int>mp;
    int i=0;
    while(s[i]!='\0'){
        mp[s[i]]++;
        i++;
    }
    char t='a';
    int frq=INT_MIN;
    for(auto i:mp){
        if(i.second>frq){
            frq=i.second;
            t=i.first;
        }
    }
    cout<<t<<" "<<frq<<" ";
}