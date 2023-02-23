#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 200001;
int N, K, acc[MAX], A, I = 0;
unordered_map<int, int> dic;
vector<int> arr[MAX];
long long ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	acc[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> A;
		acc[i] = acc[i - 1] + A;
	}
	for (int i = 1; i <= N; i++)
	{
		if (dic.count(acc[i]) == 0)
		{
			arr[I].push_back(i);
			dic[acc[i]] = I++;
		}
		else
			arr[dic[acc[i]]].push_back(i);
	}
	for (int i = 1; i <= N; i++)
	{
		if (acc[i] == K) ++ans;
		int target = acc[i] - K;
		if (dic.count(target) == 0) continue;
		int idx = dic[target];
		ans += lower_bound(arr[idx].begin(), arr[idx].end(), i) - arr[idx].begin();
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2015