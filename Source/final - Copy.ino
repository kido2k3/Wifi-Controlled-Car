/*
   -- Wifi controlled car --

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

#include "driver.h"
#include <RemoteXY.h>

// RemoteXY connection settings
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377

// RemoteXY configurate
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = // 236 bytes
    {255, 6, 0, 5, 0, 229, 0, 16, 220, 5, 130, 3, 31, 9, 32, 64, 0, 187, 130, 0,
     0, 89, 63, 11, 0, 17, 130, 3, 255, 9, 32, 64, 0, 187, 4, 128, 255, 92, 67, 8,
     0, 2, 26, 129, 0, 7, 2, 48, 7, 0, 25, 67, 79, 78, 84, 82, 79, 76, 76, 69,
     82, 0, 2, 1, 39, 75, 22, 11, 0, 2, 26, 31, 31, 67, 111, 110, 116, 114, 0, 65,
     117, 116, 111, 0, 131, 0, 3, 87, 17, 4, 2, 32, 31, 83, 112, 101, 101, 100, 0, 67,
     5, 4, 78, 15, 8, 0, 2, 26, 5, 129, 0, 20, 80, 9, 4, 0, 17, 82, 80, 77,
     0, 130, 0, 2, 12, 59, 58, 0, 97, 1, 1, 28, 45, 9, 22, 0, 2, 31, 0, 1,
     1, 3, 35, 19, 10, 0, 2, 31, 0, 131, 0, 24, 39, 16, 4, 1, 2, 25, 68, 105,
     114, 101, 99, 116, 105, 111, 110, 0, 1, 1, 41, 35, 19, 10, 0, 2, 31, 0, 1, 1,
     28, 14, 9, 22, 0, 2, 31, 0, 129, 0, 28, 15, 8, 17, 0, 6, 226, 134, 145, 0,
     129, 0, 28, 46, 8, 17, 0, 6, 226, 134, 147, 0, 129, 0, 42, 31, 17, 17, 0, 6,
     226, 134, 146, 0, 129, 0, 4, 31, 17, 17, 0, 6, 226, 134, 144, 0};

// this structure defines all the variables and events of your control interface
struct
{

  // input variables
  int8_t speed;  // =0..100 slider position
  uint8_t mode;  // =1 if switch ON and =0 if OFF
  uint8_t back;  // =1 if button pressed, else =0
  uint8_t left;  // =1 if button pressed, else =0
  uint8_t right; // =1 if button pressed, else =0
  uint8_t forw;  // =1 if button pressed, else =0

  // output variables
  char dis_text[5]; // string UTF8 end zero

  // other variable
  uint8_t connect_flag; // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

// my code
Car car;
void run()
{
  car.set_speed(RemoteXY.speed);
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
    {
      car.stop();
    }
  }
  else
  {
    car.stop();
  }
}
void display(uint8_t val)
{
  sprintf(RemoteXY.dis_text, "%d", val);
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
  display(car.get_speed());
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay()
}
