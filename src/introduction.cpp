//! Libraries & Header Files

#include <iostream>
#include <graphics.h>
#include "welcomeScreen.h"
#include "r_l_screen.h"
#include "log_regs.h"
#include "introduction.h"
#include "encryptDecrypt.h"
#include "exitfunc.h"

void intro() {
    //!To get the screen pixel count of x-axis & y-axis
    DWORD screenWidth = getScreenWidth();
    DWORD screenHeight = getScreenHeight();

    //! For the text "INTRODUCTION" & line below it
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 7);
    int textHeightIntroduction = textheight("INTRODUCTION");
    int textWidthIntroduction = textwidth("INTRODUCTION");
    outtextxy(
              ((screenWidth - textWidthIntroduction)/2),
              ((screenHeight/4) - textHeightIntroduction/2),
              "INTRODUCTION"
             );
    line(
         ((screenWidth - textWidthIntroduction)/2),
         (((screenHeight/4) + (textHeightIntroduction)/2)),
         ((screenWidth + textWidthIntroduction)/2),
         (((screenHeight/4) + (textHeightIntroduction)/2))
        );

    //! For the text1
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    int textWidthText1 = textwidth("Click on \"PROCEED\" below to read INTRODUCTION" );
    outtextxy(
              (screenWidth - textWidthText1)/2,
              ((screenHeight/3) + 55),
              "Click on \"PROCEED\" below to read INTRODUCTION"
            );

    //! For the text2
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    int textWidthText2 = textwidth("OR" );
    outtextxy(
              (screenWidth - textWidthText2)/2,
              ((screenHeight/3) + 95),
              "OR"
            );

    //! For the text3
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    int textWidthText3 = textwidth("Click on \"SKIP\" below to skip it." );
    outtextxy(
              (screenWidth - textWidthText3)/2,
              ((screenHeight/3) + 135),
              "Click on \"SKIP\" below to skip it."
            );

    //! For the text "PROCEED"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeightProceed = textheight("PROCEED");
    int textWidthProceed = textwidth("PROCEED");

    //! For the text "SKIP"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeightSkip = textheight("PROCEED");
    int textWidthSkip = textwidth("PROCEED");

    //! For the text "BACK"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeight1 = textheight("BACK");
    int textWidth1 = textwidth("BACK");

    //! For the text "EXIT"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeight5 = textheight("EXIT");
    int textWidth5 = textwidth("EXIT");

    skip();
    proceedbuttn();
    backbuttn();
    exitbuttn();

    while(1) {
        POINT cursorPosition;
        GetCursorPos(&cursorPosition);

        //! For back button
        if((GetAsyncKeyState(VK_LBUTTON)) &&
           (cursorPosition.x > ((screenWidth*4)/100) - 10) &&
           (cursorPosition.x < (((screenWidth*4)/100) + textWidth1 + 10)) &&
           (cursorPosition.y > (screenHeight-((screenWidth*6)/100)) - 5) &&
           (cursorPosition.y < (screenHeight-((screenWidth*6)/100)) + textHeight1 + 5)
          ){
            cleardevice();
            setup();
          }

        //! For exit button
        else if((GetAsyncKeyState(VK_LBUTTON)) &&
           (cursorPosition.x > ((screenWidth - textWidth5 - 25) - 10)) &&
           (cursorPosition.x < ((screenWidth - textWidth5 + 25) + 10)) &&
           (cursorPosition.y > ((screenHeight-((screenWidth*6)/100)) - 5)) &&
           (cursorPosition.y < ((screenHeight-((screenWidth*6)/100)) + 5 + textHeight5))
          ){
            exitfunc();
          }

        //! For skip button
        else if ((GetAsyncKeyState(VK_LBUTTON)) &&
           (cursorPosition.x > (((screenWidth - textWidthSkip)/2) - 10)) &&
           (cursorPosition.x < (((screenWidth + textWidthSkip)/2) + 10)) &&
           (cursorPosition.y > (((screenHeight/2)+ 150) - 5)) &&
           (cursorPosition.y < (((screenHeight/2) + textHeightSkip + 150) + 5))
          ){
            delay(500);
            cleardevice();
            encORdec();
          }

        //! For proceed button
        else if ((GetAsyncKeyState(VK_LBUTTON)) &&
           (cursorPosition.x > (((screenWidth - textWidthProceed)/2) - 10)) &&
           (cursorPosition.x < (((screenWidth + textWidthProceed)/2) + 10)) &&
           (cursorPosition.y > (((screenHeight/2)+ 100) - 5)) &&
           (cursorPosition.y < (((screenHeight/2) + textHeightProceed + 100) + 5))
          ){
            delay(500);
            closegraph();
            std::cout << "The Caesar Cipher technique is one of the earliest and simplest method of encryption technique." << std::endl << std::endl
                      << "It\’s simply a type of substitution cipher, i.e., each letter of a given text is replaced by a letter some fixed number of positions down the alphabet. For example with a shift of 1, A would be replaced by B, B would become C, and so on." << std::endl << std::endl
                      << "The method is apparently named after Julius Caesar, who apparently used it to communicate with his officials." << std::endl << std::endl;
            system("PAUSE");
            initwindow(screenWidth, screenHeight, "", -3, -3);
            encORdec();
          }
    }

}

//! skip Button
    void skip(){
    DWORD screenWidth = getScreenWidth();
    DWORD screenHeight = getScreenHeight();
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeightSkip = textheight("SKIP");
    int textWidthSkip = textwidth("SKIP");
    outtextxy(((screenWidth - textWidthSkip)/2), ((screenHeight)/2)+ 150, "SKIP");
    rectangle(
              ((screenWidth - textWidthSkip)/2) - 10,
               (((screenHeight)/2)+ 150) - 5,
               ((screenWidth + textWidthSkip)/2) + 10,
               (((screenHeight)/2) + textHeightSkip + 150) + 5
             );
    }
