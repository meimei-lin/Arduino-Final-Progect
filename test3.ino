const int In1 = 5;//1B1的腳位
    const int In2 = 6;//1A1的腳位
    const int In3 = 9;//1A2的腳位
    const int In4 = 10;//1B2的腳位

const byte trigPin = 3 ;//超音波模組的觸發腳
const byte echoPin = 2 ;//超音波模組的接收腳
unsigned long d ;//儲存高脈衝的持續時間

int SensorLeft = 8;//左感測器輸入腳
int SensorRight =12;//右感測器輸入腳
int SL;//左感測器狀態
int SR;//右感測器狀態
void setup() {
  Serial.begin(9600);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(SensorLeft, INPUT);//讀入左感測器狀態
  pinMode(SensorRight, INPUT); //讀入右感測器狀態
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  mstop();
  delay(500);
 }
void loop(){
  SL = digitalRead(SensorLeft); //讀取左感測器狀態值
  SR = digitalRead(SensorRight); //讀取右感測器狀態值
  d = ping() / 58 ;
  if( d <=25 ){//當碰到障礙物時停止
   mstop();
  }
  else{//沒障礙物就照著循跡行走
    if (SL == 1&& SR ==1) {
    mstop();
    delay(250);
    mforward();
    delay(50);
  }
  
  if (SL == 1 && SR == 0) {
   mstop(); 
   delay(500);
    mleft();
    delay(100);
  }
  
  if (SL == 0 && SR == 1) {
    mstop();
    delay(500);
    mright();
    delay (100);
  }
  
  if (SL == 0&& SR == 0) {
    mstop();
    delay (100);
  }
  }
  
 }

 unsigned long ping(){
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  return pulseIn(echoPin,HIGH,23200);
}
void mback(){
  digitalWrite(In1,LOW);
  digitalWrite(In2,HIGH);
  digitalWrite(In3,LOW);
  digitalWrite(In4,HIGH);
}
void mforward(){
  digitalWrite(In1,HIGH);
  digitalWrite(In2,LOW);
  digitalWrite(In3,HIGH);
  digitalWrite(In4,LOW);
}
void mleft(){
  digitalWrite(In1,LOW);
  digitalWrite(In2,LOW);
  digitalWrite(In3,HIGH);
  digitalWrite(In4,LOW);
}
void mright(){
  digitalWrite(In1,HIGH);
  digitalWrite(In2,LOW);
  digitalWrite(In3,LOW);
  digitalWrite(In4,LOW);
}
void mstop(){
  digitalWrite(In1,LOW);
  digitalWrite(In2,LOW);
  digitalWrite(In3,LOW);
  digitalWrite(In4,LOW);
}
