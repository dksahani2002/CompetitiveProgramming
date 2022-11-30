#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
class LRUCache{
    list<int>order;
    unordered_map<int,pair<int,list<int>::iterator>>cache;
    int maxsize=0;
    void touch(int id){
        auto it=cache.find(id);
        order.erase(it->second.second);
        order.push_front(id);
        it->second.second=order.begin();
    }
    public:
     LRUCache(int capacity){
        maxsize=capacity;
        order.clear();
        cache.clear();
     }
    int get(int key);
    void put(int key,int value);
};
int LRUCache::get(int key){
    if(cache.find(key)==cache.end()){
        return -1;
    }
    touch(key);
    return cache[key].first;
}
 void LRUCache::put(int key, int value){
    if(cache.find(key)==cache.end()){
        if(cache.size()==maxsize){
            int del=order.back();
            order.pop_back();
            cache.erase(del);
        }
        order.push_front(key);
    }else{
        touch(key);
    }
    cache[key]=make_pair(value,order.begin());
}
void solve()
{
    LRUCache ob(3);
    ob.put(3,9);
    ob.put(7,6);
    cout<<ob.get(3)<<endl;
    ob.put(9,6);
    ob.put(10,6);
    cout<<ob.get(7)<<endl;


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