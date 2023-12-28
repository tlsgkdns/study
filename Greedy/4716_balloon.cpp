#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;
using tu = tuple<int, int, int>;
int N, A, B, K, da, db;
bool cmp(tu t1, tu t2)
{
	int sub1 = abs(get<1>(t1) - get<2>(t1)), sub2 = abs(get<1>(t2) - get<2>(t2));
	if (sub1 == sub2) return min(get<1>(t1), get<2>(t1)) > min(get<1>(t1), get<2>(t2));
	return sub1 > sub2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N >> A >> B;
		if (N == 0 && A == 0 && B == 0) break;
		long long ans = 0; vector<tu> arr;
		for (int i = 0; i < N; i++)
		{
			cin >> K >> da >> db;
			arr.push_back(make_tuple(K, da, db));
		}
		sort(arr.begin(), arr.end(), cmp);
		for (int i = 0; i < arr.size(); i++)
		{
			int cnt = get<0>(arr[i]);
			int a = get<1>(arr[i]);
			int b = get<2>(arr[i]);
			if (a < b)
			{
				if (cnt > A)
				{
					ans += A * a;
					ans += (cnt - A) * b;
					B -= (cnt - A);
					A = 0;
				}
				else
				{
					ans += cnt * a;
					A -= cnt;
				}
			}
			else
			{
				if (cnt > B)
				{
					ans += B * b;
					ans += (cnt - B) * a;
					A -= (cnt - B);
					B = 0;
				}
				else
				{
					ans += cnt * b;
					B -= cnt;
				}
			}
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/4716