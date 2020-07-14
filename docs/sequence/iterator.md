# sequence\<T\>::iterator

```
class iterator;
```


### メンバ型

|メンバ型名||
|:---|:---|
|difference_type|std::ptrdiff_t|
|value_type|T|
|pointer|T *|
|reference|T &|
|iterator_category|std::random_access_iterator_tag|


### メンバ関数

|メンバ関数名||
|:---|:---|
|(constructor)|コンストラクタ|
|(destructor)|デストラクタ|
|operator=|代入|

#### コンテナへの操作

|メンバ関数名||
|:---|:---|
|insert|自身の直前に要素を追加します|
|emplace|自身の直前に要素を直接構築で追加します|
|erase|自身の指す要素を削除します|
|splice|自身の直前に他のコンテナの要素を移動させます|

#### その他

|メンバ関数名||
|:---|:---|
|is_singular|singular iterator であるかを返します|
|is_past_the_end|past-the-end iterator であるかを返します| 
|from|所属するコンテナへの参照を返します|
|position|自身の位置を返します|
