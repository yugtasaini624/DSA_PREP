/*
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

    Each letter in pattern maps to exactly one unique word in s.
    Each unique word in s maps to exactly one letter in pattern.
    No two letters map to the same word, and no two words map to the same letter.

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation:
The bijection can be established as:
    'a' maps to "dog".
    'b' maps to "cat".

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

Constraints:
    1 <= pattern.length <= 300
    pattern contains only lower-case English letters.
    1 <= s.length <= 3000
    s contains only lowercase English letters and spaces ' '.
    s does not contain any leading or trailing spaces.
    All the words in s are separated by a single space.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string get_word(const string &str, int &i) {
        string curr = "";

        while (i < str.size() && str[i] != ' ') {
            curr += str[i];
            i++;
        }

        if (i < str.size()) i++;  

        return curr;
    }

    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        int i = 0;

        for (char ch : pattern) {
            if (i >= s.size())
                return false;

            string word = get_word(s, i);

            if (mp.find(ch) == mp.end()) {
                if (rev.find(word) != rev.end())
                    return false;

                mp[ch] = word;
                rev[word] = ch;
            } else {
                if (mp[ch] != word)
                    return false;
            }
        }

        if (i < s.size())
            return false;

        return true;
    }
};

int main(){
    Solution sol;
    string pattern,s;
    cin>>pattern;
    cin.ignore();
    getline(cin,s);
    cout<<boolalpha<<sol.wordPattern(pattern,s);
    return 0;
}