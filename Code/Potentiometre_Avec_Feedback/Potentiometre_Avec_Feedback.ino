int PMW = 5;
int v_in = 10;
//int v_out_max = 4;
int duty_cycle=128;
float dv=0.1;
float p=0.1;

void setup()
{
  Serial.begin(9600);
  pinMode(PMW, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1,INPUT);
  analogWrite(PMW,duty_cycle);
  delay(100);
}

void loop()
{
  float v_out_max = (5.0/1023)*analogRead(A1);
  int v_out = analogRead(A0);
  float v_out_map = (5.0/1023)*v_out;
  float error = v_out_map - v_out_max;
  if(abs(error)>dv){
  	duty_cycle = int(duty_cycle - p*error*255/v_in);
    analogWrite(PMW,duty_cycle);
  }
  Serial.println(v_out_max);
  delay(100);
}