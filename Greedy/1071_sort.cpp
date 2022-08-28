#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<int> A(N), ans;
	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ans.push_back(-2);
	for (int i = 0; i < N; i++) q.push(A[i]);
	while (!q.empty())
	{
		if (ans.back() + 1 == q.front())
		{
			int cnt1 = 0, cp1 = q.front();
			while (!q.empty() && ans.back() + 1 == q.front())
			{
				cnt1++;
				q.pop();
			}
			if (q.empty())
			{
				int cnt2 = 0, cp2 = ans.back();
				while (cp1 == ans.back() + 1)
				{
					cnt2++;
					ans.pop_back();
				}
				for (int i = 0; i < cnt1; i++) ans.push_back(cp1);
				for (int i = 0; i < cnt2; i++) ans.push_back(cp2);
			}
			else
			{
				ans.push_back(q.front());
				q.pop();
				for (int i = 0; i < cnt1; i++) ans.push_back(cp1);
			}
		}
		else
		{
			ans.push_back(q.front());
			q.pop();
		}
	}
	for (int i = 1; i < ans.size(); i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/1071