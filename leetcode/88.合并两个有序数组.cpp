#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                --p1;
            } else {
                nums1[p] = nums2[p2];
                --p2;
            }
            --p;
        }
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            --p2;
            --p;
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution s;
    s.merge(nums1, 3, nums2, 3);
    cout << "[";
    for (int i = 0; i < nums1.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << nums1[i];
    }
    cout << "]" << endl;
    return 0;
}
