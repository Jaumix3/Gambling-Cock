#include <Wire.h>
#include <RTClib.h>  // Librería para el módulo RTC

RTC_DS3231 rtc;  // Crear objeto RTC

void setup() {
  Serial.begin(9600);  // Iniciar comunicación serial
  Wire.begin();        // Iniciar comunicación I2C

  // Verificar si el RTC está conectado
  if (!rtc.begin()) {
    Serial.println("No se pudo encontrar el RTC");
    while (1);  // Detener aquí
  }

  // Ajustar la hora del RTC (solo la primera vez)
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  DateTime now = rtc.now();  // Obtener hora actual

  // Imprimir la fecha y hora en formato: YYYY-MM-DD HH:MM:SS
  Serial.print(now.year(), DEC);
  Serial.print('-');
  Serial.print(now.month(), DEC);
  Serial.print('-');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);

  delay(1000);  // Actualizar cada segundo
}
