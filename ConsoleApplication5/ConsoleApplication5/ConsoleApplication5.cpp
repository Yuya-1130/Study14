
#include <iostream>

// 再帰関数
// sum()

//template<class T>
//auto sumAll(T first) {
//    return first;
//}

//　一つ目の引数だけ独立、二つ目以降をパラメータパック
template <class T,class... Args>
int sumAll(T first, Args... args) {
    if constexpr (sizeof...(args) != 0) {
        return first + sumAll(args...);
    }
    else {
        return first;
    }
    //first + sumAll(args...);
}
int main()
{
    auto a1 = sumAll(1, 2.1f, 3.1, 4, 5);
  
    std::cout << a1 << std::endl;
    
    return 0;
}

