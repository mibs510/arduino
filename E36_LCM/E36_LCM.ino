String command;

void setup() {  
  Serial.begin(115200);
  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  
  Serial.println("E36 LCM v1.2");
  Serial.println("Options:");
  Serial.println("         1 - lights on - Turn on lights");
  Serial.println("         2 - lights off - Turn off lights");
  
  delay(5000);

  Serial.print("Light: ");
  Serial.print(analogRead(0)/1023);
  Serial.print("% (");
  Serial.print(analogRead(0));
  Serial.println(")");
  
  if ( analogRead(0) < 10 ){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
}

void loop() {
  if ( Serial.available() > 0){
    command = Serial.readString();
    if ( command == "lights on" || command == "1" ){
      Serial.println("> Turning on lights...");
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
    if ( command == "lights off" || command == "2" ){
      Serial.println("> Turning off lights...");
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
    }
  }
  check();
  delay(1000);
}

void check(){
  if ( analogRead(0) < 10 ){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
}

