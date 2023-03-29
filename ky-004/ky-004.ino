// кнопка изначально отпущена, а свет выключен
boolean buttonWasUp = true;
boolean buttonIsUp  = false;
boolean ledEnabled  = false;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(A1, INPUT_PULLUP);
}

void loop() {
  // проверяем, отпущена ли кнопка сейчас
  buttonIsUp = digitalRead(A1);

  // если кнопка была отпущена и не отпущена сейчас
  if (buttonWasUp && !buttonIsUp) {

    // исключаем ложный сигнал при «дребезге» контактов
    // и считываем сигнал с кнопки повторно
    delay(10);
    buttonIsUp = digitalRead(A1);

    // если кнопка не была до этого момента нажата
    // значит был клик и переворачиваем сигнал светодиода
    if (!buttonIsUp) {
      ledEnabled = !ledEnabled;
      digitalWrite(13, ledEnabled);
    }
  }

  // запоминаем положение кнопки для следующей итерации
  buttonWasUp = buttonIsUp;
}