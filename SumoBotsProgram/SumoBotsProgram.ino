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

#define s0 4
#define s1 5
#define s2 6
#define s3 7
#define outPin 8

int red;
int blue;
int grn;
String color = "";

float avgRed = 0;
float avgGreen = 0;
float avgBlue = 0;


void whiteAvoidance()
{
  readRGB();

  //Reading for white color pattern and performing avoidance
  if(red > 8 && red < 18 && grn > 9 && grn < 19 && blue > 8 && blue < 16)
  {
    //TODO: CODE FOR MOVEMENT
  }
}

void trackMovement(int motorMode)
{
  if (motorMode == 0)
  {
    
  }
  else if (motorMode == 1)
  {
    
  }
  else if (motorMode == 2)
  {
    
  }
}

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


void setup() 
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT);
  
  //Initializing the frequency scaling to 100% for more accuracte color detection.
  digitalWrite(s0,HIGH);
  digitalWrite(s1, HIGH);

}


void loop()
{
  whiteAvoidance();
}
