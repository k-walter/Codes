#include <bits/stdc++.h>
using namespace std;
#define ZERO 20000000
int cnt[40000001] = {0};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // vector<int> cnt(40000001, 0);
        cnt[ZERO] = 1; // includes sum(i) - sum(0)
        int sum = 0, ans = 0;
        // from any endpoint i
            // either sum(i) - sum(0) = k
            // or sum(i) - sum(j) = k
        for (auto &i : nums) {
            sum += i; // find current sum
            ans += cnt[sum - k + ZERO]; // find how many before adds to sum before increment
            ++cnt[sum + ZERO]; // increment
        }
        return ans;
        
        // nums.insert(nums.begin(), 0);
        // for (int i = 1; i < nums.size(); ++i)
        //     nums[i] += nums[i-1];
        // int ans = 0;
        // for (int i = 0; i < nums.size(); ++i)
        //     for (int j = i+1; j < nums.size(); ++j)
        //         if (nums[j]-nums[i] == k) ++ans;
        // return ans;
    }
};
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("subarray_sum_equalks_k.in", "r", stdin);

	Solution s;
	vector<int> a = {1,2,3};
	cout << s.subarraySum(a, 3);

	return 0;
}