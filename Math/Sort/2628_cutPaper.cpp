#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int W, H, cmd, N, num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> w, h;
	cin >> W >> H;
	w.push_back(0); w.push_back(W);
	h.push_back(0); h.push_back(H);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd >> num;
		if (cmd == 0) h.push_back(num);
		else w.push_back(num);
	}
	sort(h.begin(), h.end()); sort(w.begin(), w.end());
	int width = 0, height = 0;
	for (int i = 0; i < h.size() - 1; i++)
		height = max(height, h[i + 1] - h[i]);
	for (int i = 0; i < w.size() - 1; i++)
		width = max(width, w[i + 1] - w[i]);
	cout << height * width << '\n';
}


// https://www.acmicpc.net/problem/2628