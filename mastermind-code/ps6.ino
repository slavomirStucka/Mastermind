#include "mastermind.h"
#include "lcd_wrapper.h"
#include <assert.h>

void setup() {
  lcd_init();
  pinMode(A0, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT) ;
  randomSeed(analogRead(1));
}

void loop() {
    char* code=generate_code(false,4);
    //lcd_print_at(0,0,code);
    //delay(2000);
    //lcd_clear();
    play_game(code);
    free(code);
   
}
