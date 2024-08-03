
int sensorPin = A0;
int lightG = 8;
int lightR = 7;
int lightW = 4;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // allows data to been seen on monitor
  pinMode(lightG, OUTPUT);  // tells which pin to give voltage to to light up LED
  pinMode(lightR, OUTPUT);
  pinMode(lightW, OUTPUT);
  pinMode(sensorPin, INPUT); // declare A0 as an input to read data

}

void loop() {
  // put your main code here, to run repeatedly:

  int data = analogRead(sensorPin); //reads value from specified analog pin. ADC on
                                    // micro controllers that converts voltage changes at output pin
                                    // of moisture sensor to digital output between
                                    // numbers 0 and 2023.

  if (data >= 1000) {
    Serial.println("No moisture, Soil dry");
    digitalWrite(lightR, HIGH);
    delay(100);
    digitalWrite(lightR, LOW);
    delay(100);
  } else if (data >= 500 && data <= 700) {
    Serial.println("Some moisture, Soil is medium moist");
    digitalWrite(lightW, HIGH);
    delay(50);
    digitalWrite(lightW, LOW);
    delay(50);
  } else if (data <= 400) {
    Serial.println("Soil is wet");
    digitalWrite(lightG, HIGH);
    delay(500);
    digitalWrite(lightG, LOW);
    delay(500);
  }
}
