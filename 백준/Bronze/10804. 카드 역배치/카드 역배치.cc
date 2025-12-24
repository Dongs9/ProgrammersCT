#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int card[21];

	for (int i = 1; i <= 20; ++i) card[i] = i;

	int s, e;

	for (int i = 0; i < 10; ++i)
	{
		cin >> s >> e;

		int max = (e - s) / 2;
		for (int j = 0; j <= max; ++j)
		{
			int t = card[s + j];
			card[s + j] = card[e - j];
			card[e - j] = t;
		}
	}

	for (int i = 1; i <= 20; ++i) cout << card[i] << ' ';
}