#include "mastermind.h"
#include "lcd_wrapper.h"
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <assert.h>
//#include <LCD4Bit.h>

void play_game(char* secret){
  //uvod do hry
    lcd_print_at(0,0,secret);
    delay(2000);
    lcd_clear();
    lcd_print_at(0,3,"Welcome to");
    lcd_print_at(1,3,"Mastermind!");
    delay(2000);
    lcd_clear();
     lcd_print_at(0,1,"Can you guess");
    lcd_print_at(1,1,"my combination?");
    delay(2500);
    lcd_clear();
     lcd_print_at(0,1,"I am thinking");
     lcd_print_at(1,1, "a number...");
  delay(2500); 
  lcd_clear();


  char * history[10];
  for(int i = 0; i < 10; i++){
    history[i] = (char *)calloc(5, sizeof(char));  
  }
   int peg_a=0;
   int peg_b=0;
   int attempts=0;
   while(peg_a!=4){
    peg_a=0;
    peg_b=0;
    attempts++;
    if(attempts==11){
        break;
      }
      char guess[]="0000";
      guess[strlen(guess)]='\0';
      if(attempts==10){
          lcd_print_at(1,0,"Last guess: 0000");
        }
      else{
      lcd_print_at(1,0,"Your guess: 0000");
      }
      int a=0;
        int b=0;
        int c=0;
        int d=0;
        //int s=attempts;
        int q=0;
        int but2=0;
        int but3=0;
        
        //hlavny while v ktorom sa pracuje s tlacitkami
      while(true){
        but2=0;
        but3=0;

          //while v ktorom je mozne listovat v historii
          while (digitalRead(BTN_1_PIN) == HIGH){
            if (digitalRead(BTN_2_PIN) == HIGH){      //krok spat                                                                        
              lcd_print_at(0,0,"                ");      
                if((attempts + but3)- (but2+1) >= 0){
                  but2++;
                 if((attempts + but3)- (but2+1) == 0){ lcd_print_at(0,0,"1: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        }
                 if((attempts + but3)- (but2+1) == 1){ lcd_print_at(0,0,"2: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        }
                 if((attempts + but3)- (but2+1) == 2){ lcd_print_at(0,0,"3: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        }
                 if((attempts + but3)- (but2+1) == 3){ lcd_print_at(0,0,"4: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        }
                 if((attempts + but3)- (but2+1) == 4){ lcd_print_at(0,0,"5: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        } 
                 if((attempts + but3)- (but2+1) == 5){ lcd_print_at(0,0,"6: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        } 
                 if((attempts + but3)- (but2+1) == 6){ lcd_print_at(0,0,"7: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        } 
                 if((attempts + but3)- (but2+1) == 7){ lcd_print_at(0,0,"8: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        } 
                 if((attempts + but3)- (but2+1) == 8){ lcd_print_at(0,0,"9: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        } 
                  while(digitalRead(BTN_2_PIN)!=LOW){q++;}
                  //continue;
                } 
           }
            if (digitalRead(BTN_3_PIN) == HIGH){                    //krok vpred
                lcd_print_at(0,0,"                ");    
                if((attempts + but3)- (but2+1) <=9 ){
                  but3++;
                    if((attempts + but3)- (but2+1) == 0){ lcd_print_at(0,0,"1: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        }
                                                       
                 if((attempts + but3)- (but2+1) == 1){ lcd_print_at(0,0,"2: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        }
                 if((attempts + but3)- (but2+1) == 2){ lcd_print_at(0,0,"3: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        }
                                                       
                 if((attempts + but3)- (but2+1) == 3){ lcd_print_at(0,0,"4: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        }
                 if((attempts + but3)- (but2+1) == 4){ lcd_print_at(0,0,"5: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        } 
                 if((attempts + but3)- (but2+1) == 5){ lcd_print_at(0,0,"6: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        } 
                 if((attempts + but3)- (but2+1) == 6){ lcd_print_at(0,0,"7: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        } 
                 if((attempts + but3)- (but2+1) == 7){ lcd_print_at(0,0,"8: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        } 
                 if((attempts + but3)- (but2+1) == 8){ lcd_print_at(0,0,"9: ");
                                                       lcd_print_at(0,3,history[(attempts + but3)- (but2+1)]);
                                                       turn_off_leds();
                                                        get_score(secret,history[(attempts + but3)- (but2+1)],&peg_a,&peg_b);
                                                        render_leds(peg_a,peg_b);
                                                        } 
                  while(digitalRead(BTN_3_PIN)!=LOW){q++;}
                  //continue;
                }                                                 
            }
          }   
          if(digitalRead(BTN_ENTER_PIN)==HIGH){                 //potvrdenie hadaneho cisla
            break;
          }
          if(digitalRead(BTN_1_PIN)==HIGH){                     //prva cislica
              a++;
              if(a==10){
                a=0;
                }
              guess[0]='0'+a;
              lcd_print_at(1,12,guess);
              while(digitalRead(BTN_1_PIN)!=LOW){q++;}
            }
            if(digitalRead(BTN_2_PIN)==HIGH){                    //druha cislica
              b++;
              if(b==10){
                b=0;
                }
              guess[1]='0'+b;
              lcd_print_at(1,12,guess);
              while(digitalRead(BTN_2_PIN)!=LOW){q++;}
            }
            if(digitalRead(BTN_3_PIN)==HIGH){                     //tretia cislica
              c++;
              if(c==10){
                c=0;
                }
              guess[2]='0'+c;
              lcd_print_at(1,12,guess);
              while(digitalRead(BTN_3_PIN)!=LOW){q++;}
            }
            if(digitalRead(BTN_4_PIN)==HIGH){                    //stvrta cislica
              d++;
              if(d==10){
                d=0;
                }
              guess[3]='0'+d;
              lcd_print_at(1,12,guess);
              while(digitalRead(BTN_4_PIN)!=LOW){q++;}
            }
            guess[4]='\0';
            //lcd_print_at(1,0,guess);
          }
          get_score(secret,guess,&peg_a,&peg_b);                //vyhodnotenie
          render_leds(peg_a,peg_b);
          delay(1000);
          turn_off_leds();
                                                                 //zapisanie do historie
          if(attempts==1){strcpy(history[attempts-1],guess);
          }
          if(attempts==2){strcpy(history[attempts-1],guess);}
          if(attempts==3){strcpy(history[attempts-1],guess);}
          if(attempts==4){strcpy(history[attempts-1],guess);}
          if(attempts==5){strcpy(history[attempts-1],guess);}
          if(attempts==6){strcpy(history[attempts-1],guess);}
          if(attempts==7){strcpy(history[attempts-1],guess);}
          if(attempts==8){strcpy(history[attempts-1],guess);}
          if(attempts==9){strcpy(history[attempts-1],guess);}
          
          char pokus[3];                                       //print posledneho pokusu
          sprintf(pokus,"%d",attempts);
          lcd_print_at(0,0,pokus);
          lcd_print_at(0,1,": ");
          lcd_print_at(0,3,history[attempts-1]);
          lcd_print_at(0,7,"         ");
    } 
    turn_off_leds();
    lcd_clear();  
    if(attempts>10){                                            // priprad prehry
        lcd_print_at(0,0,"LOSER! My secret");
        lcd_print_at(1,0,"combination");
        lcd_print_at(1,12,secret);
        while(digitalRead(BTN_ENTER_PIN)!=HIGH){
        analogWrite(7, 255);
        delay(100);
        analogWrite(9, 255);
        delay(100);
        analogWrite(11, 255);
        delay(100);
        analogWrite(13, 255);
        delay(100); 
        turn_off_leds();
        delay(100);
        analogWrite(13, 255);
        analogWrite(11, 255);
        analogWrite(9, 255);
        analogWrite(7, 255);
        delay(200);
        turn_off_leds();
        delay(100);
        analogWrite(13, 255);
        analogWrite(11, 255);
        analogWrite(9, 255);
        analogWrite(7, 255);
        delay(200);
        turn_off_leds();
         analogWrite(13, 255);
        delay(100);
        analogWrite(11, 255);
        delay(100);
        analogWrite(9, 255);
        delay(100);
        analogWrite(7, 255);
        delay(100); 
        turn_off_leds();
        
        }
        lcd_clear();
      }
     if(peg_a==4){                                                     //pripad vyhry
        lcd_print_at(0,0,"Congratulations!");
        lcd_print_at(1,3,"YOU WON!");
        while(digitalRead(BTN_ENTER_PIN)!=HIGH){
        analogWrite(7, 255);
        delay(100);
        analogWrite(8, 255);
        delay(100);
        analogWrite(11, 255);
        delay(100);
        analogWrite(12, 255);
        delay(100); 
        turn_off_leds();
        analogWrite(13, 255);
        delay(100);
        analogWrite(10, 255);
        delay(100);
        analogWrite(9, 255);
        delay(100);
        analogWrite(6, 255);
        delay(100);
        turn_off_leds();
        }
        
      }
      lcd_clear();
      turn_off_leds();
    
  }

void render_history(char* secret, char** history, const int entry_nr){
    char pokus=(char)('0'+entry_nr+1);
   // sprintf(pokus,"%d",entry_nr);
    //pokus=pokus+1;
    lcd_print_at(0,0,"             ");
    lcd_print_at(0,0,pokus);
    lcd_print_at(0,1,":");
    lcd_print_at(0,3,*history[entry_nr]);
    int peg_a=0;
    int peg_b=0;
    get_score(secret,history[entry_nr],&peg_a,&peg_b);
    render_leds(peg_a,peg_b);
  }
void render_leds(const int peg_a, const int peg_b){
    for(int a=0;a<peg_a;a++){
        int b=7+(2*a);
        analogWrite(b,255);
      }
     for(int a=0;a<peg_b;a++){
        int b=6+(2*a);
        b=b+(peg_a*2);
        analogWrite(b,255);
      }
  }
void turn_off_leds(){
    analogWrite(7, 0);
    analogWrite(9, 0);
    analogWrite(11, 0);
    analogWrite(13, 0);
    
    analogWrite(6, 0);
    analogWrite(8, 0);
    analogWrite(10, 0);
    analogWrite(12, 0);
  }
void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b){
      int pom_a=0;
      int pom_b=0;
      for(size_t a=0;a<strlen(secret);a++){
          if(secret[a]==guess[a]){
              pom_a++;
            }
          else{
              for(size_t c=0;c<strlen(secret);c++){
                  if(secret[a]==guess[c]&& c!=a){
                      pom_b++;
                    }
                }              
              }
        }
        *peg_a=pom_a;
        *peg_b=pom_b;
        
  }
char* generate_code(bool repeat, int length){
    if(length<1){
        return NULL;
    }
    if(repeat==false&&length>10){
        return NULL;
    }
    char* code=(char*)calloc(length+1,sizeof(char));
    if(repeat==true){                                    //mozu sa opakovat
      srand(analogRead(1));
        for(int i=0;i<length;i++){
            code[i]= rand() % 10 + '0';
        }
        code[length]='\0';
        return code;
    }
    if(repeat==false){                                   //nemozu sa opakovat
      srand(analogRead(1));
      code[0]=rand() % 10 + '0';
        for(int i=1;i<length;i++){
            code[i]= rand() % 10 + '0';
            for(int a=0;a<i;a++){
                if(code[i]==code[a]){
                    i--;
                }   
            }            
        }
        code[length]='\0';
        return code;
    }
}
