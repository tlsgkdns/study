#include <iostream>
#include <stack>

using namespace std;
stack<int> S;
int N, L[1001], t = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	for (int i = 0; i < N; i++)
	{
		if (L[i] == t)
		{
			++t;
			while (!S.empty() && S.top() == t)
			{
				++t;
				S.pop();
			}
		}
		else
		{
			S.push(L[i]);
		}
	}
	while (!S.empty() && S.top() == t)
	{
		++t;
		S.pop();
	}
	if (S.empty()) cout << "Nice\n";
	else cout << "Sad\n";
}

// https://www.acmicpc.net/problem/12789