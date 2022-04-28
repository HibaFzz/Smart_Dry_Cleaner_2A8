#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4 
#define BUZZER 2 //buzzer pin
#define LED_R 5
const int pinRST = 9; // pin RST du module RC522
const int pinSDA = 10; // pin SDA du module RC522
char refus;
MFRC522 rfid(pinSDA, pinRST);
Servo myServo; //define servo name
char data;
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
   myServo.attach(3); //servo pin
  rfid.PCD_Init();   // Initiate MFRC522
 
  
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop()

{

  int refus = 0; // quand cette variable n'est pas nulle, c'est que le code est refusé
  if (rfid.PICC_IsNewCardPresent()) // on a dédecté un tag
  {
    if (rfid.PICC_ReadCardSerial()) // on a lu avec succès son contenu
    {
      //IN
      Serial.println (rfid.uid.uidByte[0]);
    }
  }
  //OUT
  if (Serial.available())
  {
    refus = Serial.read();
    if (refus == '1') // UID accepté
    {
      
    digitalWrite(LED_G, HIGH);
    
    delay(300);
     tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);
    myServo.attach(3); //servo pin
    myServo.write(0);
    delay(1000);
    
    digitalWrite(LED_G, LOW);

      
    }
    else if (refus == '0') { // UID refusé
      // allume LED rouge et active buzzer pendant 3 secondes
      digitalWrite(LED_R, HIGH);
    delay(300);
    tone(BUZZER, 300);
    delay(500);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
    myServo.detach();
    }
  }


}
