#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, A, B;
vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> A >> B;
	if (A <= B)
	{
		for (int i = 1; i <= B; i++)
			ans.push_back(i);
		for (int i = A - 1; i >= 1; i--)
			ans.push_back(i);
		if (N < (int)ans.size()) cout << -1 << '\n';
		else
		{
			if (A > 1)
			{
				while ((int)ans.size() < N)
					ans.push_back(1);
				reverse(ans.begin(), ans.end());
				for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " ";
				cout << '\n';
			}
			else
			{
				reverse(ans.begin(), ans.end());
				cout << ans[0] << " ";
				for (int i = 0; i < N - (int)ans.size(); i++) cout << 1 << " ";
				for (int i = 1; i < (int)ans.size(); i++) cout << ans[i] << " ";
			}
			cout << '\n';
		}
	}
	else
	{
		for (int i = 1; i <= A; i++)
			ans.push_back(i);
		for (int i = B - 1; i >= 1; i--)
			ans.push_back(i);
		if (N < (int)ans.size()) cout << -1 << '\n';
		else
		{
			for (int i = 0; i < N - (int)ans.size(); i++) cout << 1 << " ";
			for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " ";
			cout << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/24337