
#include <iostream>
#include<map>

int main()
{
    // キーがchar、値がfloat を扱う map を宣言する
    std::map <char, float> map;

    // 情報を追加方法
    {
        // 'a' をキーに値 1.5f を追加する
        map['a'] = 1.5f;

        // emplace 関数 を利用する
        // 'c'という文字に 3.1f という値をむずびつけて追加する
        map.emplace('c', 3.1f);

        // std::pair と insert 関数を利用する
        // 'b' をキーに値 2.4f を追加する
        map.insert(std::make_pair('b', 2.4f));
    }

    // 取得方法
    {
        // [] でキーを指定して値を取得する
        float f1 = map['a'];
        std::cout << f1 << std::endl;

        // at 関数でキーを指定して値を取得する
        float f2 = map.at('c');
        std::cout << f2 << std::endl;

        float f3 = map.at('b');
        std::cout << f3 << std::endl;
    }

    // 更新方法
    {
        // [] にキーで指定して更新する
        map['a'] = 0.3f;

        // at 関数の戻り値で更新する（戻り値が参照である為可能）
        map.at('c') = 100.5f;
    }

    // 削除方法
    {
        // 全部削除する
        map.clear();

         // キーを指定して削除する
        map.erase('c');
    }

    // --------------map のイテレーター---------------
    // 内容を取得していく
    for (std::map<char, float>::iterator it = map.begin(); it != map.end(); it++) 
    {
        // イテレーターから要素を取得
        char key = it->first;
        float value = it->second;

        // イテレーター空要素を更新
        // it->first = 'x'; // キーは更新されない
        it->second = 500.5f;// 値は更新できる
    }
    // map は直接数値をしていして位置を移動できない

    // 挿入
    {
        // 位置を指定して追加する（ただしソートされる為意味がない）
        std::map<char, float>::const_iterator position = map.begin();
        map.insert(position, std::make_pair('x', 100.0f));
    }

    // 削除
    {
        for (std::map<char, float>::iterator it = map.begin(); it != map.end(); ++it)
        {
            // 指定のキーだったらその位置を指定して削除する
            char key = it->first;
            if (key == 'b')
            {
                map.erase(it);
                break;
            }
        }
    }
}

