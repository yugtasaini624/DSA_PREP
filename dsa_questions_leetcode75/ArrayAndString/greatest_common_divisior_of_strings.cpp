/*
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Example 2:
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Example 3:
Input: str1 = "LEET", str2 = "CODE"
Output: ""

Example 4:
Input: str1 = "AAAAAB", str2 = "AAA"
Output: ""​​​​​​​

Constraints:
    1 <= str1.length, str2.length <= 1000
    str1 and str2 consist of English uppercase letters.
*/

#include<iostream>
#include<string>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

string gcdOfStrings(string str1, string str2) {
    return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(str1.size(), str2.size())) : "";    
}

int main(){
    string s1, s2;
    cout<<"Enter two strings: ";
    cin>>s1>>s2;

    cout<<"GCD of "<<s1<<" and "<<s2<<" is = "<<gcdOfStrings(s1, s2);

    return 0;


}