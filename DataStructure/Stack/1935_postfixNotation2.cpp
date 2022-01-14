#include <iostream>
#include <vector>
#include <stack>
#include <cctype>
using namespace std;

string notation;
stack<double> s;
vector<int> vars;
int N, opp;
double calc(double a, double b, char op)
{
	double ret = 0;
	switch (op)
	{
	case '*':
		ret = a * b;
		break;
	case '+':
		ret = a + b;
		break;
	case '/':
		ret = a / b;
		break;
	case '-':
		ret = a - b;
		break;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; cin >> notation;
	vars.resize(N);
	for (int i = 0; i < N; i++)
		cin >> vars[i];
	for (int i = 0; i < notation.size(); i++)
	{
		if (isalpha(notation[i]))
			s.push(vars[notation[i] - 'A']);
		else
		{
			double v1 = s.top();
			s.pop();
			double v2 = s.top();
			s.pop();
			double tmp = calc(v2, v1, notation[i]);
			s.push(tmp);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top() << '\n';
}

// https://www.acmicpc.net/problem/1935