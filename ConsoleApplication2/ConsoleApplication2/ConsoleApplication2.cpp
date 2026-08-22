
#include <iostream>
// 可変長引数を扱う為に必要になる
//#include <stdarg.h>

// --------C言語における可変長引数関数の実装----------

 //渡された引数を全て合計する関数　　count：計算に利用する引数の数　... :計算に利用する可変長の引数

//int sum(int count, ...) {
//
//	// 可変長の引数リストを保持する変数を宣言する
//	va_list args;
//
//	// 可変長の情報を利用した処理を開始する
//	// 第二引数には可変部分が始まる直前の引数を指定する
//	va_start(args, count);
//
//	int answer{};
//
//	// count の数だけループして数値を加算していく
//	for (auto i = 0; i < count; ++i) {
//		// 可変長の引数が順番に取得できる
//		answer += va_arg(args, int);
//	}
//
//	// 可変長の情報を利用した処理を終了する
//	va_end(args);
//
//	return answer;
//}

//----------C++における可変長引数関数の実装-----------

//template <class... T>
//int sum(T... args) {
//
//	// 可変長引数の内容を配列に全て詰め込む
//	int list[] = { args... };
//
//	int answer{};
//
//	// 配列を範囲　for文　でループさせて合計する
//	for (auto i : list) {
//		answer += i;
//	}
//	return answer;
//}

//------------C++可変長引数の様々な用途--------------
// プレイヤーの列挙
enum class Player {
	Hero,
};

// プレイヤーの列挙
enum class Enemy {
	Boss,
};

// プレイヤークラス
class PlayerChara {
public:
	PlayerChara() { std::cout << "プレイヤーを生成します" << std::endl; }
};
// 敵クラス
class EnemyChara {
public:
	EnemyChara() { std::cout << "敵を生成します" << std::endl; }
};
// NPC クラス
class NPCChara {
public:
	NPCChara() { std::cout << "NPCを生成します" << std::endl; }
};

// プレイヤーを生成する関数
std::unique_ptr<PlayerChara> createChara(Player player, int attack, float speed, char weaponId) {
	return std::make_unique<PlayerChara>();
}

// 敵を生成する関数
std::unique_ptr<EnemyChara> createChara(Enemy enemy, int attack, float speed) {
	return std::make_unique<EnemyChara>();
}

// NPCを生成する関数
std::unique_ptr<NPCChara> createChara() {
	return std::make_unique<NPCChara>();
}

// キャラクター生成のテンプレート関数
// 戻り値の型を後置宣言する方法を利用して、関数の結果から戻り値型を推論する
template <class... T>
auto create(T... args) {
	// パラメータパックを展開して対応する関数に渡す
	return createChara(args...);
}

int main()
{
	//----------C言語用--------------------

	/*auto a1 = sum(5, 1, 2, 3, 4, 5);
	auto a2 = sum(7, 1, 2, 3, 4, 5 , 6, 7);

	std::cout << a1 << std::endl;
	std::cout << a2 << std::endl;

	return 0;*/

	//---------------C++用-----------------

	/*auto a1 = sum( 1, 2, 3, 4, 5);
	auto a2 = sum( 1, 2, 3, 4, 5, 6, 7);

	std::cout << a1 << std::endl;
	std::cout << a2 << std::endl;

	return 0;*/

	// count の引数が前者は必要とするが、後者は必要ない

	// プレイヤーを生成する関数が呼び出される
	auto p = create(Player::Hero, 10, 1.0f, 3);

	// 敵を生成する関数が呼び出される
	auto e = create(Enemy::Boss, 10, 1.0f);

	// NPCを生成する関数が呼び出される
	auto n = create();

	return 0;
}


