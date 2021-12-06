#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
int N;
vector<int> arr;
vector<bool> op;
int main()
{
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int idx = 0;
	for (int n = 1; n <= N; n++)
	{
		s.push(n);
		op.push_back(true);
		while (!s.empty() && arr[idx] == s.top())
		{
			idx++;
			op.push_back(false);
			s.pop();
		}
	}
	if (idx != N) cout << "NO\n";
	else
	{
		for (int i = 0; i < op.size(); i++)
		{
			if (op[i]) cout << "+" << '\n';
			else cout << "-" << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/1874