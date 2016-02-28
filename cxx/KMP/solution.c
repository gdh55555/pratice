#include <iostream>
#include <vector>

class Solution{
public:
    void getNext(vector<int>& next, string& needle){
        int i = 0;
        int j = -1;
        next[i] = j;
        while(i < needle.length()){
            while(j != -1 && needle[j] != needle[i])
                j = next[j];
            ++i;
            ++j;
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle){
        vector<int> next(needle.length(), -1);
        int h = haystack.length();
        int n = needle.length();
        if(n == 0)
            return 0;
        if(h == 0 && n != 0)
            return -1;
        getNext(next, needle);
        int  i = 0, j = 0;
        while(i < h){
            while(j != -1 && haystack[i] != needle[j])
                j = next[j];
            i++;
            ++j;
            if(j == n)
                return i-j;
        }
        return -1;
    }
};
