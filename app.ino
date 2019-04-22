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

void setPan(float deg) {
    float real = 180 - deg - PAN_OFFSET;
    panServo.write(toMicros(real));
}

void setTilt(float deg) {
    float real = deg - TILT_OFFSET;
    tiltServo.write(toMicros(real));
}

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);
    panServo.attach(PAN_SERVO);
    tiltServo.attach(TILT_SERVO);
}

float pan = 90.0;
float tilt = 55.0;

float MIN_PAN = 45.0;
float MAX_PAN = 135.0;
float MIN_TILT = 45.0;
float MAX_TILT = 90.0;

long startMillis = 0;
long jitterTimer = 0;

void sendPan() {
    setPan(constrain(pan, MIN_PAN, MAX_PAN));
}

void sendTilt() {
    setTilt(constrain(tilt, MIN_TILT, MAX_TILT));
}

float jitterAmount = 200.0;
float jumpAmount = 3000.0;
void jitter() {
    pan += random(-jitterAmount, jitterAmount) / 100.0;
    tilt += random(-jitterAmount, jitterAmount) / 100.0;
}

void loop()
{
    sendPan();
    sendTilt();

    if(millis() - startMillis > 3000) {
        pan += random(-jumpAmount, jumpAmount) / 100.0;
        pan = constrain(pan, MIN_PAN, MAX_PAN);
        tilt += random(-jumpAmount, jumpAmount) / 100.0;
        tilt = constrain(tilt, MIN_TILT, MAX_TILT);
        startMillis = millis();
    }

    if(millis() - jitterTimer > 100) {
        jitter();
        jitterTimer = millis();
    }
}
