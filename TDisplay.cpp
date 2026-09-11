#include "TDisplay.h"

TDisplay::TDisplay(){
    clearDisplay();
}

TDisplay::~TDisplay(){
}

void TDisplay::printDisplay(){
    printFrameLine();

 /*    char map[5][11] = {
        "##########",
        "#        #",
        "#  @ @@  #",
        "#        #",
        "##########"
    };

    for(int row = 0;row < 5;row++){
        //std::cout << "r" << row <<":";
        for(int col = 0;col < 11;col++){
        m_display[row][col] = map[row][col];
        }
    }
 */


    for(int row = 0;row < ROW;row++){
        //std::cout << "r" << row <<":";
        for(int col = 0;col < COL;col++){
            std::cout << m_display[row][col];
        }
        std::cout<<'\n';
    }
    printFrameLine();
}

void TDisplay::clearDisplay(){
    initscr();
    //erase();
    for(int row = 0;row < ROW;row++){
        for(int col = 0;col < COL;col++){
            m_display[row][col] = ' ';
        }
    }

    for(int row = 0;row < ROW;row++){
        for(int col = 0;col < COL;col++){
        //std::cout << "r" << row <<":";
            mvaddch(row, col, m_display[row][col]);
        }
    }
    refresh(); 
}

void TDisplay::printFrameLine(){
    for(int i=0; i < COL; i++){
        std::cout << '-';
    }
    std::cout<<'\n';
}

void TDisplay::printDisplay2(){
    initscr();
    for(int row = 0;row < ROW;row++){
        for(int col = 0;col < COL;col++){
            mvaddch(row, col, m_display[row][col]);
        }
    }
    
    if(mem.ST != 0x0){
        std::cout << "\a" << std::flush;
    }

    // Refresh the screen to show the text
    refresh(); 
    
    //getch();


}


void TDisplay::DrawSprite(uint8_t X, uint8_t Y, uint8_t N){
    uint8_t data;
    uint16_t location = mem.I;
    uint8_t mask = 0b10000000;
    bool currentPixel;
   
    initscr();
    for(int row = Y;row < (Y + N);row++){
        data = mem.MEMORY.byteBlock[location];
        //std::cout << "r" << row <<":";
        for(int col = X;col < (X + SPRITE_LENGTH);col++){
            currentPixel = data & mask;
            if(currentPixel){
                if(m_display[row][col] == BIT_ON){
                    m_display[row][col] = BIT_OFF;
                    mem.V[0xF] = 1;
                }
                else{
                    m_display[row][col] = BIT_ON;
                }            
            }
            if (col >= COL){
                continue;
            }          
            mask = mask >> 1;  
        }
        mask = 0b10000000; 
        location++;
        
    }
     refresh(); 
}
