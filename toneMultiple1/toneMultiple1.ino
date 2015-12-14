String inputString = "";         
boolean stringComplete = false;  
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  pinMode(6, OUTPUT);

}

void loop() {
  serialEvent(); //call the function
  // print the string when a newline arrives:
  if (stringComplete) {
    inputString.trim();
    Serial.println(inputString);
    //toneNumber = inputString.toInt();

      if (inputString.equals("win")) {
    tone(6, 831, 1000);
      
  }else if(inputString.equals("start")){
    //play 3 tones
      noTone(11);
    // Note A4 = 440    ` 
    tone(6, 440, 1000);
    delay(1000);
    noTone(6);
    // Note B4 = 494:
    tone(6, 494, 1000);
    delay(1000);
    noTone(7);  
    // Note C5 = 523:
    tone(6, 523, 1000);
    delay(1000);
  } 
  else if(inputString.equals("lose")){
    tone(6, 73, 1000);   
  }
    inputString = "";
    stringComplete = false;
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
      //Serial.println(inputString);

    }
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
      //Serial.println(inputString);
    }
  }
}




