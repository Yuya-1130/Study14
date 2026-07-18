#include <iostream>
#include <vector>

int main()
{
	// int型のコンテナを宣言し1～10までの整数値を追加する
	std::vector<int> nums = { 1,2,3,4,5,6,7,8,9,10 };

	// コンテナから偶数だけを削除する

	for (std::vector<int>::iterator it = nums.begin(); it != nums.end();) 
	{

		//std::vector<int>::iterator position = nums.begin();
		
	

		it = nums.erase(it);

		
	}
	
}


