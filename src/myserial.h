#ifndef INCLUDE_MYSERIAL_H_
#define INCLUDE_MYSERIAL_H_

#define DEVICE_SERIAL 1
#include "mbed.h"
#include "myserial_config.h"
#include "mbed_config.h"

namespace mbed
{
namespace lib_ygdstmidn
{
namespace myserial
{

enum myserial_print_format
{
    BIN,
    DEC,
    heX,//全部小文字で"hex"は別で使われてるらしい...
    HEX
};

class myserial : public UnbufferedSerial
{
    public:

        #if(1)//コンストラクタ、デストラクタ　

        /**
         * Create a serial port instance connected to the specified transmit and
         * receive pins, with the specified baud rate.
         *
         *  @param tx Transmit pin
         *  @param rx Receive pin
         *  @param baud The baud rate of the serial port (optional, defaults to MBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE)
         *
         *  @note
         *    Either tx or rx may be specified as NC if unused
         */
        myserial(PinName tx, PinName rx, int baud = MBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE);
    
        /** Create a UnbufferedSerial port, connected to the specified transmit and
         *  receive pins, with a particular baud rate.
         *  @param static_pinmap reference to structure which holds static pinmap
         *  @param baud The baud rate of the serial port (optional, defaults to
         *              MBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE)
         */
        myserial(const serial_pinmap_t &static_pinmap, int baud = MBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE);
    
        ~myserial();

        #endif

        #if(getc_ENABLE)//getc

        /**
         * 1バイト読み込みます。
         * @return 受信したデータ(unsigned char)
         * @note 受信データがないときは、NULL(0x00)が返ってきます。
        */
        uint8_t getc();

        #endif// getc_ENABLE

        #if(putc_ENABLE)//putc

        /**
         * 1バイト送ります。
         * @param data 送るデータ(1バイト)
        */
        void putc(uint8_t data);

        #endif// putc_ENABLE

        #if(print_ENABLE&&0)//print,int8_t

        /**
         * arduinoのprint関数が羨ましいので、mbedにも実装
         * @param data 送信するデータ
         * @param format format(BIN,DEC,heX,HEX)
         * @return 送信したバイト数(long)
        */
        int8_t print(int8_t data,myserial_print_format format = DEC);

        #endif// print_int8_t_ENABLE

};

}//namespace myserial

#if(printbin_ENABLE)//print_bin,int8_t

// /**
//  * データを2進数の文字列に変換します
//  * @param buf 変換後のデータを格納する配列(char*)
//  * @param buf_size bufの長さ
//  * @param data 変換するデータ
//  */
// int8_t printbin(char *buf,size_t buf_size,int8_t data);

template <typename T>
void printbin(T);

template <typename T>
void printbin(T inputdata)
{
    // union data_union
    // {
    //     T data;
    //     char c[sizeof(T)];
    // };
    
    // cout << "Binary representation of " << inputdata << " is:" << endl;
    // data_union inputunion;
    // inputunion.data = inputdata;
    // // for (int i = 0; i <= sizeof(T) - 1; i++)//ビッグインディアン
    // for (int i = sizeof(T) - 1; i >= 0; i--)//リトルインディアン
    // {
    //     for (int j = 7; j >= 0; j--)
    //     {
    //         cout << ((inputunion.c[i] & (1U << j)) >> j);
    //     }
    // }
    // cout << endl;
}

#endif// printbin_int8_t_ENABLE

}//namespace lib_ygdstmidn
}//namespace mbed

#endif// INCLUDE_MYSERIAL_H_