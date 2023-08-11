#define led1R 9    
#define led1G 10
#define led1B 11   
#define led2R 5    
#define led2G 6    
#define led2B 7    
#define led3R 2    
#define led3G 3    
#define led3B 4
#define potPin A0   
#define buttonPin 8 

int velocidad = 0;       

void setup() {
  pinMode(led1R, OUTPUT);
  pinMode(led1G, OUTPUT);
  pinMode(led1B, OUTPUT);
  pinMode(led2R, OUTPUT);
  pinMode(led2G, OUTPUT);
  pinMode(led2B, OUTPUT);
  pinMode(led3R, OUTPUT);
  pinMode(led3G, OUTPUT);
  pinMode(led3B, OUTPUT);

  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  
  velocidad = map(analogRead(potPin), 0, 1023, 100, 1000);

  
  if (digitalRead(buttonPin) == LOW) {
    apagarLEDs(); 
  } else {
    seguirJuegoDeLuces();
  }
}

void apagarLEDs() {
  analogWrite(led1R, 0);
  analogWrite(led1G, 0);
  analogWrite(led1B, 0);
  analogWrite(led2R, 0);
  analogWrite(led2G, 0);
  analogWrite(led2B, 0);
  analogWrite(led3R, 0);
  analogWrite(led3G, 0);
  analogWrite(led3B, 0);
}

void seguirJuegoDeLuces() {
  analogWrite(led1R, 255);
  analogWrite(led1G, 0);
  analogWrite(led1B, 0);

  delay(velocidad);

  analogWrite(led1R, 0);
  analogWrite(led1G, 0);
  analogWrite(led1B, 0);
  analogWrite(led2R, 255);
  analogWrite(led2G, 0);
  analogWrite(led2B, 255);

  delay(velocidad);

  analogWrite(led2R, 0);
  analogWrite(led2G, 0);
  analogWrite(led2B, 0);
  analogWrite(led3R, 0);
  analogWrite(led3G, 255);
  analogWrite(led3B, 255);

  delay(velocidad);

  analogWrite(led3R, 0);
  analogWrite(led3G, 0);
  analogWrite(led3B, 0);
  analogWrite(led1R, 255);
  analogWrite(led1G, 0);
  analogWrite(led1B, 0);

  delay(velocidad);
}