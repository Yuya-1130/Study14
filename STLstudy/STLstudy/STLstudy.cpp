#include<vector>
#include <iostream>

int main()
{
    // int 要素数 4 の配列
    int a[5] = {};

     a[0] = 1;
     a[1] = 2;
     a[2] = 3;
     a[3] = 4;

     a[4] = 20;
    // vector を使った整数のコンテナ
    // 複数の情報を持つコンテナとして
    // int を扱う　vector を宣言する
    std::vector<int> nums;

    
    // 追加方法
    {
        // 情報を追加する
        // push_back　を使って末尾に追加
        // 要素が増えるとアドレスが毎回確保しなおす
        nums.push_back(1); // 0番目に「１」
        nums.push_back(2); // 1番目に「２」
        nums.push_back(3); // 2番目に「３」

        // emplace_back を使って末尾に追加
        //nums.emplace_back(8);
        //nums.emplace_back(11);
    }
    
    // 取得方法の例
    {
        int i1 = nums[0];
        int i2 = nums[1];
        int i3 = nums[2];

        // [] で添え字で取得する
        for (int i = 0; i < nums.size(); ++i) {
        // 添え字を使って要素を取得する
            int ii = nums[i];
            int jj = nums.at(i);
            std::cout << ii << std::endl;
        }

        // メンバ関数呼び出しで取得
        // at 関数でインデックス(∞番目)を指定して取得する
        int num = nums.at(0);  // int i1 = nums[0] と同じことをしている
        std::cout << num << std::endl;

    }

    // 更新方法
    {
        // 添え字で更新
        nums[0] = 40;

        // メンバ関数の戻り値が参照なので = で代入して更新可能　する人は少ない
        nums.at(0) = 100;
    }

    // 削除方法
    {

        // 末尾を削除する
        nums.pop_back();

        // 全部削除する
        nums.clear();
    }
}

