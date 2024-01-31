#include <iostream>
#include <stack>
using namespace std;

stack<int> S;
string E;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> E;
	for (int i = 0; i < E.size(); i++)
	{
		if (E[i] >= '0' && E[i] <= '9')
			S.push(E[i] - '0');
		else
		{
			int b = S.top();
			S.pop();
			int a = S.top();
			S.pop();
			switch (E[i])
			{
			case '*':
				S.push(a * b);
				break;
			case '+':
				S.push(a + b);
				break;
			case '-':
				S.push(a - b);
				break;
			case '/':
				S.push(a / b);
				break;
			}
		}
	}
	cout << S.top() << '\n';
}

// https://www.acmicpc.net/problem/15815