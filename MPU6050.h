

#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

#define GYRO_RANGE_250DS    0x00
#define GYRO_RANGE_500DS    0x08
#define GYRO_RANGE_1000DS   0x10
#define GYRO_RANGE_2000DS   0x18

#define ACCEL_RANGE_2G      0x00
#define ACCEL_RANGE_4G      0x08
#define ACCEL_RANGE_8G      0x10
#define ACCEL_RANGE_16G     0x18

#define MPU6050_ADDRESS 0x68

class MPU
{
  public:
    //MPU(MPU6050_ADDRESS);
    void Sleep(boolean sleep);
    void SetAccelRange(int range);
    void SetGyroRange(int range);
    float getTemp();
    int getGyro(char axis);
    int getAccel (char axis);
  private:
};

#endif

