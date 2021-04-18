#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int part(vector<int> v, vector<int>& c, int s)
{
	int& ret = c[s];
	if (ret != -1) return ret;
	ret = 1;

	for (int next = s + 1; next < v.size(); ++next)
	{
		if (v[s] < v[next])
			ret = max(ret, part(v, c, next) + 1);
	}


	return ret;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> c(n, -1);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int ret = 0;

	for (int s = 0; s < n; s++)
		ret = max(part(v, c, s), ret);
	cout << ret << endl;
	return 0;
}

// https://www.acmicpc.net/problem/11053