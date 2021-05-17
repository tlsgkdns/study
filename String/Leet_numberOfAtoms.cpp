#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
	unordered_map<string, int> um;
	stack<char> sc;
	string countOfAtoms(string formula) {
		atoms(formula, 1);
		string ret = "";
		vector<pair<string, int>> v;
		for (auto it = um.begin(); it != um.end(); it++)
			v.push_back(make_pair(it->first, it->second));
		sort(v.begin(), v.end());
		for (pair<string, int>& p : v)
		{
			ret += p.first;
			if (p.second != 1)
				ret += to_string(p.second);
		}
		return ret;
	}
	void atoms(string formula, int mul)
	{
		string target = "", num = "";
		bool alp = true;
		for (int i = 0; i < formula.length(); i++)
		{
			char c = formula[i];
			if (isalpha(c))
			{
				if (!target.empty() && isupper(c))
				{
					if (um.count(target) == 0) um[target] = 0;
					int n = num.empty() ? 1 : stoi(num);
					um[target] += n * mul;
					target = ""; num = "";
				}
				target.push_back(c);
			}
			else if (isdigit(c))
				num.push_back(c);
			else if (c == '(')
			{
				string num = "";
				int j = i + 1;
				sc.push('(');
				while (!sc.empty())
				{
					if (formula[j] == '(')
						sc.push('(');
					else if (formula[j] == ')')
						sc.pop();
					j++;
				}
				int k = j;
				while (k < formula.length() && isdigit(formula[k]))
				{
					num.push_back(formula[k]);
					k++;
				}
				string s(formula.begin() + i + 1, formula.begin() + j - 1);
				atoms(s, (num.empty() ? 1 : stoi(num)) * mul);
				i = k - 1;
			}
		}
		if (!target.empty())
		{
			if (um.count(target) == 0) um[target] = 0;
			int n = (num.empty() ? 1 : stoi(num));
			um[target] += n * mul;
		}
	}
};

int main()
{
	string st;
	cin >> st;
	Solution s;
	cout << s.countOfAtoms(st) << '\n';
}

// https://leetcode.com/problems/number-of-atoms/