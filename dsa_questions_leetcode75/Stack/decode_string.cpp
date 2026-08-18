/*
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
The test cases are generated so that the length of the output will never exceed 105.

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Constraints:
    1 <= s.length <= 30
    s consists of lowercase English letters, digits, and square brackets '[]'.
    s is guaranteed to be a valid input.
    All the integers in s are in the range [1, 300].
*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

string decodeString(string s) {
    if(s.length() == 0) return s;
   
    string ans = "";
    int currNum = 0;
    stack<int> intStack;
    stack<string> strStack;

    for(auto &x : s) {
        if(x >= '0' && x <= '9') { 
            currNum = (currNum * 10) + (x - '0');
        } 
        else { 
            if(x == '[') {
                intStack.push(currNum);
                currNum = 0;
                    
                string temp = "";
                temp += x;
                strStack.push(temp);
            }
            else if(x == ']') {
                string temp = "";
                while(!strStack.empty() && strStack.top() != "[") {
                    temp = strStack.top() + temp;
                    strStack.pop();
                }
                strStack.pop(); 
                    
                int num = intStack.top();
                intStack.pop();
                    
                string temp_ans = "";
                for(int i = 0; i < num; ++i) {
                    temp_ans += temp;
                }
                   
                strStack.push(temp_ans);
            } 
            else {
                string temp = "";
                temp += x;
                strStack.push(temp);
            }
        }
    }
        
    while(!strStack.empty()) {
        ans = strStack.top() + ans;
        strStack.pop(); 
    }
        
    return ans;
}

int main(){
    string s;
    cin>>s;

    string a = decodeString(s);
    cout<<a;
}
