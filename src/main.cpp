#include <Arduino.h>

const uint8_t button_pin_1 = A1;
const uint8_t button_pin_2 = 2;
const uint8_t button_pin_3 = 3;
const uint8_t button_pin_4 = 4;
const uint8_t button_pin_5 = A0;
const uint8_t button_pin_6 = 6;

const uint8_t button_reboot = 5;

const uint8_t led_pin_1 = 7;
const uint8_t led_pin_2 = 8;
const uint8_t led_pin_3 = 9;
const uint8_t led_pin_4 = 10;
const uint8_t led_pin_5 = 11;
const uint8_t led_pin_6 = 12;

const uint8_t buzzer = A5;

bool restricted_state = false;

void activate_player(uint8_t pin);

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(button_pin_1, INPUT);
    pinMode(button_pin_2, INPUT);
    pinMode(button_pin_3, INPUT);
    pinMode(button_pin_4, INPUT);
    pinMode(button_pin_5, INPUT);
    pinMode(button_pin_6, INPUT);
    pinMode(button_reboot, INPUT);
    pinMode(led_pin_1, OUTPUT);
    pinMode(led_pin_2, OUTPUT);
    pinMode(led_pin_3, OUTPUT);
    pinMode(led_pin_4, OUTPUT);
    pinMode(led_pin_5, OUTPUT);
    pinMode(led_pin_6, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    if (!restricted_state)
    {
        // Player 1
        if (digitalRead(button_pin_1))
        {
            Serial.println("Lectura pin 1");
            activate_player(button_pin_1);
            restricted_state = true;
        }
        // Player 2
        else if (digitalRead(button_pin_2))
        {
            Serial.println("Lectura pin 2");
            activate_player(button_pin_2);
            restricted_state = true;
        }
        // Player 3
        else if (digitalRead(button_pin_3))
        {
            Serial.println("Lectura pin 3");
            activate_player(button_pin_3);
            restricted_state = true;
        }
        // Player 4
        else if (digitalRead(button_pin_4))
        {
            Serial.println("Lectura pin 4");
            activate_player(button_pin_4);
            restricted_state = true;
        }
        // Player 5
        else if (digitalRead(button_pin_5))
        {
            Serial.println("Lectura pin 5");
            activate_player(button_pin_5);
            restricted_state = true;
        }
        // Player 6
        else if (digitalRead(button_pin_6))
        {
            Serial.println("Lectura pin 6");
            activate_player(button_pin_6);
            restricted_state = true;
        }
    }
    else
    {
        if (digitalRead(button_reboot))
        {
            Serial.println("Lectura reboot");
            activate_player(button_reboot);
            restricted_state = false;
        }
    }
}

void activate_player(uint8_t pin)
{
    digitalWrite(led_pin_1, pin == button_pin_1);
    digitalWrite(led_pin_2, pin == button_pin_2);
    digitalWrite(led_pin_3, pin == button_pin_3);
    digitalWrite(led_pin_4, pin == button_pin_4);
    digitalWrite(led_pin_5, pin == button_pin_5);
    digitalWrite(led_pin_6, pin == button_pin_6);
    if (pin != button_reboot)
    {
        tone(buzzer, 2500, 500);
    }    
}