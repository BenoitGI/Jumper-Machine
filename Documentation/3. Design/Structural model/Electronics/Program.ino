#include <AccelStepper.h> // library to control the steppers
#include <LiquidCrystal_I2C.h> // Library to control the screen

LiquidCrystal_I2C lcd(0x27, 16, 2); // Define the screen size

// Distribution stepper
int dir_pin = 4 ;
int step_pin = 3 ;

// Cutting stepper
int dir_pin2 = 6 ;
int step_pin2 = 7 ;

// set the pins to read the inputs of the joystick
int VRx = A0;
int VRy = A1;
int btn_dem = 9;

// Variables to read joystick values
int xPosition = 0;
int yPosition = 0;
int mapX = 0;
int mapY = 0;

// Led pins
const int led_Vert = 12 ;
const int led_Red = 10 ;
const int led_Jaune = 11 ;

// Wire detection pin
const int btn_cable = 2;

const int step_per_rev1 = 3200; // number of steps per revolution, here we multiply by 16
const int step_per_rev2 = 3200; // number of steps per revolution, here we multiply by 16

int dem; // variable to register the state of the joystick button
int menu = 0; // variable to navigate between menus
int urgence = false; //variable to signal a problem when it's 1

int position_came = 0; // Variable to controle the position of the stepper when setting the blade for stripping
int position_denude = 0; // variable to save the stripping position of the stepper
int distance_denude = 7; // define the length of wire to expose on both side of the jumper, here 8 mm
int longueur_cable = 3; // variable for the length of sheath to leave on the wire, proportional to the number of pins it would cover on a breadboard
int nbr_jumper = 1; // define the number of jumpers to cut, initialized to 1

//define the steppers with the accel stepper library
AccelStepper stepper1(1, step_pin, dir_pin);
AccelStepper stepper2(1, step_pin2, dir_pin2);

void setup(){
  lcd.init(); // initialize the screen
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(btn_dem, INPUT_PULLUP);
  
  pinMode(led_Vert, OUTPUT);
  pinMode(led_Red, OUTPUT);
  pinMode(led_Jaune, OUTPUT);
  digitalWrite(led_Vert, LOW);
  digitalWrite(led_Red, LOW);
  digitalWrite(led_Jaune, LOW);

  pinMode(btn_cable, INPUT_PULLUP);
  
  Serial.begin(9600) ;

  stepper1.setMaxSpeed(7000); //SPEED = Steps / seconde
  stepper1.setAcceleration(6000); //ACCELERATION = Steps / seconde^2
  stepper1.setCurrentPosition(0);
  
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(6000);
  stepper2.setCurrentPosition(0);
  }

void loop(){
  lcd.backlight();
  cable_detect();

  if (urgence == true){
    digitalWrite(led_Red, HIGH); // the ssystem has an issue with the wire
    digitalWrite(led_Vert,LOW);
    digitalWrite(led_Jaune,LOW);

    lcd.setCursor(0,0);
    lcd.print("No wire         ");
    lcd.setCursor(0,1);
    lcd.print("           ");
  }
  
  else{
    digitalWrite(led_Red, LOW); // the system has no issue with the wire
    digitalWrite(led_Vert,HIGH); // the system works, but no program runs, we light the green LED
    digitalWrite(led_Jaune,LOW); // the yellow LED will light when executing a program running at least one of the steppers
    
    dem = false;
    button_detect();
    get_position_joystick();
    change_menu();
    enter_menu();
  }
}

void cable_detect(){      // Check the presence of wire
  if (digitalRead(btn_cable) == HIGH){
    urgence = true;
  }
  else{
    urgence = false;
  }
}

void button_detect(){
  if (digitalRead(btn_dem) == LOW){     // read the pullup of the joystick's button
    dem = not(dem);
  }
  delay(150);
}

void get_position_joystick(){     // get cordinates of the joystick and map them around zero
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  mapX = map(xPosition, 0, 1023, -512, 512);   // Map the values of the joystick around 0
  mapY = map(yPosition, 0, 1023, -512, 512);
}

