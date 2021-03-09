//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ETHERNET_LIB
#include <Ethernet.h>
/* Ethernet shield used pins: 10(SS) */
#include <SPI.h>
/* SPI interface used pins: 51(MOSI), 50(MISO), 52(SCK) */

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_ETHERNET_MAC "DE:AD:BE:EF:EF:ED"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,2,0,0,0,12,0,10,13,0,
  5,32,40,21,21,21,2,26,31 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_1_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_1_y; // =-100..100 y-coordinate joystick position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#include <Servo.h>
int SERVO_X_Center = 1500;
int SERVO_Y_Center = 1500;
Servo servo1;
Servo servo2;


void setup() 
{
  RemoteXY_Init (); 
  
  //attaches our servos on pins PWM 3-5
  servo1.attach(3);
  servo2.attach(5);  
}

void loop() 
{ 
  RemoteXY_Handler ();
    servo1.writeMicroseconds(RemoteXY.joystick_1_x*10 + SERVO_X_Center);
    servo2.writeMicroseconds(RemoteXY.joystick_1_y*10 + SERVO_Y_Center);
    
    /*RemoteXY.servo1 = RemoteXY.joystick_1_x;
    RemoteXY.servo2 = RemoteXY.joystick_1_y;*/
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
