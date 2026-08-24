#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // 核心思路：计数数组先统计每个字母出现次数，再按原字符串顺序找第一个次数为 1 的字母
    int firstUniqChar(string s) {
        int count[26] = {0};                 // 计数数组，下标对应 a~z
        for(char ch : s){
            count[ch-'a']++;                 // 统计每个字母出现次数
        }
        for(int i = 0 ; i < s.size(); i++ ){
            if(count[s[i] - 'a' ] == 1){     // 第一个只出现一次的字母
                return i;                    // 返回它的下标
            }
        }
        return -1;                           // 没有唯一字符
    }
};

int main() {
    Solution sol;
    cout << "leetcode     → " << sol.firstUniqChar("leetcode") << endl;     // 预期 0
    cout << "loveleetcode → " << sol.firstUniqChar("loveleetcode") << endl; // 预期 2
    cout << "aabb         → " << sol.firstUniqChar("aabb") << endl;         // 预期 -1
    return 0;
}
