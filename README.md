## Машина-робот на Aduino

### Подготовка:

1. Управление моторами: `src/samples/01-motor.ino`
2. Получение ИК кодов: `src/samples/02-IR.ino`
3. Подключение bluetooth: `src/samples/03-bluetooth.ino`

#### Проблема с компиляцией в Arduino IDE 1.6.5:

Чтобы решить, надо в libraries заменить каталог IRemote на архив
отсюда: https://github.com/z3t0/Arduino-IRremote

Подробнее: https://github.com/z3t0/Arduino-IRremote/issues/53#issuecomment-60281017

### Основная программа

`src/car.ino`

### Шаги

1. Научиться управлять моторами (подготовка, пункт 1).
2. Программа без удаленного управления (тэг preprogrammed).
3. Получение ИК кодов (подготовка, пункт 2).
4. Управление через ИК пульт (тег ir).
5. Повороты с сохранением состояния (тэг save-motor-state).
6. Подключение bluetooth, считывание данных (тэг bluetooth). RX модуля к TX
   контроллера и наоборот. При загрузке программы на контроллер модуль должен
   быть отключен.
