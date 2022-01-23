#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

// 1 second = 1,000 millis = 1,000,000 micros
// goal_time(n), n = millis
int id;
int gyro_degree;
int gyro_speed;
int IR_degree;
int IR_value;
int line_digits;
int line_degree;
int either_degree;
int either_speed[4];
int more;
float ratio;
const float power = 254.0;
char MT_number[] = {'A', 'B', 'C', 'D'};
int MT_speed[4];

void setup()
{
  Serial.begin(115200);
  F_switch_setup();
  F_LED_setup();
  F_MD_setup();
  F_IR_setup();
  F_GYRO_setup();
  F_LINE_setup();
  F_flame_setup();
  F_kicker_setup();
  F_reset_setup();
  F_buzzer_setup();
}

void loop()
{
  F_time_read();
  F_GYRO_read();
  F_IR_read();
  F_LINE_read();

  if (F_switch_value() == 0)
  {
    F_LED_turnon() ;

    gyro_degree = F_GYRO_get();
    //    Serial.print('g');
    //    Serial.print(gyro_degree);
    //    Serial.print(",");

    IR_value = F_IR_get();
//    Serial.print('i');
//    Serial.print(IR_value);
//    Serial.print(",");
    IR_degree = F_wrap_degree(IR_value);
//    Serial.print('w');
//    Serial.print(IR_degree);
//    Serial.print(",");

    line_digits = F_LINE_get();
    Serial.print('l');
    Serial.print(line_digits);
    Serial.print(",");
    line_degree = F_line_avoid(line_digits, IR_value);
    Serial.print('s');
    Serial.print(line_degree);
    Serial.print(",");

    if (line_degree != 0 & IR_degree != 0 | line_degree != 0 & IR_degree == 0)
    {
      either_degree = line_degree;
    }
    else if (line_degree == 0 & IR_degree != 0)
    {
      either_degree = IR_degree;
    }
    else if (line_degree == 0 & IR_degree == 0)
    {
      either_degree = 0;
    }
//    Serial.print("e");
//    Serial.print(either_degree);
//    Serial.print(",");

   F_MD_rotate(either_degree, gyro_degree, 254);

    F_kicker();
  }
  else
  {
    Serial.print("OFF");
    F_MD_rotate(0, gyro_degree, 0);
    
    F_LED_turnon();
  }
  Serial.println();
}
