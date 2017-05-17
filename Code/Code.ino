#include <UIPEthernet.h>
//#include <Ethernet.h>
#include <LiquidCrystal.h>

void resetup();

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
static byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

// Enter the IP address of the server you're connecting to:
IPAddress server(192, 168, 1, 1);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 23 is default for telnet;
// if you're using Processing's ChatServer, use port 10002):
EthernetClient client;

void setup() {
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Connecting.");
  // start the Ethernet connection:
  Ethernet.begin(mac);
  lcd.print(".");

  // give the Ethernet shield a second to initialize:
  delay(500);
  lcd.print(".");
  //Serial.println("connecting.");

  for(;;) {
    // if you get a connection, report back via serial:
    if (client.connect(server, 23)) {
      lcd.print(".");
      break;
    } else {
      // if you didn't get a connection to the server:
      delay(500);
      lcd.print(".");
    }
  }
  lcd.clear();
  lcd.print("Reading...");
}

void loop() {

}

void resetup() {
  // start the Ethernet connection:
  Ethernet.begin(mac);

  // give the Ethernet shield a second to initialize:
  delay(1000);

  for(;;) {
    // if you get a connection, report back via serial:
    if (client.connect(server, 23)) {
      break;
    } else {
      delay(500);
    }
  }
}

