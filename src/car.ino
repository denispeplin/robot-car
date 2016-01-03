// Проблема с компиляцией в Arduino IDE 1.6.5
// Чтобы решить, надо в libraries заменить каталог IRemote на архив отсюда: https://github.com/z3t0/Arduino-IRremote
// Подробнее: https://github.com/z3t0/Arduino-IRremote/issues/53#issuecomment-60281017

// Motor control
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

void setup()
{
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    int command = Serial.read();
    driveCar(command);
  }
}

// Bluetooth version. Download the program and look for letters in settings
// https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&hl=en
void driveCar(int val)
{
  switch(val)
  {
    case 'L':
      left();
      break;
    case 'R':
      right();
      break;
    case 'F':
      forward();
      break;
    case 'B':
      back();
      break;
    case 'S':
      fullstop();
      break;
  }
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
  leftstop();
  rightforward();
}

void right()
{
  rightstop();
  leftforward();
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
