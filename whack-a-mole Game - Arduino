#include <Servo.h>

//LEADERBOARD
String leaderboard[4];
String finalMessage;
int runs = 0;

//Vibration and Motor VALUES
int pingPin = 9;
int pingPin2 = 10;


//MOTOR
Servo motor1;
Servo motor2;

//Game Variables
int score = 0;
int gameLength = 8;

//Libraries and Wifi
#include <SPI.h>
#include <WiFi101.h>
#include <Temboo.h>
WiFiClient client;
int status = WL_IDLE_STATUS;
#define WIFI_SSID "NYUSHIMA"
#define WPA_PASSWORD "Vlc5k$zf"

//Twitter Info
int calls = 1;   // Execution count, so this doesn't run forever
int maxCalls = 10;   // Maximum number of times the Choreo should be executed
String twitterName;

//Temboo Info
#define TEMBOO_ACCOUNT "robertp"  // Your Temboo account name 
#define TEMBOO_APP_KEY_NAME "myFirstApp"  // Your Temboo app key name
#define TEMBOO_APP_KEY "aLoLsqjPQQ5fFlgks7s8pXN11dBVegIv"  // Your Temboo app key

void setup()
{
  //Beginging Serial and Connecting to Wifi
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  // attempt to connect to WiFi network:
  
    while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(WIFI_SSID);
    //Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(WIFI_SSID, WPA_PASSWORD);

    // wait 10 seconds for connection:
    delay(10000);
    }
  
  Serial.println("Connected to wifi");

  //BUTTON SETUP
  Serial.begin(9600);
  getName();
  motor1.attach(6);
  motor2.attach(8);
}

void loop() {
  if (runs > 0) {
    {
      Serial.println();
      Serial.println("Get ready to play");
      Serial.println("3");
      delay(1000);
      Serial.println("2");
      delay(1000);
      Serial.println("1");
      Serial.println("START!");

      //THIS IS WHERE I RUN THE GAME
      int x = 0;
      while (x < gameLength) {
        motor1.write(0);
        motor2.write(0);
        int randNumber = random(2);
        if (randNumber == 0) {
          Serial.println("MOTOR 1");
          motor1.write(0);
          delay(2000);
          long duration, inches, cm;
          motor1.write(240);
          delay(500);
          long starttime = millis();
          long endtime = 0;
          while ((endtime - starttime) <= 3000) // do this loop for up to 1000mS
          {
            long duration, inches, cm;
            
            pinMode(pingPin, OUTPUT);
            digitalWrite(pingPin, LOW);
            delayMicroseconds(2);
            digitalWrite(pingPin, HIGH);
            delayMicroseconds(5);
            digitalWrite(pingPin, LOW);

            // The same pin is used to read the signal from the PING))): a HIGH
            // pulse whose duration is the time (in microseconds) from the sending
            // of the ping to the reception of its echo off of an object.
            pinMode(pingPin, INPUT);
            duration = pulseIn(pingPin, HIGH);
            cm = duration / 29 / 2;
            if (cm < 20 and cm > 3) {
              Serial.println("YOU HIT THE DANG BALL");
              score++;
              break;
            }
            endtime = millis();
            delay(100);
          }
        }
        if (randNumber == 1) {
          Serial.println("MOTOR 2");
          motor2.write(0);
          delay(2000);
          long duration, inches, cm;
          motor2.write(240);
          delay(500);
          long starttime = millis();
          long endtime = 0;
          while ((endtime - starttime) <= 3000) // do this loop for up to 1000mS
          {
            long duration, inches, cm;
            
            pinMode(pingPin2, OUTPUT);
            digitalWrite(pingPin2, LOW);
            delayMicroseconds(2);
            digitalWrite(pingPin2, HIGH);
            delayMicroseconds(5);
            digitalWrite(pingPin2, LOW);

            // The same pin is used to read the signal from the PING))): a HIGH
            // pulse whose duration is the time (in microseconds) from the sending
            // of the ping to the reception of its echo off of an object.
            pinMode(pingPin2, INPUT);
            duration = pulseIn(pingPin2, HIGH);
            cm = duration / 29 / 2;
            if (cm < 20 and cm > 3) {
              Serial.println("YOU HIT THE DANG BALL");
              score++;
              break;
            }
            endtime = millis();
            delay(100);
          }
        }
        x++;
      }
      checkLeaderboard();
      if (runs >= 3) {
        sendTweet();
      }
      score = 0;
      getName();
    }
  }
  runs++;
}

