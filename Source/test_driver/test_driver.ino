

#define SPEED 255
class Car
{
protected:
  uint8_t speed_forward;
  uint8_t speed_other;
  uint8_t enA;
  uint8_t enB;
  uint8_t in1;
  uint8_t in2;
  uint8_t in3;
  uint8_t in4;

public:
  Car()
  {
    speed_forward = speed_other = 255;
    enA = 5;
    enB = 6;
    in1 = 4;
    in2 = 2;
    in3 = 3;
    in4 = 7;
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
  }
  void forward()
  {
    analogWrite(enA, speed_forward);
    analogWrite(enB, speed_forward);

    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(in3, 1);
    digitalWrite(in4, 0);
  }
  void backward()
  {
  }
  void left()
  {
  }
  void right()
  {
  }
  void stop()
  {
  }
  void read_speed()
  {
  }
};
void setup()
{
  Car car;
}
void loop()
{
}
