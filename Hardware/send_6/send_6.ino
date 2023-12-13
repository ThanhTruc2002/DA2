#include <SPI.h>          // SPI is used to talk to the CAN Controller
#include <mcp_can.h>      // CAN Bus library

MCP_CAN CAN(10);          // Set CAN Bus Chip Select to pin 10
byte data0[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
byte data1[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
byte data2[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
byte data3[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
byte data4[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
byte data5[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
byte data6[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
byte data7[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
byte data8[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
byte data9[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
byte data10[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
byte data11[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // Msg 8 byte data
//===============================================================================
//  Initialization
//===============================================================================
void setup()
{
  Serial.begin(115200);   // Initialize communication with Serial monitor

 Serial.println("CAN transmitter test");
   // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s
  if(CAN.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) 
    Serial.println("MCP2515 Initialized Successfully!");
  else 
    Serial.println("Error Initializing MCP2515...");

  CAN.setMode(MCP_NORMAL);   // Normal mode to allow messages to be transmitted
}

//===============================================================================
//  Main
//===============================================================================
void loop()
{
    data0[0]=50;
   //data0[0]=random(0,100);

  //CAN.sendMsgBuf(msg ID, standard frame, #of data bytes, data array);
  byte sndStat = CAN.sendMsgBuf(0x01, 1, data0); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat == CAN_OK){
    Serial.println("Message1 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message1...");
  } 
  delay(2000);
  data1[0]=150;
   //data0[0]=random(0,100);

  //CAN.sendMsgBuf(msg ID, standard frame, #of data bytes, data array);
  byte sndStat1 = CAN.sendMsgBuf(0x01, 1, data1); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat1 == CAN_OK){
    Serial.println("Message1 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message1...");
  } 
  delay(2000);
  
  data2[0]=3;
  //data1[0] = random(0,8);

  //CAN.sendMsgBuf(msg ID, standard frame, #of data bytes, data array);
  byte sndStat2 = CAN.sendMsgBuf(0x02, 1, data2); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat2 == CAN_OK){
    Serial.println("Message2 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message2...");
  }
  delay(2000);
  
  data3[0]=7;
  //data[0]=random(0,255);
  byte sndStat3 = CAN.sendMsgBuf(0x03, 1, data3); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat3 == CAN_OK){
    Serial.println("Message3 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message3...");
  }
  delay(2000);
  data4[0]=1;
  //data[0]=random(0,255);
  byte sndStat4 = CAN.sendMsgBuf(0x03, 1, data4); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat4 == CAN_OK){
    Serial.println("Message3 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message3...");
  }
  delay(2000);
  data5[0]=2;
  //data[0]=random(0,255);
  byte sndStat5 = CAN.sendMsgBuf(0x03, 1, data5); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat5 == CAN_OK){
    Serial.println("Message3 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message3...");
  }
  delay(2000);
  data6[0]=3;
  //data[0]=random(0,255);
  byte sndStat6 = CAN.sendMsgBuf(0x03, 1, data6); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat6 == CAN_OK){
    Serial.println("Message3 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message3...");
  }
  delay(2000);

  data7[0]=15;
  //data7[0]=random(0,20);
  byte sndStat7 = CAN.sendMsgBuf(0x04, 1, data7); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat7 == CAN_OK){
    Serial.println("Message4 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message4...");
  }
  delay(2000);
  data8[0]=30;
  //data7[0]=random(21,35);
  byte sndStat8 = CAN.sendMsgBuf(0x04, 1, data8); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat8 == CAN_OK){
    Serial.println("Message4 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message4...");
  }
  delay(2000);
  data9[0]=50;
  //data7[0]=random(36,100);
  byte sndStat9 = CAN.sendMsgBuf(0x04, 1, data9); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat9 == CAN_OK){
    Serial.println("Message4 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message4...");
  }
  delay(2000);

  data10[0]=75;
  //data10[0]=random(0,100);
  byte sndStat10 = CAN.sendMsgBuf(0x05, 1, data10); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat10 == CAN_OK){
    Serial.println("Message5 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message5...");
  }
  delay(2000);
  data11[0]=130;
  //data10[0]=random(0,100);
  byte sndStat11 = CAN.sendMsgBuf(0x05, 1, data11); // 6 đại diện cho số byte cần truyền đi. trường hợp này chỉ truyền đến byte thứ 5
  if(sndStat11 == CAN_OK){
    Serial.println("Message5 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message5...");
  }
  delay(2000);
  
//  Serial.print("Data0: ");
//  for (int i = 0; i < 8; i++) {
//    Serial.print(data0[i]);
//    Serial.print(" ");
//  }
//  Serial.println();
//  Serial.print("Data1: ");
//  for (int i = 0; i < 8; i++) {
//    Serial.print(data1[i]);
//    Serial.print(" ");
//  }
//  Serial.println();
//  Serial.print("Data2: ");
//  for (int i = 0; i < 8; i++) {
//    Serial.print(data2[i]);
//    Serial.print(" ");
//  }
//  Serial.println();
//  Serial.print("Data3: ");
//  for (int i = 0; i < 8; i++) {
//    Serial.print(data3[i]);
//    Serial.print(" ");
//  }
//  Serial.println();
//  Serial.print("Data4: ");
//  for (int i = 0; i < 8; i++) {
//    Serial.print(data4[i]);
//    Serial.print(" ");
//  }
//  Serial.println();
  
  
  delay(500);
  
}
