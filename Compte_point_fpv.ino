const int okPin = 3; // l'entrée du bouton de validation est sur la pin 3
const int nonokPin = 2; // l'entrée du bouton de message de non validation est sur la pin 2
const int greenPin = 4;
const int redPin = 5;

int comptePoint;
int niveau;

void setup() {
  // paramétrer les variable
  comptePoint = 0;
  niveau = 1;
  // paramétrer les pins
  //Pin des boutons
  pinMode(okPin, INPUT_PULLUP);
  pinMode(nonokPin, INPUT_PULLUP);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  //Initialiser le moniteur série
  Serial.begin(9600);

}

void loop() {
  // condition de comptage de point
  if (digitalRead(okPin) == LOW){
    Serial.println(" ");
    Serial.print("parcours  ");
    comptePoint++;
    delay(500);
    Serial.print(niveau);
    Serial.print("                                           ");
    Serial.print(comptePoint);
    Serial.print(" point(s)");
    digitalWrite(greenPin, HIGH);
    delay(500);
    digitalWrite(greenPin, LOW);

  }
  if (digitalRead(nonokPin) == LOW) {
    Serial.println(" ");
    Serial.println(" ");
    Serial.print(" Parcours recommencé. Cause: Raté parcours");
    comptePoint = 0;
    digitalWrite(redPin, HIGH);
    delay(1000);
    digitalWrite(redPin, LOW);
    Serial.println(" ");
    Serial.println(" ");

  }
  else {

  }
  if (comptePoint == 4) {
    comptePoint = 0;
    niveau = niveau + 1;
    Serial.println(" ");
    Serial.println(" ");
    Serial.print(" Parcours Suivant ");
    Serial.println(" ");
    Serial.println(" ");

  }
  else {

  }

}
