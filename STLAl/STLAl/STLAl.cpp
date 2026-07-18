
#include <iostream>
#include <vector>
#include <algorithm>

// 二つの値を受け取って第一のほうが大きい場合に true を返す
bool greater(int l,int r) {
	return l > r;
}


// エントリー関数
int main()
{
	std::vector<int> vec = { 10,8,4,9,2,3,5 };

	std::sort(vec.begin(), vec.end(),greater);
	// 小さい値空大きい値の順に並び変える
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
}

