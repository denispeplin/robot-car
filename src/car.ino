int IN1 = 1;
int IN2 = 2;
int IN3 = 3;
int IN4 = 4;

void setup()
{
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

void loop()
{
  forward();
  delay(2000);
  fullstop();
  delay(500);
  back();
  delay(2000);
  fullstop();
  delay(1000);
  rollright();
  delay(1000);
  rollleft();
  delay(1000);
  fullstop();
  delay(5000);
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

void rollleft()
{
  leftstop();
  rightforward();
}

void rollright()
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
