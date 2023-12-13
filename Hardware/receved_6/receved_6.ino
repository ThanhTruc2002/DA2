#include <Arduino.h>
#include <CAN.h>
#include <WiFi.h>
#include <FirebaseESP32.h>

#include <addons/RTDBHelper.h>

/* 1. Define the WiFi credentials */
#define WIFI_SSID "realme 6i"
#define WIFI_PASSWORD "levantien11hp"

//#define WIFI_SSID "IoT Lab-5G"
//#define WIFI_PASSWORD "IoT@123456"


#define TX_GPIO_NUM 4  //Connects to CTX
#define RX_GPIO_NUM 15 //Connects to CRX 

/* 3. Define the RTDB URL */
#define DATABASE_URL "doan2-8ec38-default-rtdb.firebaseio.com" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app



// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

byte data[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int x=0;
int y=0;
int z=0;

void setup() {
  Serial.begin(115200);
  //while (!Serial);
  //delay(1000);

  Serial.println("CAN Receiver");

  //Set the pins
  CAN.setPins (RX_GPIO_NUM, TX_GPIO_NUM);

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
  else{
    Serial.println ("CAN Initialized");
    
  }

  //wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  //firebase
   Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  config.signer.test_mode = true;
  /* Assign the callback function for the long running token generation task */

  // Comment or pass false value when WiFi reconnection will control by your code or third party library e.g. WiFiManager
  Firebase.reconnectNetwork(true);

  // Since v4.4.x, BearSSL engine was used, the SSL buffer need to be set.
  // Large data transmission may require larger RX buffer, otherwise connection issue or data read time out can be occurred.
  fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);

  Firebase.begin(&config, &auth);


  

}

void loop()
{
  
  canReceiver();
  //delay(500);
  Serial.println();
  switch (y)
  {
  case 0:
    Serial.println("KHONG CO TIN HIEU!!!!!!!!!");
    break;  
  case 1:
    Serial.printf("Set int... %s\n", Firebase.setInt(fbdo, "/Fuel", x) ? "ok" : fbdo.errorReason().c_str());
    //delay(500);
    break;
  case 2:
    //z=x*1000;
    Serial.printf("Set int... %s\n", Firebase.setInt(fbdo, "/Rpm", x) ? "ok" : fbdo.errorReason().c_str());
    //delay(500);
    break;
  case 3:
    Serial.printf("Set int... %s\n", Firebase.setInt(fbdo, "/Speed", x) ? "ok" : fbdo.errorReason().c_str());
    //delay(500);
    break;
  case 4:
    Serial.printf("Set int... %s\n", Firebase.setInt(fbdo, "/Temp", x) ? "ok" : fbdo.errorReason().c_str());
    //delay(500);
    break;
    case 5:
    Serial.printf("Set int... %s\n", Firebase.setInt(fbdo, "/Turn", x) ? "ok" : fbdo.errorReason().c_str());
    //delay(500);
    break;
  default:
    break;
  }
  delay(1500);
} 


void canReceiver(){
  // try to parse packet
  int packetSize = CAN.parsePacket();

  if (packetSize) {
    // received a packet
    Serial.print("Received ");

    if (CAN.packetExtended()) {
      Serial.print("extended ");
    }

    if (CAN.packetRtr()) {
      // Remote transmission request, packet contains no data
      Serial.print("RTR ");
    }

    Serial.print("packet with id 0x");
    Serial.print(CAN.packetId(), HEX);
    switch (CAN.packetId()) {
          case 0x01:
            y = 3;
            break;
          case 0x02:
            y = 2;
            break;
          case 0x03:
            y = 5;
            break;
          case 0x04:
            y = 1;
            break;
            case 0x05:
            y = 4;
            break;
          default:
            y = 0;// Xử lý trường hợp mặc định nếu không khớp với bất kỳ trường hợp nào trên
            break;
        }
    if (CAN.packetRtr()) {
      Serial.print(" and requested length ");
      Serial.println(CAN.packetDlc());
    } else {
      Serial.print(" and length ");
      Serial.println(packetSize);

      while (CAN.available()) {
       x = (int)CAN.read(); 
       //Serial.print((int)CAN.read());
       Serial.print(x);
      
      Serial.print("");
    }

  }
  
}

}
