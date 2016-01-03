## Машина-робот на Aduino

### Подготовка:

1. Управление моторами: `src/samples/01-motor.ino`
2. Получение ИК кодов: `src/samples/02-IR.ino`

#### Проблема с компиляцией в Arduino IDE 1.6.5:

Чтобы решить, надо в libraries заменить каталог IRemote на архив
отсюда: https://github.com/z3t0/Arduino-IRremote

Подробнее: https://github.com/z3t0/Arduino-IRremote/issues/53#issuecomment-60281017

### Основная программа

`src/car.ino`

### Git тэги

1. `preprogrammed`: заранее запрограммированые перемещения, без удаленного
управления.
2. `ir`: управление через ИК пульт.
