#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<string, long long> U = { {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3},
	{"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7}, {"grey", 8}, {"white", 9} };
string S;
long long ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> S;
	ans += U[S] * 10;
	cin >> S;
	ans += U[S];
	cin >> S;
	ans *= pow(10, U[S]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1076