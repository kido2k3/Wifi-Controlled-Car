/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "123456789"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 100 bytes
  { 255,3,0,0,0,93,0,16,13,4,129,0,26,4,40,6,0,17,84,101,
  115,116,32,82,71,66,32,76,69,68,0,4,0,12,15,5,44,0,2,26,
  4,0,28,15,5,44,0,2,26,4,0,43,15,5,44,0,2,26,131,1,
  10,12,9,4,1,2,31,82,101,100,0,131,0,25,12,11,4,2,2,31,
  66,108,117,101,0,131,0,41,12,11,4,3,2,31,71,114,101,101,110,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t RED; // =0..100 slider position 
  int8_t BLUE; // =0..100 slider position 
  int8_t GREEN; // =0..100 slider position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  analogWrite(A1, int(RemoteXY.RED/100.0*255));
  analogWrite(A2, int(RemoteXY.GREEN/100.0*255));
  analogWrite(A3, int(RemoteXY.BLUE/100.0*255));
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
