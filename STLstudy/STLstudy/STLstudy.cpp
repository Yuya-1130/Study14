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

    //-------------Vectorのイテレーター-------------
    
    // ・・・追加方法--省略--  上記の方法

    // イテレーターでアクセスする
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        // 取得方法
        {
            // イテレーターはポインタのように利用する
            int num = *it;
            std::cout << num << std::endl;
        }

        // 更新方法
        {
            // 要素の内容を「１００」に更新する
            *it = 100;
            int num = *it;
            std::cout << num << std::endl;
        }
    }

    // ・・・削除方法--省略--


    // ------指定の位置への追加方法------
    {
        // 「２」が入っている位置に「５」を追加したい
        std::vector<int>::iterator pos = nums.begin();
        pos += 1; // pos++
        nums.insert(pos, 5);
    }
    
    // ------指定の位置の削除方法--------
    {
        // 「1, 5, 2, 3」の「２」を削除したい
        std::vector<int>::iterator pos = nums.begin();
        pos += 2;
        nums.erase(pos);
    }

    // for ループで削除する場合
    // 下記のコードはクラッシュする
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        nums.erase(it);
    }
    // 回避方法
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end();)
    {
        // erase の戻り値で、削除した次の位置を取得する
      it =  nums.erase(it);
    }
    //----------------------------------------------
}

