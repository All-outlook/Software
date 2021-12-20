void kicker() {
  for (int id = 0; id <= 1; id++) {
    capture_read[id] = analogRead(capture_pin[id]);
    if (capture_read[id] >= 300) {
      capture_value[id] = 1;
    } else {
      capture_value[id] = 0;
    }
  }
  if (capture_value[0] == 1 & capture_value[1] == 1) {
    digitalWrite(kicker_pin, HIGH);
  } else {
    digitalWrite(kicker_pin, LOW);
  }
  
  Serial.print("kicker:");
  if(kicker_pin == HIGH){
    Serial.print("on");
  } else {
    Serial.print("off");
  }
  Serial.println();

  if (kicker_pin == HIGH) {
    kicker_count = goal_count(1000);
    kicker_reaction = 1;
  }
  if (kicker_reaction == 1) {
    digitalWrite(kicker_pin, LOW);
  } else if (kicker_reaction == 0) {
  }
  if (period_count == kicker_count) {
    kicker_count = -1;
    kicker_reaction = -1;
  }
}
