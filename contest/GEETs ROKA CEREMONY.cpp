#include<bits/stdc++.h>
using namespace std;
int a[20001]; 
class trieNode{
    public:
        trieNode*left;
        trieNode*right;
};

void insert(int n ,trieNode*head){
    trieNode*curr=head;
    for(int i=31;i>=0;i--){
        int b=(n>>i)&1;
        if(b==0){
            if(!curr->left){
                curr->left=new trieNode();
            }
            curr=curr->left;
        }else{
              if(!curr->right){
                curr->right=new trieNode();
            }
            curr=curr->right;
        }
    }
}

int findMaxXor(trieNode*head , int *arr , int x ,int l , int r){
    int max_xor=INT_MIN;
   
    for(int i=l;i<=r;i++){
        int val=arr[i];
        trieNode*curr=head;
         int cur_xor=0;
         for(int j=31;j>=0;j--){
             int b=(val>>j)&1;
             if(b==0){
                 if(curr->right){
                     cur_xor+=pow(2,j);
                     curr=curr->right;
                 }else{
                     curr=curr->left;
                 }
             }else{
                 if(curr->left){
                     cur_xor+=pow(2,j);
                     curr=curr->left;
                 }else{
                     curr=curr->right;
                 }
             }
         }
         max_xor=max(max_xor,cur_xor);
    }
    return max_xor;
}
int main(){
    int n,q;
    cin>>n>>q;
     memset(a,0,sizeof(a));
     for(int i=0;i<n;i++){
         int l,r;
         cin>>l>>r;
         a[l]+=1;
         a[r+1]-=1;
     }
     for(int i=1;i<20001;i++){
         a[i]+=a[i-1];
     }
     while(q--){
         int l1,r1;
         cin>>l1>>r1;
         int n=r1-l1-1;
        trieNode*head = new trieNode();
        for(int i=l1;i<=r1;i++){
            insert(a[i],head);
        }
        cout<<findMaxXor(head,a,n,l1,r1)<<endl;
     }

}