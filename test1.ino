const int In1 = 5;//1B1的腳位
   const int In2 = 6;//1A1的腳位
   const int In3 = 9;//1A2的腳位
   const int In4 = 10;//1B2的腳位

int SensorLeft = 8;//左感測器輸入腳
int SensorRight =12;//右感測器輸入腳
int SL;//左感測器狀態
int SR;//右感測器狀態
void setup() {
  Serial.begin(9600);//初始化序列埠
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(SensorLeft, INPUT);//讀入左感測器狀態
  pinMode(SensorRight, INPUT); //讀入右感測器狀態
  mstop();
  delay(500);
 }
void loop(){
  SL = digitalRead(SensorLeft); //讀取左感測器狀態值
  SR = digitalRead(SensorRight);//讀取右感測器狀態值
  if (SL == 1&& SR ==1) {//如果左右感測器的值均為 1，代表左右感測器都看到黑色，車子前進
    mstop();
    delay(250);
    mforward();
    delay(50);
  }
  
  if (SL == 1 && SR == 0) {//如果左邊感測器的值為1，而右邊感測器的值為0，代表左邊感測器看到黑色，右邊感測器看到白色，車子左轉
    mstop(); 
    delay(500);
    mleft();
    delay(100);
  }
  
  if (SL == 0 && SR == 1) {//如果左邊感測器的值為0，而右邊感測器的值為1，代表左邊感測器看到白色，右邊感測器看到黑色，車子右轉
    mstop();
    delay(500);
    mright();
    delay (100);
  }
  
  if (SL == 0&& SR == 0) { //如果左邊感測器的值為0，而右邊感測器的值為0，代表左右邊感測器都看到白色，車子停止
    mstop();
    delay (100);
  }
 }
 int mback(){//後退的函式
  digitalWrite(In1,LOW);//左邊往前
  digitalWrite(In2,HIGH);//左邊往後
  digitalWrite(In3,LOW);//右邊往前
  digitalWrite(In4, HIGH);//右邊往後
}
void mforward(){//前進的函式
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}
void mleft(){//左轉的函式
  digitalWrite(In1, LOW);  
  digitalWrite(In2, LOW);  
  digitalWrite(In3,HIGH);
  digitalWrite(In4, LOW);
}
void mright(){//右轉的函式
  digitalWrite(In1,HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}
void mstop(){//停止的函式
  digitalWrite(In1,LOW);
  digitalWrite(In2,LOW);
  digitalWrite(In3,LOW);
  digitalWrite(In4,LOW);
}
