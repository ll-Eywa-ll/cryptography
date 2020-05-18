#include <iostream>
#include <fstream>
#include <istream>
#include <stdio.h>
#include <graphics.h>
#include <string>
#include <windows.h>
#include "r_l_screen.h"
#include "welcomeScreen.h"
#include "log_regs.h"
#include "introduction.h"
#include "exitfunc.h"

void proceedbuttn();


void regs_screen() {
    DWORD screenWidth = getScreenWidth();
    DWORD screenHeight = getScreenHeight();

    //! For the text "REGISTRATION" & line below it
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 7);
    int textHeightRegistration = textheight("REGISTRATION");
    int textWidthRegistration = textwidth("REGISTRATION");
    outtextxy(
              ((screenWidth - textWidthRegistration)/2),
              ((screenHeight/4) - textHeightRegistration/2),
              "REGISTRATION"
             );
    line(
         ((screenWidth - textWidthRegistration)/2),
         (((screenHeight/4) + (textHeightRegistration)/2)),
         ((screenWidth + textWidthRegistration)/2),
         (((screenHeight/4) + (textHeightRegistration)/2))
        );

    //! For the text1
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    int textWidthText1 = textwidth("Click on \"PROCEED\" below to REGISTER" );
    outtextxy(
              (screenWidth - textWidthText1)/2,
              ((screenHeight/3) + 55),
              "Click on \"PROCEED\" below to REGISTER"
            );

    //! For the text2
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    int textWidthText2 = textwidth("where you will be asked for credentials." );
    outtextxy(
              (screenWidth - textWidthText2)/2,
              ((screenHeight/3) + 95),
              "where you will be asked for credentials."
            );

    //! For the text "BACK"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeight1 = textheight("BACK");
    int textWidth1 = textwidth("BACK");

    //! For the text "PROCEED"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeightProceed = textheight("PROCEED");
    int textWidthProceed = textwidth("PROCEED");

    backbuttn();
    proceedbuttn();

    while(1) {
        POINT cursorPosition;
        GetCursorPos(&cursorPosition);

        if((GetAsyncKeyState(VK_LBUTTON)) &&
           (cursorPosition.x > ((screenWidth*4)/100) - 10) &&
           (cursorPosition.x < (((screenWidth*4)/100) + textWidth1 + 10)) &&
           (cursorPosition.y > (screenHeight-((screenWidth*6)/100)) - 5) &&
           (cursorPosition.y < (screenHeight-((screenWidth*6)/100)) + textHeight1 + 5)
          ){
            cleardevice();
            setup();
          }
        else if ((GetAsyncKeyState(VK_LBUTTON)) &&
           (cursorPosition.x > (((screenWidth - textWidthProceed)/2) - 10)) &&
           (cursorPosition.x < (((screenWidth + textWidthProceed)/2) + 10)) &&
           (cursorPosition.y > (((screenHeight/2)+ 100) - 5)) &&
           (cursorPosition.y < (((screenHeight/2) + textHeightProceed + 100) + 5))
          ){
            delay(500);
            closegraph();
            regs();
            }
    }
}

void logs_screen() {
    DWORD screenWidth = getScreenWidth();
    DWORD screenHeight = getScreenHeight();

     //! For the text "LOGIN" & line below it
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 7);
    int textHeightLogin = textheight("LOGIN");
    int textWidthLogin = textwidth("LOGIN");
    outtextxy(
              ((screenWidth - textWidthLogin)/2),
              ((screenHeight/4) - textHeightLogin/2),
              "LOGIN"
             );
    line(
         ((screenWidth - textWidthLogin)/2),
         (((screenHeight/4) + (textHeightLogin)/2)),
         ((screenWidth + textWidthLogin)/2),
         (((screenHeight/4) + (textHeightLogin)/2))
        );

    //! For the text1
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    int textWidthText1 = textwidth("Click on \"PROCEED\" below to LOGIN" );
    outtextxy(
              (screenWidth - textWidthText1)/2,
              ((screenHeight/3) + 55),
              "Click on \"PROCEED\" below to LOGIN"
            );

    //! For the text2
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    int textWidthText2 = textwidth("where you will be asked for credentials." );
    outtextxy(
              (screenWidth - textWidthText2)/2,
              ((screenHeight/3) + 95),
              "where you will be asked for credentials."
            );

    //! For the text "BACK"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeight1 = textheight("BACK");
    int textWidth1 = textwidth("BACK");

    //! For the text "PROCEED"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeightProceed = textheight("PROCEED");
    int textWidthProceed = textwidth("PROCEED");

    backbuttn();
    proceedbuttn();

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
        //! For proceed button
        else if ((GetAsyncKeyState(VK_LBUTTON)) &&
           (cursorPosition.x > (((screenWidth - textWidthProceed)/2) - 10)) &&
           (cursorPosition.x < (((screenWidth + textWidthProceed)/2) + 10)) &&
           (cursorPosition.y > (((screenHeight/2)+ 100) - 5)) &&
           (cursorPosition.y < (((screenHeight/2) + textHeightProceed + 100) + 5))
          ){
            delay(500);
            closegraph();
            logs();
          }
    }
}

