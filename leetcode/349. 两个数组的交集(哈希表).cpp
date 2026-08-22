#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(),nums1.end());
        vector<int> result;
        for(int i = 0 ; i < nums2.size(); i++){
            if(st.count(nums2[i])){
                result.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 2, 1};
    vector<int> b = {2, 2};
    vector<int> r1 = s.intersection(a, b);
    cout << "[1,2,2,1] ∩ [2,2] = ";
    for (int x : r1) cout << x << " ";     // 预期 2
    cout << endl;

    vector<int> c = {4, 9, 5};
    vector<int> d = {9, 4, 9, 8, 4};
    vector<int> r2 = s.intersection(c, d);
    cout << "[4,9,5] ∩ [9,4,9,8,4] = ";
    for (int x : r2) cout << x << " ";     // 预期 9 4（顺序不限）
    cout << endl;

    return 0;
}
