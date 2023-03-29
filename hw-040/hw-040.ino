#include "RotaryEncoder.h"          // библиотека для энкодера
RotaryEncoder encoder(A2, A3);  // пины подключение энкодера (DT, CLK)

static int pos = 0;  // задаем начальное положение энкодера
int newPos;

void setup() {
  Serial.begin(9600);
  Serial.println(pos);  // выводим на монитор начальное значение
}

void loop() {
   // проверяем положение ручки энкодера
   encoder.tick();
   newPos = encoder.getPosition();

   // если положение изменилось - выводим на монитор
   if (pos != newPos) {
      Serial.println(newPos);
      pos = newPos; 
   }
}
