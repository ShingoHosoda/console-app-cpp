# 文字列の処理

- [同一の数字列もしくは文字列の判定](#同一の数字列もしくは文字列の判定)
- [連続する数字列や文字列の判定1$](#連続する数字列や文字列の判定1)
- [連続する数字列や文字列の判定2$](#連続する数字列や文字列の判定2)
- [英大文字が含まれているとは](#英大文字が含まれているとは)
- [英小文字が含まれているとは](#英小文字が含まれているとは)
- [数字が含まれているとは](#数字が含まれているとは)
- [特定の記号（約物）が含まれているとは](#特定の記号約物が含まれているとは)
- [入力された文字が大文字かどうかを判定](#入力された文字が大文字かどうかを判定)
- [入力された文字が小文字かどうかを判定](#入力された文字が小文字かどうかを判定)
- [入力された文字が数字かどうかを判定](#入力された文字が数字かどうかを判定)
- [入力された文字が記号かどうかを判定](#入力された文字が記号かどうかを判定)
- [大文字を小文字に変換する](#大文字を小文字に変換する)
- [小文字を大文字に変換する](#小文字を大文字に変換する)
- [大文字と小文字のアルファベット順の番号を出力する](#大文字と小文字のアルファベット順の番号を出力する)
- [テキストをN文字分右にずらす](#テキストをn文字分右にずらす)
- [テキストをN文字分左にずらす](#テキストをn文字分左にずらす)

## 同一の数字列もしくは文字列の判定

たとえば同一の数字列や文字列とは```1111```や```AAAA```などです。

判定は $S_{i} = S_{i + 1}$ で行います。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isEqualsLetter.cpp)

## 連続する数字列や文字列の判定1$

連続する数字とは```1234```や```5678```などです。```4321```や```1122```は連続する数字ではありません。

判定は $S_{i + 1} - S_{i} = 1$ で行います。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isSequenceLetter1.cpp)

## 連続する数字列や文字列の判定2$

連続する数字とは```1234```や```4321```などです。```3457```や```1122```は連続する数字ではありません。

判定は $S_{i + 1} - S_{i} = 1$ と $S_{i} - S_{i + 1} = 1$ で行います。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isSequenceLetter2.cpp)

## 英大文字が含まれているとは

文字列に英大文字が含まれているかどうかの判定です。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isContainUpperCase.cpp)

## 英小文字が含まれているとは

文字列に英小文字が含まれているかどうかの判定です。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isContainLowerCase.cpp)

## 数字が含まれているとは

文字列に数字が含まれているかどうかの判定です。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isContainNumber.cpp)

## 特定の記号（約物）が含まれているとは

文字列に記号```@, ?, !```が含まれているかどうかの判定です。

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isContainSymbol.cpp)

## 入力された文字が大文字かどうかを判定

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isUpperCase.cpp)

## 入力された文字が小文字かどうかを判定

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isLowerCase.cpp)

## 入力された文字が数字かどうかを判定

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isNumber.cpp)

## 入力された文字が記号かどうかを判定

記号セット一覧

| 記号セット  |   min   |    max    |
| :---------: | :-----: | :-------: |
| 記号セット1 | ```!``` |  ```/```  |
| 記号セット2 | ```:``` |  ```@```  |
| 記号セット3 | ```[``` | ``` ` ``` |
| 記号セット4 | ```{``` |  ```~```  |

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/isSymbol.cpp)

## 大文字を小文字に変換する

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/convertUpperCaseToLowerCase.cpp)

## 小文字を大文字に変換する

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/convertLowerCaseToUpperCase.cpp)

## 大文字と小文字のアルファベット順の番号を出力する

割り当て番号表（大文字と小文字共通）

|   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |   M   |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|   0   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |  10   |  11   |  12   |

|   N   |   O   |   P   |   Q   |   R   |   S   |   T   |   U   |   V   |   W   |   X   |   Y   |   Z   |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  13   |  14   |  15   |  16   |  17   |  18   |  19   |  20   |  21   |  22   |  23   |  24   |  25   |

[ソースコード](https://github.com/ShingoHosoda/console-app-cpp/blob/main/app/letter/processing/alphabeticalOrderNumber.cpp)

## テキストをN文字分右にずらす

例　3文字分右にずらす

|   0   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |  10   |  11   |  12   |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |   M   |
|   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |   M   |   N   |   O   |   P   |

|  13   |  14   |  15   |  16   |  17   |  18   |  19   |  20   |  21   |  22   |  23   |  24   |  25   |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|   N   |   O   |   P   |   Q   |   R   |   S   |   T   |   U   |   V   |   W   |   X   |   Y   |   Z   |
|   Q   |   R   |   S   |   T   |   U   |   V   |   W   |   X   |   Y   |   Z   |   A   |   B   |   C   |

## テキストをN文字分左にずらす
