int sensePin = A0; 
int sensorInput; 
double temp;
int ledPin = 13; 
void setup(){
Serial.begin(9600); 
 pinMode(ledPin, OUTPUT);
}
void loop() {
sensorInput = analogRead(sensePin);
 
temp = (double) sensorInput/1024; 
temp = temp * 5; 
temp = temp - 0.5; 
temp = temp * 100; 
 
Serial.print("Current Temprature :");
Serial.println(temp);
 if (temp > 30) {
 digitalWrite(ledPin, HIGH);
 delay(1000);
 } else {
 digitalWrite(ledPin, LOW);
 }
 
}
