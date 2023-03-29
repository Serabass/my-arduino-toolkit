// https://arduino-tex.ru/news/33/ky-008-lazernyi-modul-podklyuchenie-k-arduino.html

#define PIN_LED 9

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // blink the LED on pin 13
  digitalWrite(PIN_LED, HIGH);
  delay(1000);

  digitalWrite(PIN_LED, LOW);
  delay(1000);
}
