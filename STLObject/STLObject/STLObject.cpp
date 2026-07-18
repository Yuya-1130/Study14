
#include <iostream>
#include <functional>

// -----------------関数オブジェクト-------------------

// 掛け算を行う関数オブジェクト構造体
 template < class T = void>
struct Multi
{
	  T operator()(const T a, const T b)const {
		return a * b;
	}
};

// --------------関数を変数の形で保持する------------------

// 関数A
char A(int v) {
	std::cout << "v" << v << std::endl;
	return 'A';
}

// 関数B
char B(int v) {
	std::cout << "v" << v << std::endl;
	return 'B';
}

// 関数AかBを条件に併せて呼び出す
void function(std::function<char(int)> f) {
	// 関数Aを呼び出す
	char c = f(1);
	

	std::cout << "結果は" << c << std::endl;
}

int main()
{
	// -----------------関数オブジェクト-------------------
	Multi<float> fMulti;
	Multi<int>  iMulti;

   // float 同士の足し算を行う関数オブジェクト
	std::plus<float>  fPlus;
   // int 同士の大きさ比較を行う関数オブジェクト
	std::greater<int> iGreater;

    
	
	// 変数だが関数のように利用できる

	// fには合計が入る
	float f = fPlus(2.3f, 4.1f);
	// 第一引数が第二引数より大きければ true
	bool i = iGreater(2, 4);

	float fm = fMulti(1.2f, 2.4f);
	int im = iMulti(2, 4);
	
	std::cout << fm << std::endl;
	std::cout << im << std::endl;

	// --------------関数を変数の形で保持する------------------

	function(B);
}

