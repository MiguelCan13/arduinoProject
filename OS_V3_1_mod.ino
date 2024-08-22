#include <MaxMatrix.h>
#include <FastLED.h>


//#define visorSensor

//Right side of the helmet
char test[] = {8, 8, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111};
char noseRight[] =  {8, 8, B00000000, B00000000, B10000000, B11000000, B11000000, B11111100, B01111110, B00000000};
char icon01[] =     {8, 8, B00100000,B01111000,B11011110,B11000111,B11111111,B00000000,B00000000,B00000000};
char icon02[] =     {8, 8, B00000000,B00000000,B00000000,B10000000,B11100000,B01111000,B00011110,B00000111};
char icon03[] =     {8, 8,  B00000000,B00000000,B00000000,B00000000,B00000111,B00011110,B01111000,B11100000};
char icon04[] =     {8, 8, B00000000,B00000000,B00000000,B11100000,B11111000,B00011110,B00000111,B00000001};
char Glitch01[] =   {8, 8, B00001100, B00000000, B11010100, B10001001, B00010100, B01000111, B11010001, B10100101};
char Glitch011[] =  {8, 8, B00000000, B00000000, B00000000, B11010101, B10000101, B11101010, B00010111, B00000100};
char Glitch02[] =   {8, 8, B01110100, B00000000, B01001011, B10010110, B00010010, B00000000, B00000000, B00000000};
char Glitch022[] =  {8, 8, B10100010, B01010100, B10000110, B00010010, B00000101, B00000000, B00000000, B00000000};
char Glitch03[] =   {8, 8, B00101001, B10101001, B01001011, B00101100, B01110100, B00000000, B00000000, B00000000};
char Glitch033[] =  {8, 8, B01001101, B10011010, B01101001, B10100000, B00001000, B00000000, B00000000, B00000000};
char Glitch04[] =   {8, 8, B00000000, B00000000, B10010101, B10011010, B10010111, B11101010, B10111010, B11010000};
char Glitch044[] =  {8, 8, B00000000, B00000000, B10001000, B10101010, B00011011, B10010101, B00000001, B00000000};
char Eye02[] =      {8, 8, B00000000, B00000000, B00000110, B00001111, B11111111, B11111110, B11111100, B11110000};
char Eye01[] =      {8, 8, B00000000, B00000000, B10000000, B11100000, B01111111, B00011111, B00000111, B00000000};
char Angry1[] =     {8, 8, B00000000, B00000001, B00000111, B00011111, B00111111, B01111111, B00111111, B00000000};
char Angry2[] =     {8, 8, B00000000, B11000000, B11110000, B11111000, B11111100, B11111100, B11111000, B00000000};
char Spooked1[] =   {8, 8, B10000000, B11100000, B11100000, B11110000, B11110000, B11100000, B11100000, B10000000};
char Spooked2[] =   {8, 8, B00000001, B00000111, B00000111, B00001111, B00001111, B00000111, B00000111, B00000001};
char mouthR[] = {8, 8, B00000000, B00000000, B10010000, B11110000, B11110000, B11110110, B01111010, B01111110};