void getName() {
  Serial.println("Please enter your twitter name with the @ sign");
  Serial.println("If you do not have a twitter account, enter normal name");
  Serial.println();
  while (Serial.available() == 0) {}
  char rx_byte = 0;
  String rx_str = "";
  while (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character

    if (rx_byte != 'n') {
      // a character of the string was received
      rx_str += rx_byte;
    }
  }
  rx_str.trim();
  twitterName = rx_str;
  Serial.println("Welcome " + twitterName + " to the game!");
}

void checkLeaderboard() {
  if (runs == 1) {
    leaderboard[0] = String(score) + twitterName;
  }
  else if (runs == 2) {
    if (leaderboard[0][0] < score) {

      leaderboard[0] = String(score) + twitterName;
    }
    else {
      leaderboard[1] = String(score) + twitterName;
    }
  }
  else {
    if (runs == 3) {
      leaderboard[2] = String(score) + twitterName;
    }
    else {
      leaderboard[3] = String(score) + twitterName;
    }
    String copy[4];
    for (int i = 0; i < 4; i++) {
      copy[i] = (leaderboard[i]);
    }
    for (int i = 0; i < (4); i++) {
      for (int o = 0; o < (4 - (i + 1)); o++) {
        if (copy[o][0] >= copy[o + 1][0]) {
          String t = copy[o];
          copy[o] = copy[o + 1];
          copy[o + 1] = t;
        }
      }
    }
    Serial.println();
    Serial.println("HERE IS THE CURRENT LEADERBOARD!!!!");
    String name1 = String(copy[3]);
    String score1 = String(copy[3][0]);
    name1.remove(0, 1);
    String name2 = String(copy[2]);
    String score2 = String(copy[2][0]);
    name2.remove(0, 1);
    String name3 = String(copy[1]);
    String score3 = String(copy[1][0]);
    name3.remove(0, 1);

    finalMessage = " " + name1 + " " + score1 + " " + name2 + " " + score2 + " " + name3 + " " + score3;
    Serial.println(finalMessage);
    Serial.println();
    leaderboard[0] = copy[3];
    leaderboard[1] = copy[2];
    leaderboard[2] = copy[1];
    leaderboard[3] = "";
  }
}

void sendTweet() {
  Serial.println("WIFI STATUS");
  Serial.println(status);

  TembooChoreo StatusesUpdateChoreo(client);

  // Invoke the Temboo client
  StatusesUpdateChoreo.begin();

  // Set Temboo account credentials
  StatusesUpdateChoreo.setAccountName(TEMBOO_ACCOUNT);
  StatusesUpdateChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
  StatusesUpdateChoreo.setAppKey(TEMBOO_APP_KEY);


  // Set Choreo inputs
  Serial.println(finalMessage);
  String StatusUpdateValue = "LEADERBOARD " + String(finalMessage);
  StatusesUpdateChoreo.addInput("StatusUpdate", StatusUpdateValue);
  String ConsumerKeyValue = "GCgsedFeeDPjGcXX6w7omleM4";
  StatusesUpdateChoreo.addInput("ConsumerKey", ConsumerKeyValue);
  String AccessTokenValue = "861505638966243330-NnNA8w7IiMYkKzlGhJv1vxpK2F3CAcj";
  StatusesUpdateChoreo.addInput("AccessToken", AccessTokenValue);
  String ConsumerSecretValue = "8ZkAB0IDCwPCg0w6gADnCzCRYufI4n7hSJkufS3UBCRa45vdPI";
  StatusesUpdateChoreo.addInput("ConsumerSecret", ConsumerSecretValue);
  String AccessTokenSecretValue = "sTCuHtTozozZvYVX3oFRIuF4tfLUOEXRpe1waaKU2R3AJ";
  StatusesUpdateChoreo.addInput("AccessTokenSecret", AccessTokenSecretValue);

  // Identify the Choreo to run
  StatusesUpdateChoreo.setChoreo("/Library/Twitter/Tweets/StatusesUpdate");

  // Run the Choreo; when results are available, print them to serial
  StatusesUpdateChoreo.run();

  while (StatusesUpdateChoreo.available()) {
    char c = StatusesUpdateChoreo.read();
    Serial.print(c);
  }
  twitterName = "";
  StatusesUpdateChoreo.close();
  Serial.println("nWaiting...n");
  delay(10000);
}
