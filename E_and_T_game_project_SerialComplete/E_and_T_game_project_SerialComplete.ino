#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
boolean DM0 = true;
boolean DM1 = true;
boolean DM2 = true;
boolean DM3 = true;
int state = 0;
const int toggleSwitch = 2;
int toggleState = 0;
boolean pressing = false;
const int toggleSwitch1 = 7;
int toggleState1 = 0;
int val = 0;
boolean pressing1 = false;
boolean stringComplete = false;
String inputString;
void setup() {
Serial.begin(9600);
state = 0;
}
void loop() {
if (state == 0) {
if (DM0 == true) {
Serial.println("You are in the train and the power goes off. Type either 'go to the intercom'");
Serial.println("or 'sit down and cry'");
DM0 = false;
}
if (stringComplete == true) {
stringComplete = false;
if (inputString.equals("go to the intercom")) {
Serial.println("You are at the intercom");
state = 1;
DM1 = true;
}
if (inputString.equals("sit down and cry")) {
Serial.println("You lose");
state = 0;
DM0 = true;
}
inputString = "";
}
}
if (state == 1) {
if (DM1 == true) {
Serial.println("You are at the intercom and the conductor wants you to open the emergency exit. Type either 'daydream' or 'open the emergency exit'");
DM1 = false;
}
if (stringComplete == true) {
stringComplete = false;
if (inputString.equals("daydream")) {
Serial.println("You lose");
state = 0;
DM0 = true;
}
if (inputString.equals("open the emergency exit")) {
Serial.println("You are out of the train");
state = 3;
DM2 = true;
}
inputString = "";
}
}

if (state == 3) {
if (DM3 == true) {
Serial.println("Emergency exit is right here but other people are still stuck. Type either 'Help them'");
Serial.println("or 'Screw them'");
DM3 = false;
}
if (stringComplete == true) {
stringComplete = false;
if (inputString.equals("Help them")) {
Serial.println("You are a hero");
state = 0;
DM3 = true;
}
if (inputString.equals("Screw them")) {
Serial.println("You EVIL basterd");
state = 0;
DM3 = true;
}
inputString = "";
}
}
}

void serialEvent() {
while (Serial.available()) {
// get the new byte:
char inChar = (char)Serial.read();
// add it to the inputString:
//inputString += inChar;
if (inChar != '\n') {
inputString += inChar;
}
// if the incoming character is a newline, set a flag
// so the main loop can do something about it:
if (inChar == '\n') {
stringComplete = true;
}
}
}
