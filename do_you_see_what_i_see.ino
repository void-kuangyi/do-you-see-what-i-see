const int pinOFswitch = 3;
const int LED = 9;
int ValueOFswitch = 0;
int brightness = 0;
int fadeAmount = 5; 

void setup( ) {
  Serial.begin(9600);
  pinMode(pinOFswitch, INPUT);
  pinMode(LED, OUTPUT);
}
void loop( )
{
  ValueOFswitch = digitalRead(pinOFswitch);
  Serial.println(ValueOFswitch);

  if (ValueOFswitch == 1)
  {
    analogWrite(LED, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    
    delay(20);
  }

  else
  {
    analogWrite(LED, 0);
    delay(500);
  }
}
