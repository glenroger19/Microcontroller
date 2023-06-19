int PMW = 5;
int v_in = 10;
int v_out_max = 4;
int v_out;
int rc=128;
float dv=0.1;
float error;
float p=0.1;

void setup()
{
  Serial.begin(9600);
  pinMode(PMW, OUTPUT);
  pinMode(A0, INPUT);
  analogWrite(PMW,rc);
  delay(100);
}

void loop()
{
  v_out = analogRead(A0);
  float v_out_map = (5.0/1023)*v_out;
  error = v_out_map - v_out_max;
  if(abs(error)>dv){
  	rc = int(rc - p*error*255/v_in);
    analogWrite(PMW,rc);
  }
  Serial.println(v_out_map);
  delay(100);
}