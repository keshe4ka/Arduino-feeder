#include <Wire.h>
#include <TroykaRTC.h>
#include <Servo.h>
 
// Время первого кормления
#define FEED_HOUR_1     6
#define FEED_MINUTE_1   0
#define FEED_SECOND_1   0
// Время второго кормления
#define FEED_HOUR_2     10
#define FEED_MINUTE_2   0
#define FEED_SECOND_2   0
// Время третьего кормления
#define FEED_HOUR_3     15
#define FEED_MINUTE_3   0
#define FEED_SECOND_3   0
// Время четвертого кормления
#define FEED_HOUR_4     20
#define FEED_MINUTE_4   0
#define FEED_SECOND_4   0
// Время пятого кормления
#define FEED_HOUR_5     24
#define FEED_MINUTE_5   0
#define FEED_SECOND_5   0
#define SERVO_PIN A0
// Пин к которому подключается сервопривод
 
// Флаг "Уже покормили"
boolean flag = true;
 
RTC clock; 
Servo servo;

void setup() {
  // Инициализируем часы
  clock.begin();
  servo.attach(SERVO_PIN);
  servo.write(180);
  // Устанавливаем время
  clock.set(__TIMESTAMP__);
}

void loop() {
  clock.read();
  //Проверяем не пришло ли время покормить животное
  if (((clock.getHour() == FEED_HOUR_1) && (clock.getMinute() == FEED_MINUTE_1) && (clock.getSecond() == FEED_SECOND_1))
  || ((clock.getHour() == FEED_HOUR_2) && (clock.getMinute() == FEED_MINUTE_2) && (clock.getSecond() == FEED_SECOND_2))
  || ((clock.getHour() == FEED_HOUR_3) && (clock.getMinute() == FEED_MINUTE_3) && (clock.getSecond() == FEED_SECOND_3))
  || ((clock.getHour() == FEED_HOUR_4) && (clock.getMinute() == FEED_MINUTE_4) && (clock.getSecond() == FEED_SECOND_4))
  || ((clock.getHour() == FEED_HOUR_5) && (clock.getMinute() == FEED_MINUTE_5) && (clock.getSecond() == FEED_SECOND_5))) {
    // Если время пришло устанавливаем флаг "Уже покормили"
    flag == false;
    // Открываем заслонку
    servo.write(90);
    // Время открытия заслонки
    delay(500);
    servo.write(180);
  } else {
    flag == true;
    long timeMs = millis();
    while (millis() - timeMs < 10) {}
    servo.write(180);
  }
}
