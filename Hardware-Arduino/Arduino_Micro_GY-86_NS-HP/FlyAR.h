/* 
 *  Emilio Borges
 *  October - December 2016
 *  University of Toledo
 *  Senior Design Project - FlyAR
 *  
 *  The FlyAR project aims to provide an augmented reality First Person View (FPV) flying experience. As the vehicle
 *  flies through the sky, virtual graphics overlay the FPV camera image. We use the term augmented reality because 
 *  the virtual graphics rendered over the FPV image seem to stay fixed over real world locations. Given a user created
 *  virtual flying environment, the user can fly in an open area with their FPV goggles or monitor, but see virtual 
 *  objects floating in different sections of the sky and believe those virtual objects actualy exist in the real world.
 *  
 *  This code will run on an Arduino Micro (ATmega32U4) and use I2C to communicate with the GY-86 sensor board and LVTTL 
 *  to communicate with the NS-HP. The Arduino Micro will constantly read raw sensor data and, clean up the data through 
 *  post-processing algorithms, store the values in memory, and repeat to update sensor values. An external processor,
 *  the Raspberry Pi 3 in our case, can then request specific or all of these values for their own use.
 *  
 *  GY-86
 *    10 Degrees of Freedom (DOF) sensor board containing 3-axis accelerometer & 3-axis gyro (MPU6050), 
 *    3-axis magnetometer (HMC5883L), and 1-axis baromoter (MS5611). 
 *  
 *  NS-HP
 *    SkyTraQ NS-HP RTK capable GPS/GNSS receiver
 *    NS-HP is a high performance RTK capable GPS / GNSS receiver achieving centimeter-level accuracy relative positioning.
 *    http://navspark.mybigcommerce.com/ns-hp-rtk-capable-gps-gnss-receiver/
 * 
 * Sources:
 *  [1] https://github.com/farrellf/Balancing_Robot_Firmware/blob/6a7c770a52409c4dbbca72b125163df74aa2956c/main.c
 *  [2] https://youtu.be/hvjNaIlHPV0
 */

#ifndef FlyAR_H
#define FlyAR_H

// select units
#define temp_f
//#define temp_c
#define degree
//#define radian

// i2c device addresses; Sources [1][2]
#define MPU6050_ADDRESS  0b1101000
#define HMC5883L_ADDRESS 0b0011110
#define MS5611_ADDRESS   0b1110111

// globals for sensor current state; Sources [1][2]
float float_accel_x_g;
float float_accel_y_g;
float float_accel_z_g;
#ifdef temp_c
  float float_mpu_temp_c;
#endif
#ifdef temp_f
  float float_mpu_temp_f;
#endif
#ifdef radian
float float_gyro_x_rad;
float float_gyro_y_rad;
float float_gyro_z_rad;
#endif
#ifdef degree
float float_gyro_x_deg;
float float_gyro_y_deg;
float float_gyro_z_deg;
#endif
float float_magn_x_gs;
float float_magn_y_gs;
float float_magn_z_gs;
float float_pressure_mbar;
#ifdef temp_c
float float_baro_temp_c;
#endif
#ifdef temp_f
float float_baro_temp_f;
#endif

// globals for vehicle attitude and position
#ifdef degree
float float_roll_deg;
float float_pitch_deg;
float float_yaw_deg;
#endif
#ifdef radian
float float_roll_rad;
float float_pitch_rad;
float float_yaw_rad;
#endif
double double_latitude;
double double_longitude;
int int_x_distance_from_origin_cm;
int int_z_distance_from_origin_cm;
int int_altitude_from_origin_cm;

#endif