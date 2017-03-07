#define DY_DELAY 12
#define DY_PWM 9

sbit DY_LED1_H1 = P2^3; // 12
sbit DY_LED1_H2 = P2^0; // 9
sbit DY_LED1_H3 = P3^7; // 8
sbit DY_LED1_H4 = P1^5; // 6

sbit DY_LED1_L1 = P2^2; // 11
sbit DY_LED1_L2 = P3^6; // 7
sbit DY_LED1_L3 = P1^3; // 4
sbit DY_LED1_L4 = P1^1; // 2
sbit DY_LED1_L5 = P1^0; // 1
sbit DY_LED1_L6 = P2^1; // 10
sbit DY_LED1_L7 = P1^4; // 5
sbit DY_LED1_L8 = P1^2; // 3

char disdata[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void delay(unsigned int a) {
    unsigned int i;
    while (--a != 0) {
        for (i = 0; i < DY_DELAY; i++) { }
    }
}

void dis_off() {
    DY_LED1_H1 = 0;
    DY_LED1_H2 = 0;
	DY_LED1_H3 = 0;
	DY_LED1_H4 = 0;
	DY_LED1_L1 = 1;
	DY_LED1_L2 = 1;
	DY_LED1_L3 = 1;
	DY_LED1_L4 = 1;
	DY_LED1_L5 = 1;
	DY_LED1_L6 = 1;
	DY_LED1_L7 = 1;
	DY_LED1_L8 = 1;
	delay(10 - DY_PWM);
}

void displayHH1(char d) {
    char i;
    i = d & 0x01;
    if (i == 0x01) {
        DY_LED1_H1 = 1;
        DY_LED1_L1 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x02;
    if (i == 0x02) {
        DY_LED1_H1 = 1;
        DY_LED1_L2 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x04;
    if (i == 0x04) {
        DY_LED1_H1 = 1;
        DY_LED1_L3 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x08;
    if (i == 0x08) {
        DY_LED1_H1 = 1;
        DY_LED1_L4 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x10;
    if (i == 0x10) {
        DY_LED1_H1 = 1;
        DY_LED1_L5 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x20;
    if (i == 0x20) {
        DY_LED1_H1 = 1;
        DY_LED1_L6 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x40;
    if (i == 0x40) {
        DY_LED1_H1 = 1;
        DY_LED1_L7 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x80;
    if (i == 0x80) {
        DY_LED1_H1 = 1;
        DY_LED1_L8 = 0;
    }
    delay(DY_PWM);
    dis_off();
}

void displayHH2(char d) {
    char i;
    i = d & 0x01;
    if (i == 0x01) {
        DY_LED1_H2 = 1;
        DY_LED1_L1 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x02;
    if (i == 0x02) {
        DY_LED1_H2 = 1;
        DY_LED1_L2 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x04;
    if (i == 0x04) {
        DY_LED1_H2 = 1;
        DY_LED1_L3 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x08;
    if (i == 0x08) {
        DY_LED1_H2 = 1;
        DY_LED1_L4 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x10;
    if (i == 0x10) {
        DY_LED1_H2 = 1;
        DY_LED1_L5 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x20;
    if (i == 0x20) {
        DY_LED1_H2 = 1;
        DY_LED1_L6 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x40;
    if (i == 0x40) {
        DY_LED1_H2 = 1;
        DY_LED1_L7 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x80;
    if (i == 0x80) {
        DY_LED1_H2 = 1;
        DY_LED1_L8 = 0;
    }
    delay(DY_PWM);
    dis_off();
}

void displayHH3(char d) {
    char i;
    i = d & 0x01;
    if (i == 0x01) {
        DY_LED1_H3 = 1;
        DY_LED1_L1 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x02;
    if (i == 0x02) {
        DY_LED1_H3 = 1;
        DY_LED1_L2 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x04;
    if (i == 0x04) {
        DY_LED1_H3 = 1;
        DY_LED1_L3 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x08;
    if (i == 0x08) {
        DY_LED1_H3 = 1;
        DY_LED1_L4 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x10;
    if (i == 0x10) {
        DY_LED1_H3 = 1;
        DY_LED1_L5 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x20;
    if (i == 0x20) {
        DY_LED1_H3 = 1;
        DY_LED1_L6 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x40;
    if (i == 0x40) {
        DY_LED1_H3 = 1;
        DY_LED1_L7 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x80;
    if (i == 0x80) {
        DY_LED1_H3 = 1;
        DY_LED1_L8 = 0;
    }
    delay(DY_PWM);
    dis_off();

}

void displayHH4(char d) {
    char i;
    i = d & 0x01;
    if (i == 0x01) {
        DY_LED1_H4 = 1;
        DY_LED1_L1 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x02;
    if (i == 0x02) {
        DY_LED1_H4 = 1;
        DY_LED1_L2 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x04;
    if (i == 0x04) {
        DY_LED1_H4 = 1;
        DY_LED1_L3 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x08;
    if (i == 0x08) {
        DY_LED1_H4 = 1;
        DY_LED1_L4 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x10;
    if (i == 0x10) {
        DY_LED1_H4 = 1;
        DY_LED1_L5 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x20;
    if (i == 0x20) {
        DY_LED1_H4 = 1;
        DY_LED1_L6 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x40;
    if (i == 0x40) {
        DY_LED1_H4 = 1;
        DY_LED1_L7 = 0;
    }
    delay(DY_PWM);
    dis_off();
    i = d & 0x80;
    if (i == 0x80) {
        DY_LED1_H4 = 1;
        DY_LED1_L8 = 0;
    }
    delay(DY_PWM);
    dis_off();
}
