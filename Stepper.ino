
// Connections to A4988
const int dirPin = 2;  // Direction
const int stepPin = 3; // Step
String readString;
char Split;
char c;
// Motor steps per rotation
int STEPS_PER_REV ;
const int STEPS_PER_REV1 = 180;
const int STEPS_PER_STP =0;
char data;
void setup() {
  
  // Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600); 
  
  
}
void loop() {
  while (Serial.available()) {
    delay(3);  //delay to allow buffer to fill
    if (Serial.available() >0) {
      
      c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
    }
  }
  
  if (readString.length() >0) {
    
    
    switch(c)
    {
      
      case 'C':
        Anti_clock();
        break;
        
      case 'A':
        Clock_wise();
        break;
        
        // Pause for one second
        delay(1000); 
      default:
        if((c!='C')||(c!='A'))
        {
          Serial.println("COM ERROR");
        }
        break;
    }
    readString="";
  }
  
  
}
void Clock_wise()
{
  
  STEPS_PER_REV=100;
  digitalWrite(dirPin,HIGH); 
  Serial.println("Anti-clockwise");
  Serial.println("TRACK-1 DISP");
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2000); 
  }
  digitalWrite(dirPin,LOW);
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2000); 
  }
}
void Anti_clock()
{
  STEPS_PER_REV=100;
  digitalWrite(dirPin,LOW); 
  Serial.println("Clockwise");
  Serial.println("TRACK-2 DISP");
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2000); 
  }
  digitalWrite(dirPin,HIGH);
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2000); 
  }
  
}
