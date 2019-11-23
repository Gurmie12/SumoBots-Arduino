/* AUTHORS: Gurman Brar, Eknoor Singh, Jagroop Gill
 * DATE: NOV.19 - NOV.24
 * PURPOSE: Create an autonomous sumo bot that is able to defend,
 * attack and move on its own, responding to different 
 * sensory feedback from its enviroment. Created to compete at the Sumo
 * Bots advanced robotics competition at McMaster university
 */


/*TO DO:
* Create Function for left turn
* Create a function for right turn
* Create a function for attacking
* Create function for defense
* Create function for ultrasonic sensor (F,R,L)  
* Create function for PIR sensor 
*/


// Colour Sensor
//#define s0 0
//#define s1 1
#define s2 0
#define s3 1
#define outPin 2

// Motor A
 
int enA = 9;
int in1 = 8;
int in2 = 7;
 
// Motor B
 
int enB = 3;
int in3 = 5;
int in4 = 4;

//UltraSonic Sensor - FRONT - 

int trigPinF = 10;
int echoPinF = 11;

//UltraSonic Sensor - RIGHT - 

int trigPinR = 12;
int echoPinR = 13;

//Colour Values for Colour Sensor
int red;
int blue;
int grn;
String color = "";

float avgRed = 0;
float avgGreen = 0;
float avgBlue = 0;

//Function that reads the RGB components of the color by taking an average to reduce error
void readRGB()
{
  red = 0;
  grn = 0;
  blue = 0;
  int iter = 10;
  
  //Loop the RGB check 3 times to find an average and avoid any partial errors
  for(int i = 0; i < iter; i++)
  {
  
  // By setting s2 and s3 to low we are reading for red components of light.
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  red = red + pulseIn(outPin, LOW);

  // By setting s2 and s3 to low we are reading for green components of light.
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  grn = grn + pulseIn(outPin, LOW);

  // By setting s2 and s3 to low we are reading for blue components of light.
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  blue = blue + pulseIn(outPin, LOW);
}
  //Taking the average
  red = red / iter;
  grn = grn / iter;
  blue = blue / iter;
}

//Function that finds a white line directly under the robot and does tasks accordingly
void whiteAvoidance()
{
  readRGB();

  //Reading for white color pattern and performing avoidance
  if(red > 8 && red < 18 && grn > 9 && grn < 19 && blue > 8 && blue < 16)
  {
    //TODO: CODE FOR MOVEMENT
  }
}

//Basic track movement, foward, pivoting, and reverse
void motion(int motorMode, int scale)
{
  if (motorMode == 0) //Forward
  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, 10 * scale);
  analogWrite(enB, 10 * scale);
  }
  else if (motorMode == 1) //Left or Right
  {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, 10 * scale);
  analogWrite(enB, 10 * scale);
  }
  else if (motorMode == 2)//Left or Right
  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, 10 * scale);
  analogWrite(enB, 10 * scale);
  }
  else if (motorMode == 3) //Reverse
  {
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, 10 * scale);
  analogWrite(enB, 10 * scale);
  }
}

 //Object detection method that takes parameters of a tring and echo pin value and return weather an
 //object is detected or not and returns an int.
int objectDetection(int trig, int echo)
{
 //Declaring pins for UltraSonic Sensor 
 digitalWrite(trig, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trig, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trig, LOW);

 float duration = pulseIn(echo, HIGH);

 //Using a formula, finding the distance of the object
 float distance = (duration*.0343)/2;

 //Varify that the distance is within the rings total diameter
 if(distance <= 154.0 && distance > 0.0)
 {
 Serial.print("Distance: ");
 Serial.println(distance);
 delay(50); 
 return 1;
 }
 else return 0;
 }

void attacking()
{
   while(objectDetection(trigPinF, echoPinF) == 0 && objectDetection(trigPinR, echoPinR) == 0)
   {
     motion(2, 5);
   }
}


void setup() 
{
  //Colour Sensor pin declaration
  //pinMode(s0, OUTPUT);
  //pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT);

  //Initializing the frequency scaling to 100% for more accuracte color detection.
  //digitalWrite(s0,HIGH);
  //digitalWrite(s1, HIGH);
  
  //Motor pin declaration
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //Ultra-Sonic pin declaration
  pinMode(trigPinF, OUTPUT); 
  pinMode(echoPinF, INPUT); 

  pinMode(trigPinR, OUTPUT); 
  pinMode(echoPinR, INPUT); 
}


void loop()
{
   whiteAvoidance();
}
