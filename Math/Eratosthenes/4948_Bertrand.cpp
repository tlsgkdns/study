#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

vector<int> ans;
const int MAX = 250001;
int N;
bool isPrime[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j < MAX; j += i)
			isPrime[j] = false;
	}
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		int cnt = 0;
		for (int i = N + 1; i <= 2 * N; i++) cnt += isPrime[i];
		ans.push_back(cnt);
	}
	for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/4948