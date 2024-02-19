int led1 = 2; 
int sensortod;

void setup ()
{
  pinMode(led1, OUTPUT);
  pinMode(sensortod, INPUT);
  Serial.begin(9600);
}

void loop () 
{
  sensortod=analogRead(A0);
  Serial.println(sensortod); 

  if (sensortod < 35) {
    digitalWrite(led1,HIGH);
  } else {
     digitalWrite(led1,LOW);
    }
}
