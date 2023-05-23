const int redbuttonPin = 3;
const int redLED = 8;
int redbuttonState = 0;

const int greenbuttonPin = 4;
const int greenLED = 9;
int greenbuttonState = 0;

const int bluebuttonPin = 5;
const int blueLED = 10;
int bluebuttonState = 0;

const int yellowbuttonPin = 6;
const int yellowLED = 11;
int yellowbuttonState = 0;

const int whitebuttonPin = 7;
const int whiteLED = 12;
int whitebuttonState = 0;


void setup() {
  Serial.begin(9600);
  pinMode(redbuttonPin, INPUT);
  pinMode(redLED, OUTPUT);
  
  pinMode(greenbuttonPin, INPUT);
  pinMode(greenLED, OUTPUT);  

  pinMode(bluebuttonPin, INPUT);
  pinMode(blueLED, OUTPUT);

  pinMode(yellowbuttonPin, INPUT);
  pinMode(yellowLED, OUTPUT);    

  pinMode(whitebuttonPin, INPUT);
  pinMode(whiteLED, OUTPUT);
}

void loop() {

  redbuttonState = digitalRead(redbuttonPin);
  greenbuttonState = digitalRead(greenbuttonPin);
  bluebuttonState = digitalRead(bluebuttonPin);
  yellowbuttonState = digitalRead(yellowbuttonPin);
  whitebuttonState = digitalRead(whitebuttonPin);
  
  if (redbuttonState == HIGH) {
    Serial.println("3");
    delay(500);

  }  

  else if (greenbuttonState == HIGH) {
    Serial.println("4");
    delay(500);

  }  
  
  else if (bluebuttonState == HIGH) {
    Serial.println("5");
    delay(500);

  }  

  else if (yellowbuttonState == HIGH) {
    Serial.println("6");
    delay(500);

  }  

  else if (whitebuttonState == HIGH) {
    Serial.println("7");
    delay(500);

  }  



  if (Serial.available () > 0){
    String msg = Serial.readString();

    if (msg == "3"){
      digitalWrite(redLED , HIGH);
      delay(500);
      digitalWrite(redLED , LOW);
    }
    else if (msg =="4"){
      digitalWrite(greenLED, HIGH);
      delay(500);
      digitalWrite(greenLED , LOW);
    }
    else if (msg =="5"){
      digitalWrite(blueLED, HIGH);
      delay(500);
      digitalWrite(blueLED , LOW);
    }
    else if (msg =="6"){
      digitalWrite(yellowLED, HIGH);
      delay(500);
      digitalWrite(yellowLED , LOW);
    }    
    else if (msg =="7"){
      digitalWrite(whiteLED, HIGH);
      delay(500);
      digitalWrite(whiteLED , LOW);
    }    
    
    }
  


}
