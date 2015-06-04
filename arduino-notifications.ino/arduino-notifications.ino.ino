/*

  CSR Development, Co.
  George Craig

  www.csrdevco.com/

  Used Blink as a template for my message notification - Blink Sketch
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald

  added © 2015 GRobotronics Learning
  by Riley Porter - driving Seven Segment Display

  modified 4 June 2015
  by George Craig

 */

#include <stdio.h>

#define A 8
#define B 9
#define C 2
#define D 3
#define E 4
#define f 5
#define G 6

bool diags = true;

//
// the way you have your seven segment display wired
// to the outputs of the uProcessor has a direct
// function on its output
// the image at:
// http://learning.grobotronics.com/2014/09/arduino-lesson-4-drive-7-segment-display/#top3
// shows you which segments should be +Vcc and which ones
// should be grounded
// my wiring and subsequent tracing seriously needs to be corrected, but its 2:38am,
// no sleep in 3 days, and I have neurosarcoidosis
//


void one()
{
  //Displays 1 - done
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(f, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);

}

void two()
{
  //Displays 2 - done
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
}

void three()
{
  //Displays three - done
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void four()
{
  //Displays 4 - done
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void five()
{
  //Displays 5 - done
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
}

void six()
{
  //Displays 6 - done
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
}

void seven()
{
  //Displays 7
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(f, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void eight()
{
  //Displays 8 - done
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void nine()
{
  //Displays 9 - done
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void zero()
{
  //Displays 0 - done
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

// the setup function runs once when you press reset or power the board

void setup() {

  // initialize digital pin 13 as an output.

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);


  // diagnostics
  if (diags == true) {
    blink(13, 300);
    blink(12, 300);
    blink(11, 300);
    blink(10, 300);
    //blink(9, 300);
    //blink(9, 300);
    blink(10, 300);
    blink(11, 300);
    blink(12, 300);
    blink(13, 300);

    zero();
    delay(700);
    one();
    delay(700);
    two();
    delay(700);
    three();
    delay(700);
    four();
    delay(700);
    five();
    delay(700);
    six();
    delay(700);
    seven();
    delay(700);
    eight();
    delay(700);
    nine();
    delay(700);

  }

  zero();
}

void blink(int pin, int time) {

  digitalWrite(pin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(time);              // wait for a second
  digitalWrite(pin, LOW);   // turn the LED off by making the voltage LOW
  delay(time);              // wait for a second

}

// the loop function runs over and over again forever

int messages = 0;

void loop() {

  //digitalWrite(10, HIGH);

  if (HIGH == digitalRead(7)) {
    messages = messages + 1;
  }

  switch (messages) {

    case 1: one();
      blink(10, 300);
      break;
    case     2: two();
      blink(11, 300);
      break;
    case 3: three();
      blink(12, 300);
      break;
    case     4: four();
      blink(13, 300);
      break;
    case     5: five();
      blink(10, 300);
      break;
    case     6: six();
      blink(11, 300);
      break;
    case     7: seven();
      blink(12, 300);
      break;
    case     8: eight();
      blink(10, 300);
      break;
    case     9: nine();
      blink(11, 300);
      break;
    case     0: zero();
      break;
  }
}
