#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int date[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
unordered_map<string, int> months = { {"December", 11}, {"January", 0}, {"February", 1},
									{"March", 2}, {"April", 3}, {"May", 4}, {"June", 5},
									{"July", 6}, {"August", 7}, {"September", 8}, {"October", 9}, {"November", 10} };
string M, D, T, hour = "", minute = "";
int Y, dateTime = 1440;
double total = dateTime * 365, S = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> D >> Y >> T;
	D = string(D.begin(), D.end() - 1);
	if (Y % 400 == 0 || (Y % 4 == 0 && Y % 100 > 0))
	{
		date[1] = 29;
		total += dateTime;
	}
	for (int i = 0; i < months[M]; i++) S += (date[i] * dateTime);
	S += (stoi(D) - 1) * dateTime;
	hour.push_back(T[0]); hour.push_back(T[1]);
	minute.push_back(T[3]); minute.push_back(T[4]);
	S += stoi(hour) * 60; S += stoi(minute);
	cout << fixed; cout.precision(13);
	cout << (S / total) * 100 << '\n';
}

// https://www.acmicpc.net/problem/1340