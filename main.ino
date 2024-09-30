#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolousion = 200;
Stepper arm(stepsPerRevolousion, 10, 11, 12, 13);
Servo pickOne;
Servo pickTwo;
Servo pickThree;
int pos = 100;
int offset = 0;
int pickpose1 = 0;
int pickpose2 = 0;
int pickpose3 = 0;
int PICK_PLACE11 = 100;
// int PICK_PLACE12 = 140;
int PICK_PLACE12 = 60;
int PICK_PLACE21 =100;
// int PICK_PLACE22 =130;
int PICK_PLACE22 = 60;
int PICK_PLACE31 = 100;
int PICK_PLACE32 = 60;
// int PICK_PLACE32 = 15;
int armSpeed = 60;
void setup(){
  for(int i = 2; i<=9; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(115200);
  Serial.setTimeout(10);
  arm.setSpeed(8000);
  pickOne.attach(50);
  pickTwo.attach(51);
  pickThree.attach(52);
  pickOne.write(PICK_PLACE11);
  pickTwo.write(PICK_PLACE21);
  pickThree.write(PICK_PLACE31);
  delay(1000);
}

void loop(){
  if(Serial.available() > 0){
    String s = Serial.readString();
    s.trim();
    //Serial.println(s);
    String sarmp = s.substring(0,3);
    if(sarmp == "vlv"){
      for(int i = 1; i <= 9; i++){
        digitalWrite(i, LOW);
      }
    }
    if(sarmp == "sts"){
      Serial.print("speed - stepper posistion - servo positions ");
      Serial.print(armSpeed);
      Serial.print(' ');
      Serial.print(pos);
      Serial.print(' ');
      Serial.print(PICK_PLACE11);
      Serial.print(' ');
      Serial.print(PICK_PLACE12);
      Serial.print(' ');
      Serial.print(PICK_PLACE21);
      Serial.print(' ');
      Serial.print(PICK_PLACE22);
      Serial.print(' ');
      Serial.print(PICK_PLACE31);
      Serial.print(' ');
      Serial.print(PICK_PLACE32);
      Serial.print(' ');
    }
    if(sarmp == "set"){
      String att = s.substring(3, 6);
      if(att == "spd"){
        String spd = s.substring(6, 8);
        armSpeed = spd.toInt();
        arm.setSpeed((armSpeed / 3) * 200);
        arm.step(-2000);
        delay(50);
        arm.step(2000);
      }
      else if(att == "ofs"){
        String ofs = s.substring(6, 10);
        int offset = ofs.toInt();
        arm.setSpeed(abs((armSpeed / 3) * offset));
        arm.step(-10 * offset);
      }
      else if(att[0] == "p"){
        int newPickPose = s.substring(6,9).toInt();
        if(att == "p11"){
          PICK_PLACE11 = newPickPose;
          pickOne.write(PICK_PLACE11);
        }
        else if(att == "p12"){
          PICK_PLACE12 = newPickPose;
          pickOne.write(PICK_PLACE12);
        }
        else if(att == "p21"){
          PICK_PLACE31 = newPickPose;
          pickThree.write(PICK_PLACE31);
        }
        else if(att == "p22"){
          PICK_PLACE32 = newPickPose;
          pickThree.write(PICK_PLACE32);
        }
        else if(att == "p31"){
          PICK_PLACE21 = newPickPose;
          pickTwo.write(PICK_PLACE21);
        }
        else if(att == "p32"){
          PICK_PLACE22 = newPickPose;
          pickTwo.write(PICK_PLACE22);
        }
      }
    }
    String sangoosht = s.substring(4,5);
    String angooshtflag = s.substring(6,7);
    String picknum = s.substring(8, 9);
    int armp = sarmp.toInt();
    int angoosht = sangoosht.toInt();
    if(picknum == "4"){
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
          if(pickpose1 == 0){
            //pickOne.write(PICK_PLACE12 + 10);
            //delay(50);F
            pickOne.write(PICK_PLACE12);
            pickpose1 = 1;
          } else{
            //pickOne.write(PICK_PLACE11-  10);
            //delay(50);
            pickOne.write(PICK_PLACE11);
            pickpose1 = 0;
          }
    }
    else if(picknum == "5"){
      digitalWrite(4, LOW);
      digitalWrite(2, LOW);
      digitalWrite(8, LOW);
          if(pickpose2 == 0){
            //pickTwo.write(PICK_PLACE22 + 10);
            //delay(50);
            pickTwo.write(PICK_PLACE22 );
            pickpose2 = 1;
          } else{
            //pickTwo.write(PICK_PLACE21 - 10);
            //delay(50);
            pickTwo.write(PICK_PLACE21);
            pickpose2 = 0;
          }
    }
    else if(picknum == "6"){
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(9, LOW);
        if(pickpose3 == 0){
            //pickThree.write(PICK_PLACE32 - 10);
            //delay(50);
            pickThree.write(PICK_PLACE32);
            pickpose3 = 1;
          } else{
            //pickThree.write(PICK_PLACE31 + 10);
            //delay(50);
            pickThree.write(PICK_PLACE31 );
            pickpose3 = 0;
          }
    }
    else{
    //Serial.println(armp);
    //Serial.println(angoosht);
    //Serial.println(angooshtflag);
    //Serial.println(picknum);
    if(armp >= 100 && armp<850){
      if (armp != pos){
        for(int i = 1; i <= 9; i++){
        digitalWrite(i, LOW);
        }
        //delay(25);
      }
      arm.setSpeed((armSpeed / 3) * abs(armp - pos));
      arm.step((armp-pos) * -10);
      //delay(100);
      pos = armp;
    }
    if(angoosht >=1 && angoosht <=9){
      //Serial.println(angoosht);
      //if(angooshtflag == "0"){
      //  digitalWrite(angoosht, LOW);
      //}
        if(angoosht == 7){
          digitalWrite(6, LOW);
        }
        else if(angoosht == 4){
          digitalWrite(2, LOW);
        }
        else if(angoosht == 8){
          digitalWrite(2, LOW);
          digitalWrite(4, LOW);
        }
        else if(angoosht == 5){
          digitalWrite(9, LOW);
        }
        else if(angoosht == 3){
          digitalWrite(5, LOW);
          digitalWrite(9, LOW);
        }
        digitalWrite(angoosht, HIGH);
      }
        if(picknum == "1"){
         //Serial.println("pick1");
          if(pickpose1 == 0){
            //pickOne.write(PICK_PLACE12 + 10);
            //delay(50);
            pickOne.write(PICK_PLACE12);
            pickpose1 = 1;
          } else{
            //pickOne.write(PICK_PLACE11 - 10);
            //delay(50);
            pickOne.write(PICK_PLACE11);
            pickpose1 = 0;
          }
        }
        else if(picknum == "2"){
          //Serial.println("pick2");
          if(pickpose2 == 0){
            //pickTwo.write(PICK_PLACE22 + 10);
            //delay(50);
            pickTwo.write(PICK_PLACE22 );
            pickpose2 = 1;
          } else{
            //pickTwo.write(PICK_PLACE21 - 10);
            //delay(50);
            pickTwo.write(PICK_PLACE21);
            pickpose2 = 0;
          }
        }
        else if(picknum == "3"){
          //Serial.println("pick3");
          if(pickpose3 == 0){
            //pickThree.write(PICK_PLACE32 - 10);
            //delay(50);
            pickThree.write(PICK_PLACE32);
            pickpose3 = 1;
          } else{
            //pickThree.write(PICK_PLACE31 + 10);
            //delay(50);
            pickThree.write(PICK_PLACE31);
            pickpose3 = 0;
          }
        }
    }

      //}
      //if(angooshtflag == "0"){
      //delay(250);
      //digitalWrite(angoosht, LOW);
      ////delay(50);
      //}
      delay(10);
  }
}