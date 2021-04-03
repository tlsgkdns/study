#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int n;
stack<int> s1, s2;
vector<int> v, ans;

int main()
{
	cin >> n; v.resize(n); ans.resize(n, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		s1.push(v[i]);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		while (!s2.empty())
		{
			if (s1.top() < s2.top())
			{
				ans[i] = s2.top();
				break;
			}
			s2.pop();
		}
		s2.push(s1.top());
		s1.pop();
	}
	for (int a : ans) cout << a << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/17298

/*
Little difficult stack problem.
At first, I reviewed the answer array when stack's top is larger than another stack's. But it came out "Times out"
So I used stack more efficiently, and it corrects.
*/