#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int A, B, C;

int clamp(int val, int lo, int hi)
{
	if (val < lo) return lo;
	if (val > hi) return hi;
	return val;
}
int main()
{
	cin >> A >> B >> C;
	vector<vector<bool>> v(B + 1, vector<bool>(C + 1, false));
	queue<tuple<int, int, int>> q;
	vector<int> ans;
	q.push(make_tuple(0, 0, C));
	while (!q.empty())
	{
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();
		if (v[b][c]) continue;
		if (a == 0)	ans.push_back(c);
		v[b][c] = true;
		int na, nb, nc;
		na = clamp(a + b, 0, A); nb = clamp(b - (na - a), 0, B); nc = c;
		q.push(make_tuple(na, nb, nc));
		nb = clamp(a + b, 0, B); na = clamp(a - (nb - b), 0, A); nc = c;
		q.push(make_tuple(na, nb, nc));
		na = a; nb = clamp(b + c, 0, B); nc = clamp(c - (nb - b), 0, C);
		q.push(make_tuple(na, nb, nc));
		na = a; nc = clamp(b + c, 0, C); nb = clamp(b - (nc - c), 0, B);
		q.push(make_tuple(na, nb, nc));
		na = clamp(a + c, 0, A); nb = b; nc = clamp(c - (na - a), 0, C);
		q.push(make_tuple(na, nb, nc));
		nc = clamp(a + c, 0, C); nb = b; na = clamp(a - (nc - c), 0, A);
		q.push(make_tuple(na, nb, nc));
	}
	sort(ans.begin(), ans.end());
	for (int a : ans) cout << a << " ";
	cout << '\n';
}
// https://www.acmicpc.net/problem/2251