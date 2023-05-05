#include <U8g2lib.h>
#include <SoftWire.h>
#include <LobotServoController.h>
#include <AsyncDelay.h>

#include "SoftWire.h"
#include "U8g2lib.h"
#include "SoftwareSerial.h"
#include "LobotServoController.h"

#define  RxPin 8     //Define soft serial port
#define  TxPin 9

int err = -7;
int posStep = 5;
int runtime = 2000;

SoftwareSerial mySerial(RxPin, TxPin);       //Set an example of SoftwareSerial
LobotServoController myController(mySerial);//Set an example of LobotSerialController 

int sensorPin1 = 2; // 
int sensorPin2 = 4; // 
int sensorPin3 = 7;
int sensorPin4 = 10;
int sensorPin5 = 11;
int sensorPin6 = 12;
int sensorPin7 = 6;
/// // the LED is connected to digital pin 13
int sensor1; // an integer variable to store the potentiometer reading
int sensor2; // an integer variable to store the potentiometer reading
int sensor3; // an integer variable to store the potentiometer reading
int sensor4; // an integer variable to store the potentiometer reading
int sensor5; // an integer variable to store the potentiometer reading
int sensor6; // an integer variable to store the potentiometer reading
int sensor7; // an integer variable to store the potentiometer reading

bool start = false;

int sensor_ref1; // an integer variable to store the potentiometer reading
int sensor_ref2; // an integer variable to store the potentiometer reading
int sensor_ref3; // an integer variable to store the potentiometer reading
int sensor_ref4; // an integer variable to store the potentiometer reading
int sensor_ref5; // an integer variable to store the potentiometer reading
int sensor_ref6; // an integer variable to store the potentiometer reading
int sensor_ref7; // an integer variable to store the potentiometer reading

int incomingData; // 

static unsigned int state = 2; // 1 wait for input, 2 read sensro, 3 wait for command

// homing
void homing(){
  myController.moveServo(2,500,runtime);
  // Servo 3
  myController.moveServo(3,500,runtime);
  // Servo 4
  myController.moveServo(4,500,runtime);
  // Servo 5
  myController.moveServo(5, 500,runtime);
  // Servo 6
  myController.moveServo(6,500,runtime);
  delay(3000);
}

// first column
void p1(){
//  myController.moveServo(1, 500, runtime);
//   myController.moveServo(1, 700, runtime);
  myController.moveServo(2, 500, runtime);
  myController.moveServo(3, 845, runtime);
  myController.moveServo(4, 150, runtime);
  myController.moveServo(5, 780, runtime);
  myController.moveServo(6, 535+err, runtime);
  delay(3000);

  // open gripper
  myController.moveServo(1, 500, 1000);
  delay(1000);
}


// second column
void p2(){
//  myController.moveServo(1, 500, 1000);
  myController.moveServo(2, 500, runtime);
  myController.moveServo(3, 780, runtime);
  myController.moveServo(4, 120, runtime);
  myController.moveServo(5, 745, runtime);
  myController.moveServo(6, 530+err, runtime);
  delay(3000);

  // open gripper
  myController.moveServo(1, 500, 1000);
  delay(1000);
}

// third column
void p3(){
//  myController.moveServo(1, 500, 1000);
  myController.moveServo(2, 500, runtime);
  myController.moveServo(3, 740, runtime);
  myController.moveServo(4, 140, runtime);
  myController.moveServo(5, 685, runtime);
  myController.moveServo(6, 525+err, runtime);
  delay(3000);

  // open gripper
  myController.moveServo(1, 500, 1000);
  delay(1000);
}

// forth column
void p4(){
//  myController.moveServo(1, 500, 1000);
  myController.moveServo(2, 500, runtime);
  myController.moveServo(3, 695, runtime);
  myController.moveServo(4, 155, runtime);
  myController.moveServo(5, 620, runtime);
  myController.moveServo(6, 526+err, runtime);
  delay(3000);

  // open gripper
  myController.moveServo(1, 500, 1000);
  delay(1000);
}

// fifth column
void p5(){
//  myController.moveServo(1, 500, 1000);
  myController.moveServo(2, 500, runtime);
  myController.moveServo(3, 710, runtime);
  myController.moveServo(4, 250, runtime);
  myController.moveServo(5, 530, runtime);
  myController.moveServo(6, 522+err, runtime);
  delay(3000);

  // open gripper
  myController.moveServo(1, 500, 1000);
  delay(1000);
}

// sixth column
void p6(){
//  myController.moveServo(1, 500, 1000);
  myController.moveServo(2, 500, runtime);
  myController.moveServo(3, 710, runtime);
  myController.moveServo(4, 300, runtime);
  myController.moveServo(5, 460, runtime);
  myController.moveServo(6, 525+err, runtime);
  delay(3000);

  // open gripper
  myController.moveServo(1, 500, 1000);
  delay(1000);
}


// seventh column
void p7(){
//  myController.moveServo(1, 500, 1000);
  myController.moveServo(2, 500, runtime);
  myController.moveServo(3, 695, runtime);
  myController.moveServo(4, 392, runtime);
  myController.moveServo(5, 380, runtime);
  myController.moveServo(6, 523+err, runtime);
  delay(3000);

  // open gripper
  myController.moveServo(1, 500, 1000);
  delay(1000);
}

