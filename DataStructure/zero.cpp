#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> q;
	int n, tmp;
	long long ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == 0) q.pop();
		else q.push(tmp);
	}

	while (!q.empty())
	{
		ans += q.top();
		q.pop();
	}

	cout << ans << endl;
	return 0;
}
// https://www.acmicpc.net/problem/10773

/*
0 means stack.pop();
else n means stack.push(n);
*/