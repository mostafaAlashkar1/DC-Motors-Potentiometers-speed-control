int switch_R=4;
int switch_L=2;
int motor_R=10;
int motor_L=11;
int pot_R=A5;
int pot_L=A1;
void setup()
{
  pinMode(switch_R,0);
  pinMode(switch_L,0);
  pinMode(motor_R,1);
  pinMode(motor_L,1);
  Serial.begin(9600);
}

void loop()
{
  int open_R=digitalRead(switch_R);
  int open_L=digitalRead(switch_L);
  int readingPot_R=map(analogRead(pot_R),0,1023,0,255);
  int readingPot_L=map(analogRead(pot_L),0,1023,0,255);


  if(open_R==1 && open_L==0){
    analogWrite(motor_R,readingPot_R);
    analogWrite(motor_L,0);
  }
  else if(open_L==1 && open_R==0){
    analogWrite(motor_L,readingPot_L);
    analogWrite(motor_R,0);
  }
  else if(open_R==1 && open_L==1){
    analogWrite(motor_R,readingPot_R);
    analogWrite(motor_L,readingPot_L);
  }
  else if(open_R==0 && open_L==0){
    analogWrite(motor_R,0);
    analogWrite(motor_L,0);
  }

  if (Serial.available()) {
    char reading=Serial.read();
    if(reading=='R'){
      analogWrite(motor_R,readingPot_R);
    }
    else if(reading=='L'){
      analogWrite(motor_L,readingPot_L);
    }
    else if(reading=='S'){
      analogWrite(motor_R,0);
      analogWrite(motor_L,0);
    }  
  } 
}