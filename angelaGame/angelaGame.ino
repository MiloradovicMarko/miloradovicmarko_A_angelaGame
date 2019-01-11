void setup() {
// put your setup code here, to run once:

int ledRosso = 8;
int ledBlu = 9;

}

void loop() {
  // put your main code here, to run repeatedly:
    if(digitalRead(ledRosso) == HIGH)
    {
        digitalWrite(ledRosso) = LOW;  
    }
}
