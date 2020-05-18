//! Pre-processor Commands

#define AND &&

//! Libraries & Header Files

#include <iostream>
#include <graphics.h>
#include "r_l_screen.h"
#include "welcomeScreen.h"
#include "log_regs.h"
#include "encryptDecrypt.h"
#include "exitfunc.h"

POINT cursorPosition;

//! To get the screen Metrics x-axis & y-axis
DWORD screenWidth = getScreenWidth();
DWORD screenHeight = getScreenHeight();

//! Back Button
void backbuttn(){
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(((screenWidth*4)/100), (screenHeight-((screenWidth*6)/100)), "BACK");
    int textHeight = textheight("BACK");
    int textWidth = textwidth("BACK");
    rectangle(
              ((screenWidth*4)/100) - 10,
               (screenHeight-((screenWidth*6)/100)) - 5,
               ((screenWidth*4)/100) + textWidth + 10,
               (screenHeight-((screenWidth*6)/100)) + textHeight + 5
             );
}

//! Exit Button
void exitbuttn(){
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeight = textheight("EXIT");
    int textWidth = textwidth("EXIT");
    outtextxy((screenWidth - textWidth - 25), (screenHeight-((screenWidth*6)/100)), "EXIT");
    rectangle(
              ((screenWidth - textWidth - 25) - 10),
               ((screenHeight-((screenWidth*6)/100)) - 5),
               ((screenWidth - textWidth + 25) + 10) ,
               ((screenHeight-((screenWidth*6)/100)) + 5 + textHeight)
             );
}

void setup() {

    //! Delay of .35 second
    delay(350);

    //! For the text "WELCOME" & line below it
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 7);
    int textHeight1 = textheight("WELCOME");
    int textWidth1 = textwidth("WELCOME");
    outtextxy(
              ((screenWidth - textWidth1)/2),
              ((screenHeight/4) - textHeight1/2),
              "WELCOME"
             );
    line(
         ((screenWidth - textWidth1)/2),
         (((screenHeight/4) + (textHeight1)/2)),
         ((screenWidth + textWidth1)/2),
         (((screenHeight/4) + (textHeight1)/2))
        );

    //! For the text "REGISTER" & "LOGIN"
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    int textHeight2 = textheight("REGISTER");
    int textWidth2 = textwidth("REGISTER");
    int textHeight3 = textheight("LOGIN");
    int textWidth3 = textwidth("LOGIN");

    outtextxy(
              ((screenWidth - textWidth2)/2),
              (screenHeight/2),
              "REGISTER"
             );
    outtextxy(
              ((screenWidth - textWidth3)/2),
              ((screenHeight/2) + textHeight1*2),
              "LOGIN"
             );
    //! For the text "BACK"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeight4 = textheight("BACK");
    int textWidth4 = textwidth("BACK");

    //! For the text "EXIT"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeight5 = textheight("EXIT");
    int textWidth5 = textwidth("EXIT");

    backbuttn();
    exitbuttn();

    while(1) {
        GetCursorPos(&cursorPosition);

        //! For Registration
        if((GetAsyncKeyState(VK_LBUTTON)) AND
           (cursorPosition.x > (screenWidth - textWidth2)/2) AND
           (cursorPosition.x < ((screenWidth - textWidth2)/2)+textWidth2) AND
           (cursorPosition.y > (screenHeight/2)) AND
           (cursorPosition.y < (screenHeight/2)+textHeight2)
          ){
            cleardevice();
            regs_screen();
        }

        //! For Login
        if((GetAsyncKeyState(VK_LBUTTON)) AND
           (cursorPosition.x > (screenWidth - textWidth3)/2) AND
           (cursorPosition.x < ((screenWidth - textWidth3)/2) + textWidth3) AND
           (cursorPosition.y > (screenHeight/2) + textHeight1*2) AND
           (cursorPosition.y < ((screenHeight/2) + textHeight1*2) + textHeight3)
          ){
            cleardevice();
            logs_screen();
        }

        //! For back button
        if((GetAsyncKeyState(VK_LBUTTON)) AND
           (cursorPosition.x > ((screenWidth*4)/100) - 10) AND
           (cursorPosition.x < (((screenWidth*4)/100) + textWidth4 + 10)) AND
           (cursorPosition.y > (screenHeight-((screenWidth*6)/100)) - 5) AND
           (cursorPosition.y < (screenHeight-((screenWidth*6)/100)) + textHeight4 + 5)
          ){
            cleardevice();
            projectTitle();
          }

        //! For exit button
        if((GetAsyncKeyState(VK_LBUTTON)) AND
           (cursorPosition.x > ((screenWidth - textWidth5 - 25) - 10)) AND
           (cursorPosition.x < ((screenWidth - textWidth5 + 25) + 10)) AND
           (cursorPosition.y > ((screenHeight-((screenWidth*6)/100)) - 5)) AND
           (cursorPosition.y < ((screenHeight-((screenWidth*6)/100)) + 5 + textHeight5))
          ){
            exitfunc();
          }
    }
}
