#include <DHT.h>

#define DHTPIN 2    // Pin tempel sensor DHT11
#define DHTTYPE DHT11   // Tipe sensor DHT (DHT11 atau DHT22)

#define GREEN_LED_PIN 3  // Pin lampu hijau
#define RED_LED_PIN 4    // Pin lampu merah

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  delay(2000);  // Delay untuk membaca suhu setiap 2 detik

  float temperature = dht.readTemperature();

  if (!isnan(temperature)) {  // Periksa apakah pembacaan suhu valid
    Serial.print("Suhu: ");
    Serial.println(temperature);

    if (temperature < 31.0) {
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(RED_LED_PIN, LOW);
    } else {
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
    }
  } else {
    Serial.println("Gagal membaca suhu. Periksa koneksi dan sensor.");
  }
}
