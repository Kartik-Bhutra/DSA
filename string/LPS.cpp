// https://leetcode.com/problems/longest-palindromic-substring/description/
#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s)
{
  string ans = "";
  auto expand = [&](int i, int j) -> string
  {
    int left = i;
    int right = j;
    while (left >= 0 && right < s.size() && s[left] == s[right])
    {
      left--;
      right++;
    }
    return s.substr(left + 1, right - left - 1);
  };
  for (int i = 0; i < s.size(); i++)
  {
    string odd = expand(i, i);
    if (odd.size() > ans.size())
    {
      ans = odd;
    }
    string even = expand(i, i + 1);
    if (even.size() > ans.size())
    {
      ans = even;
    }
  }
  return ans;
}
string longestPalindrome(string s)
{
  string s_prime = "#";
  for (char c : s)
  {
    s_prime += c;
    s_prime += "#";
  }
  int n = s_prime.length();
  vector<int> palindrome_radii(n, 0);
  int center = 0;
  int radius = 0;
  for (int i = 0; i < n; i++)
  {
    int mirror = 2 * center - i;
    if (i < radius)
    {
      palindrome_radii[i] = min(radius - i, palindrome_radii[mirror]);
    }
    while (i + 1 + palindrome_radii[i] < n &&
           i - 1 - palindrome_radii[i] >= 0 &&
           s_prime[i + 1 + palindrome_radii[i]] ==
               s_prime[i - 1 - palindrome_radii[i]])
    {
      palindrome_radii[i]++;
    }
    if (i + palindrome_radii[i] > radius)
    {
      center = i;
      radius = i + palindrome_radii[i];
    }
  }
  int max_length = 0;
  int center_index = 0;
  for (int i = 0; i < n; i++)
  {
    if (palindrome_radii[i] > max_length)
    {
      max_length = palindrome_radii[i];
      center_index = i;
    }
  }
  int start_index = (center_index - max_length) / 2;
  string longest_palindrome = s.substr(start_index, max_length);
  return longest_palindrome;
}
int main()
{
  return 0;
}