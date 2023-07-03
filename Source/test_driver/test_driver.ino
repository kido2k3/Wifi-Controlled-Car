
// Pinout
// MOTOR
#define MOTOR1
#define MOTOR2
#define MOTOR3_1
#define MOTOR3_2
#define MOTOR4_1
#define MOTOR4_2
// ULTRASONIC SEN HC-SC04
#define TRIG
#define ECHO
////////////////////////////////////////////////
class Ult_ss
{
public:
  void intial()
  {
  }
};
class Car
{
private:
  int speed, speed_turn;

public:
  void intial()
  {
    speed = 0;
    speed_turn = 0;
  }
  void forw()
  {
  }
  void left()
  {
  }
  void right()
  {
  }
  void back()
  {
  }
};
