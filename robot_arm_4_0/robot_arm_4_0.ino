
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150
#define SERVOMAX  600

uint8_t servonum = 0;



int servo[5]={425,225,202,340,515};
void servoReflash()
{
   pwm.setPWM(14, 0, servo[4]);
   pwm.setPWM(13, 0, servo[3]);    //domysle 350
   pwm.setPWM(12, 0, servo[2]);   //default 400
   pwm.setPWM(11, 0, servo[1]);  //domysle 235
   pwm.setPWM(10, 0, servo[0]);  //domysle 425

   Serial.print(servo[0]);
   Serial.print("---");
   Serial.print(servo[1]);
   Serial.print("---");
   Serial.print(servo[2]);
   Serial.print("---");
   Serial.print(servo[3]);
   Serial.print("---");
   Serial.println(servo[4]);

  }
void defaultt()
{
   servo[4]=515;
   servo[3]=340;
   servo[2]=202;
   servo[1]=225;
   servo[0]=425;
   servoReflash();
   Serial.println("position:defaultt ");
 }
void position0()
{
   servo[4]=515;
   servo[3]=430;
   servo[2]=400;
   servo[1]=130;
   servo[0]=425;
   servoReflash();
   Serial.println("position:0");
 }
 void position1()
{
   servo[4]=515;
   servo[3]=340;
   servo[2]=400;
   servo[1]=225;
   servo[0]=425;
   servoReflash();

   Serial.println("position:1");

 }
void xRun(int x){
  servo[2]=(servo[2]-(x));   //default 400
  servo[1]=(servo[1]+(x));  //domysle 235
  servoReflash();
  Serial.println("position Xrun");
  }
void yRun(int y){
  servo[2]=(servo[2]-(y));   //default 400
  servo[1]=(servo[1]+(y/2));  //domysle 235
     servoReflash();
  Serial.println("position Yrun");
  }
void qRun(int y){
  servo[3]=(servo[3]-(y));
     servoReflash();
  Serial.println("position qrun");
  }
void zRun(int y){
  servo[0]=(servo[0]-(y));
     servoReflash();
  Serial.println("position qrun");
  }









#include <SoftwareSerial.h>

int bluetoothTx = 2;
int bluetoothRx = 3;
int stanszczypiec=0;
int stanC=0;
int stanD=0;

int speedd=100;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

int led = 13;

char cmd[100];
int cmdIndex;


void exeCmd() {


    if(strcmp(cmd, "default")==0) defaultt();
    if(strcmp(cmd, "position0")==0) position0();
    if(strcmp(cmd, "position1")==0) position1();
    for(;strcmp(cmd, "xRun0")==0;) {
      xRun(1);
      delay(speedd);
      bl();
      if(strcmp(cmd, "xRun0n")==0)break;
    }
    for(;strcmp(cmd, "xRun1")==0;) {
      xRun(-1);
      delay(speedd);
      bl();
    if(strcmp(cmd, "xRun1n")==0)break;
    }
    for(;strcmp(cmd, "yRun0")==0;) {
      yRun(-1);
      delay(speedd);
      bl();
      if(strcmp(cmd, "yRun0n")==0)break;
    }
    for(;strcmp(cmd, "yRun1")==0;){
      yRun(1);
      delay(speedd);
      bl();
      if(strcmp(cmd, "yRun1n")==0)break;
    }
    for(;strcmp(cmd, "qRun0")==0;) {
      qRun(1);
      delay(speedd);
      bl();
      if(strcmp(cmd, "qRun0n")==0)break;
    }
    for(;strcmp(cmd, "qRun1")==0;){
      qRun(-1);
      delay(speedd);
      bl();
      if(strcmp(cmd, "qRun1n")==0)break;
    }
     if(cmd[0]=='s' &&
     cmd[1]=='e' &&
     cmd[2]=='r' &&
     cmd[3]=='v' &&
     cmd[4]=='5' &&
     cmd[5]==' ') {

       int val = 0;
       for(int i=6; cmd[i]!=0; i++) {
         val = val*10 + (cmd[i]-'0');
       }
       // if cmd is "servo 1234", val will be 1234
            Serial.println(cmd);


      servo[4]=val;
      servoReflash();
     }
    for(;strcmp(cmd, "zRun0")==0;) {
      zRun(1);
      delay(speedd);
      bl();
      if(strcmp(cmd, "zRun0n")==0)break;
    }
    for(;strcmp(cmd, "zRun1")==0;){
      zRun(-1);
      delay(speedd);
      bl();
      if(strcmp(cmd, "zRun1n")==0)break;
    }

    if(strcmp(cmd, "A")==0){

    if(stanszczypiec==0){
    pwm.setPWM(15, 0, 450);//recommended 450
    stanszczypiec++;}
    else{
    pwm.setPWM(15, 0, 330);//recommended 330
    stanszczypiec--;}}

    if(strcmp(cmd, "B")==0){

    if(speedd==100){
    speedd=1;}
    else{
    speedd=100;}}

        if(strcmp(cmd, "c")==0){
            f3();
            f3();
            f3();



    }


        if(strcmp(cmd, "d")==0){



    }

}
void f1(){
    servo[0]=425;
    servo[3]=553;
    servo[4]=346;
    pwm.setPWM(15, 0, 330);
    stanszczypiec=0;
    servoReflash();
    delay(1000);
    //servo[2]=300;
    servo[1]=280;
    servoReflash();
    delay(300);
    for(int i=200;i!=300;i=i+10){
       pwm.setPWM(12, 0, i);   //default 400
       delay(300);
    }
    delay(300);
    pwm.setPWM(15, 0, 400);
    stanszczypiec=1;
    delay(500);
        delay(300);
    for(int i=300;i!=200;i=i-10){
       pwm.setPWM(12, 0, i);   //default 400
       delay(300);
    }
    defaultt();}
void f2(){
    servo[0]=560;
    servo[1]=226;
    servo[3]=340;
    servo[4]=515;
    servoReflash();
    for(int i=200;i!=330;i=i+10){
       pwm.setPWM(12, 0, i);   //default 400
       delay(300);
    }
    }
void f3(){
          f1();
          f2();
          pwm.setPWM(15, 0, 330);//recommended 450
          stanszczypiec--;
          delay(100);
          defaultt();}
void bl(){

  if(bluetooth.available()) {

    char c = (char)bluetooth.read();

    if(c=='\n') {
      cmd[cmdIndex] = 0;
      exeCmd();  // execute the command
      cmdIndex = 0; // reset the cmdIndex
    } else {
      cmd[cmdIndex] = c;
      if(cmdIndex<99) cmdIndex++;
    }

  }

}

void setup() {



  //-----------------------------------------------------
  //-----------------------------------------------------
  //-----------------------------------------------------
  delay(500); // wait for bluetooth module to start

  bluetooth.begin(115200); // Bluetooth default baud is 115200

  bluetooth.print("$");
  bluetooth.print("$");
  bluetooth.print("$"); // enter cmd mode
  delay(250);
  bluetooth.println("U,9600,N"); // change baud to 9600

  bluetooth.begin(9600);


  cmdIndex = 0;

  //-----------------------------------------------------
  //-----------------------------------------------------
  //-----------------------------------------------------

Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();

  pwm.setPWMFreq(60);

  delay(10);
}


void setServoPulse(uint8_t n, double pulse) {
  double pulselength;

  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period");
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit");
  pulse *= 1000000;  // convert to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}




void loop() {

bl();

}

