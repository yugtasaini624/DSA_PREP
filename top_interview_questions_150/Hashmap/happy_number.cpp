/*
Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:
Input: n = 2
Output: false

Constraints:
    1 <= n <= 231 - 1
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int getNext(int num) {
        int result = 0;
        while (num > 0) {
            int lastDigit = num % 10;
            result += lastDigit * lastDigit;
            num /= 10;
        }
        return result;
    }

    bool isHappy(int num) {
        if (num <= 0) return false;

        int slow = num;
        int fast = getNext(num);

        while (fast != 1 && slow != fast) {
            slow = getNext(slow); 
            fast = getNext(getNext(fast)); 
        }

        return fast == 1; 
    }
};

int main(){
    Solution sol;
    int n;
    cin>>n;
    cout<<boolalpha<<sol.isHappy(n);
    return 0;
}