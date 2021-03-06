//! Libraries & Header Files
#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include "welcomeScreen.h"
#include "r_l_screen.h"
#include "log_regs.h"
#include "introduction.h"
#include "encryptDecrypt.h"
#include "exitfunc.h"



void encORdec() {
    POINT cursorPosition;
    //! To get the screen pixel count
        DWORD screenWidth = getScreenWidth();
        DWORD screenHeight = getScreenHeight();

    //! Delay of .35 second
    delay(350);

    //! For the text "ENCRYPT/DECRYPT" & line below it
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 7);
    int textHeight1 = textheight("ENCRYPT/DECRYPT");
    int textWidth1 = textwidth("ENCRYPT/DECRYPT");
    outtextxy(
              ((screenWidth - textWidth1)/2),
              ((screenHeight/4) - textHeight1/2),
              "ENCRYPT/DECRYPT"
             );
    line(
         ((screenWidth - textWidth1)/2),
         (((screenHeight/4) + (textHeight1)/2)),
         ((screenWidth + textWidth1)/2),
         (((screenHeight/4) + (textHeight1)/2))
        );

    //! For the text "ENCRYPT" & "DECRYPT"
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    int textHeight2 = textheight("ENCRYPT");
    int textWidth2 = textwidth("ENCRYPT");
    int textHeight3 = textheight("DECRYPT");
    int textWidth3 = textwidth("DECRYPT");

    outtextxy(
              ((screenWidth - textWidth2)/2),
              (screenHeight/2),
              "ENCRYPT"
             );
    outtextxy(
              ((screenWidth - textWidth3)/2),
              ((screenHeight/2) + textHeight1*2),
              "DECRYPT"
             );

    //! For the text "EXIT"
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    int textHeight5 = textheight("EXIT");
    int textWidth5 = textwidth("EXIT");

    backbuttn();
    exitbuttn();

    while(1) {
        GetCursorPos(&cursorPosition);

        //! For ENCRYPT
        if((GetAsyncKeyState(VK_LBUTTON)) &&
           (cursorPosition.x > (screenWidth - textWidth2)/2) &&
           (cursorPosition.x < ((screenWidth - textWidth2)/2)+textWidth2) &&
           (cursorPosition.y > (screenHeight/2)) &&
           (cursorPosition.y < (screenHeight/2)+textHeight2)
          ){
            closegraph();
            encrypt();
        }

        //! For DECRYPT
        if((GetAsyncKeyState(VK_LBUTTON)) &&
           (cursorPosition.x > (screenWidth - textWidth3)/2) &&
           (cursorPosition.x < ((screenWidth - textWidth3)/2) + textWidth3) &&
           (cursorPosition.y > (screenHeight/2) + textHeight1*2) &&
           (cursorPosition.y < ((screenHeight/2) + textHeight1*2) + textHeight3)
          ){
            closegraph();
            decrypt();
        }

        //! For exit button
        if((GetAsyncKeyState(VK_LBUTTON)) &&
           (cursorPosition.x > ((screenWidth - textWidth5 - 25) - 10)) &&
           (cursorPosition.x < ((screenWidth - textWidth5 + 25) + 10)) &&
           (cursorPosition.y > ((screenHeight-((screenWidth*6)/100)) - 5)) &&
           (cursorPosition.y < ((screenHeight-((screenWidth*6)/100)) + 5 + textHeight5))
          ){
            exitfunc();
          }
    }
}

void encrypt() {
    //! To get the screen pixel count
        DWORD screenWidth = getScreenWidth();
        DWORD screenHeight = getScreenHeight();
    system("CLS");
    std::string choice;
    char message[100], ch;
	int i, key;

	std::cout << "\t\t\t\t ENCRYPTION" << std::endl << std::endl;

	std::cout << "Enter a message to encrypt: ";
	std::cin.ignore();
	std::cin.getline(message, 100);
	std::cout << "Shift key: ";
	std::cin >> key;

	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;

			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}

			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;

			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}

			message[i] = ch;
		}
	}

	std::cout << "Encrypted message - ";
	puts(message);

	std::cout << std::endl << std::endl << "Want to encrypt another? (Yes OR No) - ";
	std::cin >> choice;
	if(choice == "yes"|| choice == "Yes") {
        encrypt();
	}
	else {
        initwindow(screenWidth, screenHeight, "", -3, -3);
        encORdec();
	}

}

void decrypt() {
    //! To get the screen pixel count
        DWORD screenWidth = getScreenWidth();
        DWORD screenHeight = getScreenHeight();
    system("CLS");
    std::string choice;
    char message[100], ch;
	int i, key;

	std::cout << "Enter a message to decrypt: ";
	std::cin.ignore();
	std::cin.getline(message, 100);
	std::cout << "Shift key: ";
	std::cin >> key;

	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;

			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}

			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;

			if(ch > 'a'){
				ch = ch + 'Z' - 'A' + 1;
			}

			message[i] = ch;
		}
	}

	std::cout << "Decrypted message: " << message;

	std::cout << std::endl << std::endl << "Want to decrypt another? (Yes OR No) - ";
	std::cin >> choice;
	if(choice == "yes"|| choice == "Yes") {
        decrypt();
	}
	else {
        initwindow(screenWidth, screenHeight, "", -3, -3);
        encORdec();
	}
}
