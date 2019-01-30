LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

char data;
char modedata;
int pir=8;
int relay=9;
int value=A0;
int temp=0;
float volts=0.0;

void setup() {
pinMode(relay,OUTPUT);
pinMode(pir,INPUT);
lcd.begin(16,2);
Serial.begin(9600);
}

void loop() {
 lcd.setCursor(0,0);
 lcd.print("Bluetooth Mode");
 value=analogRead(A0); //read from A0
volts=(value/1024.0)*5.0;      //conversion to volts
temp=volts*100.0;             //conversion to temp Celsius
  

//display temp no lcd
  lcd.setCursor(0,1);
  lcd.print("TEMP= ");
  lcd.print(temp);
  lcd.print(" C");
modedata = Serial.read(); //Read byte of data
//Turn Relay on
if (modedata == '1')
{
digitalWrite(relay,LOW);
Serial.println("Lamp ON");
}
//Turn Lamp off
else if (modedata == '0')
{
digitalWrite(relay, HIGH);
Serial.println("Lamp OFF");
}
else if (modedata == '5')
{lcd.clear();
  lcd.print("Motion Detection Mode");
  value=analogRead(A0);          //read from A0
  volts=(value/1024.0)*5.0;      //conversion to volts
  temp= volts*100.0;             //conversion to temp Celsius
  

//display temp no lcd
  lcd.setCursor(0,1);
  lcd.print("TEMP= ");
  lcd.print(temp);
  lcd.print(" C");
  while(modedata == '5')
  { int sensorValue = digitalRead(pir);
  
  if (sensorValue == 0)
  {
    digitalWrite(relay,HIGH);
    digitalWrite(3,LOW)
  }
else   if (sensorValue == 1) {
    
    digitalWrite(relay, LOW); // The Relay Input works Inversely
    digitalWrite (3,HIGH);
    delay(500);
}
if(Serial.available()>0)
{
   Serial.println("exited");
   lcd.clear();
  break;
 }
}
}
}
