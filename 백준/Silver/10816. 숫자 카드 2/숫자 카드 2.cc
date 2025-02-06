#include <iostream>
#include <algorithm>
#include <map>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	std::map<int, int> m;
	int N, M, n;
	std::cin >> N;

	while (N--)
	{
		std::cin >> n;
		m[n]++;
	}

	std::cin >> M;
	while (M--)
	{
		std::cin >> n;
		auto it = m.find(n);

		if (it != m.end())
			std::cout << it->second << ' ';
		else
			std::cout << "0" << ' ';
	}
}