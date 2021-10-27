// Se importa la librería para el servomotor
#include<Servo.h>

// Se inicializa el nombre del servomotor
Servo motor1;

// Se inician variables de posicion y tiempo
int angulo=0;
int distancia=0;
int tiempo=0;

void setup()
{
  // Se inicializa el monitor serial
  Serial.begin (9600);

  // Se designa el pin 13 al servomotor
  motor1.attach(13);

  // TRIG, Se define como salida, Lanza señal ultrasónica
  pinMode(4, OUTPUT);  
  
  // ECHO, Se define como ENTRADA, Recibe señal ultrasónica
  pinMode(2, INPUT);   
  
  // Se definen ambos LED's como salidas
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  // Lanzamiento de señal ultrasónica
  digitalWrite(4, HIGH);
  delay(1);
  digitalWrite(4, LOW);

  // Recibe señal últrasónica y calcula la distancia por el tiempo que tarda en regresar
  tiempo = pulseIn (2, HIGH);
  distancia= tiempo/58.2;

  // Se muestra la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.println(distancia);
  delay(500);

  // Si la distancia es menor o igual a 10 se cumple la siguiente condición
  if (distancia <= 10)
  {
    // Se reasgina el valor de 90 grados al ángulo
    angulo=90;

    // El servomotor se alinea a los grados correspondiente (90 grados)
    motor1.write(angulo);
    delay(50);

    // Enciende LED verde, apaga LED rojo
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
   }

  // Si la distancia es mayor que 10 se cumple la siguiente condición
  if (distancia >10)
  {
    // Se reasgina el valor de 0 grados al ángulo
    angulo=0;

    // El servomotor se alinea a los grados correspondiente (0 grados)
    motor1.write(angulo);
    delay(50);

    // Enciende LED rojo, apaga LED verde
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
   }
   
delay(1000);
}  
