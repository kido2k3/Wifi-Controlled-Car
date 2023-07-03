#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 188 bytes
  { 255,6,0,5,0,181,0,16,220,5,130,3,31,9,32,64,0,187,130,0,
  0,89,63,11,0,17,130,3,255,9,32,64,0,187,4,128,255,92,67,8,
  0,2,26,129,0,7,2,48,7,0,25,67,79,78,84,82,79,76,76,69,
  82,0,2,1,39,75,22,11,0,2,26,31,31,65,117,116,111,0,67,111,
  110,116,114,0,131,0,3,87,17,4,2,32,31,83,112,101,101,100,0,67,
  5,4,78,15,8,0,2,26,5,129,0,20,80,9,4,0,17,82,80,77,
  0,130,0,2,12,59,58,0,220,1,1,27,45,9,22,0,2,31,0,1,
  1,3,36,19,9,0,2,31,0,131,0,24,39,16,4,1,2,25,68,105,
  114,101,99,116,105,111,110,0,1,1,41,36,19,9,0,2,31,0,1,1,
  27,14,9,22,0,2,31,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t speed; // =0..100 slider position 
  uint8_t mode; // =1 if switch ON and =0 if OFF 
  uint8_t back; // =1 if button pressed, else =0 
  uint8_t left; // =1 if button pressed, else =0 
  uint8_t right; // =1 if button pressed, else =0 
  uint8_t forw; // =1 if button pressed, else =0 

    // output variables
  char dis_text[4];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)


void setup() 
{
  RemoteXY_Init (); 
  
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
