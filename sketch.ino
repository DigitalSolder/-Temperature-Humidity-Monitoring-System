#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>
#include <RTClib.h>
#include <Preferences.h>

// ------------------ Pin Definitions ------------------
#define DHTPIN        15
#define DHTTYPE       DHT22
#define LED_PIN       12
#define BUZZER_PIN    13
#define BUTTON_PIN    14

// ------------------ Variables ------------------
bool alertMuted = false;

// ------------------ Hardware Objects ------------------
DHT dht(DHTPIN, DHTTYPE);
RTC_DS1307 rtc;
Adafruit_SSD1306 display(128, 64, &Wire, -1);
Preferences prefs;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  dht.begin();

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  prefs.begin("ai-settings", false);
  prefs.end();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed");
    while (1);
  }

  display.clearDisplay();

  if (!rtc.begin()) {
    Serial.println("RTC not found");
  }
  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

// ---------- Simulated AI Decision Logic ----------
bool isAIAlertTriggered(float temp, float hum, int hour) {
  if (temp > 32 && hum > 75) {
    return true;
  } else if (temp > 30 && hour >= 12 && hour <= 15) {
    return true;
  } else if (hum > 85 && hour >= 18 && hour <= 23) {
    return true;
  }
  return false;
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  DateTime now = rtc.now();

  // Button Press to Toggle Mute
  if (digitalRead(BUTTON_PIN) == LOW) {
    alertMuted = !alertMuted;
    Serial.println(alertMuted ? "🔇 Alert Muted" : "🔔 Alert Unmuted");
    delay(300); // Debounce
  }

  // Use AI-like logic to decide alert
  bool alert = isAIAlertTriggered(temperature, humidity, now.hour());

  if (alert && !alertMuted) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // OLED Display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  display.print("Time: ");
  if (now.hour() < 10) display.print('0');
  display.print(now.hour());
  display.print(':');
  if (now.minute() < 10) display.print('0');
  display.println(now.minute());

  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");

  display.print("Hum : ");
  display.print(humidity);
  display.println(" %");

  display.print("Status: ");
  if (alert) {
    display.setTextColor(BLACK, WHITE); // Inverted
    display.println("ALERT!");
    display.setTextColor(WHITE);
  } else {
    display.println("Normal");
  }

  display.display();

  delay(2000); // Wait 2 seconds
}
