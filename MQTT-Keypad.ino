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

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols);

long lastMsg = 0;
char msg[50];

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
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

void callback(char* topic, byte* payload, unsigned int length) 
{
  
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  long now = millis();
  int status;
  char myKey = myKeypad.getKey();

// BUTTON A  
  if (myKey != NULL) {
     String msg="Button status: ";
     if(myKey=='A' )
     {
        msg= "A";
       char message[58];
       msg.toCharArray(message,58);
       Serial.println(message);
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
    String clientId = "MQTTKeypad-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("connected");
      client.subscribe(mqtt_command);
      client.publish(mqtt_state, state_on);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
