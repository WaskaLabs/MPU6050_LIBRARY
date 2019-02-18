# MPU6050_LIBRARY
MPU6050 LIBRARY FOR ARDUINO WITH SLEEP / CONFIGURATION OPTIONS

MPU6050 LIBRARY WRITTEN BY MORGAN WASKA @WASKALABS -- READ THE README FILE FOR INFORMATION ON LICENSING -- FOR QUESTIONS / COMMENTS, GO TO FACEBOOK.COM/WASKALABS

  USE...
    1 - INCLUDE LIBRARY
    2 - CREATE OBJECT
    3 - MAKE SURE THE SENSOR IS "AWAKE" BY SETTING SLEEP TO FALSE
    4 - SETTING THE RANGE IS OPTIONAL, IT DEFAULTS TO THE LOWEST VALUES (250D/S && 2gs)
    5 - USE THE "GET" FUNCTIONS TO GET THE VALUES, BE SURE TO PASS IN A CAPITAL ('CHAR') FOR THE AXIS YOU WANT TO GET DATA FROM ('X') ('Y') ('Z')
    6 - THATS IT!

  NOTE: THIS LIBRARY HAS THE I2C ADDRESS SET AS 0x68, WHICH SHOULD WORK FOR ALL 6050s... IF IT DOESNT WORK, OR YOU HAVE ANOTHER MPU60X0...
    1 - RUN I2C SCANNER .INO FILE TO FIND THE ADDRESS (https://playground.arduino.cc/Main/I2cScanner)
    2 - GO TO PROGRAM FILES (OR APPLICATIONS > RIGHT-CLICK > SHOW PACKAGE CONTENTS, ON MAC) > ARDUINO > JAVA > LIBRARIES > MPU6050 > MPU6050.h
    3 - CHANGE MPU6050_ADDRESS TO YOUR DEVICE ADDRESS (ex. MPU6050_ADDRESS 0xFF) - NO SIMICOLON
    4 - SAVE THE FILE AND YOU SHOULD BE GOOD! YOU MAY NEED TO RELAUNCH THE IDE.

 // GYRO RANGE OPTIONS // PASS IN LIKE MPU.SetGyroRange(-- COPY/PASTE HERE --);

GYRO_RANGE_250DS  (250 degrees / second)
GYRO_RANGE_500DS  (500 degrees / second)
GYRO_RANGE_1000DS (1000 degrees / second)
GYRO_RANGE_2000DS (5000 degrees / second)

 // ACCELEROMETER RANGE OPTIONS // PASS IN LIKE MPU.SetAccelRange(-- COPY/PASTE HERE --);

ACCEL_RANGE_2G  (2gs)
ACCEL_RANGE_4G  (4gs)
ACCEL_RANGE_8G  (8gs)
ACCEL_RANGE_16G (16gs)

 */
