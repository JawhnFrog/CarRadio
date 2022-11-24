// Rotary Encoder Stuff

// rotery encoder pins
#define pinA 4
#define pinB 5

// mosfet pins
#define mosfetUp 11
#define mosfetDn 12

const int mosfetOn = 80;

int currState;
int prevState;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);

  pinMode(mosfetUp, OUTPUT);
  pinMode(mosfetDn, OUTPUT);

  // initialize mosfet drivers to low 
  digitalWrite(mosfetUp, LOW);
  digitalWrite(mosfetDn, LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  currState = digitalRead(pinA);

  if (currState != prevState){

    if(digitalRead(pinB) != currState){
      // volume up
      VolumeUp(mosfetOn);

    }else{
      // volume down
      VolumeDn(mosfetOn);
      
    }
  }
  prevState = currState;

}

void VolumeUp(int onTime) {
  Serial.println("Volume Up");

  digitalWrite(mosfetUp, HIGH);
  delay(onTime);
  digitalWrite(mosfetDn, LOW);
}

void VolumeDn(int onTime) {
  Serial.println("Volume Down");
  
  digitalWrite(mosfetDn, HIGH);
  delay(onTime);
  digitalWrite(mosfetDn, LOW);
}
