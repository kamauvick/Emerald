const int PIN_A = A0;
const int PIN_D = 10;

const int LED = 11;

int val;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_A, INPUT);
  pinMode(PIN_D, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  if(digitalRead(PIN_D) == LOW){
    Serial.println("Raining");
    delay(30);
    digitalWrite(LED, LOW);
  }
  else{
    Serial.println("Not Raining");
    delay(30);
  }
  val = analogRead(PIN_A);

  Serial.println("Analog values");
  Serial.println(val);
  delay(1000);
}
