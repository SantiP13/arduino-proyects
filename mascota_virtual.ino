// Se importa la librería para el display
#include <LiquidCrystal.h>

// Se inicializa el lcd display, asignandole sus puertos respectivos
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

// Se crean variables para la cantidad de "comida" y para el puerto del botón
int food = 0;
int PIN = 7;

void setup() {
  // Se inicializa el monitor o consola
  Serial.begin(9600);
  
  // Se designa el pin del botón como entrada
  pinMode(PIN, INPUT_PULLUP);
  
  // Comienza el display, utilizando todas sus 16 columnas y 2 filas
  lcd.begin(16, 2);
}

void loop() {
  // Condicional para saber si el botón esta presionado
  if (digitalRead(PIN) == HIGH) {
    food = food + 2;
  } else if (food > 0){ // Si no lo está, se resta comida
    food --;
  } else if (food == 0) { // Pero deja de restar si la comida ya es igual a 0
    food = 0;
  }
  
  // Según el número de comida disponible, cambia la imagen del display
  if (food < 1) {
    image00();
  } else if (food <= 2) {
    image01();
  } else if (food <= 4) {
    image02();
  } else if (food <= 6) {
    image03();
  } else if (food <= 8) {
    image04();
  } else if (food <= 10) {
    image05();
  } else if (food <= 12) {
    image06();
  } else if (food <= 14) {
    image07();
  } else if (food <= 16) {
    image08();
  } else if (food <= 18) {
    image09();
  } else if (food <= 20) {
    image10();
  } else if (food <= 22) {
    image11();
  } else if (food <= 24) {
    image12();
  } else if (food <= 26) {
    image13();
  } else if (food <= 28) {
    image14();
  } else if (food <= 30) {
    image15();
  } else if (food <= 32) {
    image16();
  } else if (food <= 34) {
    image17();
  } else if (food <= 36) {
    image18();
  }
  
  // Imprime en la consola el número de comida
  Serial.print(food);
  
  // Crea un delay de 600ms cada ciclo 
  delay(600);
}

// 18 funciones para crear cada imagen (creadas en: https://tusindfryd.github.io/screenduino/)
void image00() {
  lcd.clear();

  byte image07[8] = {B00000, B00110, B00001, B00000, B00001, B00001, B00001, B00000};
  byte image08[8] = {B00000, B00000, B00000, B10001, B01010, B00000, B00000, B00000};
  byte image09[8] = {B00000, B01100, B10000, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00000, B00001, B00010, B00100, B00111, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B11111, B00000};
  byte image25[8] = {B00000, B00000, B00000, B10000, B01000, B00100, B11100, B00000};
  byte image27[8] = {B11111, B10001, B10001, B10001, B10001, B10001, B10001, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image08);
  lcd.createChar(2, image09);
  lcd.createChar(3, image23);
  lcd.createChar(4, image24);
  lcd.createChar(5, image25);
  lcd.createChar(6, image27);
  lcd.createChar(7, image11);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(7, 0);
  lcd.write(byte(1));
  lcd.setCursor(8, 0);
  lcd.write(byte(2));
  lcd.setCursor(6, 1);
  lcd.write(byte(3));
  lcd.setCursor(7, 1);
  lcd.write(byte(4));
  lcd.setCursor(8, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 1);
  lcd.write(byte(6));
  lcd.setCursor(10, 0);
  lcd.write(byte(7));
}

void image01() {
  lcd.clear();

  byte image07[8] = {B00000, B00110, B00001, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B01100, B10000, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00000, B00001, B00010, B00100, B00111, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B11111, B00000};
  byte image25[8] = {B00000, B00000, B00000, B10000, B01000, B00100, B11100, B00000};
  byte image27[8] = {B11111, B10001, B10001, B10001, B10001, B10001, B11001, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};
  byte image08[8] = {B00000, B00000, B00000, B10001, B01010, B00000, B00000, B00000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);
  lcd.createChar(7, image08);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
  lcd.setCursor(7, 0);
  lcd.write(byte(7));
}

