

#include "Arduino.h"
#include "MPU6050.h"

#include <Wire.h>


//MPU::MPU(int ADDRESS)
//{
//  pinMode(pin, OUTPUT);
//  _pin = pin;
//}

void MPU::Sleep(boolean sleep) { // RETURNS TRUE IF SUCCEED IN READING BYTE, ELSE FALSE
    
    if (sleep) {
        Wire.beginTransmission(MPU6050_ADDRESS); // ALWAYS HAVE TO BEGIN WITH ADDRESS
        Wire.write(0x1B); // WHERE TO START WRITING
        Wire.write(0x40); // WHAT TO WRITE
        Wire.endTransmission();
    } else {
        Wire.write(0x1B); // WHERE TO START WRITING
        Wire.write(0x00); // WHAT TO WRITE
    }
}


void MPU::SetAccelRange(int range) { //ex: SetGyroRange(ACCEL_RANGE_2G); // SHOULD ALWAYS BE IN SETUP // RETURNS TRUE IF SUCCEED IN READING BYTE, ELSE FALSE
    
    // THIS CAN BE DIRECTLY SET, DATASHEET SPECIFIES RESET VALUES FOR THIS REGISTER AS 0x00, SO SETTING THE WHOLE REG IS FINE
    
    Wire.beginTransmission(MPU6050_ADDRESS); // ALWAYS HAVE TO BEGIN WITH ADDRESS
    Wire.write(0x1C); // WHERE TO START WRITING
    Wire.write(range); // WHAT TO WRITE
    Wire.endTransmission();
}


void MPU::SetGyroRange(int range) { //ex: SetGyroRange(GYRO_RANGE_250DS); // SHOULD ALWAYS BE IN SETUP // RETURNS TRUE IF SUCCEED IN READING BYTE, ELSE FALSE
    
    // THIS CAN BE DIRECTLY SET, DATASHEET SPECIFIES RESET VALUES FOR THIS REGISTER AS 0x00, SO SETTING THE WHOLE REG IS FINE
    
    Wire.beginTransmission(MPU6050_ADDRESS); // ALWAYS HAVE TO BEGIN WITH ADDRESS
    Wire.write(0x1B); // WHERE TO START WRITING
    Wire.write(range); // WHAT TO WRITE
    Wire.endTransmission();
}


float MPU::getTemp() {
    
    byte H, L;
    
    Wire.beginTransmission(MPU6050_ADDRESS); // ALWAYS HAVE TO BEGIN WITH ADDRESS
    Wire.write(0x41); // WHERE TO START READING FROM
    Wire.endTransmission(false); // IMPORTANT!!!
    
    Wire.requestFrom(MPU6050_ADDRESS, 2); // REQUEST 2 BYTES
    if (Wire.available()) {
        H = Wire.read(); // TAKE IN HIGH BYTE
        L = Wire.read(); // TAKE IN LOW BYTE
    } else {
        Serial.print("  Not getting available data... ");
    }
    
    Wire.endTransmission(); // MAY NEED TO TAKE IN A BOOL TRUE
    
    int t = (H << 8) | L; // PUT INTO INT
    float temp = t / 340.00 + 36.53; // CONVERT TO TEMP C / FORMULA FROM DATASHEET
    
    return temp;
}


int MPU::getGyro (char axis) {
    
    int addr;
    byte H, L;
    
    switch (axis) {
            
        case 'X':
            addr = 0x43;
            break;
            
        case 'Y':
            addr = 0x45;
            break;
            
        case 'Z':
            addr = 0x47;
            break;
    }
    
    Wire.beginTransmission(MPU6050_ADDRESS); // ALWAYS HAVE TO BEGIN WITH ADDRESS
    Wire.write(addr); // WHERE TO START READING FROM
    Wire.endTransmission(false); // IMPORTANT!!!
    
    Wire.requestFrom(MPU6050_ADDRESS, 2); // REQUEST 2 BYTES
    if (Wire.available()) {
        H = Wire.read(); // TAKE IN HIGH BYTE
        L = Wire.read(); // TAKE IN LOW BYTE
    }
    
    Wire.endTransmission(); // MAY NEED TO TAKE IN A BOOL TRUE
    
    return (H << 8) | L; // COMBINE INTO INT16 AND RETURN
}

int MPU::getAccel (char axis) {
    
    int addr;
    byte H, L;
    
    switch (axis) {
            
        case 'X':
            addr = 0x3B;
            break;
            
        case 'Y':
            addr = 0x3D;
            break;
            
        case 'Z':
            addr = 0x3F;
            break;
    }
    
    Wire.beginTransmission(MPU6050_ADDRESS); // ALWAYS HAVE TO BEGIN WITH ADDRESS
    Wire.write(addr); // WHERE TO START READING FROM
    Wire.endTransmission(false); // IMPORTANT!!!
    
    Wire.requestFrom(MPU6050_ADDRESS, 2); // REQUEST 2 BYTES
    if (Wire.available()) {
        H = Wire.read(); // TAKE IN HIGH BYTE
        L = Wire.read(); // TAKE IN LOW BYTE
        
    } else {
        Serial.print("  Not getting available data... ");
    }
    
    Wire.endTransmission(); // MAY NEED TO TAKE IN A BOOL TRUE
    
    return (H << 8) | L;
}
