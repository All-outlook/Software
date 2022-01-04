#include <SoftwareSerial.h>

SoftwareSerial MT_R_Serial(43, 54);//rx,tx
SoftwareSerial MT_L_Serial(45, 58);//rx,tx
//SoftwareSerial MT1_Serial(42, 53);//rx,tx
//SoftwareSerial MT2_Serial(44, 59);//rx,tx


void F_MD_setup() {
  //  pinMode(42, INPUT);
  //  pinMode(53, OUTPUT);
  pinMode(45, INPUT);
  pinMode(58, OUTPUT);
  pinMode(43, INPUT);
  pinMode(54, OUTPUT);
  //  pinMode(44, INPUT);
  //  pinMode(59, OUTPUT);


  MT_R_Serial.begin(38400);
  MT_L_Serial.begin(38400);
  //  MT1_Serial.begin(38400);
  //  MT2_Serial.begin(38400);
}

void test(){
  for (int i = 0; i <= 100; i++) {
    MT_L_Serial.write(i);
    MT_R_Serial.write(i);
  }
}


void F_speed_send(int id , int mySpeed) {
  if (id == 0 || id == 1) {
    if (mySpeed == -1) {
      //ブレーキ 40
      MT_R_Serial.write(40 + id);
    } else if (mySpeed > 0) {
      //正転 10
      MT_R_Serial.write(10 + id);
      MT_R_Serial.write(mySpeed);
    } else if (mySpeed < 0) {
      //後転 20
      MT_R_Serial.write(20 + id);
      MT_R_Serial.write(abs(mySpeed));
    } else if (mySpeed == 0) {
      //ストップ 30
      MT_R_Serial.write(30 + id);
    }
  } else if (id == 2 || id == 3) {
    if (mySpeed == -1) {
      //ブレーキ 40
      MT_L_Serial.write(40 + id);
    } else if (mySpeed > 0) {
      //正転 10
      MT_L_Serial.write(10 + id);
      MT_L_Serial.write(mySpeed);
    } else if (mySpeed < 0) {
      //後転 20
      MT_L_Serial.write(20 + id);
      MT_L_Serial.write(abs(mySpeed));
    } else if (mySpeed == 0) {
      //ストップ 30
      MT_L_Serial.write(30 + id);
    }
  }
}
