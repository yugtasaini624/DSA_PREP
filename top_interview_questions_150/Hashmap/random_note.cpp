/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:

    1 <= ransomNote.length, magazine.length <= 105
    ransomNote and magazine consist of lowercase English letters.

*/

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string a, string b) {
        unordered_map<char, int> mp;

        for(char ch: b){
            mp[ch]++;
        }

        for(char ch: a){
            if(mp.find(ch) == mp.end() || mp[ch] == 0){
                return false;
            }
            mp[ch]--;
        }

        return true;
    }
};

int main(){
    string a, b;
    cin>>a>>b;

    Solution s;

    cout<<s.canConstruct(a, b);
}