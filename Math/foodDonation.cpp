#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
vector<int> minFactor, output, dp;
vector<pair<int, int>> input;
vector<long long> psum;
int t, m = -1, f, s;
void eratosthenes()
{
	for (int i = 2; i <= m; i++) minFactor[i] = i;
	for (int i = 2; i <= sqrt(m); i++)
	{
		if (minFactor[i] == i)
			for (int j = i * i; j <= m; j += i)
				if (minFactor[j] == j)
					minFactor[j] = i;
	}
}
int factor(int num)
{
	int& ret = dp[num];
	if (num <= 1) return dp[num] = 0;
	if (ret != -1) return ret;
	ret = factor(num / minFactor[num]) + 1;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> f >> s;
		input.push_back(make_pair(f, s));
		m = max(m, f);
	}
	minFactor.resize(m + 1); dp.resize(m + 1, -1); psum.resize(m + 1, 0);
	minFactor[0] = minFactor[1] = -1;
	eratosthenes();
	for (int num = 2; num <= m; num++)
		psum[num] = psum[num - 1] + factor(num);
	for (pair<int, int> p : input)
	{
		ll a = psum[p.first] - psum[p.second];
		output.push_back(a);
	}
	for (int o : output)
		cout << o << '\n';
}

// https://codeforces.com/gym/102986/problem/E

/*
First code from codeForce.
I translate this problem as factorization.
And I thought it is the problem of translation and If it correctly translated
I can easily solve this problem.
But, That was wrong, At the end of use all my knowledge(DP, accumulatedSum, Eratosthenes) to use.
I finally can solve this problem. I can't believe I solved this problem.
*/