void image02() {
  lcd.clear();

  byte image07[8] = {B00000, B00110, B00001, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B01100, B10000, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00000, B00001, B00010, B00100, B00111, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B11111, B00000};
  byte image25[8] = {B00000, B00000, B00000, B10000, B01000, B00100, B11100, B00000};
  byte image27[8] = {B11111, B10001, B10001, B10001, B10001, B10001, B11101, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};
  byte image08[8] = {B00000, B00000, B00000, B10001, B01010, B00000, B00000, B00000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);
  lcd.createChar(7, image08);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
  lcd.setCursor(7, 0);
  lcd.write(byte(7));
}

void image03() {
  lcd.clear();

  byte image07[8] = {B00000, B00110, B00001, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B01100, B10000, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00000, B00001, B00010, B00100, B00111, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B11111, B00000};
  byte image25[8] = {B00000, B00000, B00000, B10000, B01000, B00100, B11100, B00000};
  byte image27[8] = {B11111, B10001, B10001, B10001, B10001, B10001, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};
  byte image08[8] = {B00000, B00000, B00000, B10001, B01010, B00000, B00000, B00000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);
  lcd.createChar(7, image08);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
  lcd.setCursor(7, 0);
  lcd.write(byte(7));
}

void image04() {
  lcd.clear();

  byte image07[8] = {B00000, B00111, B00000, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B11100, B00000, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00000, B00001, B00010, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B00000, B10000, B01000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B10001, B10001, B10001, B11001, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};
  byte image08[8] = {B00000, B00000, B10001, B00000, B00000, B00000, B00000, B00000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);
  lcd.createChar(7, image08);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
  lcd.setCursor(7, 0);
  lcd.write(byte(7));
}

void image05() {
  lcd.clear();

  byte image07[8] = {B00000, B00111, B00000, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B11100, B00000, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00000, B00001, B00010, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B00000, B10000, B01000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B10001, B10001, B10001, B11101, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};
  byte image08[8] = {B00000, B00000, B10001, B00000, B00000, B00000, B00000, B00000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);
  lcd.createChar(7, image08);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
  lcd.setCursor(7, 0);
  lcd.write(byte(7));
}

void image06() {
  lcd.clear();

  byte image07[8] = {B00000, B00111, B00000, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B11100, B00000, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00000, B00001, B00010, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B00000, B10000, B01000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B10001, B10001, B10001, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};
  byte image08[8] = {B00000, B00000, B10001, B00000, B00000, B00000, B00000, B00000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);
  lcd.createChar(7, image08);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
  lcd.setCursor(7, 0);
  lcd.write(byte(7));
}

