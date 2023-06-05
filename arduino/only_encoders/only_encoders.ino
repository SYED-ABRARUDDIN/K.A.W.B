
const int el1=18,el2=19;
const int er1=3,er2=23;


volatile long pulse_output_ra_f = 0;
volatile long pulse_output_la_f = 0;
void right_motor_forward();
void left_motor_forward();


void right_motor_forward()
{
  if (digitalRead(er1) == digitalRead(er2))
  {
    pulse_output_ra_f--;
  }
  else {
    pulse_output_ra_f++;
  }
}
void left_motor_forward()
{
  if (digitalRead(el1) == digitalRead(el2))
  {
    pulse_output_la_f--;

  }
  else {
    pulse_output_la_f++;  
  }
}


//__________________________


void setup() {
  
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(er1, INPUT_PULLUP);
  pinMode(er2, INPUT_PULLUP);
  pinMode(el1, INPUT_PULLUP);
  pinMode(el2, INPUT_PULLUP);
  //digitalWrite(23,HIGH);
  //digitalWrite(3,HIGH);
  //digitalWrite(19,HIGH);
  //digitalWrite(18,HIGH);
 
  attachInterrupt(digitalPinToInterrupt(er1), right_motor_forward, RISING);
  attachInterrupt(digitalPinToInterrupt(el1), left_motor_forward, RISING);
  //Serial.print("starting...");

}


void loop() {

  Serial.print(" : ");
  Serial.print(pulse_output_la_f);

  Serial.print(" : ");
  Serial.print(pulse_output_ra_f);
  Serial.println(" : ");

  Serial2.print(" : ");
  Serial2.print(pulse_output_la_f);

  Serial2.print(" : ");
  Serial2.print(pulse_output_ra_f);
  Serial2.println("  ");
 

  delay(30);
 
}
