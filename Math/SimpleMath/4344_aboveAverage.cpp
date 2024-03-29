#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int c, n, sum, cnt;
double avg;
vector<double> ans;
int main()
{
	cin >> c; cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < c; i++)
	{
		cin >> n;
		vector<int> arr(n);
		sum = 0, cnt = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
			sum += arr[j];
		}
		avg = sum / n;
		for (int j = 0; j < n; j++)
			if (arr[j] > avg) cnt++;
		double a = (double)cnt / n;
		ans.push_back(a * 100);
	}
	cout.precision(3);
	for (double a : ans)
	{
		cout << fixed;
		cout << round(1000 * a) / 1000 << "%" << '\n';
	}
}

// https://www.acmicpc.net/problem/4344