#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using pos = pair<int, int>;
vector<string> mv;
unordered_map<string, pos> um;
string k, s;
int N;
pos king, stone;
pos operator+(pos p1, pos p2)
{
	return make_pair(p1.first + p2.first, p1.second +
		p2.second);
}
bool isInside(pos p)
{
	return (p.first >= 0 && p.second >= 0 && p.first < 8
		&& p.second < 8);
}
void init()
{
	um["R"] = make_pair(0, 1); um["L"] = make_pair(0,
		-1);
	um["B"] = make_pair(1, 0); um["T"] = make_pair(-1,
		0);
	um["RT"] = make_pair(-1, 1); um["LT"] =
		make_pair(-1, -1);
	um["RB"] = make_pair(1, 1); um["LB"] =
		make_pair(1, -1);
}
int main()
{
	init();
	cin >> k >> s >> N; mv.resize(N);
	for (int i = 0; i < N; i++) cin >> mv[i];
	king = make_pair(8 - (k[1] - '0'), k[0] - 'A'); stone =
		make_pair(8 - (s[1] - '0'), s[0] - 'A');
	for (string m : mv)
	{
		pos tmpK, tmpS = stone;
		tmpK = um[m] + king;
		if (!isInside(tmpK)) continue;
		if (tmpK == stone)
		{
			tmpS = stone + um[m];
			if (!isInside(tmpS)) continue;
		}
		king = tmpK; stone = tmpS;
	}
	string ansK, ansS;
	ansK.push_back(king.second + 'A');
	ansK.push_back((8 - king.first) + '0');
	ansS.push_back(stone.second + 'A');
	ansS.push_back((8 - stone.first) + '0');

	cout << ansK << '\n' << ansS << '\n';
}

// https://www.acmicpc.net/problem/1063