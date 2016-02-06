#define HUM_pin   7  //Human detektor
#define REL_pin   8  //Relé

bool LED;           //LED állapota
bool HUM;           //Human detektor állapota
int  T = 3;         //Időzítő

void setup() {
  noInterrupts()
  Serial.begin(9600);
  pinMode(REL_pin, OUTPUT);
  digitalWrite(REL_pin,HIGH);
  pinMode(HUM_pin, INPUT);
}

void loop() {
  bool HUM = digitalRead(HUM_pin);
  if (HUM) T = 3;                           //Ha van mozgás, akkor időzítőviszzaállít 3-ra
  else if (T) T--;                          //Ha nincs mozgás, és T>0 akkor T--
  
  if (T) digitalWrite(REL_pin,LOW);        //Ha T>0 Led ég
  else digitalWrite(REL_pin,HIGH);           //Ha T=0 Led nem ég

  Serial.print("Move: ");
  Serial.print(HUM);
  Serial.print(" Time: ");
  Serial.print(T);
  Serial.print(" Led state: ");
  Serial.println(digitalRead(REL_pin));
  
  delay(1000);      