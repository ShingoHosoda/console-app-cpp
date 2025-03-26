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

英大文字が含まれているかどうかの判定です。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isContainUpperCase.cpp)

### 英小文字が含まれているとは

英小文字が含まれているかどうかの判定です。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isContainLowerCase.cpp)
