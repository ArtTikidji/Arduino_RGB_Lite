/* === Arduino_RGB_Lite  ===*/

#define LITE_R  10
#define LITE_G  11
#define LITE_B  12

#define START_VALUME 0
#define STEP 1 
#define Pi 3.1415192654


#define R 128.
#define G 128.
#define B 128.
#define TAU 100.
#define SIGMA_R 0.5
#define SIGMA_G 0.5
#define SIGMA_B 0.5

double r,g,b;

void setup() {
  Serial.begin(9600);
  pinMode(LITE_R, OUTPUT);
  pinMode(LITE_G, OUTPUT);
  pinMode(LITE_B, OUTPUT);
  r=128.;
  g=128.;
  b=128.;
}

// функция плавного перехода между цветами
void fluensy(double rOld, double gOld, double bOld, int timeMs){
  int stepCount = 10;
  double rStep = (r - rOld)/stepCount;
  double gStep = (g - gOld)/stepCount;
  double bStep = (b - bOld)/stepCount;
  for(int i = 0; i < stepCount; ++i){
    analogWrite(LITE_R, (int)(rOld + rStep*i));
    analogWrite(LITE_G, (int)(gOld + gStep*i));
    analogWrite(LITE_B, (int)(bOld + bStep*i));
    delay(timeMs/stepCount+1);
  }
  analogWrite(LITE_R, (int)r);
  analogWrite(LITE_G, (int)g);
  analogWrite(LITE_B, (int)b);
}


void loop() {
  
  double rOld = r, gOld = g, bOld = b;
  
  //dx/dt = (X-x)/tau + random
  //x[n+1] = x[n] + (X-x)/tau + random
  r = r + (R-r)/TAU +   SIGMA_R*(random(0,255)-R);
  g = g + (R-g)/TAU + SIGMA_G*(random(0,255)-G);
  b = b + (B-b)/TAU + SIGMA_B*(random(0,255)-B);
  
  // проверки на выход за пределы допустимых 
  // значений [0..255] 
  if (r<0) r=0.;
  if(r>255) r= 255.;
  if (g<0) g=0.;
  if(g>255) g= 255.;
  if (b<0) b=0.;
  if(b>255) b= 255.;

  fluensy(rOld, gOld, bOld, 500);
  
  Serial.print("r = "); Serial.print(r); Serial.print("\n");
  Serial.print("g = "); Serial.print(g); Serial.print("\n");
  Serial.print("b = "); Serial.print(b); Serial.print("\n");

  delay(500);
}
