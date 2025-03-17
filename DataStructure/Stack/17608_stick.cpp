#include <iostream>
#include <stack>
using namespace std;

stack<int> S;
int N, L;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	S.push(0);
	for (int i = 0; i < N; i++)
	{
		cin >> L;
		if (S.top() > L) S.push(L);
		else
		{
			while (!S.empty() && S.top() <= L)
				S.pop();
			S.push(L);
		}
	}
	cout << S.size() << '\n';
}

// https://www.acmicpc.net/problem/17608