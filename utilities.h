#include <cstdint>
#include <sstream>
#include <string>


namespace util{

    static uint8_t BIT_SHIT_TO_4_NIBBLE = 12;
    static uint8_t BIT_SHIT_TO_3_NIBBLE = 8;
    static uint8_t BIT_SHIT_TO_2_NIBBLE = 4;

    inline uint16_t getNNN(uint16_t instruction){
        uint16_t NNN = (instruction & 0x0FFF);
        return NNN;
    }

    inline uint8_t getLastByte(uint16_t instruction){
        uint8_t byte = (instruction & 0x00FF);
        return byte;
    }

    inline uint8_t getLastNibble(uint16_t instruction){
        uint8_t byte = (instruction & 0x000F);
        return byte;
    }

    inline uint8_t getRegisterX(uint16_t instruction){
        uint8_t registerX = (instruction & 0x0F00) >> BIT_SHIT_TO_3_NIBBLE;
        return registerX;
    }

    inline uint8_t getRegisterY(uint16_t instruction){
        uint8_t registerY = (instruction & 0x00F0) >> BIT_SHIT_TO_2_NIBBLE;
        return registerY;
    }

    inline std::string printMessage1(std::string text, uint16_t arg1){
        std::string outString;
        char temp[20];
        snprintf(temp, sizeof(temp), text.c_str(), arg1);
        outString = temp;
        return outString;
    }

    inline std::string printMessage2(std::string text, uint16_t arg1, uint16_t arg2){
        std::string outString;
        char temp[20];
        snprintf(temp, sizeof(temp), text.c_str(), arg1, arg2);
        outString = temp;
        return outString;
    }

    inline std::string printMessage3(std::string text, uint16_t arg1, uint16_t arg2, uint16_t arg3){
        std::string outString;
        char temp[20];
        snprintf(temp, sizeof(temp), text.c_str(), arg1, arg2, arg3);
        outString = temp;
        return outString;
    }

    inline uint16_t swapBytes(uint16_t byte){
        return (((byte & 0xff) << 8) | ((byte & 0xff00) >> 8));  
    }

    struct BCDType{
        uint8_t hundreds;
        uint8_t tens;
        uint8_t ones;
    };

    inline BCDType BCD(uint16_t number){
        BCDType returnValue;
        returnValue.ones = number % 10;
        returnValue.hundreds = number / 100;
        returnValue.tens = (number - (returnValue.hundreds*100) - returnValue.ones)/10;
        return returnValue;
    }

}

