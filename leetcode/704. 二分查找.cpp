#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;                          // 左边界
        int right = nums.size() - 1;           // 右边界
        while (left <= right) {
            int mid = left + (right - left) / 2;   // 取中间（防溢出写法）
            if (nums[mid] == target) return mid;   // 找到了
            else if (nums[mid] < target) left = mid + 1;   // 目标在右边
            else right = mid - 1;                          // 目标在左边
        }
        return -1;                             // 没找到
    }
};

int main() {
    Solution s;
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    cout << "[-1,0,3,5,9,12] 找 9  → " << s.search(a, 9) << endl;     // 预期 4
    cout << "[-1,0,3,5,9,12] 找 2  → " << s.search(a, 2) << endl;     // 预期 -1
    vector<int> b = {5};
    cout << "[5] 找 5              → " << s.search(b, 5) << endl;     // 预期 0
    return 0;
}
