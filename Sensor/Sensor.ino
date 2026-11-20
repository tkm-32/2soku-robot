#include <Servo.h> // 制限事項：D9～10ピンでanalogWrite関数が使えなくなる点に注意．
#define SV_PIN 12 // PWNピンでなくてよい（analogWrite関数やPWMについては後述）．
Servo s; // Servoオブジェクト
void setup(){
// サーボを割り当てる．角度にズレがある場合は，第2～3引数を変更して調整することが可能．
// 第2引数は0度のとき，第3引数は180度の時のパルス幅（μs）を指定する．
s.attach(SV_PIN, 500, 2400); // パルス幅0.5～2.4ms（SG90のデータシート準拠）
}
void loop(){
for (int i = 0; i <= 180; i += 20) {
s.write(i); // 引数に角度（0～180）を指定
delay(1000);
}
}

