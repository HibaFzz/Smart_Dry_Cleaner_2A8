Khouloud BOUSSAHA21:52
#include <LiquidCrystal_I2C.h> 
//#include <LiquidCrystal.h>
// En cas de non fonctionnement, mettez la ligne 8 en
// commentaire et retirez le commentaire à la ligne 9.
LiquidCrystal_I2C lcd(0x27, 20, 4); // ligne 8
//LiquidCrystal_I2C lcd(0x3F,20,4); // ligne 9
char data;

void setup()
{
  Serial.begin(9600);
lcd.init(); // initialisation de l'afficheur47
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("hello");
delay(2000);



lcd.clear();
}
void loop()
{

//lcd.setCursor(0, 0); // se position
