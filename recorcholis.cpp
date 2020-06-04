#include <Servo.h>                 //Librería para el servomotor
 Servo servo1;                      // se crea el objeto servo1
 
 int BTN_INICIO   = 5;                 //pin 2 conección del boton "verde"
 int BTN_INICIO_VAL;               //variable para guardar el estado (High - low) del boton inicio
 int SENSOR_1  = 8;                    //pin 8 conexión del sensor1 "bajo las válvulas"
 int SENSOR1_VAL = LOW;                 //variable para guardar el estado (High - low) del sensor1
 int SENSOR_2 = 9;
 int SENSOR2_VAL = LOW;
 #define STEEP_PIN  25                 //pin 25 pone en movimiento el motor de la banda 
 #define DIR_PIN    26                 //pin 26 indica al motor el sentido de giro 
 #define VALVULA_1  23                 //pin 23 válvula del contenedor 1 
 #define SELLADO_R  28                 //pin 28 resistencia para sellado 
 
void setup() {

      servo1.attach(11);
      pinMode(STEEP_PIN,OUTPUT);           //asigno el pin 25 como salida
      pinMode(DIR_PIN,OUTPUT);             //asigno el pin 26 como salida
      pinMode(VALVULA_1,OUTPUT);           //asigno el pin 23 como salida
      pinMode(SELLADO_R,OUTPUT);
}


void loop() {

  

BTN_INICIO_VAL = digitalRead (5);   // Lee el boton inicio (botón verde) y asigna el estado a valorinicio
SENSOR1_VAL =  digitalRead (8);   // Lee el sensor1 y asigna el estado a valsensor1

//******************* INICIO DEL PROCESO **************************
 
if (BTN_INICIO_VAL == LOW){               // si el botón verde está presionado... 
    digitalWrite(DIR_PIN,HIGH);           // especifica la dirección de giro del motor a pasos

//******************* LLENADO DE BOLIS X4 **************************  
  
       while(digitalRead (SENSOR_1) == LOW){                        // mientras el sensor1 no detecte nada, el motor sigue girando, de lo contrario para
             digitalWrite(STEEP_PIN,HIGH);                          // crea una onda cuadrada que es ugual a 1 paso del motor
             delay(1);                                              //            ______  HIGH
             digitalWrite(STEEP_PIN,LOW);                           //            |    |
             delay(1);                                              //   LOW _____|1ms |_____  1 vuelta del motor (360°) = 400 pasos         
  }
              delay(1000);                                                  // espera 1 segundo
              digitalWrite (VALVULA_1, HIGH);                               // activa la válvula 1 por 2 segundos
              delay (2000);                                                 // espera 2 segundos
              digitalWrite (VALVULA_1, LOW);                                // desactiva la válvula 1 por 2 segundos
              delay (500);                                                  // espera 2 segundos
                                                                            
        while(digitalRead (8) == LOW){                                     
               digitalWrite(STEEP_PIN,HIGH);                                
               delay(1);                                                    
               digitalWrite(STEEP_PIN,LOW);                                 
               delay(1);                                                    
   }
              delay(1000);                                                      
              digitalWrite (VALVULA_1, HIGH);                                     
              delay (2000);
              digitalWrite (VALVULA_1, LOW);                                      
              delay (500);

        while(digitalRead (8) == LOW){                                      
              digitalWrite(STEEP_PIN,HIGH);                                
              delay(1);                                                    
              digitalWrite(STEEP_PIN,LOW);                                 
              delay(1);                                                    
  }
              delay(1000);                                                      
              digitalWrite (VALVULA_1, HIGH);                                     
              delay (2000);
              digitalWrite (VALVULA_1, LOW);                                     
              delay (500);

        while(digitalRead (8) == LOW){                                      
              digitalWrite(STEEP_PIN,HIGH);                                
              delay(1);                                                  
              digitalWrite(STEEP_PIN,LOW);                                 
              delay(1);                                                    
  }
              delay(1000);                                                      
              digitalWrite (VALVULA_1, HIGH);                                     
              delay (2000);
              digitalWrite (VALVULA_1, LOW);                                      
              delay (500);
} 

else{                                                             // si el botón verde NO está presionado...
    digitalWrite(DIR_PIN,HIGH);                                   // mantiene la misma direccion de giro del motor
    digitalWrite(STEEP_PIN,LOW);                                  // deshabilita el pin de "arranque" del motor
    delay (1000);                                                   // espera 10 milisegundos
  } 
//***********************  SELLADADO  *********************** 
 
 /*                                            // mientras REPET_2 sea mayor que 0, hace lo que sigue: 
 
       while(digitalRead (SENSOR_2) == LOW){                        // mientras el sensor2 no detecte nada, el motor sigue girando, de lo contrario se detiene
             digitalWrite(STEEP_PIN,HIGH);                          // crea una onda cuadrada que es ugual a 1 paso del motor
             delay(1);                                              //            ______  HIGH
             digitalWrite(STEEP_PIN,LOW);                           //            |    |
             delay(1);                                              //   LOW _____|1ms |_____  1 vuelta del motor (360°) = 400 pasos
           
  }
      delay(10);                                                    // espera 1 segundo
      digitalWrite (SELLADO_R, HIGH);                               // activa la resistencia de sellado por 2 segundos
      delay (2000);
      servo1.write (25);                                            // mueve el servo 25° para sellar y cortar los bolis
      delay (1000);                                                 // espera 1 segundo
      digitalWrite (SELLADO_R, LOW);                                // desactiva la resistencia
      servo1.write (0);                                             // regresa el servo a 0° 
      delay(1000);                                                  // resta 1 a REPET_2
  
}*/
}
