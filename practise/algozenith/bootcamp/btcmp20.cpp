#include <bits/stdc++.h>
using namespace std;

void MovingZeros(vector <int>& nums) {
	int j=0,i=0;
    while(j<nums.size()){
        if(nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
        }else{
            j++;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector <int> nums(n);
	for (auto &i : nums)
		cin >> i;
	MovingZeros(nums);
	for (auto i : nums)
		cout << i << " ";
}