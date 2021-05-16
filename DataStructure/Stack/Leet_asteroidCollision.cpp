#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		stack<int> s;
		vector<int> ans, tmp;
		for (int ast : asteroids)
		{
			if (ast > 0)
				s.push(ast);
			else
			{
				ast = -ast;
				bool f = false;
				while (!f && !s.empty() && ast >= s.top())
				{
					if (ast == s.top()) f = true;
					s.pop();
				}

				if (!f && s.empty()) ans.push_back(-ast);
			}
		}
		while (!s.empty())
		{
			tmp.push_back(s.top());
			s.pop();
		}
		reverse(tmp.begin(), tmp.end());
		for (int t : tmp) ans.push_back(t);
		return ans;
	}
};

//https://leetcode.com/problems/asteroid-collision/