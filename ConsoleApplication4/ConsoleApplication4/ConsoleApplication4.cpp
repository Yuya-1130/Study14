
#include <iostream>

// draw 関数を持っているクラス
class HasDrawA {
public:
    void draw() { std::cout << "HasDrawA::draw() が呼び出されました" << std::endl; }
};

// draw 関数を持っているクラス
class HasDrawB {
public:
    void draw() { std::cout << "HasDrawB::draw() が呼び出されました" << std::endl; }
};

// draw 関数を持っていないクラス
class NoneDraw{};

// T が draw という関数を持っているかどうかを判断するためのコンセプト
template <class T>
concept HasDrawObject = requires(T & t) {
    t.draw();// T型 draw という関数を呼び出せる、という意味になる
};

// draw 関数を呼び出すためのテンプレート関数
// テンプレート仮引数にコンセプトを指定する
template <class T>
void callDraw(T& x) {
    if constexpr (HasDrawObject<T>) {
        x.draw();
    }
    else {
        std::cout << "スキップ" << std::endl;
    }
}

// エントリー関数
int main()
{
    HasDrawA a;
    HasDrawA b;
    NoneDraw n;

    callDraw(a); // HasDrawA は draw を呼び出せるので問題ない
    callDraw(b); // HasDrawB は draw を呼び出せるので問題ない
    callDraw(n); // NoneDraw は draw を呼び出せないのでコンパイルエラー
   
    return 0;
}

