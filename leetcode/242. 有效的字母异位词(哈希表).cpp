#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // 核心思路：用长度为 26 的计数数组统计字母次数，s 的字母 +1，t 的字母 -1，最后全 0 即为异位词
    bool isAnagram(string s, string t) {
        int count[26] = {0};                 // 计数数组，下标对应 a~z
        for(char c : s ){
            count[c - 'a'] ++;               // s 中出现的字母次数 +1
        }
        for(char c : t){
            count[c - 'a'] --;               // t 中出现的字母次数 -1
        }
        for(int i  = 0 ; i < 26 ; i++){
            if(count[i] != 0 ){              // 有字母次数没抵消完，说明不是异位词
                return false;
            }
        }
        return true;                         // 全部抵消，是异位词
    }
};

int main() {
    Solution sol;
    cout << "anagram/nagaram → " << (sol.isAnagram("anagram", "nagaram") ? "是" : "否") << endl;  // 预期 是
    cout << "rat/car         → " << (sol.isAnagram("rat", "car") ? "是" : "否") << endl;          // 预期 否
    return 0;
}
