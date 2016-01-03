// http://zelectro.cc/Motor_shield_L298N_Arduino

int IN3 = 3; // Input3 подключен к выводу 3
int IN4 = 4;

void setup()
{
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
}

void loop()
{
  // На пару выводов "IN" поданы разноименные сигналы, мотор вращается
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW);
  delay(4000);
  // На пару выводов "IN" поданы одноименные сигналы, мотор не вращается
  digitalWrite (IN4, LOW);
  delay(500);
  // На пару выводов "IN" поданы разноименные (и уже противоположные относительно первого случая) сигналы, мотор вращается
  // относительно первого случая) сигналы, мотор вращается в другую сторону
  digitalWrite (IN3, HIGH);
  delay(4000);
  // Снова на выводах "IN" появились одноименные сигналы, мотор не вращается
  digitalWrite (IN3, LOW);
  delay(5000);
}
