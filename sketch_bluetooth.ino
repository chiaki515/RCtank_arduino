/*
//1 : 前進
//2 : 後退
//3 : 左へ転回
//4 : 右へ転回
//s : 停止
//b : ブレーキ
*/
 
void setup() {
  Serial.begin(115200);
  /*motor 1 : LEFT*/
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  /*motor 2 : RIGHT*/
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

/* モジュールのリセット
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(2, HIGH);
  delay(500);

  Serial.begin(9600);

  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  
*/

}
 
void loop() {
  char c;
  int v = 100;
  if(Serial.available() >= 0){/*受信したデータが存在する*/
    char c = Serial.read();/*受信データを読み込む*/
    /*前進*/
    if(c == '1'){
      Serial.print("Forward\n");
      delay(10);
      analogWrite(11, v);
      digitalWrite(10, LOW);
      analogWrite(6, v);
      digitalWrite(5, LOW);
    }
    /*後退*/
    else if(c == '2'){
      Serial.print("Back\n");
      delay(10);
      digitalWrite(11, LOW);
      analogWrite(10, v);
      digitalWrite(6, LOW);
      analogWrite(5, v);
    }
    /*左へ転回*/
    else if(c == '3'){
      Serial.print("Left\n");
      delay(10);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      analogWrite(6, v);
      digitalWrite(5, LOW);
    }
    /*右へ転回*/
    else if(c == '4'){
      Serial.print("Rigth\n");
      delay(10);
      analogWrite(11, v);
      digitalWrite(10, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
    }
    /*停止*/
    else if(c == 's'){
      Serial.print("Stop\n");
      delay(10);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
    }
    /*ブレーキ*/
    else if(c == 'b'){
      Serial.print("Brake\n");
      delay(10);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
    }
  }
}
