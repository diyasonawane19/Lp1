int IRSensor = 2;     
int LED = 13;         

void setup() {
  pinMode(IRSensor, INPUT);   
  pinMode(LED, OUTPUT);       
  Serial.begin(9600);         
}

void loop() {
  int statusSensor = digitalRead(IRSensor);  
  Serial.println(statusSensor);              

  if (statusSensor == HIGH){   
   digitalWrite(LED, LOW);     
 }
 else{                       
    digitalWrite(LED, HIGH);     
  }

  delay(50); 
}
