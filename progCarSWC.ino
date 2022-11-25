// Sketch to keep mosfets on to program SWC on android car stereo

// mosfet pins
#define mosfetUp 11
#define mosfetDn 12

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(mosfetUp, OUTPUT);
  pinMode(mosfetDn, OUTPUT);

  // initialize mosfet drivers to low 
  digitalWrite(mosfetUp, LOW);
  digitalWrite(mosfetDn, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("");
  Serial.println("Choose one of the following:");
  Serial.println("1. Volume Up");
  Serial.println("2. Volume Down");
  Serial.println("");

  while (Serial.available() == 0){}

  int menuChoice = Serial.parseInt();

  switch (menuChoice){
    case 1:
      // program volume up
      Serial.println("Volume Up will be enabled for 5 seconds.");

      digitalWrite(mosfetUp, HIGH);
      Serial.println("Press 'Volume Up' on android stereo.");
      delay(5000);
      digitalWrite(mosfetUp, LOW);
      
      Serial.println("Volume Up has been disabled.");
      Serial.println("");
      break;
    case 2:
      // program volume down
      Serial.println("Volume Down will be enabled for 5 seconds.");
      
      digitalWrite(mosfetDn, HIGH);
      Serial.println("Press 'Volume Down' on android stereo.");
      delay(5000);
      digitalWrite(mosfetDn, LOW);

      Serial.println("Volume Down has been disabled.");
      Serial.println("");
      break;

    default:
      Serial.println("Choose a valid selection. 1 for volume up, 2 for volume down");
      Serial.println("");
  }
}
