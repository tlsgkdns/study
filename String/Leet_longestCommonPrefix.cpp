#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int l = 201, i = 0;
		for (string s : strs)
			l = (l > s.length()) ? s.length() : l;
		for (i = 0; i < l; i++)
		{
			char c = strs[0][i];
			bool flag = false;
			for (string s : strs)
			{
				if (s[i] != c)
				{
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		string ans(strs[0].begin(), strs[0].begin() + i);
		return ans;
	}
};

// https://leetcode.com/problems/longest-common-prefix/