#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int P, M, L;
string N;

class Room
{
	int lv = 0;
	int capacity = 0;
	vector<pair<string, int>> players;
public:
	Room(string n, int lev)
	{
		lv = lev;
		capacity = 1;
		players.push_back({ n, lev });
	}
	bool isFull()
	{
		return (capacity == M);
	}
	bool canEnter(int lev)
	{
		if (isFull()) return false;
		return abs(lv - lev) <= 10;
	}
	void playerEnter(string nickname, int _lv)
	{
		players.push_back({ nickname, _lv });
		capacity++;
		sort(players.begin(), players.end());
	}
	void printRoom()
	{
		if (isFull()) cout << "Started!\n";
		else cout << "Waiting!\n";
		for (int i = 0; i < (int)players.size(); i++)
			cout << players[i].second << " " << players[i].first << '\n';
	}
};
vector<Room> rooms;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> P >> M;
	for (int p = 0; p < P; p++)
	{
		cin >> L >> N;
		bool found = false;
		for (int i = 0; i < rooms.size(); i++)
		{
			if (found) break;
			if (rooms[i].canEnter(L))
			{
				rooms[i].playerEnter(N, L);
				found = true;
			}
		}
		if (!found) rooms.push_back(Room(N, L));
	}
	for (int i = 0; i < (int)rooms.size(); i++)
		rooms[i].printRoom();
}

// https://www.acmicpc.net/problem/20006