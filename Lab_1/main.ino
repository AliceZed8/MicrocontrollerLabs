bool blink = false;
int buttonState = 0;
int lastButtonState = 0;

void setup()
{
  pinMode(2, INPUT);
  
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(2);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
   		blink = !blink;
    }
    delay(5);
  }
  
  lastButtonState = buttonState;
  
  if (blink) {
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
    delay(300); 
    
    
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
    delay(300);
    
  } else {
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
  }
}
