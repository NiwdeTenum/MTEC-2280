#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
boolean DM1 = true;
boolean DM2 = true;
boolean DM3 = true;
int state = 0;

const int toggleSwitch =  2;

int toggleState = 0;

boolean pressing = false;

const int toggleSwitch1 =  7;

int toggleState1 = 0;

int val = 0;

boolean pressing1 = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(toggleSwitch, OUTPUT);
  pinMode(toggleSwitch1, OUTPUT);
  lcd.begin (16, 2);
  Serial.begin(9600);
  lcd.print("Train Escape!");
  delay(3000);
  lcd.clear();

}

void loop() {
Serial.println(state);
  
  toggleState = digitalRead(toggleSwitch);


  if (toggleState == HIGH) {
    pressing = true;
  }

  if (toggleState == LOW && pressing == true) {
    pressing = false;
    val = 1;
    //lcd.print(val);
    // Your action goes here
  }

  toggleState1 = digitalRead(toggleSwitch1);

  if (toggleState1 == HIGH) {
    pressing1 = true;
  }

  if (toggleState1 == LOW && pressing1 == true) {
    pressing1 = false;
    val = 2;
    //lcd.print(val);

    // Your action goes here
  }


  if (state == 0) {
    if (DM1 == true) {
      lcd.setCursor(0, 0);
      lcd.print("You are in the");
      lcd.setCursor(0, 1);
      lcd.print("train and the");
      delay(3000);
      lcd.clear();
    lcd.setCursor(0, 0);
      lcd.print("power goes out.");
      lcd.setCursor(0, 1);
      lcd.print("Press 1 to go to");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("the intercom or");
      lcd.setCursor(0, 1);
      lcd.print("2 to sit down");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("and cry.");
      DM1 = false;
    }

    if (val == 1) {
      lcd.setCursor(0, 0);
      lcd.print("You are at the ");
      lcd.setCursor(0, 1);
      lcd.print("intercom and");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("talk to the ");
      lcd.setCursor(0, 1);
      lcd.print("conductor");
      delay(3000);
      lcd.clear();
      val = 0;
      state = 1;

    }
    if (val == 2) {
      lcd.setCursor(0, 0);
      lcd.print("You lose!");
      delay(3000);
      lcd.clear();
      val = 0;
      state = 0;
      DM1 = true;
    }
  }
  //
  if (state == 1) {
    if (DM2 == true) {
      lcd.setCursor(0, 0);
      lcd.print("Conductor says ");
      lcd.setCursor(0, 1);
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("go to the ");
      lcd.setCursor(0, 1);
      lcd.print("emergency window");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("and open it.");
      lcd.setCursor(0, 1);
      lcd.print("1 dont listen");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("2 go to window");
      DM2 = false;
    }

    if (val == 1) {
      lcd.setCursor(0, 0);
      lcd.print("You trip and die");
      val = 0;
      state = 0;
      DM2 = true;
    }
    if (val == 2) {
      lcd.setCursor(0, 0);
      lcd.print("You climb out");
      lcd.setCursor(0, 1);
      lcd.print("the window and");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("find an");
      lcd.setCursor(0, 1);
      lcd.print("emergency exit.");
      delay(3000);
      lcd.clear();
      val = 0;
      state = 2;
    }
  }
  if (state == 2) {
    if (DM3 == true) {
      lcd.setCursor(0, 0);
      lcd.print("Emergency Exit ");
      lcd.setCursor(0, 1);
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Is right here ");
      lcd.setCursor(0, 1);
      lcd.print("But other people");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("are still stuck.");
      lcd.setCursor(0, 1);
      lcd.print("1 Help them");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("2 Screw them");
      DM3 = false;
    }

    if (val == 1) {
      lcd.setCursor(0, 0);
      lcd.print("You are a hero");
      lcd.setCursor(0, 1);
      lcd.print("Good End");
      val = 0;
      state = 0;
      DM3 = true;
    }
    if (val == 2) {
      lcd.setCursor(0, 0);
      lcd.print("You Evil");
      lcd.setCursor(0, 1);
      lcd.print("Basterd");
      delay(3000);
      lcd.clear();
      
      lcd.setCursor(0, 0);
      lcd.print("They all died");
      lcd.setCursor(0, 1);
      lcd.print("great job gettin.");
      delay(3000);
      lcd.clear();
      
      lcd.setCursor(0, 0);
      lcd.print("The BAD End!");
      val = 0;
      state = 0;
      DM3 = true;
    }
  }


}
