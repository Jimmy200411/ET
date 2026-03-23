// PIN DEFENITIONS
const int PUL_PIN = 3;  // Pulse input
const int DIR_PIN = 5;  // Direction input
const int FW_PIN  = 6;
const int BW_PIN  = 7;
const int AUTO_PIN = 8;

// constants for motor control
const int PulseDelay = 5;  // ms between the pulses for the Steppermotor
const int Steps      = 1;  // 1 rotation = 1,8° by full step
char incomming = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  // defining outputpins
  pinMode(PUL_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  // defining inputpins
  pinMode(FW_PIN, INPUT);
  pinMode(BW_PIN, INPUT);
  pinMode(AUTO_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    incomming = Serial.read();
  }
  
  
  switch(incomming){
    case 0:
      if (incomming == 'w')
      {
        Serial.println("Beweging vooruit");
        digitalWrite(DIR_PIN, HIGH);
        for(long i = 0; i < Steps; i++){
          digitalWrite(PUL_PIN, HIGH);
          delay(PulseDelay);
          digitalWrite(PUL_PIN, LOW);
          delay(PulseDelay);
        }
      }

      else if (incomming == 's')
      {
        Serial.println("Beweging achteruit");
        digitalWrite(DIR_PIN, LOW);
        for(long i = 0; i < Steps; i++){
          digitalWrite(PUL_PIN, HIGH);
          delay(PulseDelay);
          digitalWrite(PUL_PIN, LOW);
          delay(PulseDelay);
        }
      }
      
    break;

    case 1:
      if(FW_PIN > 0 && BW_PIN < 1) // if FW_PIN == 5v
      {
        Serial.println("KNOP - Beweging vooruit");
          digitalWrite(DIR_PIN, HIGH);
          for(long i = 0; i < Steps; i++){
            digitalWrite(PUL_PIN, HIGH);
            delay(PulseDelay);
            digitalWrite(PUL_PIN, LOW);
            delay(PulseDelay);
          }
      }

      else if(BW_PIN > 0 && FW_PIN < 1) // if BW_PIN == 5v
      {
        Serial.println("KNOP - Beweging achteruit ");
          digitalWrite(DIR_PIN, LOW);
          for(long i = 0; i < Steps; i++){
            digitalWrite(PUL_PIN, HIGH);
            delay(PulseDelay);
            digitalWrite(PUL_PIN, LOW);
            delay(PulseDelay);
          }
      }
    break;

  }
}
