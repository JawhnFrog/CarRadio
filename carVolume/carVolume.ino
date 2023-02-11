//editted to have LEFT and RIGHT pinmode as normal instead up PULLUP

#define LEFT 4
#define RIGHT 5
// #define PUSH 10

#define mosfetUp 6
#define mosfetDn 8

const int mosfetOn = 50;

uint8_t lrmem = 3;
int lrsum = 0;
int num = 0;

int8_t rotary()
{
   static int8_t TRANS[] = {0,-1,1,14,1,0,14,-1,-1,14,0,1,14,1,-1,0};
   int8_t l, r;

   l = digitalRead(LEFT);
   r = digitalRead(RIGHT);

   lrmem = ((lrmem & 0x03) << 2) + 2*l + r;
   lrsum = lrsum + TRANS[lrmem];
   /* encoder not in the neutral state */
   if(lrsum % 2 != 0) return(0);
   /* encoder in the neutral state */
   if (lrsum == 2)
      {
      lrsum=0;
      return(1);
      }
   if (lrsum == -2)
      {
      lrsum=0;
      return(-1);
      }
   /* lrsum > 0 if the impossible transition */
   lrsum=0;
   return(0);
}

void VolumeUp(int onTime) {
  Serial.println("Volume Up");

  digitalWrite(mosfetUp, HIGH);
  delay(onTime);
  digitalWrite(mosfetUp, LOW);
}

void VolumeDn(int onTime) {
  Serial.println("Volume Down");
  
  digitalWrite(mosfetDn, HIGH);
  delay(onTime);
  digitalWrite(mosfetDn, LOW);
}

void setup()
{
   pinMode(LEFT, INPUT);
   pinMode(RIGHT, INPUT);
  //  pinMode(PUSH, INPUT);
  //  pinMode(LEFT, INPUT_PULLUP);
  //  pinMode(RIGHT, INPUT_PULLUP);
  //  pinMode(PUSH, INPUT_PULLUP);`

   pinMode(mosfetUp, OUTPUT);
   pinMode(mosfetDn, OUTPUT);

  // initialize mosfet drivers to low 
   digitalWrite(mosfetUp, LOW);
   digitalWrite(mosfetDn, LOW);

   Serial.begin(9600);
   Serial.println(num, DEC);
}

void loop()
{
   int8_t res;
   
   res = rotary();
   if (res!=0)
   {
      num = num + res;
      Serial.println(num);
   }
   if (res==1){
     VolumeUp(mosfetOn);
   }
   if (res==-1){
     VolumeDn(mosfetOn);
   }

  //  if (digitalRead(PUSH) == 0)
  //  {
  //     Serial.println(num);
  //     delay(250);
  //  }
}