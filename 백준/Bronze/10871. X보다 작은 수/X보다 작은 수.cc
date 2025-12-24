#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n, x, a;
	std::cin >> n >> x;

	while (n--)
	{
		std::cin >> a;
		if (a < x) std::cout << a << ' ';
	}
}