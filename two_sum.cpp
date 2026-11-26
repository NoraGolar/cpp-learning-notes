#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// LeetCode 1. 两数之和
// 核心思路：利用哈希表（unordered_map）将查找时间从 O(n) 降至 O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // key: 已经遍历过的值，value: 对应的索引
        for (int i = 0; i < nums.size(); ++i) {
            int need = target - nums[i]; // 还差多少
            auto it = seen.find(need);   // 在哈希表中查找
            if (it != seen.end()) {
                return {it->second, i};  // 找到了，返回两个索引
            }
            seen[nums[i]] = i;           // 没找到，将当前值和索引存入哈希表
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Result: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}