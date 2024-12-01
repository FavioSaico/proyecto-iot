#define SENSOR_PIN_D0 2     // Pin de salida digital del sensor (DO)
#define SENSOR_PIN_A0 A0      // Pin de salida analogica del sensor (AO)
#define BUZZER_PIN 8     // Pin del buzzer
#define LED_RED 9        // Pin del LED rojo
#define LED_GREEN 10     // Pin del LED verde
#define LED_BLUE 11      // Pin del LED azul

void setup() {
  // Configuración de los pines
  pinMode(SENSOR_PIN_D0, INPUT);    // Pin D0 como entrada
  pinMode(SENSOR_PIN_A0, INPUT);    // Pin A0 como entrada
  pinMode(BUZZER_PIN, OUTPUT);  // Buzzer como salida
  pinMode(LED_RED, OUTPUT);     // LED rojo como salida
  pinMode(LED_GREEN, OUTPUT);   // LED verde como salida
  pinMode(LED_BLUE, OUTPUT);    // LED azul como salida
  
  // LED verde encendido
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, HIGH);

  // Buzzer apagado
  digitalWrite(BUZZER_PIN, LOW);

  Serial.begin(9600); // Para monitoreo en Serial Monitor
}

void loop() {
  int valor_D0 = digitalRead(SENSOR_PIN_D0); // Leer estado del sensor (DO)
  int valor_A0 = analogRead(SENSOR_PIN_A0); // Leer estado del sensor (AO)

  // Imprimiendo valores detectados
  String valorDetectado = "Pin Digital (D0): ";
  valorDetectado += valor_D0;
  valorDetectado += " | Pin Analógico (A0): ";
  valorDetectado += valor_A0;

  if (valor_D0 == LOW && valor_A0 <= 500) { // Si detecta agua

    // Activar buzzer
    digitalWrite(BUZZER_PIN, HIGH); 
    // Encender LED rojo
    digitalWrite(LED_RED, LOW);   
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    // Mensaje
    Serial.print("¡Agua detectada! - ");
    Serial.println(valorDetectado);

  } else { // Si no detecta agua

    // Apagar buzzer
    digitalWrite(BUZZER_PIN, LOW);
    // Encender LED verde
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW); 
    digitalWrite(LED_BLUE, HIGH);
    // Mensaje
    Serial.print("Estado normal - ");
    Serial.println(valorDetectado);

  }
  
  delay(2000); // Realizar una lectura cada 2 segundos
}