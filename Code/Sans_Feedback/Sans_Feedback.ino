
int PWM = 5;
int v_in = 10;
int v_out;


void setup()
{
  Serial.begin(9600);
  pinMode(PWM, OUTPUT);
  pinMode(A0, INPUT);
  analogWrite(PWM,127);
}

void loop()
{
  Serial.println(analogRead(A0));
  delay(100);
}