void change_menu(){                         // change the menu with the x coordinates of the joystick
  if ((mapX>=100)&&(mapY>=-175)&& (mapY<=175)){
    if (menu <= 4){
      menu += 1;
      if (menu == 5){
        menu = 0;
      }
    }
  }
  
  if ((mapX<=-100)&&(mapY>=-175)&& (mapY<=175)){
    if (menu >= 0){
      menu -= 1;
      if (menu == -1){
        menu = 4;
      }
    }
  }
  
  delay(150);
}

void enter_menu(){          // will execute the functions of a menu if the user pressed the button of the joystick
  // Menu 0: feed some wire if executed
  if (menu == 0){
    lcd.setCursor(0,0);
    lcd.print("Push wire       ");
    lcd.setCursor(0,1);
    lcd.print("           ");
    
    if (dem){
      lcd.setCursor(0,1);
      lcd.print("Executing       ");
      digitalWrite(led_Jaune,HIGH);
      digitalWrite(led_Vert,LOW);
      distribution(110);
    }
  }

  // Menu 1: Change the number of jumper we want
  if (menu == 1){
    lcd.setCursor(0,0);
    lcd.print("Nbr Jumper:  OUT");
    lcd.setCursor(0,1);
    lcd.print(nbr_jumper);
    lcd.setCursor(String(nbr_jumper).length(),1);
    lcd.print("     ");
    if (dem){
      define_jumper_nbr();
    }
  }

  // Menu 2: Change the length of the jumpers we want
  if (menu == 2){
    lcd.setCursor(0,0);
    lcd.print("Len  Jumper: OUT");
    lcd.setCursor(0,1);
    lcd.print(longueur_cable + 2);
    lcd.setCursor(String(longueur_cable + 2).length(),1);
    lcd.print("     ");
    if (dem){
      define_jumper_long();
    }
  }

  // Menu 3: will set the position of the blade for stripping
  if (menu == 3){
    lcd.setCursor(0,0);
    lcd.print("Set denude:  OUT");
    lcd.setCursor(0,1);
    lcd.print(position_denude);
    lcd.setCursor(String(position_denude).length(),1);
    lcd.print("     ");
    if (dem){
      digitalWrite(led_Jaune,HIGH);
      digitalWrite(led_Vert,LOW);
      define_denude();
    }
  }

  // Menu 4: Cut the jumpers if executed
  if (menu == 4){
    lcd.setCursor(0,0);
    lcd.print("Program         ");
    lcd.setCursor(0,1);
    lcd.print("             ");
    if (dem){
      digitalWrite(led_Jaune,HIGH);
      digitalWrite(led_Vert,LOW);
      lcd.setCursor(0,0);
      lcd.print("Cutting jumper: ");

      // To show the numbers of jumper to cut
      lcd.setCursor(0,1);
      lcd.print("1 over ");
      lcd.setCursor(7,1);
      lcd.print(nbr_jumper);
      
      programme_jumper(nbr_jumper);
      dem = not(dem);
    }
  }
} 

void distribution(float distance){  // feed cable with a given distance in mm
  stepper1.moveTo(step_per_rev1 * distance / (10.3 * 3.14159265)); // 12.24 is the value mesured of the diameter from the extruder
  stepper1.runToPosition();
  stepper1.setCurrentPosition(0);
  delay(100);
}

void coupe(){
  stepper2.moveTo(step_per_rev2); // make a complete turn of the motor to cut
  stepper2.runToPosition();
  stepper2.setCurrentPosition(0);
  delay(100);
}

void define_jumper_nbr(){  // while there's no press of the button we can change the values with y coordinates of the joystick
  while (dem){ //
    get_position_joystick();
    change_nbr_jumper();  // change the value of nbr_jumper
    button_detect();
  }
  delay(100);
}

void change_nbr_jumper(){  // read the joystick coordinates to change the number of jumper
  
  if ((nbr_jumper < 500) && (mapY>=20)){
    if (mapY>= 470){      // add one jumper at the time if the joystick is lean to the extreme
      nbr_jumper += 10;
    }
    else{              // add one jumper at the time if the joystick is lean lightly
      nbr_jumper += 1;
    }
  }
  if (nbr_jumper > 500){   // Jumper high limit
    nbr_jumper = 500;
  }
  
  if ((nbr_jumper > 1) && (mapY<=-20)){  // same as before but suppress jumpers
    if (mapY <=-470){
      nbr_jumper -= 10;
    }
    else{
      nbr_jumper -= 1;
    }
  }
  if (nbr_jumper < 1){  // Jumper low limit
    nbr_jumper = 1;
  }
  
  lcd.setCursor(0,0);
  lcd.print("Nbr Jumper:   IN");
  lcd.setCursor(0,1);
  lcd.print(nbr_jumper);
  lcd.setCursor(String(nbr_jumper).length(),1); // add spaces to avoid flickering on the screen
  lcd.print("     ");
  delay(100);
}

