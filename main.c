#include "STC15F2K60S2.H"
#include "display.h"
#include "iap.h"

#define KEY_DELAY   6  // x 50ms

sbit key_zero = P3^4;
sbit key_reset = P3^2;
sbit key_start = P2^5;
sbit key_n = P2^6;
sbit key_t1 = P2^7;
sbit key_t2 = P1^6;
sbit key_t3 = P1^7;

sbit IR_LED = P5 ^5;

char n = -1, ti = 25, disp[4] = {0, 0, 3, 6};
int t[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dis;

char key = 1;
char time_key = KEY_DELAY;

void shutter() {
    int i;
    TH1 = 0xff;
    TL1 = 0xf1;
    TR1 = 1;//开计时器
    for (i = 0; i < 32; i++) {
        while (TF1 == 0) { }
        TF1 = 0;
        IR_LED = ~IR_LED;
    }
    TR1 = 0;
    TH1 = 0xf2;
    TL1 = 0x04;
    TR1 = 1;
    while (TF1 == 0) { }
    TF1 = 0;
    TH1 = 0xff;
    TL1 = 0xf1;
    TR1 = 1;
    for (i = 0; i < 32; i++) {
        while (TF1 == 0) { }
        TF1 = 0;
        IR_LED = ~IR_LED;
    }
    TR1 = 0;
}

void timer() {
    dis--;
    if (dis == 0) {
        shutter();
        disp[0]++;
        if (disp[0] > n) { disp[0] = 0; }
        dis = t[disp[0]];
    }
    disp[1] = dis / 100;
    disp[2] = (dis / 10) % 10;
    disp[3] = dis % 10;
}

void start() {
    int i = 0;
    while (1) {
        if (i == 10) { break; }
        if (t[i] == 0) {
            i++;
            continue;
        }
        else {
            n++;
            t[n] = t[i];
            i++;
        }
    }
    dis = t[0];
    disp[0] = 0;
    disp[1] = dis / 100;
    disp[2] = (dis / 10) % 10;
    disp[3] = dis % 10;
    ET0 = 1;//开计时器中断
    TH0 = 0x63;
    TL0 = 0xC0;
    TR0 = 1;//开计时器
}

void control() {
    if ((key_n && key_t1 && key_t2 && key_t3 && key_zero) == 0) {
        key = 0;
        ET1 = 1;//开计时器中断
        TH1 = 0x3c;
        TL1 = 0xb0;
        TR1 = 1;//开计时器
    }
    if (key_zero == 0) {
        int i;
        for (i = 0; i < 10; i++) { t[i] = 0; }
        for (i = 0; i < 3; i++) { disp[i] = 0; }
        disp[3] = 8;
    }
    if (key_n == 0) {
        t[disp[0]] = 100 * disp[1] + 10 * disp[2] + disp[3];
        disp[0] = disp[0] + 1;
        if (disp[0] == 10) { disp[0] = 0; }
        disp[1] = t[disp[0]] / 100;
        disp[2] = t[disp[0]] / 10 % 10;
        disp[3] = t[disp[0]] % 10;
    }
    else if (key_t1 == 0) {
        if (disp[1] == 9) {
            disp[1] = 0;
        } else { disp[1]++; }
    }
    else if (key_t2 == 0) {
        if (disp[2] == 9) {
            disp[2] = 0;
        } else { disp[2]++; }
    }
    else if (key_t3 == 0) {
        if (disp[3] == 9) {
            disp[3] = 0;
        } else { disp[3]++; }
    }
    else if (key_start == 0) {
        t[disp[0]] = 100 * disp[1] + 10 * disp[2] + disp[3];
        key = 0;
        start();
    }
}

void init(void) {
    IR_LED = 1;
    P1M0 = 0x20;
    P1M1 = 0x00;
    P2M0 = 0x09;
    P2M1 = 0x00;
    P3M0 = 0x80;
    P3M1 = 0x00;
    dis_off();
    EA = 1;//开总中断
}

void main() {
    IapIdle();
    init();
    while (1) {
        displayHH1(disdata[disp[0]]);
        displayHH2(disdata[disp[1]]);
        displayHH3(disdata[disp[2]]);
        displayHH4(disdata[disp[3]]);
        if (key == 1) {
            control();
        }
        if (key_reset == 0) { IAP_CONTR = 0x20; }
    }
}

void int3() interrupt 3 {
    time_key--;
    if (time_key == 0) {
        time_key = KEY_DELAY;
        key = 1;
        ET1 = 0;//关计时器中断
        TR1 = 0;//关计时器
    }
}


void int1() interrupt 1 {
    ti--;
    if (ti == 0) {
        ti = 25;
        timer();
    }
}