#include <LiquidCrystal.h>

//definitions
const int m1 = 2;
const int m2 = 3;

//Initialisation
void setup() {
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("Booting...");
lcd.setCursor(0,1);

pinMode(m1, OUTPUT);
pinMode(m2, OUTPUT);
digitalWrite(m1, LOW);
digitalWrite(m2, LOW);

delay(1000);
}

//Main loop
void loop() {
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Was darfs sein?");
lcd.setCursor(1,0);
lcd.print("<D1 VMix D2>");

byte choice = GetKeypadInput();

switch (choice) {
  case 1:
    RunPump(m1, 8000);
    break;

  case 2:
    RunPump(m2, 8000);
    break;

  case 3:
    RunPump(m1, 4000);
    RunPump(m2, 4000);
    break;

  default:
    break;
}

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Prost :)");
delay(3000);
}

//Functions
byte GetKeypadInput() {
  do {
    int v = analogRead(A0);
  } while (v < 20);

  while (true) {
    if(v>20 && v<60){
      //Right button
      return 2;
    }
    else if(v>200 && v<400){
      //Down button
      return 3;
    }
    else if(v>400 && v<6000){
      //Left button
      return 1;
    }
  }
}

void RunPump (byte pin, int runtime) {
  LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
  
  digitalWrite(pin, HIGH);
  for(int i = runtime / 100; i != 0; i--) {
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(i + " / " + runtime / 100);
  }
  digitalWrite(pin, LOW);
}
