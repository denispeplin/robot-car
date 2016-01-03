// Проблема с компиляцией в Arduino IDE 1.6.5
// Чтобы решить, надо в libraries заменить каталог IRemote на архив отсюда: https://github.com/z3t0/Arduino-IRremote
// Подробнее: https://github.com/z3t0/Arduino-IRremote/issues/53#issuecomment-60281017

// Motor control
int IN1 = 1;
int IN2 = 2;
int IN3 = 3;
int IN4 = 4;

int motorState[4] = {LOW, LOW, LOW, LOW};

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN); // create instance of 'irrecv'
decode_results results; // create instance of 'decode_results'

void setup()
{
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&results)) {
    driveCar();
    irrecv.resume(); // Receive the next value
  }
}

void driveCar()
{
  switch(results.value)
  {
    case 0xFF10EF: // number 4
      left();
      break;
    case 0xFF5AA5: // 6
      right();
      break;
    case 0xFF18E7: // 2
      forward();
      break;
    case 0xFF4AB5: // 8
      back();
      break;
    case 0xFF38C7: // 5
      fullstop();
      break;
  }
  delay(100);
}

void saveMotorState()
{
  motorState[0] = digitalRead(IN1);
  motorState[1] = digitalRead(IN2);
  motorState[2] = digitalRead(IN3);
  motorState[3] = digitalRead(IN4);
}

void loadMotorState()
{
  digitalWrite(IN1, motorState[0]);
  digitalWrite(IN2, motorState[1]);
  digitalWrite(IN3, motorState[2]);
  digitalWrite(IN4, motorState[3]);
}

void forward()
{
  leftforward();
  rightforward();
}

void fullstop()
{
  leftstop();
  rightstop();
}

void back()
{
  leftback();
  rightback();
}

void left()
{
  saveMotorState();
  leftstop();
  rightforward();
  delay(400);
  loadMotorState();
}

void right()
{
  saveMotorState();
  rightstop();
  leftforward();
  delay(400);
  loadMotorState();
}

void leftforward()
{
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void leftstop()
{
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
}


void leftback()
{
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void rightforward()
{
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
}

void rightstop()
{
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
}

void rightback()
{
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
}
