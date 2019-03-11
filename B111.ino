int led[] = {3, 5, 6, 9, 10, 11};
int b = 0;
int j = 0;

void setup()
{
}
void loop()
{
  for (b = 0; b <= 255; b++) {
    analogWrite(led[j], b);
    delayMicroseconds(5000);
  }

  for (b = 255; b >= 0; b--) {
    analogWrite(led[j], b);
    delayMicroseconds(5000);
  }

  j++;
  if (j == 6) {
    j = 0;
  }
}
