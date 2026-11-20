#include <Servo.h>

const int SV_PINS[4] = {2, 3, 4, 5};  // 左股関節, 右股関節, 左足首, 右足首
Servo sv[4];

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    sv[i].attach(SV_PINS[i], 500, 2400);  // パルス幅0.5～2.4ms（SG90）
    sv[i].write(90);                       // 中央の位置
  }
  delay(1000);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    Serial.print("Servo ");
    Serial.print(i + 1);
    Serial.print(" (D");
    Serial.print(SV_PINS[i]);
    Serial.println(")");

    sv[i].write(60);
    delay(700);
    sv[i].write(120);
    delay(700);
    sv[i].write(90);
    delay(700);
  }
}