# 文字列の処理

## 文字列判定

### 同一の数字列もしくは文字列の判定

たとえば同一の数字列や文字列とは```1111```や```AAAA```などです。

判定は $S_{i} = S_{i + 1}$ で行います。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isEqualsLetter.cpp)

### 連続する数字列や文字列の判定 $(1)$

連続する数字とは```1234```や```5678```などです。```4321```や```1122```は連続する数字ではありません。

判定は $S_{i + 1} - S_{i} = 1$ で行います。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isSequenceLetter1.cpp)

### 連続する数字列や文字列の判定 $(2)$

連続する数字とは```1234```や```4321```などです。```3457```や```1122```は連続する数字ではありません。

判定は $S_{i + 1} - S_{i} = 1$ と $S_{i} - S_{i + 1} = 1$ で行います。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isSequenceLetter2.cpp)

### 英大文字が含まれているとは

文字列に英大文字が含まれているかどうかの判定です。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isContainUpperCase.cpp)

### 英小文字が含まれているとは

文字列に英小文字が含まれているかどうかの判定です。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isContainLowerCase.cpp)

### 数字が含まれているとは

文字列に数字が含まれているかどうかの判定です。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isContainNumber.cpp)

### 特定の記号（約物）が含まれているとは

文字列に記号```@, ?, !```が含まれているかどうかの判定です。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isContainSymbol.cpp)

### 入力された文字が大文字かどうかを判定

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isUpperCase.cpp)

### 入力された文字が小文字かどうかを判定

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isLowerCase.cpp)

### 入力された文字が数字かどうかを判定

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isNumber.cpp)

### 入力された文字が記号かどうかを判定

記号セット一覧

| 記号セット  |   min   |    max    |
| :---------: | :-----: | :-------: |
| 記号セット1 | ```!``` |  ```/```  |
| 記号セット2 | ```:``` |  ```@```  |
| 記号セット3 | ```[``` | ``` ` ``` |
| 記号セット4 | ```{``` |  ```~```  |

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isSymbol.cpp)

### 大文字を小文字に変換する

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/convertUpperCaseToLowerCase.cpp)

### 小文字を大文字に変換する

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/convertLowerCaseToUpperCase.cpp)

### アルファベットの番号を出力する

### テキストをN文字分右にずらす

### テキストをN文字分左にずらす
