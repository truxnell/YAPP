// YAPP
// Yet Another Portable PI
// Teensy 2.0++ code for handheld controls and other functions
// Buttons map as joystick, with keyboard for triggerhappy calls
//
// Code inspired by:
// Nintimdo-RP https://github.com/timlindquist/Nintimdo-RP
// dc740 https://github.com/dc740/Game-port-to-USB-joystick-converter

// Joystick variables
int L_X_CENTER = 0;
int L_Y_CENTER = 0;
int R_X_CENTER = 0;
int R_Y_CENTER = 0;

int L_X_MIN = 0;
int L_X_MAX = 0;
int L_Y_MIN = 0;
int L_Y_MAX = 0;


// Define pins

// D-PAD
int BTN_UP = 14;        //C4
int BTN_DOWN = 15;       //C5
int BTN_LEFT = 16;       //C6
int BTN_RIGHT = 17;      //C7

// ABXY
int BTN_A = 10;         //C0
int BTN_B = 11;         //C1
int BTN_X = 12;         //C2
int BTN_Y = 13;         //C3

// Misc
int BTN_START = 8;      //PE0
int BTN_SELECT = 9;     //PE1
int BTN_HOME = 7;       //PD7
int BTN_PWR = 5;        //PD5

// Triggers
int BTN_LBUTTON = 18;   //PE6
int BTN_LTRIGGER = 19;  //PE7
int BTN_RTRIGGER = 42;  //PF4
int BTN_RBUTTON = 43;   //PF5

// Analog sticks
int STICK_L_X = 38;     //PF0
int STICK_L_Y = 39;     //PF1
int STICK_R_X = 40;     //PF2
int STICK_R_Y = 41;     //PF3

//Define Joystick button responses
//D-PAD
int BTN_UP_JOY = 1;
int BTN_DOWN_JOY = 2;
int BTN_LEFT_JOY = 3;
int BTN_RIGHT_JOY = 4;

//ABXY
int BTN_A_JOY = 5;
int BTN_B_JOY = 6;
int BTN_X_JOY = 7;
int BTN_Y_JOY = 8;

// Misc
int BTN_START_JOY = 9;
int BTN_SELECT_JOY = 10;

// Triggers
int BTN_LBUTTON_JOY = 12;
int BTN_LTRIGGER_JOY = 13;
int BTN_RTRIGGER_JOY = 14;
int BTN_RBUTTON_JOY = 15;

void setup() {

  // Serial for debugging
  Serial.begin(9600);


  // Setup pinouts
  
  // DPAD
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);

  // ABXY
  pinMode(BTN_A, INPUT_PULLUP);
  pinMode(BTN_B, INPUT_PULLUP);
  pinMode(BTN_X, INPUT_PULLUP);
  pinMode(BTN_Y, INPUT_PULLUP);
  
  // Misc
  pinMode(BTN_START, INPUT_PULLUP);
  pinMode(BTN_SELECT, INPUT_PULLUP);
  pinMode(BTN_HOME, INPUT_PULLUP);
  pinMode(BTN_PWR, INPUT_PULLUP);

  // Triggers
  pinMode(BTN_LBUTTON, INPUT_PULLUP);
  pinMode(BTN_LTRIGGER, INPUT_PULLUP);
  pinMode(BTN_RBUTTON, INPUT_PULLUP);
  pinMode(BTN_RTRIGGER, INPUT_PULLUP);

  // Analog sticks
  pinMode(STICK_L_X, INPUT);
  pinMode(STICK_L_Y, INPUT);
  pinMode(STICK_R_X, INPUT);
  pinMode(STICK_R_Y, INPUT);

}

void loop() {

  // Make Joystick buttons only send when called
  Joystick.useManualSend(true);
  
  // Main Loop
  for (;;) {

    Serial.println(analogRead(STICK_L_X));
    Joystick.X(analogRead(-1*(STICK_L_X))); // Invert X axis
    Joystick.Y(analogRead(STICK_L_Y));

    Joystick.Z(analogRead(STICK_R_X));
    Joystick.Zrotate(analogRead(STICK_R_Y));
    
    // Poll buttons and map to joystick buttons
    // Since using pullups, invert the read states of button presses
    //D-PAD
    Joystick.button(BTN_UP_JOY,!digitalRead(BTN_UP));
    Joystick.button(BTN_DOWN_JOY,!digitalRead(BTN_DOWN));
    Joystick.button(BTN_LEFT_JOY,!digitalRead(BTN_LEFT));
    Joystick.button(BTN_RIGHT_JOY,!digitalRead(BTN_RIGHT));
    
    // ABXY
    Joystick.button(BTN_A_JOY,!digitalRead(BTN_A));
    Joystick.button(BTN_B_JOY,!digitalRead(BTN_B));
    Joystick.button(BTN_X_JOY,!digitalRead(BTN_X));
    Joystick.button(BTN_Y_JOY,!digitalRead(BTN_Y));

    // Misc
    Joystick.button(BTN_START_JOY,!digitalRead(BTN_START));
    Joystick.button(BTN_SELECT_JOY,!digitalRead(BTN_SELECT));

    //Triggers
    Joystick.button(BTN_LBUTTON_JOY,!digitalRead(BTN_LBUTTON));
    Joystick.button(BTN_LTRIGGER_JOY,!digitalRead(BTN_LTRIGGER));
    Joystick.button(BTN_RTRIGGER_JOY,!digitalRead(BTN_RTRIGGER));
    Joystick.button(BTN_RBUTTON_JOY,!digitalRead(BTN_RBUTTON));

    // Home button maps Start + Sel for quick game exit
    if(!digitalRead(BTN_HOME)) {
  
      // Overwrite above polled start/sel, simulate dual press
      Joystick.button(BTN_START,1);
      Joystick.button(BTN_SELECT,1);
      
    }

    
    // Send joystick button presses simeltaneously.
    Joystick.send_now();
  }


}

void calibrate_deadzone() {

  // Calibrate the Joystick deadzone upon boot

  int counter = 0;

  

  while ( counter < 200 ) {

    

    counter++;
    
  }
  
}

