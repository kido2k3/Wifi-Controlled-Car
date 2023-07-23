#define SPEED_OTHER 255
class Car
{
protected:
  uint8_t speed; // from 105 to 255
  uint8_t enA;
  uint8_t enB;
  uint8_t in1;
  uint8_t in2;
  uint8_t in3;
  uint8_t in4;

public:
  Car()
  {
    speed = 255;
    enA = 6;
    enB = 5;
    in1 = 2; // move forward: 1: off, 2: on
    in2 = 4;
    in3 = 7; // move forward: 3: on, 4: off
    in4 = 3;
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
  }
  void forward()
  {
    analogWrite(enA, speed);
    analogWrite(enB, speed);

    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(in3, 1);
    digitalWrite(in4, 0);
  }
  void backward()
  {
    analogWrite(enA, SPEED_OTHER);
    analogWrite(enB, SPEED_OTHER);

    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(in3, 0);
    digitalWrite(in4, 1);
  }
  void left()
  {
    analogWrite(enA, 0);
    analogWrite(enB, SPEED_OTHER);

    digitalWrite(in3, 1);
    digitalWrite(in4, 0);
  }
  void right()
  {
    analogWrite(enA, SPEED_OTHER);
    analogWrite(enB, 0);

    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
  }
  void stop()
  {
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  }
  void set_speed(int val)
  {
    speed = 105 + (255 - 105) * val / 100.0;
  }
  uint8_t get_speed()
  {
    return speed;
  }
};