void regs() {
    //! To get the screen pixel count
    DWORD screenWidth = getScreenWidth();
    DWORD screenHeight = getScreenHeight();

    std::string reguser, regpass, regfname, reglname;

    std::cout << std::endl << std::endl << "\t\t\t\t REGISTRATION" << std::endl << std::endl;
    std::cout << std::endl << "Enter your first name - ";
    std::cin >> regfname;
    std::cout << std::endl << "Enter your last name - ";
    std::cin >> reglname;
    std::cout << std::endl << "Create your Username - ";
    std::cin >> reguser;
    std::cout << std::endl << "Create your Password - ";
    std::cin >> regpass;

    std::ofstream reg("data.txt", std::ios::app);

    reg << regfname << "\t\t\t" << reglname << "\t\t\t" << reguser << "\t\t\t" << regpass << std::endl << std::endl;

    system("CLS");
    for (int i = 0 ; i <= 10 ; i ++) {
        std::cout << std::endl;
    }
    std::cout << "\t     Congratulations " << regfname << ". Your Registration is successful!";
    delay(2000);
    system("CLS");
    initwindow(screenWidth, screenHeight, "", -3, -3);
    setup();
}

void logs() {
    //! To get the screen pixel count
    DWORD screenWidth = getScreenWidth();
    DWORD screenHeight = getScreenHeight();

    bool exist;
    int c;
    std::string user, pass, u, p;
    system("CLS");
    std::cout << "Enter Username - ";
    std::cin >> user;
    std::cout << std::endl;
    std::cout << "Enter Password - ";
    std::cin >> pass;

    std::ifstream input("data.txt");

    while(input >> u >> p){
        if(u != user || p!= pass) {
            exist = false;
        }

        else if(u == user && p == pass) {
            exist = true;
        }
    }
    if(exist == true) {
        system("CLS");
        for (int i = 0 ; i <= 10 ; i ++) {
            std::cout << std::endl;
        }
        std::cout << "\t     Login Successful \"" << user << "\". You are being redirected.";
        delay(2000);
        system("CLS");
        initwindow(screenWidth, screenHeight, "", -3, -3);
        intro();
    }

    else if(exist == false) {
        system("CLS");
        for (int i = 0 ; i <= 10 ; i ++) {
            std::cout << std::endl;
        }
        std::cout << "\t\t\tIncorrect username or password" << std::endl << std:: endl<< "\t\t\tTry again";
        delay(2000);
        logs();
    }
}

//! Proceed Button
    void proceedbuttn(){
    DWORD screenWidth = getScreenWidth();
    DWORD screenHeight = getScreenHeight();
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeightProceed = textheight("PROCEED");
    int textWidthProceed = textwidth("PROCEED");
    outtextxy(((screenWidth - textWidthProceed)/2), ((screenHeight)/2)+ 100, "PROCEED");
    rectangle(
              ((screenWidth - textWidthProceed)/2) - 10,
               (((screenHeight)/2)+ 100) - 5,
               ((screenWidth + textWidthProceed)/2) + 10,
               (((screenHeight)/2) + textHeightProceed + 100) + 5
             );
    }
