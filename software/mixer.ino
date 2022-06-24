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
lcd.print("Was darfs sein?");

byte choice = GetKeypadInput();

switch (choice) {
  case 1:
    RunPump(m1, 7000);
    break;

  case 2:
    RunPump(m2, 7000);
    break;

  case 3:
    RunPump(m1, 3500);
    RunPump(m2, 3500);
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
  int v = 0;
  do {
    v = analogRead(A0);
  } while (v > 512);

  if(v<3){
    //Right button
    return 2;
  }
  else if(v>304 && v<308){
    //Down button
    return 3;
  }
  else if(v>478 && v<482){
    //Left button
    return 1;
  }
}

void RunPump (byte pin, float runtime) {
  LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
  
  digitalWrite(pin, HIGH);
  for(float i = 0; i <= runtime / 100; i++) {
    int progress = ((i/(runtime / 100))*100);
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(progress);
  }
  digitalWrite(pin, LOW);
}
