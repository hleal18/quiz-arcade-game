#include <Arduino.h>

const int button_pin_1 = D7;
const int button_pin_2 = D6;
const int button_pin_3 = D5;

const int button_reboot = D8;

const int led_pin_1 = D4;
const int led_pin_2 = D2;
const int led_pin_3 = D1;

const int led_restricted_pin = D0;

int lectura = 0;

bool estado_restringido = false;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(button_pin_1, INPUT);
    pinMode(button_pin_2, INPUT);
    pinMode(button_pin_3, INPUT);
    pinMode(button_reboot, INPUT);
    pinMode(led_pin_1, OUTPUT);
    pinMode(led_pin_2, OUTPUT);
    pinMode(led_pin_3, OUTPUT);
    pinMode(led_restricted_pin, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    lectura = digitalRead(button_pin_1);

    if (lectura == HIGH && !estado_restringido)
    {
        Serial.println("Lectura pin 1");
        digitalWrite(led_pin_1, HIGH);
        digitalWrite(led_pin_2, LOW);
        digitalWrite(led_pin_3, LOW);
        digitalWrite(led_restricted_pin, HIGH);
        estado_restringido = true;
    }

    lectura = digitalRead(button_pin_2);

    if (lectura == HIGH && !estado_restringido)
    {
        Serial.println("Lectura pin 2");
        digitalWrite(led_pin_1, LOW);
        digitalWrite(led_pin_2, HIGH);
        digitalWrite(led_pin_3, LOW);
        digitalWrite(led_restricted_pin, HIGH);
        estado_restringido = true;
    }

    lectura = digitalRead(button_pin_3);

    if (lectura == HIGH && !estado_restringido)
    {
        Serial.println("Lectura pin 3");
        digitalWrite(led_pin_1, LOW);
        digitalWrite(led_pin_2, LOW);
        digitalWrite(led_pin_3, HIGH);
        digitalWrite(led_restricted_pin, HIGH);
        estado_restringido = true;
    }

    lectura = digitalRead(button_reboot);

    if (lectura == HIGH && estado_restringido)
    {
        Serial.println("Lectura pin de reboot");
        digitalWrite(led_pin_1, LOW);
        digitalWrite(led_pin_2, LOW);
        digitalWrite(led_pin_3, LOW);
        digitalWrite(led_restricted_pin, LOW);
        estado_restringido = false;
    }
}