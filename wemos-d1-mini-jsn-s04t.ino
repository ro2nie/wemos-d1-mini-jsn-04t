/* This Arduino sketch file is a demonstration of how to use the Wemos D1 mini board with the JSN-SR04T ultrasonic
    proximity sensor. It will perform 10 reads and then sleep for 5 seconds.
*/
#include <ESP8266WiFi.h>
#define echoPin D7 // Echo Pin
#define trigPin D6 // Trigger Pin
long duration, distance; // Duration used to calculate distance

void setup()
{
  Serial.begin (9600);
  //Wemos D1 mini has issue waking up after deep sleep.
  //The fix is to connect RST to D0, after the board was flashed.
  Serial.println("WAKING UP");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  program();
  Serial.println("GOING TO SLEEP");
  //Sleep for 5 seconds
  ESP.deepSleep(5e6);
}

void program()
{
  for (int i = 0; i <= 10; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    //Calculate the distance (in cm) based on the speed of sound.
    distance = duration / 58.2;
    Serial.println("Level: " + String(distance) + " cm");
    delay(50);
  }
}

void loop() {}
