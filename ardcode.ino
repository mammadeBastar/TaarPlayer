#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolousion = 200;
Stepper arm(stepsPerRevolousion, 10, 11, 12, 13);
Servo pickOne;
Servo pickTwo;
Servo pickThree;
int pos = 100;
int pickpose1 = 0;
int pickpose2 = 0;
int pickpose3 = 0;
int PICK_PLACE11 = 70;
int PICK_PLACE12 = 60;
int PICK_PLACE21 = 75;
int PICK_PLACE22 = 90;
int PICK_PLACE31 = 35;
int PICK_PLACE32 = 25;
void setup(){
  for(int i = 2; i<=9; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(115200);
  Serial.setTimeout(10);
  arm.setSpeed(3600);
  pickOne.attach(50);
  pickTwo.attach(51);
  pickThree.attach(52);
  pickOne.write(PICK_PLACE11);
  pickTwo.write(PICK_PLACE21);
  pickThree.write(PICK_PLACE31);
  delay(300);
}

void loop(){
  if(Serial.available() > 0){
    String s = Serial.readString();
    s.trim();
    //Serial.println(s);
    String sarmp = s.substring(0,3);
    String sangoosht = s.substring(4,5);
    String angooshtflag = s.substring(6,7);
    String picknum = s.substring(8, 9);
    int armp = sarmp.toInt();
    int angoosht = sangoosht.toInt();
    if(picknum == "4"){
      digitalWrite(2, LOW);
      digitalWrite(6, LOW);
          if(pickpose1 == 0){
            pickOne.write(PICK_PLACE12);
            pickpose1 = 1;
          } else{
            pickOne.write(PICK_PLACE11);
            pickpose1 = 0;
          }
    }
    else if(picknum == "5"){
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(8, LOW);
          if(pickpose2 == 0){
            pickTwo.write(PICK_PLACE21);
            pickpose2 = 1;
          } else{
            pickTwo.write(PICK_PLACE22);
            pickpose2 = 0;
          }
    }
    else if(picknum == "6"){
      digitalWrite(3, LOW);
      digitalWrite(7, LOW);
      digitalWrite(9, LOW);
        if(pickpose3 == 0){
            pickThree.write(PICK_PLACE31);
            pickpose3 = 1;
          } else{
            pickThree.write(PICK_PLACE32);
            pickpose3 = 0;
          }
    }
    else{
    if(armp == 999){
      for(int i = 0; i <= 5; i++){
        //digitalWrite(7, HIGH);
        //delay(100);
        //digitalWrite(7, LOW);
        //delay(100);
        //digitalWrite(2, HIGH);
        //delay(100);
        //digitalWrite(2, LOW);
        //delay(100);
        //digitalWrite(7, HIGH);
        //delay(100);
        //digitalWrite(7, LOW);
        //delay(100);
        //digitalWrite(2, HIGH);
        //delay(100);
        //digitalWrite(2, LOW);
        //delay(100);
        //digitalWrite(7, HIGH);
        //delay(100);
        //digitalWrite(7, LOW);
        //delay(100);
        //digitalWrite(2, HIGH);
        //delay(100);
        //digitalWrite(2, LOW);
        //delay(100);
        //digitalWrite(7, HIGH);
        //delay(100);
        //digitalWrite(7, LOW);
        //delay(100);
        //digitalWrite(2, HIGH);
        //delay(100);
        //digitalWrite(2, LOW);
        //arm.step(3*-100);
        //delay(100);
        //digitalWrite(7, HIGH);
        //delay(100);
        //digitalWrite(7, LOW);
        //delay(100);
        //digitalWrite(2, HIGH);
        //delay(100);
        //digitalWrite(2, LOW);
        //delay(100);
        //digitalWrite(7, HIGH);
        //delay(100);
        //digitalWrite(7, LOW);
        //delay(100);
        //digitalWrite(2, HIGH);
        //delay(100);
        //digitalWrite(2, LOW);
        //delay(100);
        //digitalWrite(7, HIGH);
        //delay(100);
        //digitalWrite(7, LOW);
        //delay(100);
        //digitalWrite(2, HIGH);
        //delay(100);
        //digitalWrite(2, LOW);
        //delay(100);
        //digitalWrite(7, HIGH);
        //delay(100);
        //digitalWrite(7, LOW);
        //delay(100);
        //digitalWrite(2, HIGH);
        //delay(100);
        //digitalWrite(2, LOW);
        //arm.step(3*100);
        //delay(100);
        //digitalWrite(5, LOW);
        //delay(100);
        digitalWrite(3, HIGH);
        delay(100);
        //digitalWrite(3, LOW);
        //delay(100);
        digitalWrite(9, HIGH);
        delay(100);
        digitalWrite(9, LOW);
        delay(100);
        //digitalWrite(3, HIGH);
        //delay(100);
        digitalWrite(3, LOW);
        //delay(100);
        arm.step(15*-100);
        delay(100);
        digitalWrite(3, HIGH);
        delay(100);
        digitalWrite(3, LOW);
        delay(100);
        digitalWrite(7, HIGH);
        delay(100);
        digitalWrite(7, LOW);
        delay(100);
        digitalWrite(9, HIGH);
        delay(100);
        digitalWrite(9, LOW);
        delay(100);
        digitalWrite(7, HIGH);
        delay(100);
        digitalWrite(7, LOW);
        delay(100);
        //digitalWrite(5, LOW);
        //delay(100);
        digitalWrite(3, HIGH);
        delay(100);
        digitalWrite(3, LOW);
        delay(100);
        digitalWrite(9, HIGH);
        delay(100);
        digitalWrite(9, LOW);
        delay(100);
        digitalWrite(3, HIGH);
        delay(100);
        digitalWrite(3, LOW);
        //delay(100);
        arm.step(15*100);
        delay(100);
      }
    }
    //Serial.println(armp);
    //Serial.println(angoosht);
    //Serial.println(angooshtflag);
    //Serial.println(picknum);
    if(armp >= 100 && armp<999){
      if (armp != pos){
        for(int i = 1; i <= 9; i++){
        digitalWrite(i, LOW);
        }
      delay(100);
      }
      arm.step((armp-pos) * -10);
      delay(150);
      pos = armp;
    }
    if(angoosht >=2 && angoosht <=9){
      //Serial.println(angoosht);
      //if(angooshtflag == "0"){
      //  digitalWrite(angoosht, LOW);
      //}
        if(angoosht == 2){
          digitalWrite(6, LOW);
        }
        else if(angoosht == 5){
          digitalWrite(8, LOW);
        }
        else if(angoosht == 4){
          digitalWrite(5, LOW);
          digitalWrite(8, LOW);
        }
        else if(angoosht == 7){
          digitalWrite(9, LOW);
        }
        else if(angoosht == 3){
          digitalWrite(7, LOW);
          digitalWrite(9, LOW);
        }
        digitalWrite(angoosht, HIGH);
      }
        if(picknum == "1"){
         //Serial.println("pick1");
          if(pickpose1 == 0){
            pickOne.write(PICK_PLACE12);
            pickpose1 = 1;
          } else{
            pickOne.write(PICK_PLACE11);
            pickpose1 = 0;
          }
        }
        else if(picknum == "2"){
          //Serial.println("pick2");
          if(pickpose2 == 0){
            pickTwo.write(PICK_PLACE22);
            pickpose2 = 1;
          } else{
            pickTwo.write(PICK_PLACE21);
            pickpose2 = 0;
          }
        }
        else if(picknum == "3"){
          //Serial.println("pick3");
          if(pickpose3 == 0){
            pickThree.write(PICK_PLACE32);
            pickpose3 = 1;
          } else{
            pickThree.write(PICK_PLACE31);
            pickpose3 = 0;
          }
        }
    }

      //}
      //if(angooshtflag == "0"){
      //delay(250);
      //digitalWrite(angoosht, LOW);
      //delay(50);
      //}
      //delay(200);
  }
}