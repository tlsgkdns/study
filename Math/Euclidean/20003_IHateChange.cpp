#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long gcd(long long a, long long b)
{
	return (b != 0) ? gcd(b, a % b) : a;
}
long long lcm(long long a, long long b)
{
	return (a * b) / gcd(a, b);
}
long long integ(stack<long long> s, long long(*f)(long long, long long))
{
	while (s.size() != 1)
	{
		long long f1 = s.top();
		s.pop();
		long long f2 = s.top();
		s.pop();
		s.push(f(f1, f2));
	}
	return s.top();
}
int main()
{
	int n;
	cin >> n;
	stack<long long> A, B, C;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		A.push(a);
		B.push(b);
	}
	long long m = integ(B, lcm);
	while (!A.empty())
	{
		long long a = A.top() * (m / B.top());
		C.push(a);
		A.pop();
		B.pop();
	}
	long long s = integ(C, gcd);
	long long sm = gcd(s, m);
	cout << (s / sm) << " " << (m / sm) << '\n';
}

// https://www.acmicpc.net/problem/20003