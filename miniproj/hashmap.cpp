 #include <bits/stdc++.h>
 using namespace std;
 #define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #define int long long
 const int mod=1e9+7;
 class Hash{
    int bucket;
    list<int>*table;
    public:
        Hash(int v);
        void insertItem(int x);
        void deleteItem(int key);
        int hashFunction(int x){
            return (x%bucket);
        }
        void displayHash();
 };
 Hash::Hash(int v){
    this->bucket=v;
    table=new list<int>[bucket];
 }
 void Hash::insertItem(int key){
    int index=hashFunction(key);
    table[index].push_back(key);
 }
 void Hash::deleteItem(int key){
    int index=hashFunction(key);
    auto i=table[index].begin();
    for(;i!=table[index].end();i++){
        if(*i==key)break;
    }
    if(i!=table[index].end()){
        table[index].erase(i);
    }
 }
 void Hash::displayHash(){
    for(int i=0;i<bucket;i++){
        for(auto x:table[i]){
            cout<<"-->"<<x;
        }
        cout<<endl;
    }
 }
 void solve()
 {
    int n;cin>>n;
    Hash h(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        h.insertItem(x);
    }
    h.deleteItem(12);
    h.displayHash();
 }
 signed main()
 {
     fast;
     int t=1;
    //  cin >> t;
     while (t--)
     {
         solve();
     }
 }