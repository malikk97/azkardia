#include <Servo.h>
/* PIN LAYOUT
   kaki           siku           bahu
   -------------------------------------------
   1              30              31
   2              32              33
   3              34              35
   4               8               9
   5              10              11
   6              12              13
*/
Servo bahu[6];
Servo siku[6];

int bahu_pos[6][3];

int genap_kaki[3];
int ganjil_kaki[3];

const int depan=0; 
const int tengah=1;
const int belakang=2;

const int up=30;
const int down=70;
const int in=90;
const int out=20;


void register_servos() {
  // Kaitkan semua kaki ke pin yang sesuai dan rentang gerakan yang ada.
  genap_kaki[0] = 0;
  genap_kaki[1] = 2;
  genap_kaki[2] = 4;
  
  ganjil_kaki[0] = 1;
  ganjil_kaki[1] = 3;
  ganjil_kaki[2] = 5;
  
  siku[0].attach(30);
  bahu[0].attach(31);
  bahu_pos[0][depan] = 115;
  bahu_pos[0][tengah] = 130;
  bahu_pos[0][belakang] = 145;

  siku[1].attach(32);
  bahu[1].attach(33);
  bahu_pos[1][depan] = 75;
  bahu_pos[1][tengah] = 90;
  bahu_pos[1][belakang] = 105;

  siku[2].attach(34);
  bahu[2].attach(35);
  bahu_pos[2][depan] = 45;
  bahu_pos[2][tengah] = 60;
  bahu_pos[2][belakang] = 75;

  siku[3].attach(8);
  bahu[3].attach(9);
  bahu_pos[3][depan] = 145;
  bahu_pos[3][tengah] = 130;
  bahu_pos[3][belakang] = 115;

  siku[4].attach(10);
  bahu[4].attach(11);
  bahu_pos[4][depan] = 105;
  bahu_pos[4][tengah] = 90;
  bahu_pos[4][belakang] = 75;

  siku[5].attach(12);
  bahu[5].attach(13);
  bahu_pos[5][depan] = 75;
  bahu_pos[5][tengah] = 60;
  bahu_pos[5][belakang] = 45;
}

void pindah_kaki_depan(int kaki[]){
  for (int i=0; i<3; i+=1){
   bahu[kaki[i]].write(bahu_pos[kaki[i]][depan]);
  }
  delay(75);
}

void pindah_kaki_atas(int kaki[]){
  for (int i=0; i<3; i+=1){
   siku[kaki[i]].write(up); 
  }
  delay(75);
}

void pindah_kaki_bawah(int kaki[]){
  for (int i=0; i<3; i+=1){
   siku[kaki[i]].write(down); 
  }
  delay(75);
}

void move_legs_backward(int legs[]){
  for (int i=0; i<3; i+=1){
   shoulders[legs[i]].write(shoulder_pos[legs[i]][rear]);
  }
  delay(75);
}

void move_legs_in(int legs[]){
  for (int i=0; i<3; i+=1){
    elbows[legs[i]].write(in);
  } 
  delay(200);
}

void move_legs_out(int legs[]){
  for (int i=0; i<3; i+=1){
    elbows[legs[i]].write(in);
  }
  delay(200); 
}

void leg_move_neutral(int leg){
  shoulders[leg].write(shoulder_pos[leg][neutral]);
  delay(75);
    
  elbows[leg].write(down);
  delay(75);
}

void move_legs_neutral(int legs[]){
  for (int i=0; i<3; i+=1){ 
   leg_move_neutral(legs[i]);
  } 
}

// Walk forward
void walk_forward() {
  move_legs_up(odd_legs);
  move_legs_forward(odd_legs);
  move_legs_down(odd_legs);
  
  move_legs_up(even_legs);
  move_legs_backward(odd_legs);
  move_legs_forward(even_legs);
  
  move_legs_down(even_legs);
  move_legs_up(odd_legs);
  move_legs_backward(even_legs);
}

void init_position() {
  // Elbows should be moved to position 55
  // Shoulders should be moved to position 90
  move_legs_neutral(even_legs);
  move_legs_neutral(odd_legs);
}

void setup() {
  // Put setup code here. This only runs once.
  register_servos();
  init_position();
}

void loop() {
  // Put main code here; this loops continuously.
  walk_forward();
}

