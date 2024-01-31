/*
 * icm20602_chuli.h
 *
 *  Created on: 2023Äê4ÔÂ16ÈÕ
 *      Author: ¹¢Ë§¸ç
 */

#ifndef ICM20602_CHULI_H_
#define ICM20602_CHULI_H_

extern int16 Pitch, Yaw;
extern int16 imu660ra_gyro_x, imu660ra_gyro_y, imu660ra_gyro_z;
extern int16 imu660ra_acc_x, imu660ra_acc_y, imu660ra_acc_z;
extern int gyroscope_time;
void my_imu660ra_date_chuli(void);
void Angle_add();
void Angle_Get();
float Complementary(float newAngle, float newRate);
void imu_open();

#endif /* ICM20602_CHULI_H_ */
