#include <Keypad.h>
#include <Password.h>

Password password = Password( "123" );
const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};
byte rowPins[ROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8 }; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int KeyCheck = 0;
int kunci = 0;

void setup() 
{
  Serial.begin(9600); 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10,LOW);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad     
}

void loop() 
{
  char key = keypad.getKey();
  while (kunci == 1){ tombol();}
}

//take care of some special events
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
  //Serial.print("Pressed: ");
  //Serial.println(eKey);
  switch (eKey){
    case '*': checkPassword(); break;
    case '#': password.reset(); break;
    default: password.append(eKey);
     }
  }
}

void checkPassword(){
  if (password.evaluate()){
    digitalWrite(9, HIGH);
    Serial.print("8");
    kunci = 1;delay(3000);digitalWrite(9,LOW);
    }
  else{
    digitalWrite(10, HIGH);
    kunci = 0;
    delay(3000);
    digitalWrite(10,LOW);
  }
}

void tombol(){
  char key = keypad.getKey();
    
    if (key){
    if(key == '1'){KeyCheck = 1; Serial.print("1");}
    if(key == '2'){KeyCheck = 1; Serial.print("2");}
    if(key == '3'){KeyCheck = 1; Serial.print("3");}  
    if(key == '4'){KeyCheck = 1; Serial.print("4");}
    if(key == '5'){KeyCheck = 1; Serial.print("5");}
    if(key == '6'){KeyCheck = 1; Serial.print("6");}
    if(key == '7'){KeyCheck = 1; Serial.print("7");}
    if(key == '8'){KeyCheck = 1; Serial.print("8");}
    if(KeyCheck == 0){Serial.print(key);}
    KeyCheck = 0;
  
}
}
