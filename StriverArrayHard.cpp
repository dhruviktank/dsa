#include <iostream>
#include <vector>
#include <map>
using namespace std;

// largest subarray sum 0
int largestSubArraySum(vector<int> nums) {
    map<int, int> prefixSum;
    int sum = 0;
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        int rem = 0-sum;
        if (sum == 0) {
            maxLen = i+1;
        } else if (prefixSum.find(rem) != prefixSum.end()) {
            int len = i - prefixSum[rem];
            maxLen = max(maxLen, len);
        } else {
            prefixSum[sum] = i;
        }
    }
    return maxLen;
}

int main() {
    vector<int> nums = {6, -2, 2, -8, 1, 7, -10};
    cout << largestSubArraySum(nums) << endl;
    return 0;
}