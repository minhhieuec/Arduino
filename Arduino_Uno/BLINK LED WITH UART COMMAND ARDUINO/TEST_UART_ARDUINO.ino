/*
*   @author:  MinhHieuEC
*   
*   @date:    21/01/2019
*   
*   @brief: - read uart string data from Serial (pin 0 and pin 1)
*           - if sting data equal "toogle" then toogle led at LED_PIN
*           - to test this code, please upload code to your board and open Serial Monitor => type "toogle" command and click send.
*             Led is connected at LED_PIN will be toogle.
*             
*   @follow me at:
*   @mail:    MinhHieuEC@gmail.com
*   @blog:    https://ratdongian.blogspot.com/
*   @github:  https://github.com/minhhieuec
*   @youtube: https://www.youtube.com/channel/UCP1J5jV7UnQbk66-N540rPw/videos
*/

#define BUTTON_PIN  12 //  define button pin
#define LED_PIN     11

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  //  init button pin is input
  
  pinMode(LED_PIN,  OUTPUT);  //  init led pin is output
  digitalWrite(LED_PIN, LOW); //  connect led pin to GND to turn off led
  
  Serial.begin(115200); //  init baudrate is 115200 bps
}

int led_stt = false;

void read_uart(){
    String s = "";
    if(Serial.available() > 0){
        while(Serial.available()>0){
          char a = char(Serial.read());
            if (a != '\n')
              s += a;
            delay(10);
        }

      //  if receiving data is "toogle" string
      if (s == "toogle"){
        led_stt = ! led_stt;

        digitalWrite(LED_PIN, led_stt);
      }
    }
}

void loop() {
  
  read_uart();

  //  read button pin
  if (digitalRead(BUTTON_PIN) == 0){
    delay(150); //  debounce time

      if(digitalRead(BUTTON_PIN) == 0){
        Serial.println("toogle");  
      }
  }
}
