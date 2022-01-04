#include <SoftwareSerial.h>

SoftwareSerial MT_R_Serial(42, 53);//rx,tx
SoftwareSerial MT_L_Serial(45, 58);//rx,tx

void F_MD_setup() {
  pinMode(42, INPUT);
  pinMode(53, OUTPUT);
  pinMode(45, INPUT);
  pinMode(58, OUTPUT);


  MT_R_Serial.begin(38400);
  MT_L_Serial.begin(38400);
}

void test() {
  for (int i = 0; i <= 100; i++) {
    MT_L_Serial.write(i);
    MT_R_Serial.write(i);
  }
}


void F_speed_send(int id , int mySpeed) {
  if (id == 0 || id == 1) {
    if (mySpeed == -1) {
      //ブレーキ 0
      MT_R_Serial.write(0 + id);
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
      //ブレーキ 0
      MT_L_Serial.write(0 + id);
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








//#include <SoftwareSerialParity.h>
//
//SoftwareSerialParity MT0_Serial(42, 53);//rx,tx
//SoftwareSerialParity MT1_Serial(43, 54);//rx,tx
//SoftwareSerialParity MT2_Serial(44, 59);//rx,tx
//SoftwareSerialParity MT3_Serial(45, 58);//rx,tx
//
//
//void F_MD_setup() {
//  pinMode(42, INPUT);
//  pinMode(53, OUTPUT);
//  pinMode(43, INPUT);
//  pinMode(54, OUTPUT);
//  pinMode(44, INPUT);
//  pinMode(59, OUTPUT);
//  pinMode(45, INPUT);
//  pinMode(58, OUTPUT);
//  MT0_Serial.begin(38400, ODD);
//  MT1_Serial.begin(38400, ODD);
//  MT2_Serial.begin(38400, ODD);
//  MT3_Serial.begin(38400, ODD);
//}
//
//
////void ALL_UART(int value) {
////  for (int i = 0; i <= 3; i++) {
////    MT_UART(i, value);
////  }
////}
//
//void F_speed_send(int id , int mySpeed) {
//  if (mySpeed == -1) {
//    //ブレーキ 40
//    F_MT_UART(id, 40);
//  } else if (mySpeed > 0) {
//    //正転 10
//    F_MT_UART(id, 10);
//    F_MT_UART(id, mySpeed);
//
//  } else if (mySpeed < 0) {
//    //後転 20
//    F_MT_UART(id, 20);
//    F_MT_UART(id, abs(mySpeed));
//
//  } else if (mySpeed == 0) {
//    //ストップ 30
//    F_MT_UART(id, 30);
//  }
//}
//
//
//
//void F_MT_UART(int id, int knob) { //knob == 送信値
//  if (id == 0) {
//    MT0_Serial.write(knob);
//    MT0_Serial.flush();
//  } else if (id == 1) {
//    MT1_Serial.write(knob);
//    MT1_Serial.flush();
//  } else if (id == 2) {
//    MT2_Serial.write(knob);
//    MT2_Serial.flush();
//  } else if (id == 3) {
//    MT3_Serial.write(knob);
//    MT3_Serial.flush();
//  } else {
//    //なし
//  }
//}
