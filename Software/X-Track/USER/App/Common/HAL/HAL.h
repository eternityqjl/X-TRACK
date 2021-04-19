#ifndef __HAL_H
#define __HAL_H

#include <stdint.h>
#include "HAL_Def.h"

namespace HAL {
    
void HAL_Init();
void HAL_Update();

/*Backlight*/
void Backlight_Init();
uint16_t Backlight_GetValue();
void Backlight_SetValue(int16_t val);
void Backlight_SetGradual(uint16_t target, uint16_t time = 500);
void Backlight_UpdateBKP(void);
uint16_t Backlight_GetBKP(void);

/*I2C*/
void I2C_Scan(bool startScan);

/*IMU*/
void IMU_Init();
void IMU_Update();
int16_t IMU_GetSteps();
    
/*MAG*/
void MAG_Init();
void MAG_Update();

/*SD*/
void SD_Init();
void SD_Update();
bool SD_GetReady();

/*Power*/
void Power_Init();
void Power_HandleTimeUpdate();
void Power_SetAutoLowPowerTimeout(uint16_t sec);
uint16_t Power_GetAutoLowPowerTimeout();
void Power_SetAutoLowPowerEnable(bool en);
void Power_Shutdown();
void Power_Update();
void Power_GetInfo(Power_Info_t* info);

/*Clock*/
void Clock_Init();
void Clock_GetInfo(Clock_Info_t* info);
void Clock_SetInfo(const Clock_Info_t* info);
const char* Clock_GetWeekString(uint8_t week);

/*GPS*/
void GPS_Init();
void GPS_Update();
bool GPS_GetInfo(GPS_Info_t* info);
bool GPS_LocationIsValid();

/*Buzzer*/
void Buzz_init();
void Buzz_SetEnable(bool en);
void Buzz_Tone(uint32_t freq, int32_t duration = -1);

/*Encoder*/
void Encoder_Init();
void Encoder_Update();
int32_t Encoder_GetDiff();
bool Encoder_GetIsPush();

/*Audio*/
void Audio_Init();
void Audio_Update();
bool Audio_PlayMusic(const char* name);

/*AHRS*/
void AHRS_Update();
void AHRS_GetInfo(AHRS_Info_t* info);

}

#endif
