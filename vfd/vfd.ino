#include <avr/io.h>
#include <avr/interrupt.h>

int phaseA[] = {85, 170, 85, 0, 0, 0};
int phaseB[] = {0, 85, 170, 85, 0, 0};
int phaseC[] = {0, 0, 85, 170, 85, 0};
int phaseANeg[] = {0, 0, 0, 85, 170, 85};
int phaseBNeg[] = {85, 0, 0, 0, 85, 170};
int phaseCNeg[] = {170, 85, 0, 0, 0, 85};

void setup()
{
    TCCR1A = 0b10100001;
    TCCR1B = 0b00000001;
    TIMSK1 = 0b00000001;
    /*TIMER0 Config*/
    TCCR0A = 0b10100010;
    TCCR0B = 0b00000001;
    TIMSK0 = 0b00000001;
    /*TIMER2 Config*/
    TCCR2A = 0b10100010;
    TCCR2B = 0b00000001;
    TIMSK2 = 0b00000001;
    ICR1 = 1600;

    sei();
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(3, OUTPUT);
}

void loop()
{
}

ISR(TIMER1_OVF_vect)
{
    static int num;
    OCR1A = phaseA[num];
    OCR1B = phaseANeg[num];
    if (++num >= 6)
    {
        num = 0;
    }
}
ISR(TIMER0_OVF_vect)
{
    static int num0;
    OCR0A = phaseA[num0];
    OCR0B = phaseANeg[num0];
    if (++num0 >= 6)
    {
        num0 = 0;
    }
}
ISR(TIMER2_OVF_vect)
{
    static int num2;
    OCR2A = phaseA[num2];
    OCR2B = phaseANeg[num2];
    if (++num2 >= 6)
    {
        num2 = 0;
    }
}
