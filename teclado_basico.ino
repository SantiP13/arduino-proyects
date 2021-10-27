// Se importa la librería para el LCD Display 
#include <LiquidCrystal.h>

// Se inicializa el lcd display, asignandole sus puertos respectivos
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

// Variables para definir el puerto de los botones y los carácteres disponibles
const int changeButton = 13;
const int moveButton = 10;
const char chars[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','.',',','1','2','3','4','5','6','7','8','9','0','-','*','@', ' '};

// Inicialización de variables
int charsIndex = 0;
int changeButtonState = 0;
int moveButtonState = 0;
int resetButtonState = 0;
int charsSize = 0;
int cx = 0;
int cy = 0;

void setup() {
  // Comienza el monitor serial
  Serial.begin(9600);
  
  // Comienza el display, utilizando todas sus 16 columnas y 2 filas
  lcd.begin(16,2);
  
  // Se limpia el display cuando comienza y se asigna el cursor a la primera posición
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.blink(); // Causa el parpadeo del cursor
  
  // Número de carácteres en la lista chars
  charsSize = sizeof(chars);
  
  // Configura los puertos de ambos botones como entradas
  pinMode(changeButton, INPUT);
  pinMode(moveButton, INPUT);
  
}

void loop() {
  // Lee el estado de ambos botones
  changeButtonState = digitalRead(changeButton);
  moveButtonState = digitalRead(moveButton);
  
  // Condicional if/elif que revisa que botón ha sido presionado
  if (changeButtonState == HIGH) {
    // Si el botón para cambiar carácteres fue presionado
    // Condicional if para volver a ciclar entre todos los caracteres (Si el índice es más grande que la lista, entonces reinicia el índice)
    if (charsIndex == charsSize) {
      charsIndex = 0;
    }
    
    // Muestra el carácter en la pantalla
    lcd.print(chars[charsIndex]);
    lcd.setCursor(cx,cy); // Fija el cursor en la posición actual
    charsIndex ++; // Suma 1 al índice 
  } else if (moveButtonState == HIGH) {
    // Si el botón para moverse un espacio ha sido presionado
    // Se reinicia el índice de carácteres
    charsIndex = 0;
    // Se suma 1 a la posición en x
    cx ++;
    
    // Si la posición en x es más que la disponible en el display (16), salta a la siguiente fila (cy)
    if (cx == 16) {
      cx = 0;
      cy ++;
    }
    
    // Si la posición en y es más que la disponible en el display (2), regresa a la primera línea
    if (cy == 2){
      cy = 0;
    }
    
    // Ajusta el cursor a la nueva posición
    lcd.setCursor(cx,cy);
  } 
  
  // Causa que el bucle corra cada 340ms
  delay(340);
}
