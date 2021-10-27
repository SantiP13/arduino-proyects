// Se incluye la librería de los servomotores
#include <Servo.h>

// Se inicializan los servos
Servo servo1; //Servos
Servo servo2;
Servo servo3;
  
/*
const int LED1 = 2; //LEDs para marcar las posiciones guardadas (no utilizado)
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 7;
const int LED5 = 8;
*/

// Variables con el puerto digital para cada botón
const int button1 = 13; //Buttons
const int button2 = 12;

// Variables dependientes de los botones
int button1Presses = 0; //Button values
boolean button2Pressed = false;

// Variables con el puerto análogo para los potenciómetros
const int pot1 = A2; //Potentimeters
const int pot2 = A1; 
const int pot3 = A0;

// Variables para los valores de los potenciometros y su conversión a ángulo
int pot1Val; //Potentimeter values
int pot2Val;
int pot3Val;
int pot1Angle;
int pot2Angle;
int pot3Angle;

// Variables que guardan hasta 5 posiciones de cada motor
int servo1PosSaves[] = {1,1,1,1,1}; //position saves
int servo2PosSaves[] = {1,1,1,1,1};
int servo3PosSaves[] = {1,1,1,1,1};

void setup() {
  servo1.attach(5); // Configura todo y corre una vez, defines los motores y les asignas un puerto
  servo2.attach(6);
  servo3.attach(9);
  /*
  pinMode(LED1, OUTPUT); // Se definen los puertos de los leds como salidas (no utilizado)
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT); */
  
  // se definen los puertos de los botones como entradas
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  
  // Se inicializa el monitor serial
  Serial.begin(9600);
}

void loop() { 
  pot1Val = analogRead(pot1); // Le el valor análogo del potenciómetro y lo guarda
  pot1Angle = map(pot1Val, 0, 1023, 0, 179); // Usa map(), para transformar los valores de 0 a 1024 a grados de 0 a 179 grados
  pot2Val = analogRead(pot2); 
  pot2Angle = map(pot2Val, 0, 1023, 0, 179);
  pot3Val = analogRead(pot3);
  pot3Angle = map(pot3Val, 0, 1023, 0, 179);
  
  // Causas que el servo se mueva al ángulo específicado
  servo1.write(pot1Angle); 
  servo2.write(pot2Angle);
  servo3.write(pot3Angle);
  
  // Condicional if que revisa cuantas veces el botón se ha presionado
  if(digitalRead(button1) == HIGH){ 
    // Añade uno al número de veces que se ha presionado el botón
    button1Presses++;
    
    // Condicional switch (funciona casi igual que un if), revisa cuantas veces se ha presionado el botón y guarda los grados
    switch(button1Presses){
      case 1:
        servo1PosSaves[0] = pot1Angle;
        servo2PosSaves[0] = pot2Angle;
        servo3PosSaves[0] = pot3Angle;
        //digitalWrite(LED1, LOW);
        delay(50);
        //digitalWrite(LED1, HIGH);
        Serial.println("Pos 1 Saved");
        break;
      case 2:
        servo1PosSaves[1] = pot1Angle;
        servo2PosSaves[1] = pot2Angle;
        servo3PosSaves[1] = pot3Angle;
        //digitalWrite(LED2, LOW);
        delay(50);
        //digitalWrite(LED2, HIGH);
        Serial.println("Pos 2 Saved");
        break;
      case 3:
        servo1PosSaves[2] = pot1Angle;
        servo2PosSaves[2] = pot2Angle;
        servo3PosSaves[2] = pot3Angle;
        //digitalWrite(LED3, LOW);
        delay(50);
        //digitalWrite(LED3, HIGH);
        Serial.println("Pos 3 Saved");
        break;
       case 4:
        servo1PosSaves[3] = pot1Angle;
        servo2PosSaves[3] = pot2Angle;
        servo3PosSaves[3] = pot3Angle;
        //digitalWrite(LED4, LOW);
        delay(50);
        //digitalWrite(LED4, HIGH);
        Serial.println("Pos 4 Saved");
        break;
       case 5:
        servo1PosSaves[4] = pot1Angle;
        servo2PosSaves[4] = pot2Angle;
        servo3PosSaves[4] = pot3Angle;
        //digitalWrite(LED5, LOW);
        delay(50);
        //digitalWrite(LED5, HIGH);
        Serial.println("Pos 5 Saved");
        break;
      case 6:
        // Si se ha presionado más de 5 veces, el contador se reincia
        button1Presses = 0;
        break;
    }
  }
  
  // Revisa si el segundo botón ha sido presionado
  if(digitalRead(button2) == HIGH){ 
    button2Pressed = true;   
  } else {
    button2Pressed = false;
  }
  
  // Condicional que revisa si el botón ha sido presionado, si así es, corre las 5 posiciones guardadas con 1050ms de delay gracias a un ciclo for
  if(button2Pressed){ 
    for(int i = 0; i < 5; i++){
        servo1.write(servo1PosSaves[i]);
        servo2.write(servo2PosSaves[i]);
        servo3.write(servo3PosSaves[i]);
        Serial.println(" potentimeter Angles: ");
        Serial.println(servo1PosSaves[i]);
        Serial.println(servo2PosSaves[i]);
        Serial.println(servo3PosSaves[i]);
        delay(1050);
      }
  }
  
  // Causa que el bucle se corra cada 300ms
  delay(300);
} 
