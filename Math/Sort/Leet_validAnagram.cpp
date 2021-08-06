#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return (s == t);
	}
};
int main()
{
	string s, t;
	cin >> s >> t;
	Solution so;
	cout << so.isAnagram(s, t) << '\n';
}
// https://leetcode.com/problems/valid-anagram/