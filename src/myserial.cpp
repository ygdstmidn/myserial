#include "myserial.h"

namespace mbed
{
namespace lib_ygdstmidn
{
namespace myserial
{

#define PRINT_INT8_T_BUF_SIZE   9

#if(1)//コンストラクタ、デストラクタ

myserial::myserial(PinName tx, PinName rx, int baud) : UnbufferedSerial(tx,rx,baud)
{
}

myserial::myserial(const serial_pinmap_t &static_pinmap, int baud) : UnbufferedSerial(static_pinmap,baud)
{
}

myserial::~myserial()
{
}

#endif

#if(getc_ENABLE)//getc

uint8_t myserial::getc()
{
    uint8_t buf;
    read(&buf,1);
    return buf;
}

#endif// getc_ENABLE

#if(putc_ENABLE)//putc

void myserial::putc(uint8_t data)
{
    write(&data,1);
}

#endif// putc_ENABLE

#if(print_int8_t_ENABLE&&0)//print,int8_t

int8_t myserial::print(int8_t data,myserial_print_format format)
{
    char buf[PRINT_INT8_T_BUF_SIZE];
    uint8_t size;

    switch (format)
    {
        case BIN:
            size=printbin(buf,PRINT_INT8_T_BUF_SIZE,data);
            return write(buf,size);
            break;
        case DEC:
            size=snprintf(buf,PRINT_INT8_T_BUF_SIZE,"%d",data);
            return write(buf,size);
            break;
        case heX:
            size=snprintf(buf,PRINT_INT8_T_BUF_SIZE,"%x",data);
            return write(buf,size);
            break;
        case HEX:
            size=snprintf(buf,PRINT_INT8_T_BUF_SIZE,"%X",data);
            return write(buf,size);
            break;
        default:
            break;
    }

    return 0;//error
}

#endif// print_int8_t_ENABLE

}//namespace myserial
}//namespace lib_ygdstmidn
}//namespace mbed