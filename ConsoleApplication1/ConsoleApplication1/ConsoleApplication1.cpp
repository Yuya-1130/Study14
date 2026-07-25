#include <iostream>

// 整数型のデータを扱うクラス
class MyClass {
public:
    // コンストラクタ
    MyClass() = default;

    // 引数付きコンストラクタ
    MyClass(int size) {
        data_ = new int[size];
        dataSize_ = size;
    }

    // コピーコンストラクタ
    MyClass(const MyClass& src) {

        if (data_) {
            delete[] data_;
        }

        // インスタンスを別に再生成
        data_ = new int[src.dataSize_];
        dataSize_ = src.dataSize_;

        // 内容を全部設定する
        for (auto i = 0; i < dataSize_; ++i) {
            data_[i] = src.data_[i];
        }

        std::cout << "コピーコンストラクタ" << std::endl;
    }

    // ムーブコンストラクタ
    MyClass(MyClass&& src) noexcept {

        if (data_) {
            delete[] data_;
        }

        // 再生成ではなく、src のdata_が指すアドレスをそのまま取得する
        data_ = src.data_;
        dataSize_ = src.dataSize_;

        // src が破棄された際にデストラクタで delete されると問題なので初期化しておく
        src.data_ = {};
        src.dataSize_ = {};

        std::cout << "ムーブコンストラクタ" << std::endl;
    }


    // デストラクタ
    ~MyClass() {
        if (data_) {
            delete[] data_;
        }
        data_ = {};
    }

private:
    int* data_ = {}; // データポインタ
    int     dataSize_ = {}; // データサイズ
};


// エントリー関数
int main()
{

    MyClass src(1000);
    // autoやテンプレート仮引数（T等）に＆＆を使っている時は、
    // 右辺値を渡されたら、右辺値参照に、
    // 左辺値を渡されていたら左辺値参照
    // std::move(src); = 右辺値　rRef = 右辺値参照
    auto&& rRef = std::move(src);
    // src 左辺値　ref autoをつけると左辺値参照
    auto&& ref = src;

    // 以降 src は data_ が nullptr になっている為利用できない
    {
        // ループ処理等
    }

    return 0;
}

