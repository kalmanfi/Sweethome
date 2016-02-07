#define HUM_pin   2  //Human detektor
#define REL_pin   8  //Relé

volatile bool HUM;           //Human detektor állapota
volatile int  T = 3;         //Időzítő

void setup() {
  Serial.begin(9600);
  pinMode(REL_pin, OUTPUT);
  digitalWrite(REL_pin,HIGH);
  pinMode(HUM_pin, INPUT);
  attachInterrupt(0, HUM_event,CHANGE);
}

void loop() {
  if ((!HUM) & T>0) T--;                             //Ha nincs mozgás, akkor visszaszámol
  if (!T) digitalWrite(REL_pin,HIGH);                //Ha T=0 LED kikapcsol          

  Serial.print("Move: ");
  Serial.print(HUM);
  Serial.print(" Time: ");
  Serial.print(T);
  Serial.print(" Led state: ");
  Serial.println(digitalRead(REL_pin));
  
  delay(1000);
}

void HUM_event() {                     //Ha van mozgás, akkor időzítőviszzaállít 3-ra, LED fel
  HUM = digitalRead(HUM_pin);
  if (HUM) {
    T = 3;
    Serial.println("mozgás van"); 
    digitalWrite(REL_pin,LOW);                        
  }
}


