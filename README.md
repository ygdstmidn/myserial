# このライブラリについて

mbedでuart通信をするなら、UnbufferedSerialクラスを使うかと思います。
<br>しかし、UnbufferedSerialクラスは直感的に使いにくい...と思うこともあるかと思います。
<br>その問題を解決するべく、このmyserialというクラスを作ります。
<br>myserialクラスはUnbufferedSerialクラスを継承することにより、UnbufferedSerialクラスと同じ機能を使うことができます。

クラス外の関数として、データを2進数の文字列に変換する関数、データをCOBS/Rを用いた形式に変換する関数などを入れています。

myserial_config.hで要らない機能の項目を0にすることにより、メモリ領域の削減、コンパイルする時間の短縮につながります。

名前空間は`mbed::lib_ygdstmidn::myserial`です。ヘッダファイル内でusingしています．

# publicメンバ関数

## getc,putc

昔のSerialクラスにあったメンバ関数です。

```c++
val = getc();
```
1バイト読み込みます。
<br>戻り値:
<br>受信したデータ(unsigned char)
<br>注:
<br>受信データがない場合は、受信するまで待ちます

```c++
putc(data);
```
<br>1バイト送ります。
<br>パラメーター:
<br>data – 送るデータ(1バイト)

## print

arduinoにある関数です。
<br>arduinoのprint関数が羨ましいので、mbedにも実装

・引数 data 送信するデータ
・引数 format format(BIN,DEC,heX,HEX)
・返り値 送信したバイト数(long)

### 第２引数について

BIN : 2進数
DEC : 10進数
heX : 16進数(小文字)
HEX : 16進数(大文字)

# クラス外関数

## printbin

データを2進数の文字列に変換します。