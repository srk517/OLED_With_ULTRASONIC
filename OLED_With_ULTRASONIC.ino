#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int const trigger_pin = 3;
int const echo_pin  = 2;
long dur;
float dist;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }   
  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  
}

void loop() {
  oled.clearDisplay();
  digitalWrite(trigger_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin,LOW);
  dur = pulseIn(echo_pin,HIGH);
  dist = ((dur*0.034)/2);
  oled.setTextSize(1.80);
  oled.setTextColor(WHITE);
  oled.setCursor(1,10);
  Serial.print(dist);
  oled.print("Distance= ");
  oled.print(dist);
  oled.display(); 
   Serial.println(dist);
  // put your main code here, to run repeatedly:
  delay(1000);

}
