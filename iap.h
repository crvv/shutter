#include <intrins.h>

#define CMD_IDLE    0
#define CMD_READ    1
#define CMD_WRITE    2
#define ENABLE_IAP    0x82
#define IAP_ADDRESS    0x0000

void IapIdle() {
    IAP_CONTR = 0;
    IAP_CMD = 0;
    IAP_TRIG = 0;
    IAP_ADDRH = 0xff;
    IAP_ADDRL = 0xff;
}

char IapRead(int addr) {
    char dat;
    IAP_CONTR = ENABLE_IAP;
    IAP_CMD = CMD_READ;
    IAP_ADDRL = addr;
    IAP_ADDRH = addr >> 8;
    IAP_TRIG = 0x5a;
    IAP_TRIG = 0xa5;
    _nop_();
    dat = IAP_DATA;
    IapIdle();
    return dat;
}

void IapWrite(int addr, char dat) {
    IAP_CONTR = ENABLE_IAP;
    IAP_CMD = CMD_WRITE;
    IAP_ADDRL = addr;
    IAP_ADDRH = addr >> 8;
    IAP_DATA = dat;
    IAP_TRIG = 0x5a;
    IAP_TRIG = 0xa5;
    _nop_();
    IapIdle();
}
