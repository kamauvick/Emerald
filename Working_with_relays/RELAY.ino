int relay = 9;

void setup() {
 Serial.begin(9600);
 Serial.println("Enter 1 to switch light on");
 Serial.println("Enter 0 to turn off");
 pinMode(relay, OUTPUT);
 

}

void loop() {
 while (Serial.available()){
  char inchar = (char)Serial.read();
  if(inchar == '1'){
    digitalWrite(relay, LOW);
    Serial.print("The bulb is ON");
    delay(1000);
  }else if(inchar == '0'){
    digitalWrite(relay, HIGH);
    Serial.print("The bulb is OFF");
    delay(1000);
  }
 }
}
