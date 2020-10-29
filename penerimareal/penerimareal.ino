int DataCheck = 0;
void setup() 
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.print("Simulasi Home Automation dengan Password:");
  Serial.println();
}
void loop() 
{
  if(Serial.available())
  {
    char data = Serial.read();
    Serial.print(data);
    Serial.print("      ======== >      ");
    
    if(data == '1'){DataCheck = 1; digitalWrite(6, HIGH);Serial.println("Light on.");}
    if(data == '2'){DataCheck = 1; digitalWrite(6, LOW);Serial.println("Light off.");}
    if(data == '3'){DataCheck = 1; digitalWrite(5, HIGH);Serial.println("Fan on.");} 
    if(data == '4'){DataCheck = 1; digitalWrite(5, LOW);Serial.println("Fan off.");}
    if(data == '5'){DataCheck = 1; digitalWrite(4, HIGH);Serial.println("Night lamp on.");}
    if(data == '6'){DataCheck = 1; digitalWrite(4, LOW);Serial.println("Night lamp off.");}
    if(data == '7'){DataCheck = 1; digitalWrite(5, HIGH);digitalWrite(4, HIGH);digitalWrite(6, HIGH);Serial.println("All on.");}
    if(data == '8'){DataCheck = 1; digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(6, LOW);Serial.println("All off.");}
    if(DataCheck == 0){Serial.println("Perintah Salah. Silakan ulangi !!! ");}
    Serial.println();
    DataCheck = 0;
  }
}
