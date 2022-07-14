#include <LiquidCrystal_I2C.h>

int totalColumns = 16;
int totalRows = 2;

LiquidCrystal_I2C lcd(0x27, totalColumns, totalRows);  

String staticMessage = "Grp16 BE Project";
String scrollingMessage = "ADVANCE STRUCTURE OF CHARGING PORTS IN RAILWAYS";

void scrollMessage(int row, String message, int delayTime, int totalColumns) {
  for (int i=0; i < totalColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int position = 0; position < message.length(); position++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(position, position + totalColumns));
    delay(delayTime);
  }
}

void setup(){
  lcd.init();                    
  lcd.backlight();
}

void loop(){

  for (int i = 30; i>= 0; i--){
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(i);
    lcd.setCursor(3, 1);
    lcd.print("sec");
  }
}
