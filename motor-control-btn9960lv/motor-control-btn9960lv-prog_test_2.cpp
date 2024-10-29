#include <cstdio>
#include <unistd.h>
#include <iostream>

void writeToFile(const char* path, int value) {
    FILE* file = fopen(path, "w");
    if (file != nullptr) {
        fprintf(file, "%d", value);
        fclose(file);
    } else {
        std::cerr << "Error while opening file: " << path << std::endl;
    }
}

int main() {
    
    writeToFile("/sys/class/pwm/pwmchip0/export", 0); 
    sleep(1); 
    writeToFile("/sys/class/pwm/pwmchip0/pwm0/enable", 1);

    for(int i = 0; i < 10; i ++)

    {
        writeToFile("/sys/class/pwm/pwmchip0/pwm0/period", 1000000); 
        writeToFile("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", 500000); 

        sleep(2); 

        writeToFile("/sys/class/pwm/pwmchip0/pwm0/period", 1000000); 
        writeToFile("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", 200000); 

        sleep(2);
    }

    writeToFile("/sys/class/pwm/pwmchip0/pwm0/enable", 0);
    writeToFile("/sys/class/pwm/pwmchip0/unexport", 0);

    return 0;
}