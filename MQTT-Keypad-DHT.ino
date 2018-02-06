#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <PubSubClient.h>
#include "user_config.h"
#include <Keypad.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>


const byte n_rows = 4;
const byte n_cols = 4;

char keys[n_rows][n_cols] = {
  {'A', 'B', 'C', 'D'},
  {'E', 'F', 'G', 'H'},
  {'I', 'J', 'K', 'L'},
  {'M', 'N', 'O', 'P'}
};

byte colPins[n_rows] = {D3, D2, D1, D0};
byte rowPins[n_cols] = {D7, D6, D5, D4};

long lastMsg = 0;
char msg[50];

#define DHTPIN D7 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int chk;
float hum;
float temp;

WiFiClient espClient;
PubSubClient client(espClient);
LiquidCrystal_I2C lcd(0x3F, D2, D1);
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols);

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  dht.begin();
  lcd.begin(16,2);
  lcd.init();
  lcd.setBacklight(HIGH);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {

}

void loop() 
{
  delay(2000);
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Hum:  ");
  lcd.print(hum);
  lcd.print(" %");
  delay(2000); //Delay 2 sec.

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  long now = millis();
  int status;
  char myKey = myKeypad.getKey();
  

  if (myKey != NULL) {
     String msg="Button status: ";
     if(myKey=='A' )
     {
        msg= "A";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
       // 1 Line MSG
       lcd.setCursor(0, 0);
       lcd.print("ALARM SYSTEM:");
       // 2 Line MSG
       lcd.setCursor(0, 1);      
       lcd.print("Disarmed!");  
      client.publish(mqtt_state, message);
       }
     else if (myKey=='B' )
     {
      msg= "B";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='C' )
     {
      msg= "C";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='D' )
     {
      msg= "D";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='E' )
     {
      msg= "E";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='F' )
     {
      msg= "F";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='G' )
     {
      msg= "G";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='H' )
     {
      msg= "H";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='I' )
     {
      msg= "I";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='J' )
     {
      msg= "J";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='K' )
     {
      msg= "K";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='L' )
     {
      msg= "L";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='M' )
     {
      msg= "M";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='N' )
     {
      msg= "N";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }
     else if (myKey=='O' )
     {
      msg= "O";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }

     else if (myKey=='P' )
     {
      msg= "P";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish(mqtt_state, message);
     }     
    }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");

    // Create a random client ID
    String clientId = project_name"-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("connected");
      client.subscribe(alarm_state_topic);
//      client.subscribe(mqtt_command);
      client.publish(mqtt_state, state_on);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
