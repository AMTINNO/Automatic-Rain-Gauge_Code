const int REED_PIN = 7; // Pin connected to reed switch

int val = 0;
int old_val = 0;
int REEDCOUNT = 0; //This is the variable that hold the count of switching

void setup() 
{
  Serial.begin(9600);
  // Since the other end of the reed switch is connected to ground, we need
  // to pull-up the reed switch pin internally.
  pinMode(REED_PIN, INPUT_PULLUP);
}

void loop() 
{
  int val = digitalRead(REED_PIN); // Read the state of the switch
  if ((val == LOW) && (old_val == HIGH)) {// If the pin reads low, the switch is closed.
    
    delay(10); // Delay put in to deal with any "bouncing" in the switch.
    
    REEDCOUNT++;
    old_val = val;
    
    Serial.print("Medida de chuva (contagem): ");
    Serial.print(REEDCOUNT);//*0.2794); 
    Serial.println(" pulso");
    Serial.print("Medida de chuva (calculado): ");
    Serial.print(REEDCOUNT*0.25); 
    Serial.println(" mm");
  }
  else {
   old_val = val;              //If the status hasn't changed then do nothing
  }
}
