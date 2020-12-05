#include <SoftwareSerial.h>
const int LDR = 2;
int valor = 0;
int ValorLidoPassado = 0;
String s = "Ola";

void setup() {
  Serial.begin(9600);
  Serial.println(s);

}

void loop() {

  valor = digitalRead(LDR);

  Serial.println(valor);

  delay(1000);

}
