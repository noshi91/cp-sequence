# sequence

```
template <class T>
class sequence;
```

sequence は列を取り扱うデータ構造の実装です。
内部は splay tree で実装されており、ランダムアクセスなど様々な操作が
${\rm amortized} \ O(\log N)$ の時間計算量で実行可能です。


### テンプレート引数

|引数名||
|:---|:---|
|T|要素の型|


### メンバ型

|メンバ型名||
|:---|:---|
|value_type|T|
|reference|T &|
|const_reference|const T &|
|iterator|[iterator](sequence/iterator.md)|
|const_iterator|[const_iterator](sequence/const_iterator.md)|
|size_type|std::size_t|
|difference_type|std::ptrdiff_t|
|reverse_iterator|std::reverse_iterator<iterator>|
|const_reverse_iterator|std::reverse_iterator<const_iterator>|


### メンバ関数

|メンバ関数名||
|:---|:---|
|(constructor)|コンストラクタ|
|(destructor)|デストラクタ|
|operator=|代入|
|assign|代入|

#### 要素アクセス

|メンバ関数名||
|:---|:---|
|operator[]|n 番目の要素にアクセスします|
|at|n 番目の要素にアクセスし、範囲外の場合例外を送出します|
|front|先頭要素にアクセスします|
|back|末尾要素にアクセスします|

#### イテレータ

|メンバ関数名||
|:---|:---|
|begin, cbegin|先頭要素を指すイテレータを返します|
|end, cend|終端を指すイテレータを返します|
|rbegin, crbegin|終端を指す逆イテレータを返します|
|rend, crend|先頭要素を指す逆イテレータを返します|
|nth_iterator|n 番目の要素を指すイテレータを返します|

####　容量

|メンバ関数名||
|:---|:---|
|size|要素数を返します|
|empty|コンテナが空かどうかを返します|

#### 変更

|メンバ関数名||
|:---|:---|
|push_back|末尾に要素を追加します|
|emplace_back|末尾に要素を直接構築で追加します|
|pop_back|末尾の要素を削除します|
|push_front|先頭に要素を追加します|
|emplace_front|先頭に要素を直接構築で追加します|
|pop_front|先頭の要素を削除します|
|insert|指定した位置に要素を追加します|
|emplace|指定した位置に要素を直接構築で追加します|
|erase|指定した要素を削除します|
|clear|全ての要素を削除します|
|resize|サイズを変更します|
|swap|別のコンテナと内容を入れ替えます|

#### 操作

|メンバ関数名||
|:---|:---|
|splice|他のコンテナから要素を移動させます|
|reverse|列全体を反転させます|
