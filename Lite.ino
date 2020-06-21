/* === Lite ===*/

#define LITE_R  10
#define LITE_G  11
#define LITE_B  12

#define START_VALUME 0
#define STEP 1 
#define Pi 3.1415192654

double r,g,b;
#define R 128.
#define G 128.
#define B 128.
#define TAU 100.
#define SIGMA_R 0.5
#define SIGMA_G 0.5
#define SIGMA_B 0.5

void setup() {
  Serial.begin(9600);
  pinMode(LITE_R, OUTPUT);
  pinMode(LITE_G, OUTPUT);
  pinMode(LITE_B, OUTPUT);
  r=128.;
  g=128.;
  b=128.;
}


void loop() {
  //dx/dt = (X-x)/tau + random
  //x[n+1] = x[n] + (X-x)/tau + random
  r = r + (R-r)/TAU +   SIGMA_R*(random(0,255)-R);
  g = g + (R-g)/TAU + SIGMA_G*(random(0,255)-G);
  b = b + (B-b)/TAU + SIGMA_B*(random(0,255)-B);
  if (r<0) r=0.;
  if(r>255) r= 255.;
  if (g<0) g=0.;
  if(g>255) g= 255.;
  if (b<0) b=0.;
  if(b>255) b= 255.;

  analogWrite(LITE_R, (int)r);
  analogWrite(LITE_G, (int)g);
  analogWrite(LITE_B, (int)b);
  Serial.print("r = "); Serial.print(r); Serial.print("\n");
  Serial.print("g = "); Serial.print(g); Serial.print("\n");
  Serial.print("b = "); Serial.print(b); Serial.print("\n");

  delay(500);
}
