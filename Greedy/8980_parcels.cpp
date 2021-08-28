#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Box
{
	int src, dst, num;
	Box(int s, int d, int n)
	{
		src = s; dst = d; num = n;
	}
	bool operator<(const Box& box)
	{
		if (dst == box.dst) return src < box.src;
		return dst < box.dst;
	}
};
int N, C, M, s, d, n;
int clamp(int num, int limit)
{
	if (num < 0) return 0;
	if (num > limit) return limit;
	return num;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<Box> truck;
	cin >> N >> C;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> d >> n;
		Box box(s, d, n);
		truck.push_back(box);
	}
	sort(truck.begin(), truck.end());
	int ans = 0;
	vector<int> boxes(N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		int load = C;
		for (int t = truck[i].src; t < truck[i].dst; t++)
			load = min(clamp(truck[i].num, C - boxes[t]), load);
		if (load == 0) continue;
		ans += load;
		for (int t = truck[i].src; t < truck[i].dst; t++)
			boxes[t] += load;
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/8980