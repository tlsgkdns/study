#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<bool> cache(1000001, false);

int useElevator(const int building, const int up, const int down, const int goal, const int start)
{
	queue<pair<int, int>> q;
	int answer = -1;
	q.push(make_pair(start, 0));
	while (!q.empty())
	{
		int f = q.front().first;
		int s = q.front().second;
		q.pop();
		if (f > building || f <= 0 || cache[f]) continue;
		cache[f] = true;

		if (f == goal)
		{
			answer = s;
			break;
		}
		q.push(make_pair(f + up, s + 1));
		q.push(make_pair(f - down, s + 1));
	}

	return answer;
}

int main(void)
{
	int f, s, g, u, d;

	cin >> f >> s >> g >> u >> d;

	string impossible = "use the stairs";
	int answer = useElevator(f, u, d, g, s);

	if (answer == -1)
		cout << impossible << '\n';
	else
		cout << answer << '\n';
}

// https://www.acmicpc.net/problem/5014

/*
bfs problem
*/