//Left side of the helmet
char noseLeft[] =   {8, 8, B00000000, B00000000, B00000001, B00000011, B00000011, B00111111, B01111110, B00000000};
char icon01L[] =    {8, 8, B00001000, B00011110, B01111011, B11100011, B11111111, B00000000, B00000000, B00000000};
char icon02L[] =    {8, 8, B00000000, B00000000, B00000000, B00000001, B00000111, B00011110, B01111000, B11100000};
char icon03L[] =    {8, 8, B00000000, B00000000, B00000000, B00000000, B11100000, B01111000, B00011110, B00000111};
char icon04L[] =    {8, 8, B00000000, B00000000, B00000000, B00000111, B00011111, B01111000, B11100000, B10000000};
char Glitch01L[] =  {8, 8, B10100101, B11010001, B01000111, B00001010, B10001001, B11010100, B00001100, B00000000};
char Glitch011L[] = {8, 8, B00000000, B00000000, B00000000, B10101011, B10100001, B01010111, B11101000, B00100000};
char Glitch02L[] =  {8, 8, B00000000, B00000000, B00000000, B00000000, B00010010, B10010110, B01001011, B01110100};
char Glitch022L[] = {8, 8, B00000000, B00000000, B00000000, B00000101, B00010010, B10000110, B01010100, B10100010};
char Glitch03L[] =  {8, 8, B00000000, B00000000, B00000000, B01110100, B00101100, B01001011, B10101001, B00101001};
char Glitch033L[] = {8, 8, B00000000, B00000000, B00000000, B00001000, B10100000, B01101001, B10011010, B01001101};
char Glitch04L[] =  {8, 8, B00000000, B00000000, B10101001, B01011001, B11101001, B01010111, B01011101, B00001011};
char Glitch044L[] = {8, 8, B00000000, B00000000, B00010001, B00000110, B01010101, B11011000, B10101001, B10000000};
char Eye02L[] =     {8, 8, B00000000, B00000000, B01100000, B11110000, B11111111, B01111111, B00111111, B00001111}; 
char Eye01L[] =     {8, 8, B00000000,B00000000,B00000001,B00000111,B11111110,B11111000,B11100000,B00000000};//new: B00000000,B00000000,B00000001,B00000111,B11111110,B11111000,B11100000,B00000000 old:B01110000, B01110000, B01110000, B00110000, B00110000, B00011000, B00011000, B00001100
char Angry2L[] =    {8, 8, B00000000, B10000000, B11100000, B11111000, B11111100, B11111110, B11111100, B00000000};
char Angry1L[] =    {8, 8, B00000000, B00000011, B00001111, B00011111, B00111111, B00111111, B00011111, B00000000};
char Spooked1L[] =  {8, 8, B10000000, B11100000, B11100000, B11110000, B11110000, B11100000, B11100000, B10000000};
char Spooked2L[] =  {8, 8, B00000001, B00000111, B00000111, B00001111, B00001111, B00000111, B00000111, B00000001};
char mouthL[] = {8, 8, B00000000, B00000000, B00001001, B00001111, B00001111, B01101111, B01011110, B01111110};

const int interruptPin = 2;
//const int interruptPin2 = 3;
volatile long debounceTime = 0;
volatile long currentTime = 0;

int redPin = 5; 
int greenPin = 11;
int bluePin = 9;


int DIN = 6;   // DIN pin of MAX7219 module
int CLK = 7;   // CLK pin of MAX7219 module
int CS = 8;    // CS pin of MAX7219 module
int maxInUse = 16; 
byte counter = 0;
byte counter2 = 0;
int column1L = 120;
int column2L = 128;
int column3L = 111;
int column4L = 119;
int column1 = 8;
int column2 = 16;
int column3 = -1;
int column4 = 7;
int state = 0;
//int state2;
int stateSerial;

MaxMatrix m(DIN, CS, CLK, maxInUse);

#define LED_PIN     3
#define NUM_LEDS    26
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

void setup() {                        //starting up sequence
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
  randomSeed(analogRead(0));
  m.init();
  m.setIntensity(0);   //brightness
  m.clear();
  pinMode(interruptPin, OUTPUT);
  digitalWrite(2, HIGH);
  attachInterrupt(digitalPinToInterrupt(2), ISR_button, FALLING);

  //side LED:
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

}


