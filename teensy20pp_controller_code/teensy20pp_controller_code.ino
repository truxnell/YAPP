// YAPP
// Yet Another Portable PI
// Teensy 2.0++ code for handheld controls and other functions
// Buttons map as joystick, with keyboard for triggerhappy calls

// Define pins

// D-PAD
int DP_UP = 14;       //C4
int DP_DOWN = 15;     //C5
int DP_LEFT = 16;     //C6
int DP_RIGHT = 17;    //C7

// ABXY
int BTN_A = 10;       //C0
int BTN_B = 11;       //C1
int BTN_X = 12;       //C2
int BTN_Y = 13;       //C3


//Define Joystick button responses
int BTN_A_JOY = 1;
int BTN_B_JOY = 2;
int BTN_X_JOY = 3;
int BTN_Y_JOY = 4;

void setup() {

  // Serial for debugging
  Serial.begin(9600);
  
  // Setup pinouts
  
  // DPAD
  pinMode(DP_UP, INPUT_PULLUP);
  pinMode(DP_DOWN, INPUT_PULLUP);
  pinMode(DP_LEFT, INPUT_PULLUP);
  pinMode(DP_RIGHT, INPUT_PULLUP);

  // DPAD
  pinMode(BTN_A, INPUT_PULLUP);
  pinMode(BTN_B, INPUT_PULLUP);
  pinMode(BTN_X, INPUT_PULLUP);
  pinMode(BTN_Y, INPUT_PULLUP);

}

void loop() {

  // Make Joystick buttons only send when called
  Joystick.useManualSend(true);
  
  // Main Loop
  for (;;) {

    // ABXY
    //Joystick.button(BTN_A_JOY,digitalRead(BTN_A));
    Joystick.button(BTN_A_JOY,!digitalRead(BTN_A));
    // Send joystick button presses simeltaneously.
    Joystick.send_now();
  }


}
