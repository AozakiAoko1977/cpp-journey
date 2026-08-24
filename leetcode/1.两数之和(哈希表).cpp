#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // 哈希表解法：遍历数组时把"数值 -> 下标"存进哈希表，
    // 每步先查当前数的补数（target - nums[i]）是否已经出现过
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;           // 记录已见过的数值及其下标
        for(int  i =  0; i < nums.size(); i++ ){
            int complement = target - nums[i];  // 与当前数配对所需的另一半
            if(seen.count(complement)){         // 补数已出现过 → 找到答案
                return {seen[complement],i};    // 返回 [之前下标, 当前下标]
            }
            seen[nums[i]] = i;                  // 没找到，把当前数记进哈希表
        }
        return {};                              // 题目保证有解，此行仅为兜底
    }
};

int main() {
    Solution s;
    // 测试用例：数组中 2 + 7 = 9，答案应为下标 [0, 1]
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}