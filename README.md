# このライブラリについて

mbedでuart通信をするなら、UnbufferedSerialクラスを使うかと思います。
しかし、UnbufferedSerialクラスは直感的に使いにくい...と思うこともあるかと思います。
その問題を解決するべく、このmyserialというクラスを作ります。
myserialクラスはUnbufferedSerialクラスを継承することにより、UnbufferedSerialクラスと同じ機能を使うことができます。

クラス外の関数として、データを2進数の文字列に変換する関数、データをCOBS/Rを用いた形式に変換する関数などを入れています。

myserial_config.hで要らない機能の項目を0にすることにより、メモリ領域の削減、コンパイルする時間の短縮につながります。

名前空間は`lib_mbed_myserial`です。

# publicメンバ関数

## getc,putc

昔のSerialクラスにあったメンバ関数です。

`uint8_t getc();`
1バイト読み込みます。
・返り値 受信したデータ(unsigned char)
・注 受信データがないときは、NULL(0x00)が返ってきます。

`void putc(uint8_t data);`
1バイト送ります。
・引数 data 送るデータ(1バイト)

## print

arduinoにある関数です。

arduinoのprint関数が羨ましいので、mbedにも実装

・引数 data 送信するデータ
・引数 format format(BIN,DEC,heX,HEX)
・返り値 送信したバイト数(long)

### 第２引数について

BIN : 2進数
DEC : 10進数
heX : 16進数(小文字)
HEX : 16進数(大文字)

8進数はありません。
**使わないよね???**
mbedのminimal-printfでは%oが使えないし...
無理やり実装してもメモリを食うし...

### 整数型

`int8_t print(int8_t data,myserial_class_print_format format = DEC);`

# クラス外関数

## printbin

データを2進数の文字列に変換します。

### 整数型

`static int8_t printbin(const char *buf,size_t buf_size,int8_t data);`