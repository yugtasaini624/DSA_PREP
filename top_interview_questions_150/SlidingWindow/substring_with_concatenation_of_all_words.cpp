/*
You are given a string s and an array of strings words. All the strings of words are of the same length.
A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
    For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

Example 1:
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation:
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation:
There is no concatenated substring.

Example 3:
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation:
The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

Constraints:
    1 <= s.length <= 104
    1 <= words.length <= 5000
    1 <= words[i].length <= 30
    s and words[i] consist of lowercase English letters.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<string, unsigned int> map;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;

    unsigned int length = words[0].size();

    map.clear();
    for(const string& word : words) {
        map[word]++;
    }

    for(unsigned int offset = 0; offset < length; ++offset) {
        unsigned int size = 0;

        unordered_map<string, unsigned int> seen;

        for (unsigned int i = offset;i + length <= s.size();i += length) {
            string sub = s.substr(i, length);

            auto itr = map.find(sub);

            if (itr == map.end()) {
                seen.clear();
                size = 0;
                continue;
            }

            ++seen[sub];
            ++size;

            while(seen[sub] > itr->second) {
                string first = s.substr(i - (size - 1) * length, length);
                --seen[first];
                --size;
            }
            if(size == words.size()) {
                result.push_back(i - (size - 1) * length);
            }
        }
    }
    return result;
}

int main(){
    string str;
    cin>>str;
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i = 0;i <n;i++){
        cin>>arr[i];
    }

    vector<int> res = findSubstring(str, arr);
    for(int i = 0;i < res.size();i++){
        cout<<res[i]<<" ";
    }
}