#include <iostream>
#include <graphics.h>
#include "welcomeScreen.h"
#include "r_l_screen.h"
#include "exitfunc.h"



void projectTitle() {
    //! To get the screen pixel count
    DWORD screenWidth = getScreenWidth();
    DWORD screenHeight = getScreenHeight();

    //! Delay of 1 second
    delay(1000);

    //! For the text, "CRYPTOGRAPHY"
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 6.7);
    int textWidth1 = textwidth("CRYPTOGRAPHY");
    int textHeight1 = textheight("CRYPTOGRAPHY");
    outtextxy(
              (screenWidth - textWidth1)/2,
              (screenHeight - (textHeight1+70)) / 2,
              "CRYPTOGRAPHY"
            );

    //! For top and bottom line of text, "CRYPTOGRAPHY"
    line(
         ((screenWidth - textWidth1)/2),
         (((screenHeight - textHeight1)/2) - 40),
         (screenWidth + textWidth1)/2,
         (((screenHeight - textHeight1)/2) - 40)
        );
    line(
         ((screenWidth - textWidth1)/2),
         (((screenHeight - textHeight1)/2) + 20),
         (screenWidth + textWidth1)/2,
         (((screenHeight - textHeight1)/2) + 20)
        );

    //! Delay of 1 second
    delay(1000);

    //! For the text, "A PROJECET BY"
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    int textWidth2 = textwidth("A PROJECT BY");
    outtextxy(
              (screenWidth - textWidth2)/2,
              (((screenHeight - textHeight1)/2) + 55),
              "A PROJECT BY"
            );

    //! For the text, "SARTHAK ROHATGI"
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    int textWidth3 = textwidth("SARTHAK ROHATGI");
    outtextxy(
              (screenWidth - textWidth3)/2,
              (((screenHeight - textHeight1)/2) + 75),
              "SARTHAK ROHATGI"
            );

    //! For the text, "PRESS ANY KEY TO CONTINUE"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textWidth4 = textwidth("PRESS ANY KEY TO CONTINUE");
    outtextxy(
              (screenWidth - textWidth4)/2,
              screenHeight - 100,
              "PRESS ANY KEY TO CONTINUE"
            );
    getch();
    cleardevice();
    setup(); //! To call function "setup" from r_l_screen.h

}
