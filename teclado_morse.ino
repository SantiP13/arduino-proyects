// Se incluye la librería para el LCD Display
#include <LiquidCrystal.h>

// Inicialización de variables
long tiempo_pres = 0;
long tiempo_inicio = 0;
long tiempo_final = 0;
long tiempo_no = 0;
long tiempo_total = 0;
bool trad = false;
String palabras = "";
String x = "";
String morse = "";
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int cx = 0;
int cy = 0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  //Inicializa el botón en el pin 13
  pinMode(13, INPUT);
  Serial.begin(9600);
  //Empieza el monitor serial de 16x2
  lcd.begin(16, 2);
}

void loop() {
  //Guarda el tiempo total
  tiempo_inicio = millis();
  while (digitalRead(13) == HIGH) {
    Serial.print("tiempo inicio: ");
    Serial.println(tiempo_inicio);
    //Guarda el tiempo total
    tiempo_total = millis();
    //Resta el tiempo de inicio al tiempo total y se guarda como el tiempo presionado
    tiempo_pres = (tiempo_total - tiempo_inicio);
    Serial.print("tiempo final: ");
    Serial.println(tiempo_pres);
    }
  if (tiempo_pres > 10 and tiempo_pres <= 450){
    //Si el tiempo es menor a 450ms y mayor a 10ms, guarda un punto
    morse+= ".";
    tiempo_pres = 0;
  }
  if (tiempo_pres > 450 and tiempo_pres < 4000) {
    //Si el tiempo es mayor a 450ms y menor a 4000ms guarda una línea
    morse+= "-";
    tiempo_pres = 0;
  }
  if (tiempo_pres > 4000) {
    //Si el tiempo es mayor a 4 segundos se pone un espacio
    morse+= "1";
    tiempo_pres = 0;
  }
  tiempo_final = millis();
  while (digitalRead(13) == LOW) {
    Serial.print("tiempo final: ");
    Serial.println(tiempo_final);
    //Guarda el tiempo total
    tiempo_total = millis();
    //Resta el tiempo de inicio al tiempo total y se guarda como el tiempo con el botón sin presionar
    tiempo_no = (tiempo_total - tiempo_final);
    Serial.print("tiempo no: ");
    Serial.println(tiempo_no);
    if (tiempo_no > 3000) {
      //Si el tiempo es mayor a 3 segundos, se muestra la letra en el lcd
      trad = true;
      tiempo_no = 0;
      break;
    }
   }
  if (trad == true){
    //Guardado de la variable impresa en el lcd
    if (x.length() ==  15) {
      cy ++;
      x = "";
    }
    //llama a la función que traduce y guarda la letra regresada en una variable
    x += traductor(morse, "");
    if (cy == 0){
    //Pone la letra en el lcd
    lcd.clear();
    lcd.setCursor(0,cy);
    lcd.print(x);
    Serial.println("x: ");
    Serial.print(x);
    trad = false;
    morse = "";
      }
    if (cy == 1){
    lcd.clear();
    lcd.setCursor(0,cy);
    lcd.print(x);
    Serial.println("x: ");
    Serial.print(x);
    trad = false;
    morse = "";
      }
      }
    if (cy == 2) {
      cy = 0;
    }
   }
// Función que recibe el morse y regresa una letra
String traductor(String morse1, String palabras){
  morse1 = morse;
  if (morse1 == ""){
    return("");
    }
  else {
    if (morse1 == "1"){
      morse1 = " ";
      }
    if (morse1 == ".-"){
      morse1 = "a";
      }
    if (morse1 == "-..."){
      morse1 = "b";
      }
    if (morse1 == "-.-."){
      morse1 = "c";
      }
    if (morse1 == "-.."){
      morse1 = "d";
      }
    if (morse1 == "."){
      morse1 = "e";
      }
    if (morse1 == "..-."){
      morse1 = "f";
      }
    if (morse1 == "--."){
      morse1 = "g";
      }
    if (morse1 == "...."){
      morse1 = "h";
      }
    if (morse1 == ".."){
      morse1 = "i";
      }
    if (morse1 == ".---"){
      morse1 = "j";
      }
    if (morse1 == "-.-"){
      morse1 = "k";
      }
    if (morse1 == ".-.."){
      morse1 = "l";
      }
    if (morse1 == "--"){
      morse1 = "m";
      }
    if (morse1 == "-."){
      morse1 = "n";
      }
    if (morse1 == "---"){
      morse1 = "o";
      }
    if (morse1 == ".--."){
      morse1 = "p";
      }
    if (morse1 == "--.-"){
      morse1 = "q";
      }
    if (morse1 == ".-."){
      morse1 = "r";
      }
    if (morse1 == "..."){
      morse1 = "s";
      }
    if (morse1 == "-"){
      morse1 = "t";
      }
    if (morse1 == "..-"){
      morse1 = "u";
      }
    if (morse1 == "...-"){
      morse1 = "v";
      }
    if (morse1 == ".--"){
      morse1 = "w";
      }
    if (morse1 == "-..-"){
      morse1 = "x";
      }
    if (morse1 == "-.--"){
      morse1 = "y";
      }
    if (morse1 == "--.."){
      morse1 = "z";
      }
    
    palabras += (morse1);
    morse1 = "";
    morse = "";
    Serial.println("palabras");
    Serial.print(palabras);
    return(palabras);
    }
  }
