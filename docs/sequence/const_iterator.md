# sequence\<T\>::const_iterator

```
class const_iterator;
```


### メンバ型

|メンバ型名||
|:---|:---|
|difference_type|std::ptrdiff_t|
|value_type|T|
|pointer|const T *|
|reference|const T &|
|iterator_category|std::random_access_iterator_tag|


### メンバ関数

|メンバ関数名||
|:---|:---|
|(constructor)|コンストラクタ|
|(destructor)|デストラクタ|
|operator=|代入|

#### その他

|メンバ関数名||
|:---|:---|
|is_singular|singular iterator であるかを返します|
|is_past_the_end|past-the-end iterator であるかを返します| 
|from|所属するコンテナへの参照を返します|
|position|自身の位置を返します|
