// http://zelectro.cc/HC-06_bluetooth_module
//
// just term https://play.google.com/store/apps/details?id=Qwerty.BluetoothTerminal
// or
// car control https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&hl=en

int val;
int LED = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

}

void loop()
{
  if (Serial.available())
  {
    val = Serial.read();

    if (val == 'F')
    {
      digitalWrite(LED, HIGH);
    }

    if (val == 'B')
    {
      digitalWrite(LED, LOW);
    }
  }
}