void loop() {                        //This is where the program loop starts.
    FastLED.delay(1000 / UPDATES_PER_SECOND);
    for( int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CRGB::Fuchsia;
    }
    if (stateSerial == '0') {
      state = 0;
    }
    if (stateSerial == '1') {
      state = 1;
    }
    if (stateSerial == '2') {
      state = 2;
    }
    m.writeSprite(104, 0, icon01L);          
    m.writeSprite(96, 0, icon02L);
    m.writeSprite(88, 0, icon03L);
    m.writeSprite(80, 0, icon04L);
    m.writeSprite(72, 0, noseLeft);
    m.writeSprite(64, 0, mouthR);
    m.writeSprite(56, 0, mouthL);
    m.writeSprite(48, 0, noseRight);
    
    m.writeSprite(40, 0, icon04);
    m.writeSprite(32, 0, icon03);
    m.writeSprite(24, 0, icon02);
    m.writeSprite(16, 0, icon01);
    


    if (counter2 > 17) {                    //The blinking animation begins here
      for (int i = 0; i < 5; i++) {
        column1L = column1L - 1;
        column2L = column2L - 1;
        column1 = column1 - 1;
        column2 = column2 - 1;
        column3L = column3L + 1;
        column4L = column4L + 1;
        column3 = column3 + 1;
        column4 = column4 + 1;
        m.setColumn(column1L, B00000000);
        m.setColumn(column2L, B00000000);
        m.setColumn(column3L, B00000000);
        m.setColumn(column4L, B00000000);

        m.setColumn(column1, B00000000);
        m.setColumn(column2, B00000000);
        m.setColumn(column3, B00000000);
        m.setColumn(column4, B00000000);
        delay(15);
        counter2++;
      }
      column1L = 120;
      column2L = 128;
      column3L = 111;
      column4L = 119;
      column1 = 8;
      column2 = 16;
      column3 = -1;
      column4 = 7;
      counter2 = 0;
    }
    counter2++;
    Serial.print(("Expression #"));
    Serial.println(state);

    switch (state) {                      //Happy
      case 0:
        m.writeSprite(120, 0, Eye01L);
        m.writeSprite(112, 0, Eye02L);
        m.writeSprite(8, 0, Eye02);
        m.writeSprite(0, 0, Eye01);
        setColor(0, 32, 0);               //green
        break;

      case 1:                             //Surprised
        m.writeSprite(120, 0, Spooked1L);
        m.writeSprite(112, 0, Spooked2L);
        m.writeSprite(8, 0, Spooked1);
        m.writeSprite(0, 0, Spooked2);
        setColor(0, 0, 8);              //blue
        break;

      case 2:                             //Angry
        m.writeSprite(120, 0, Angry2L);
        m.writeSprite(112, 0, Angry1L);
        m.writeSprite(8, 0, Angry2);
        m.writeSprite(0, 0, Angry1);
        setColor(16, 0, 0);               //red
        counter++;

        if (counter == 16) {
          m.writeSprite(80, 0, Glitch044L);
          m.writeSprite(88, 0, Glitch033L);
          m.writeSprite(96, 0, Glitch022L);
          m.writeSprite(104, 0, Glitch011L);
          m.writeSprite(16, 0, Glitch011);
          m.writeSprite(24, 0, Glitch022);
          m.writeSprite(32, 0, Glitch033);
          m.writeSprite(40, 0, Glitch044);
          delay(75);
          counter++;
        }
        if ((counter >= 17) && (counter < 18)) {
          m.writeSprite(104, 0, icon01L);
          m.writeSprite(96, 0, icon02L);
          m.writeSprite(88, 0, icon03L);
          m.writeSprite(80, 0, icon04L);
          m.writeSprite(40, 0, icon04);
          m.writeSprite(32, 0, icon03);
          m.writeSprite(24, 0, icon02);
          m.writeSprite(16, 0, icon01);
          delay(200);
          counter++;
        }
        if (counter >= 18) {
          m.writeSprite(80, 0, Glitch04L);
          m.writeSprite(88, 0, Glitch03L);
          m.writeSprite(96, 0, Glitch02L);
          m.writeSprite(104, 0, Glitch01L);
          m.writeSprite(16, 0, Glitch01);
          m.writeSprite(24, 0, Glitch02);
          m.writeSprite(32, 0, Glitch03);
          m.writeSprite(40, 0, Glitch04);
          delay(75);
          counter = 0;
        }
        break;

    }
}



void ISR_button() {                               
  currentTime = millis();
  if ((currentTime - debounceTime) > 250) {
    if (state < 2) {
      state++;
    }
    else {
      state = 0;
    }
  }
  debounceTime = currentTime;
}


void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
