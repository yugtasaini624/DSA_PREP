/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.Return the merged string.

Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q r s

Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:  p   q 
merged: a p b q c   d

Constraints:
    1 <= word1.length, word2.length <= 100
    word1 and word2 consist of lowercase English letters.
*/

#include<iostream>
#include<string>
using namespace std;

string mergeAlternately(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();

    string res = "";
    int i = 0, j = 0;

    while(i < n1 && j < n2){
        res += word1[i++];
        res += word2[j++];
    }

    while(i < n1)
        res += word1[i++];

    while(j < n2)
        res += word2[j++];

    return res;
}

int main(){
    string s1, s2;
    cout<<"Enter two strings: ";
    cin>>s1>>s2;

    cout<<"Merged string is: "<<mergeAlternately(s1,s2);
}