#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int key[9];
	for (int i = 0; i < 9; ++i) cin >> key[i];
	sort(key, key + 9);
	
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (i == j) continue;

			int num = 0;
			for (int k = 0; k < 9; ++k)
			{
				if (k == i || k == j) continue;
				num += key[k];
			}

			if (num == 100)
			{
				for (int k = 0; k < 9; ++k)
				{
					if (k == i || k == j) continue;
					cout << key[k] << '\n';
				}

				return 0;
			}
		}
	}
}