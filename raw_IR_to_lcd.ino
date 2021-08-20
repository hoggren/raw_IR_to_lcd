#include <IRLremote.h>
#include <LiquidCrystal_I2C.h>

#define IR_PIN 27

CHashIR IRLremote;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  
  if (!IRLremote.begin(IR_PIN))
    Serial.println(F("Check the IR_PIN"));

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  if (IRLremote.available())
  {
    auto data = IRLremote.read();

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ADR: 0x" + String(data.address, HEX));
    
    lcd.setCursor(0,1);
    lcd.print("CMD: 0x" + String(data.command, HEX));
  }
}
