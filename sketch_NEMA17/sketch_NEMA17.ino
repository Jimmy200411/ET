// Pin definities
int PUL_PIN = 3;  // Pulse input      (DQ)
int DIR_PIN = 5;  // Direction input  (DQ)

// Snelheid instellingen
const int PUL_DELAY_US = 5;  // microsecond delay tussen pulsen (pas aan voor snelheid)

// Aantal stappen
const long STEPS = 1;       // 1 rotation bij full step (1,8° per stap)

void setup() {
  
  // Set baudrate of the serial port
  Serial.begin(115200);   
  
  // initializing the direction of the pin (in or out)
  pinMode(PUL_PIN, OUTPUT); 
  pinMode(DIR_PIN, OUTPUT);

  // Motor aansturen: DIR_PIN; HIGH = clockwise, LOW = counterclockwise
  digitalWrite(DIR_PIN, HIGH);  
  digitalWrite(PUL_PIN, HIGH);
  delay(1000);
  digitalWrite(PUL_PIN, LOW);
  delay(500);
  digitalWrite(DIR_PIN, LOW);
  digitalWrite(PUL_PIN, HIGH);
  delay(1000);
  digitalWrite(PUL_PIN, LOW);
}

void loop() {
  
  if (Serial.available() > 0)
  {
    Serial.println("message incomming");
    char incomming = Serial.read();

    // 1 'w' is 1 step clockwise
    if (incomming == 'w')
    {
      Serial.println("Beweging vooruit");
      digitalWrite(DIR_PIN, HIGH);
      for(long i = 0; i < STEPS; i++){
        digitalWrite(PUL_PIN, HIGH);
        delay(PUL_DELAY_US);
        digitalWrite(PUL_PIN, LOW);
        delay(PUL_DELAY_US);
      }
    }

    // 1 's' is 1 step counterclockwise
    else if (incomming == 's')
    {
      Serial.println("Beweging achteruit");
      digitalWrite(DIR_PIN, LOW);
      for(long i = 0; i < STEPS; i++){
        digitalWrite(PUL_PIN, HIGH);
        delay(PUL_DELAY_US);
        digitalWrite(PUL_PIN, LOW);
        delay(PUL_DELAY_US);
      }
    }

    // if nothing is writen, print message in serial monitor.
    else if (incomming == ' ')
    {
      Serial.println("no message incomming");
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
