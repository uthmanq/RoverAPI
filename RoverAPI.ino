/*
  Launchify Rover API V1.1
  Written by Uthman Qureshi, Founder and CEO of Launchify
  All Rights Reserved
 */

#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <SoftwareSerial.h>
#include <Sabertooth.h>


SoftwareSerial SWSerial(12, 11); // RX on no pin (unused), TX on pin 11 (to S1).
Sabertooth ST(128, SWSerial); // Address 128, and use SWSerial as the serial port.

// Listen to the default port 5555, the Yún webserver
// will forward there all the HTTP requests you send
YunServer server;


void setup() {
  SWSerial.begin(9600);
  //Serial.begin(SERIAL_CONST);
  //ST.autobaud(); //decreases boot time by a few seconds v1.1
  // Bridge startup
  ST.motor(1,0);
  ST.motor(2,0);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);
  
  // Listen for incoming connection only from localhost
  // (no one from the external network could connect)
  server.listenOnLocalhost();
  server.begin();
}

void loop() {
  // Get clients coming from server
  YunClient client = server.accept();

  // There is a new client?
  if (client) {
    // Process request
    process(client);

    // Close connection and free resources.
    client.stop();
  }

  // delay(50); // Poll every 50ms // Removed to decrease latency v1.1
}

void process(YunClient client) {
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
  // read the command
  String command = client.readStringUntil('/');

  // is "Forward" command?
  if (command == "forward") {
    forwardCommand(client);
  }

  // is "Backward" command?
  if (command == "backwards") {
    backwardCommand(client);
  }

  // is "Left" command?
  if (command == "left") {
    leftCommand(client);
  }
   // is "Right" command?
  if (command == "right") {
    rightCommand(client);
  }
  
}

void forwardCommand(YunClient client) {
  int speed;
  speed = client.parseInt();
  if (speed <= 180 && speed >= 0)
  {
    ST.motor(1,speed);
    ST.motor(2,speed);  
  }
}
void backwardCommand(YunClient client) {
  int speed;
  speed = client.parseInt();
  if (speed <= 180 && speed >= 0)
  {
    ST.motor(1,-speed);
    ST.motor(2,-speed);  
  }
}
void leftCommand(YunClient client) {
 int speed;
  speed = client.parseInt();
  if (speed <= 180 && speed >= 0)
  {
    ST.motor(1,-speed);
    ST.motor(2,speed);  
  }
}


void rightCommand(YunClient client) {
int speed;
  speed = client.parseInt();
  if (speed <= 180 && speed >= 0)
  {
    ST.motor(1,speed);
    ST.motor(2,-speed);  
  }
}

