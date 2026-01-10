#include <iostream>


using namespace std;
int N, cnt1 = 0, cnt2 = 0;
string B1, B2;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    cin >> B1;
    cin >> B2;
    for (int i = 0; i < B1.size(); i++) cnt1 += (B1[i] == 'w');
    for (int i = 0; i < B2.size(); i++) cnt2 += (B2[i] == 'w');
    if (B1 == B2) cout << "Good\n";
    else if (cnt1 == cnt2) cout << "Its fine\n";
    else if (cnt1 > cnt2) cout << "Oryang\n";
    else cout << "Manners maketh man\n";
}

// https://www.acmicpc.net/problem/34980