void define_jumper_long(){
  while (dem){    // while there's no press of the button we can change the values with y coordinates of the joystick
    get_position_joystick();
    change_long_jumper();  // change the value of longueur_cable
    button_detect();
  }
  delay(100);
}

void change_long_jumper(){
  if ((mapY>=100) && (longueur_cable < 15)){  // add jumpers if the value is under the limit
    longueur_cable += 1;
  }
  if ((longueur_cable > 1) && (mapY<=-100)){  // remove jumpers if the value is above the limit
    longueur_cable -= 1;
  }
  lcd.setCursor(0,0);
  lcd.print("Len Jumper:   IN");
  lcd.setCursor(0,1);
  lcd.print(longueur_cable + 2);
  lcd.setCursor(String(longueur_cable + 2).length(),1); // spaces to avoid flickering
  lcd.print("     ");
  delay(100);
}

void define_denude(){
  lcd.setCursor(0,0);
  lcd.print("Set denude:   IN");
  while (dem){        // while there's no press of the button we can change the values with y coordinates of the joystick
    get_position_joystick();
    change_pos_came();      // change the value of position_came
    stepper2.moveTo(position_came);
    stepper2.runToPosition();
    button_detect();
  }
  
  position_denude = position_came; //when the button is pressed we register the value for stripping
  position_came = 0;  // resetting the stepper to initial position
  stepper2.moveTo(position_came);
  stepper2.runToPosition(); // then we set the came back to its initial position
}

void change_pos_came(){
  if (((position_came > 0) || ((position_came <= 0) && (mapY > 0)))&& (abs(mapY)>15)){ // will allow to set the position only in the direction the came turns
    position_came += 0.1 * mapY;   // the more we push the joystick in one way, the more steps it will make the mottor move
  }
  lcd.setCursor(0,1);
  lcd.print(position_came);
  lcd.setCursor(String(position_came).length(),1); // spaces to avoid flickering
  lcd.print("     ");
  delayMicroseconds(100);
}

void denude(int pattes){

  stepper2.moveTo(position_denude);  // move the stepper to the position to cut the sheath
  stepper2.runToPosition();

  stepper2.moveTo(position_denude-160); // step back to retain the sheath but not bite into the core
  stepper2.runToPosition();
  delayMicroseconds(1000);
  
  if (pattes == 2){
    distribution(-distance_denude * pattes - 10); // pull the sheath whether we pull it completly, thus the steps added (pattes = 2) or we are centering it (pattes = 1)
  }
  else{
    distribution(-distance_denude * pattes);
  }
  delayMicroseconds(1000);
  
  stepper2.moveTo(-2); // come back to initial position + some offset to compensate an error
  stepper2.runToPosition();
  delay(100);
}

void programme_jumper(int nbr_jumper){
  coupe(); // cut the tip of the wire to ensure to cut the first one to the good length
  
  for (int i=0; i <= nbr_jumper-1; i++){
    
    cable_detect(); // run the program only if the machine has wire
    if (urgence == true){
      menu = 0;
      break;
    }

    lcd.setCursor(0,1);
    lcd.print(i+1);
    lcd.setCursor(String(i+1).length(), 1);
    lcd.print(" over ");
    lcd.setCursor(String(i+1).length() + 6, 1);
    lcd.print(nbr_jumper);
    
    distribution(distance_denude * 2); // feed the wire the double the length to strip
    denude(2); // strip the double lentgh defined before
    distribution(distance_denude * 2 + longueur_cable * 2.54 + 10); // feed the cable to the end of the jumper
    denude(1); // centers the sheath
    distribution(distance_denude); // feed the cable to the end of the jumper + some offset so that there no sheath left on the jumper
    coupe();   // cut a jumper
    delay(100);
  }
  
  lcd.setCursor(0,1);
  lcd.print("            "); // reset the second line when over
}
