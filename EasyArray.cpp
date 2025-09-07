#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

void findSecondLargestSmallestElement(vector<int> nums) {
    if (nums.size() <= 1) {
        cout << -1;
        return;
    }
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == min1 || nums[i] == min2 || nums[i] == max1 || nums[i] == max2) continue;
        if (nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        } else if (nums[i] < min2) {
            min2 = nums[i];
        }
        if (nums[i] > max1) {
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] > max2) {
            max2 = nums[i];
        }
    }
    cout << "Second Smallest " << min2 << endl;
    cout << "Second Largest " << max2 << endl;
}

vector<int> findUnion(vector<int> nums1, vector<int> nums2) {
    vector<int> ans;
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();
    while (i < n && j < m) {
        if (nums1[i] < nums2[j]) {
            if (ans.empty() || ans.back() != nums1[i]) {
                ans.push_back(nums1[i]);
            }
            i += 1;
        } else if (nums1[i] > nums2[j]) {
            if (ans.empty() || ans.back() != nums2[j]) {
                ans.push_back(nums2[j]);
            }
            j += 1;
        } else {
            if (ans.empty() || ans.back() != nums1[i]) {
                ans.push_back(nums1[i]);
            }
            i += 1;
            j += 1;
        }
    }
    while (i < n) {
        if (ans.empty() || ans.back() != nums1[i])
            ans.push_back(nums1[i]);
        i++;
    }
    while (j < m) {
        if (ans.empty() || ans.back() != nums2[j])
            ans.push_back(nums2[j]);
        j++;
    }
    return ans;
}

vector<int> longestSubArrayWithSum(vector<int> nums, int k) {
    vector<int> subArray;
    int sum = 0 ;
    int i = 0, j = 0;
    int maxLen = 0;
    // 1,7,8,9,2,3,4,5,6,10
    while (i < nums.size() && j < nums.size()) {
        if (sum >= k) {
            if (sum == k && (j - i + 1) > maxLen) {
                maxLen = j - i + 1;
                subArray.assign(nums.begin()+i, nums.begin()+j);
            }
            sum -= nums[i];
            i++;
        } else if (sum < k) {
            sum += nums[j];
            j++;
        }
        cout << i << " " << j << " " << sum << endl;
    }
    if (sum == k && (j - i + 1) > maxLen) {
        maxLen = j - i + 1;
        subArray.assign(nums.begin()+i, nums.begin()+j);
    }
    return subArray;
}

int longestSubArrayPosNeg(vector<int>& nums, int k) {
    int n = nums.size();

    map<int, int> prefixSum;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum == k) {
            maxLen = max(maxLen, i+1);
        }
        int rem = sum - k;
        if (prefixSum.find(rem) != prefixSum.end()) {
            int len = i - prefixSum[rem];
            maxLen = max(maxLen, len);
        }
        if (prefixSum.find(sum) == prefixSum.end()) {
            cout << sum << " " << i << endl;
            prefixSum[sum] = i;
        }
    }
    for (auto pair : prefixSum) {
    }
    return maxLen;
}

int majorityElement(vector<int>& nums) {
    int res = 0;
    int majority = 0;
    for (int n : nums) {
        if (majority == 0) {
            res = n;
        }
        if (n == res) {
            majority++;
        } else {
            majority--;
        }
    }
    return res;
}

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int maxUntil = nums[0];
    int a = 0;
    int b = 0;
    int maxa = 0, maxb = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] + maxSum > nums[i]) {
            maxSum = nums[i] + maxSum;
            b++;
        } else {
            maxSum = nums[i];
            a = i;
            b = i;
        }
        if (maxSum > maxUntil) {
            maxa = a;
            maxb = b;
            maxUntil = maxSum;
        }
    }
    for (int i = maxa; i <= maxb; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return maxUntil;
}

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && nums[i] < 0) {
            int j = i + 1;
            while (j < n) {
                if (nums[j] > 0) {
                    while (j > i) {
                        swap(nums[j], nums[j-1]);
                        j--;
                    }
                    break;
                }
                j++;
            }
        } else if (i % 2 == 1 && nums[i] > 0) {
            int j = i + 1;
            while (j < n) {
                if (nums[j] < 0) {
                    while (j > i) {
                        swap(nums[j], nums[j-1]);
                        j--;
                    }
                    break;
                }
                j++;
            }
        }
    }
    return nums;
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    while (i >= 0 && nums[i] > nums[i+1]) {
        i--;
    }
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[j], nums[i]);
    }
    reverse(nums.begin()+i+1, nums.end());
}

vector<int> findLeaders(vector<int>& nums) {
    vector<int> leaders;
    int max = nums[nums.size()-1];
    leaders.push_back(max);
    for (int i = nums.size()-2; i>=0; i--) {
        if (nums[i] > max) {
            max = nums[i];
            leaders.push_back(max);
        }
    }
    return leaders;
}

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, bool> map;
    for (int num : nums) {
        map[num] = true;
    }
    for (int num : nums) {
        if (map.count(num-1) > 0) {
            map[num] = false;
        }
    }
    int maxCount = 0;
    for (int num : nums) {
        if (map[num] == true) {
            int j = 0;
            while (map.count(num+j) > 0) {
                j++;
            }
            maxCount = max(maxCount, j);
        }
    }
    return maxCount;
}

int main(){
    vector<int> nums = {4, 7, 1, 0};
    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    // findSecondLargestSmallestElement(nums);
    // vector<int> unionArray = findUnion(nums, nums2);
    // int subArray = longestSubArrayPosNeg(nums2, -5);
    // maxSubArray(nums2);
    // nextPermutation(nums);
    // vector<int> leaders = findLeaders(nums);
    int consecutiveLen = longestConsecutive(nums2);
    // for (int num : leaders) {
    //     cout << num << " ";
    // }
    return 0;
}