String command;
int light;
bool ignore = false;

void setup() {  
  Serial.begin(115200);
  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(4,HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  
  Serial.println("E36 LCM v1.3");
  Serial.println("Options:");
  Serial.println("         1 - lights on - Turn on lights");
  Serial.println("         2 - lights off - Turn off lights");
  Serial.println("         3 - reset - Reset conditions for automation");
  
  delay(5000);

  light = analogRead(0);

  Serial.print("Light: ");
  Serial.println(light);
  
  if ( light < 10 ){
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
      ignore = true;
    }
    if ( command == "lights off" || command == "2" ){
      Serial.println("> Turning off lights...");
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      ignore = true;
    }
    if ( command == "reset" || command == "3" ){
      Serial.println("> Resetting conditions...");
      ignore = false;
    }
  }
  
  if ( ! ignore )
    check();
    
  delay(500);
}

void check(){
  light = analogRead(0);
  
  if ( light < 10 ){
    // Turn lights on
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  } else
  if ( light > 10 ){
    // Turn lights off
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
  }
}

