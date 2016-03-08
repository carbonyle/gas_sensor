#include <CS_MQ7.h>
#include <LiquidCrystal.h>

CS_MQ7 MQ7(10, 13);  

int CoSensorOutput = A0; 
int CoData = 0;         
int MQ135 = A1;
int MQ135val = 0;
int MQ4 = A2;
int MQ4val = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
Serial.begin(9600);

lcd.begin(16, 2);

pinMode(MQ135, INPUT);
pinMode(MQ4, INPUT);
//pinMode(MQ7, INPUT);
}

void loop() {
  
 MQ135val = analogRead(MQ135);
 Serial.print("MQ135:");
 Serial.println(MQ135val);
 lcd.setCursor(9, 0);
 lcd.print("MQ135");
 lcd.setCursor(9, 1);
 lcd.print(MQ135val);
 delay(1000);
 
 MQ4val = analogRead(MQ4);
 Serial.print("MQ4:");
 Serial.println(MQ4val);
 lcd.setCursor(0, 1);
 lcd.print("MQ4");
 lcd.setCursor(4, 1);
 lcd.print(MQ4val);
 delay(1000);
 
 MQ7.CoPwrCycler(); 
 
 if(MQ7.CurrentState() == LOW){   //we are at 1.4v, read sensor data!
    CoData = analogRead(CoSensorOutput);
    Serial.print("MQ7:");
    Serial.println(CoData);
    lcd.setCursor(0, 0);
    lcd.print("MQ7");
    lcd.setCursor(4, 0);
    lcd.print(CoData);
    delay(1000);
 }
 else{                            //sensor is at 5v, heating time
    Serial.println("MQ7: heating!");
    lcd.setCursor(0, 0);
    lcd.print("MQ7");
    lcd.setCursor(4, 0);
    lcd.print("wait");
    delay(1000);
 }      
}
