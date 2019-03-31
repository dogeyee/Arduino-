#include <IRremote.h>     //引用函式庫

int RECV_PIN = 6;     //設定紅外線腳位 = 6

IRrecv irrecv(RECV_PIN);

decode_results results;     //收到紅外線訊號值

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();      //啟動紅外線接收器
  pinMode(7,OUTPUT);      //(LED 燈腳位)
}

void loop() {
  if (irrecv.decode(&results)) {      //如果接收到紅外線
    Serial.println(results.value);
    if (results.value == 1168) {      //如果是家裡遙控器的上面按鈕(752)
      digitalWrite(7,HIGH);      //LED 亮
    } else if(results.value == 3216) {      //如果是家裡遙控器的上面按鈕(2800)
      digitalWrite(7,LOW);      //LED 滅
    } 
    irrecv.resume();      //可以再次讀取
  }
}
