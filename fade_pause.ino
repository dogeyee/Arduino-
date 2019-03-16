const int buttonPin = 2;
const int ledPin =  13;
boolean push = true;

int led[] = {3, 5, 6, 9, 10, 11};
int b = 0;
int j = 0;

int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  for (b = 0; b <= 255;) {
    analogWrite(led[j], b);
    delayMicroseconds(5000);
    if ( ! sw()) {
      b++;
    }
  }

  for (b = 255; b >= 0;) {
    analogWrite(led[j], b);
    delayMicroseconds(5000);
    if ( ! sw()) {
      b--;
    }
  }

  j++;
  if (j == 6) {
    j = 0;
  }
}

boolean sw() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    push = true;
  } else {
    digitalWrite(ledPin, LOW);
    push = false;
  }
  return push;
}

