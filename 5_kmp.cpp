/**
 * leetcode 28 Implement strStr()
 */
class Solution {
public:
    void get_next(int next[], string s) {
        next[0] = -1;
        int i=0, j=-1;
        int size = s.size();
        while (i < size) {
            if (j == -1 || s[i] == s[j]) {
                i++; j++;
                next[i] = j;
            } else j = next[j];
        }
    }
    
    int match(string s1, string s2, int next[]) {
        int size1=s1.size(), size2 = s2.size();
        int i=0, j=0;
        while (i < size1 && j < size2) {
            if (j == -1 || s1[i] == s2[j]) {
                i++; j++;
            } else j = next[j];
        }
        if (j == size2) return i-size2;
        else return -1;
    }
    
    int strStr(string haystack, string needle) {
        int size = needle.size();
        if (size == 0) return 0;
        int next[size];
        get_next(next, needle);
        int ans = match(haystack, needle, next);
        return ans;
    }
};