// get chip
void chip(){
  myController.moveServo(1, 500, runtime);
  myController.moveServo(2, 500, runtime);
  myController.moveServo(3, 815, runtime);
  myController.moveServo(4, 140, runtime);
  myController.moveServo(5, 450, runtime);
  myController.moveServo(6, 150+err, 1000);
  delay(3000);

  // close gripper
  myController.moveServo(1, 700, 1000);
  delay(1000);
}

void turn(){
  myController.moveServo(2, 500, runtime);
  myController.moveServo(3, 500, runtime);
  myController.moveServo(4, 500, runtime);
  myController.moveServo(5, 500, runtime);
  myController.moveServo(6, 150+err, 1000);
  delay(3000);
}

void handoff(){
  myController.moveServo(2, 500, runtime);
  myController.moveServo(3, 933, runtime);
  myController.moveServo(4, 251, runtime);
  myController.moveServo(5, 450, runtime);
  myController.moveServo(6, 150+err, 1000);
  delay(3000);

}

void setup() { // this function runs once when the sketch starts up
  //pinMode (ledPin, OUTPUT);
  // initialize serial communication :
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(1000);

  homing();


  delay(3000);
}

void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}

void loop() { // this loop runs repeatedly after setup() finishes
  if(state == 1){
    delay (1000);
    while (Serial.available()==0){}             // wait for user input
    incomingData = Serial.parseInt();  

//    Serial.println(incomingData);
    if(incomingData == 0){
      state = 2;
    }else{
      Serial.println("not start");
    }
    serialFlush();

  }else if(state == 2){
//    if(start == false){
//      sensor_ref1 = digitalRead(sensorPin1); // read the sensor
//      sensor_ref2 = digitalRead(sensorPin2);
//      sensor_ref3 = digitalRead(sensorPin3);
//      sensor_ref4 = digitalRead(sensorPin4);
//      sensor_ref5 = digitalRead(sensorPin5);
//      sensor_ref6 = digitalRead(sensorPin6);
//      sensor_ref7 = digitalRead(sensorPin7);
//      start = true;
//    }

    
    sensor1 = digitalRead(sensorPin1); // read the sensor
    sensor2 = digitalRead(sensorPin2);
    sensor3 = digitalRead(sensorPin3);
    sensor4 = digitalRead(sensorPin4);
    sensor5 = digitalRead(sensorPin5);
    sensor6 = digitalRead(sensorPin6);
    sensor7 = digitalRead(sensorPin7);
//    Serial.println(sensor1); // output reading to the serial line
    serialFlush();
    delay (10); // Pause in milliseconds before next reading
    if(sensor1 == 0){
      state = 3;
//      Serial.println("state_changed");
      Serial.println(1);
    }
    if(sensor2 == 0){
      state = 3;

      Serial.println(2);
    }
    if(sensor3 == 0){
      state = 3;

      Serial.println(3);
    }
    if(sensor4 == 0){
      state = 3;

      Serial.println(4);
    }
    if(sensor5 == 0){
      state = 3;

      Serial.println(5);
    }
    if(sensor6 == 0){
      state = 3;

      Serial.println(6);
    }
    if(sensor7 == 0){
      state = 3;

      Serial.println(7);
    }

// depend on initial state:
//    if(sensor1 != sensor_ref1){
//      state = 3;
////      Serial.println("state_changed");
//      Serial.println(1);
//    }
//    if(sensor2 != sensor_ref2){
//      state = 3;
//
//      Serial.println(2);
//    }
//    if(sensor3 != sensor_ref3){
//      state = 3;
//
//      Serial.println(3);
//    }
//    if(sensor4 != sensor_ref4){
//      state = 3;
//
//      Serial.println(4);
//    }
//    if(sensor5 != sensor_ref5){
//      state = 3;
//
//      Serial.println(5);
//    }
//    if(sensor6 != sensor_ref6){
//      state = 3;
//
//      Serial.println(6);
//    }
//    if(sensor7 != sensor_ref7){
//      state = 3;
//
//      Serial.println(7);
//    }
//    
  }else if(state = 3){
    while (Serial.available()==0){}             // wait for user input
    incomingData = Serial.parseInt();
//    Serial.println(incomingData);
    if(incomingData == 1){
      turn();
      handoff();
      chip();
      handoff();
      homing();
      p1();
      homing();
      Serial.println(1);
    }else if(incomingData == 2){
      turn();
      handoff();
      chip();
      handoff();
      homing();
      p2();
      homing();
      Serial.println(2);
    }else if(incomingData == 3){
      turn();
      handoff();
      chip();
      handoff();
      homing();
      p3();
      homing();
      Serial.println(3);

    }else if(incomingData == 4){
      turn();
      handoff();
      chip();
      handoff();
      homing();
      p4();
      homing();
      Serial.println(4);

    }else if(incomingData == 5){
      turn();
      handoff();
      chip();
      handoff();
      homing();
      
      p5();
      homing();
      Serial.println(5);
      
    }else if(incomingData == 6){
      turn();
      handoff();
      chip();
      handoff();
      homing();
      p6();
      homing();
      Serial.println(6);
    }else if(incomingData == 7){
      turn();
      handoff();
      chip();
      handoff();
      homing();
      p7();
      homing();
      Serial.println(7);
    }else if(incomingData == 8){
      
      chip();
      Serial.println(8);
    }else if(incomingData == 9){
      
      homing();
      Serial.println(9);
    }
    
    serialFlush();
    start = false;
    state = 2;
  }
}
