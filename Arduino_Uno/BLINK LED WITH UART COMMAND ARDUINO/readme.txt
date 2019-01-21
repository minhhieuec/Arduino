1. Read UART command.
if data is "toogle" => toogle led.

2. Read button value at BUTTON_PIN (12).
if button is pushed => send "toogle" string via Uart to other Uart device.
