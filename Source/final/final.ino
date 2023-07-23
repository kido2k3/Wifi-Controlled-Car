/*
   -- MyCar --

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
#include "driver.h"
// RemoteXY connection settings
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "MyCar"
#define REMOTEXY_WIFI_PASSWORD ""
#define REMOTEXY_SERVER_PORT 6377

// RemoteXY configurate
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = // 66 bytes
    {255, 5, 0, 0, 0, 59, 0, 16, 31, 1, 1, 1, 33, 76, 9, 17, 2, 31, 0, 1,
     1, 33, 50, 9, 17, 2, 31, 0, 1, 1, 16, 68, 17, 8, 2, 31, 0, 1, 1, 42,
     68, 17, 8, 2, 31, 0, 2, 1, 3, 84, 22, 11, 2, 26, 31, 31, 87, 105, 102, 105,
     0, 65, 117, 116, 111, 0};

// this structure defines all the variables and events of your control interface
struct
{

  // input variables
  uint8_t back;  // =1 if button pressed, else =0
  uint8_t forw;  // =1 if button pressed, else =0
  uint8_t left;  // =1 if button pressed, else =0
  uint8_t right; // =1 if button pressed, else =0
  uint8_t mode;  // =1 if switch ON and =0 if OFF

  // other variable
  uint8_t connect_flag; // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
Car car;
void run()
{
  if (RemoteXY.mode)
  {
    if (RemoteXY.forw)
    {
      car.forward();
    }
    else if (RemoteXY.back)
    {
      car.backward();
    }
    else if (RemoteXY.left)
    {
      car.left();
    }
    else if (RemoteXY.right)
    {
      car.right();
    }
    else
      car.stop();
  }
  else
  {
  }
}

void setup()
{
  RemoteXY_Init();

  // TODO you setup code
}

void loop()
{
  RemoteXY_Handler();
  run();

  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay()
}
