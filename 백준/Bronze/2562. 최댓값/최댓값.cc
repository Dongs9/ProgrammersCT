#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[9];

	for (int i = 0; i < 9; ++i)
		cin >> arr[i];

	auto iter = max_element(arr, arr + 9);
	int a = iter - arr + 1;
	cout << *iter << '\n' << a;

	return 0;
}