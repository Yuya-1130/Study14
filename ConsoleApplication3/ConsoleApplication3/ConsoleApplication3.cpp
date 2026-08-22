
// -----------------従来のバージョンのコード--------------------

//#include <iostream>
//
//// 昨今のC++に合わせた文字列の扱いを利用すする
//#include <string_view>
//
//// 引数 value がゼロかどうかをチェックする関数
//template <class T>
//std::string_view checkZero(T value) {
//    if (value != 0) {
//        return "ゼロではありません";
//    }
//
//    return "ゼロです";
//}
//
//// 引数 の型が float の場合の特殊化関数
//template <>
//std::string_view checkZero(float value) {
//    if (value != 0) {
//
//        // 0.x だった場合は特殊な判定を行う
//        if (0 < value && value < 1.0f) {
//            return "小数部はゼロではありませんが、整数部はゼロです";
//        }
//
//        return "ゼロではありません";
//    }
//
//    return "ゼロです";
//}

// -------------昨今のC++のバージョンに変化させると下記になる---------------

#include <iostream>

// 昨今の C++ に合わせた文字列の扱い方を利用する
#include <string_view>

// テンプレート内で T の型をチェックする為に必要になる
#include <type_traits>

// 引数 value がゼロかどうかをチェックする関数
template <class T>
std::string_view checkZero(T value) {
    if (value != 0) {
        // 引数 value(T) の型が float 型だった場合の特殊判定を追加する
        if constexpr (std::is_same_v<decltype(value), float>) {

            // 0.x だった場合は特殊な判定を行う
            if (0 < value && value < 1.0f) {
                return "小数部はゼロではありませんが、整数部はゼロです";
            }
        }

        return "ゼロではありません";
    }

    return "ゼロです";
}

// エントリー関数
int main() {
    int   i = 5;
    char  c = 0;
    float f1 = 0.3f;
    float f2 = 1.5f;
    float f3 = 0.f;

    // 各変数がゼロかどうかをチェックする
    std::cout << "i は" << checkZero(i) << std::endl;
    std::cout << "c は" << checkZero(c) << std::endl;
    std::cout << "f1 は" << checkZero(f1) << std::endl;
    std::cout << "f2 は" << checkZero(f2) << std::endl;
    std::cout << "f3 は" << checkZero(f3) << std::endl;

    return 0;
}
