const int DRIVE_PIN = 5; // arbitrary pin choice
const int SWITCH_PERIOD_MS = 5000; // milliseconds
const int TEMP_SENSOR_PIN = 6; // arbitrary pin choice so long as it supports analog since using thermistor voltage divider

int desiredTemperature = 160; // this is configured over BT


void setup() {
  // put your setup code here, to run once:
  pinMode(DRIVE_PIN, OUTPUT);
  pinMode(TEMP_SENSOR_PIN, INPUT); // if it's a serial protocol, don't do this
  desiredTemperature = getConfigurationTemperate();
}

void loop() {
  // put your main code here, to run repeatedly:
 delay(SWITCH_PERIOD_MS);
 if (shouldDecreaseTemperature(desiredTemperature) {
  digitalWrite(DRIVE_PIN, LOW);
 } else {
  digitalWrite(DRIVE_PIN, HIGH);
 }
}

int getConfigurationTemperature() {
  while (!Serial.available());
  // HC-06 uses UART
  return Serial.parseInt();
}

int shouldDecreaseTemperature(int desiredTemp) {
  return analogRead(TEMP_SENSOR_PIN) > desiredTemp ;
}

