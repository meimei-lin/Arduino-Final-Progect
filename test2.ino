const int In1 = 5;//1B1的腳位
const int In2 = 6;//1A1的腳位
const int In3 = 9;//1A2的腳位
const int In4 = 10;//1B2的腳位
void mback(){//後退的函式
  digitalWrite(In1,LOW);//左邊往前
  digitalWrite(In2,HIGH);//左邊往後
  digitalWrite(In3,LOW);//右邊往前
  digitalWrite(In4,HIGH);//右邊往後
}

void mforward(){//前進的函式
  digitalWrite(In1,HIGH);
  digitalWrite(In2,LOW);
  digitalWrite(In3,HIGH);
  digitalWrite(In4,LOW);
}

void mstop(){//停止的函式
  digitalWrite(In1,LOW);
  digitalWrite(In2,LOW);
  digitalWrite(In3,LOW);
  digitalWrite(In4,LOW);
}

void mleft(){//左轉的函式
  digitalWrite(In1,LOW);  
  digitalWrite(In2,HIGH);  
  digitalWrite(In3,HIGH);  
  digitalWrite(In4,LOW); 
}

void mright(){//右轉的函式
  digitalWrite(In1,HIGH);
  digitalWrite(In2,LOW);
  digitalWrite(In3,LOW);
  digitalWrite(In4,HIGH);
}

const byte trigPin = 3 ;//超音波模組的觸發腳
const byte echoPin = 2 ;//超音波模組的接收腳
unsigned long d ;//儲存高脈衝的持續時間
unsigned long ping(){
  digitalWrite(trigPin,HIGH);//觸發腳設為高電位
  delayMicroseconds(10);//持續10微秒
  digitalWrite(trigPin,LOW);//觸發腳設為低電位
  return pulseIn(echoPin,HIGH,23200);//傳回高脈衝的持續時間
}

int collapseDetect(int d){//自訂距離偵測函數
   if( d <= 15 ){
  mstop();//碰到障礙物停止
  }
  else{
    mforward();
  }
}

void setup() {
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(trigPin,OUTPUT);//觸發腳設為輸出
  pinMode(echoPin,INPUT);//接收腳設為輸入
  delay(30);
  mforward();
  Serial.begin(9600);//初始化序列埠
}

void loop(){
  d = ping() / 58 ;//把高脈衝時間值換算成公分單位
  Serial.println(String("") + d +" cm");//顯示距離
  delay(100);
  collapseDetect(d);
}
