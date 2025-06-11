#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long int;
ll A, B;

ll gcd(ll a, ll b)
{
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	cout << (A * B) / gcd(A, B) << '\n';
}

// https://www.acmicpc.net/problem/13241