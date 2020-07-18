#define RED_LED 9
#define GREEN_LED 10
#define BLUE_LED 11

void setup(){
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  analogWrite(RED_LED, 0);
  analogWrite(GREEN_LED, 0); 
  analogWrite(BLUE_LED, 0); // zato jer je sink, 255 predstavlja 0
  Serial.begin(115200);
}

void loop(){
  if(Serial.available()){
    char led_specifier = Serial.read();
    int led_brightness = Serial.parseInt();
    write_leds(led_specifier, led_brightness);
    }
}

void write_leds(char led, int brightness){
  if(led == 'r'){
    analogWrite(RED_LED, 0 + brightness);
    return;
  }
  if(led == 'g'){
    analogWrite(GREEN_LED, 0 + brightness);
    return;
  }
  if(led == 'b'){
    analogWrite(BLUE_LED, 0 + brightness);
    return;
  }
  return;
}
