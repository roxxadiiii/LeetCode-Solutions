/**
*URL: https://leetcode.com/problems/palindrome-number/description/

9. Palindrome Number

Given an integer x, return true if x is a palindrome, and false otherwise.

 
Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

 
Constraints:

        -231 <= x <= 231 - 1

 
Follow up: Could you solve it without converting the integer to a string?
*/

bool isPalindrome(int x) {
  // ignore -ive due to negative
  // if the last digit is 0 ,to be a palindrome the first digit must be also 0
  // the only number that meets this criteria is 0 itself
  if (x < 0 || (x % 10 == 0 && x != 0)) {
    return false;
  }
  // reversing the number
  int reversedHalf = 0;
  while (x > reversedHalf) {
    reversedHalf = reversedHalf * 10 + x % 10;
    x /= 10;
  }
  // comapare the reversed half with the remaining half
  // for the number with an odd number of digits , the middle digit will be part
  // of the reversed half so , we also compared to reverseHalf/10
  return x == reversedHalf || x == reversedHalf / 10;
}

/**# [13. Roman to Integer](https://leetcode.com/problems/roman-to-integer/)

Given an integer `x`, return `true` if `x` is a <div aria-expanded="false"
data-headlessui-state="" id="headlessui-popover-button-:rt:">**palindrome** <div
style="position: fixed; z-index: 40; inset: 0px auto auto 0px; transform:
translate(324px, 182px);">, and `false` otherwise.

**Example 1:**

```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

**Example 2:**

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome.
```

**Example 3:**

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

**Constraints:**

- `-2^31<= x <= 2^31- 1`

**Follow up:**  Could you solve it without converting the integer to a string?
 *
 * */

int romanToInt(char *s) {
  int values[26];
  values['I' - 'A'] = 1;
  values['V' - 'A'] = 5;
  values['X' - 'A'] = 10;
  values['L' - 'A'] = 50;
  values['C' - 'A'] = 100;
  values['D' - 'A'] = 500;
  values['M' - 'A'] = 1000;

  int result = 0;
  int prevValue = 0;

  int length = strlen(s);
  for (int i = length - 1; i >= 0; i--) {
    int currentValue = values[s[i] - 'A'];
    if (currentValue < prevValue) {
      result -= currentValue;
    } else {
      result += currentValue;
    }
    prevValue = currentValue;
  }

  return result;
}