void image07() {
  lcd.clear();

  byte image07[8] = {B00000, B00011, B00100, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B11000, B00100, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00010, B00011, B00010, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B01000, B11000, B01000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B10001, B10001, B11001, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
}

void image08() {
  lcd.clear();

  byte image07[8] = {B00000, B00011, B00100, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B11000, B00100, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00010, B00011, B00010, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B01000, B11000, B01000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B10001, B10001, B11101, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
}

void image09() {
  lcd.clear();

  byte image07[8] = {B00000, B00011, B00100, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B11000, B00100, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00010, B00011, B00010, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B01000, B11000, B01000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B10001, B10001, B11111, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
}

void image10() {
  lcd.clear();

  byte image07[8] = {B00000, B00000, B00011, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B00000, B11000, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00100, B00011, B00000, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B00000, B11100, B00000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B10001, B11001, B11111, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
}

void image11() {
  lcd.clear();

  byte image07[8] = {B00000, B00000, B00011, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B00000, B11000, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00100, B00011, B00000, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B00000, B11100, B00000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B10001, B11101, B11111, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
}

void image12() {
  lcd.clear();

  byte image07[8] = {B00000, B00000, B00011, B00000, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B00000, B11000, B00000, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00100, B00011, B00000, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B11111, B00000, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B00000, B11100, B00000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B10001, B11111, B11111, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
}

void image13() {
  lcd.clear();

  byte image07[8] = {B00000, B00000, B00011, B00100, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B00000, B11000, B00100, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00100, B00010, B00001, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B00000, B11111, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B00100, B01000, B10000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B11001, B11111, B11111, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
}

void image14() {
  lcd.clear();

  byte image07[8] = {B00000, B00000, B00011, B00100, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B00000, B11000, B00100, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00100, B00010, B00001, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B00000, B11111, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B00100, B01000, B10000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B11101, B11111, B11111, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
}

void image15() {
  lcd.clear();

  byte image07[8] = {B00000, B00000, B00011, B00100, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B00000, B11000, B00100, B10000, B10000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00100, B00010, B00001, B00000, B00000, B00000};
  byte image24[8] = {B00000, B00000, B00000, B00000, B11111, B00000, B00000, B00000};
  byte image25[8] = {B00000, B00000, B00100, B01000, B10000, B00000, B00000, B00000};
  byte image27[8] = {B11111, B10001, B11111, B11111, B11111, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
}

void image16() {
  lcd.clear();

  byte image07[8] = {B00000, B00000, B00011, B00100, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B00000, B11000, B00000, B10000, B00000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00111, B00100, B00010, B00001, B00000, B00000};
  byte image24[8] = {B00000, B00000, B11111, B00000, B00000, B11111, B00000, B00000};
  byte image25[8] = {B00000, B00000, B11100, B00100, B01000, B10000, B00000, B00000};
  byte image27[8] = {B11111, B11001, B11111, B11111, B11111, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};
  byte image08[8] = {B00000, B00000, B00001, B00011, B00000, B00001, B00011, B00000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);
  lcd.createChar(7, image08);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
  lcd.setCursor(7, 0);
  lcd.write(byte(7));
}

void image17() {
  lcd.clear();

  byte image07[8] = {B00000, B00000, B00011, B00100, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B00000, B11000, B00000, B10000, B00000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00111, B00100, B00010, B00001, B00000, B00000};
  byte image24[8] = {B00000, B00000, B11111, B00000, B00000, B11111, B00000, B00000};
  byte image25[8] = {B00000, B00000, B11100, B00100, B01000, B10000, B00000, B00000};
  byte image27[8] = {B11111, B11101, B11111, B11111, B11111, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};
  byte image08[8] = {B00000, B00000, B00001, B00011, B00000, B00001, B00011, B00000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);
  lcd.createChar(7, image08);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
  lcd.setCursor(7, 0);
  lcd.write(byte(7));
}

void image18() {
  lcd.clear();

  byte image07[8] = {B00000, B00000, B00011, B00100, B00001, B00001, B00001, B00000};
  byte image09[8] = {B00000, B00000, B11000, B00000, B10000, B00000, B10000, B00000};
  byte image23[8] = {B00000, B00000, B00111, B00100, B00010, B00001, B00000, B00000};
  byte image24[8] = {B00000, B00000, B11111, B00000, B00000, B11111, B00000, B00000};
  byte image25[8] = {B00000, B00000, B11100, B00100, B01000, B10000, B00000, B00000};
  byte image27[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B01111};
  byte image11[8] = {B00001, B00011, B00110, B01110, B11111, B00110, B01100, B11000};
  byte image08[8] = {B00000, B00000, B00001, B00011, B00000, B00001, B00011, B00000};

  lcd.createChar(0, image07);
  lcd.createChar(1, image09);
  lcd.createChar(2, image23);
  lcd.createChar(3, image24);
  lcd.createChar(4, image25);
  lcd.createChar(5, image27);
  lcd.createChar(6, image11);
  lcd.createChar(7, image08);

  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 0);
  lcd.write(byte(6));
  lcd.setCursor(7, 0);
  lcd.write(byte(7));
}
