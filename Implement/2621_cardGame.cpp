#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pci = pair<int, char>;
int score = 0;
vector<pci> card(5);
bool isSeq()
{
	for (int i = 0; i < 4; i++)
		if (card[i].first + 1 != card[i + 1].first)
			return false;
	return true;
}
bool sameClr()
{
	for (int i = 0; i < 4; i++)
		if (card[i].second != card[i + 1].second)
			return false;
	return true;
}
bool con2()
{
	if (card[1].first != card[2].first) return false;
	if (card[2].first != card[3].first) return false;
	if (card[0].first == card[1].first || card[3].first == card[4].first) return true;
	return false;
}
bool con3()
{
	if (card[0].first != card[1].first || card[3].first != card[4].first) return false;
	if (card[1].first != card[2].first && card[2].first != card[3].first) return false;
	return true;
}
int con6()
{
	if (card[0].first == card[1].first && card[1].first == card[2].first) return 2;
	if (card[2].first == card[3].first && card[1].first == card[2].first) return 3;
	if (card[2].first == card[3].first && card[3].first == card[4].first) return 4;
	return -1;
}
pair<int, int> con7()
{
	if (card[0].first == card[1].first && card[3].first == card[4].first) return { 1, 4 };
	if (card[1].first == card[2].first && card[3].first == card[4].first) return { 2, 4 };
	if (card[0].first == card[1].first && card[2].first == card[3].first) return { 1, 3 };
	return { -1, -1 };
}
int con8()
{
	for (int i = 0; i < 4; i++)
		if (card[i].first == card[i + 1].first)
			return i;
	return -1;
}
int main()
{
	for (int i = 0; i < 5; i++) cin >> card[i].second >> card[i].first;
	sort(card.begin(), card.end());
	if (isSeq() && sameClr()) score = 900 + card[4].first;
	else if (con2()) score = 800 + ((card[3].first == card[4].first) ? card[4].first : card[3].first);
	else if (con3()) score = 700 + ((card[1].first == card[2].first) ? card[0].first * 10 + card[4].first : card[4].first * 10 + card[0].first);
	else if (sameClr()) score = 600 + card[4].first;
	else if (isSeq()) score = 500 + card[4].first;
	else if (con6() != -1) score = 400 + card[con6()].first;
	else if (con7().first != -1) score = 300 + card[con7().second].first * 10 + card[con7().first].first;
	else if (con8() != -1) score = 200 + card[con8()].first;
	else score = 100 + card[4].first;
	cout << score << '\n';
}

// https://www.acmicpc.net/problem/2621