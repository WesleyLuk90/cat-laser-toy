#include <Servo.h>

int LED_PIN = 2;
int PAN_SERVO = A4;
int PAN_OFFSET = 35; // + is to the right
int TILT_SERVO = A5;
int TILT_OFFSET = 45; // + is down

Servo panServo;
Servo tiltServo;

float toMicros(float deg) {
    return map(deg, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

void pan(float deg) {
    float real = 180 - deg - PAN_OFFSET;
    panServo.write(toMicros(real));
}

void tilt(float deg) {
    float real = deg - TILT_OFFSET;
    tiltServo.write(toMicros(real));
}

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);
    panServo.attach(PAN_SERVO);
    tiltServo.attach(TILT_SERVO);
    pan(90.0);
    tilt(45.0);
}

    int pos = 0;
void loop()
{
    // for (pos = 0; pos <= 180; pos += 1) {
    //     panServo.write(pos,);
    //     tiltServo.write(pos);
    //     delay(15);
    // }
    // for (pos = 180; pos >= 0; pos -= 1) {
    //     panServo.write(pos);
    //     tiltServo.write(pos);
    //     delay(15);
    // }
    float real = 90.0 - TILT_OFFSET;
    Serial.println(real);
    Serial.println(toMicros(real));
}
