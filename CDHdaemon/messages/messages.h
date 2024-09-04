#ifndef MESSAGES_H
#define MESSAGES_H

/*
 Automatically generated by parseMessages.py
 from messages.json
*/

#include <stdint.h>

// message name: opmodeADCS code: 20
#define OPMODEADCS_CODE 20
typedef struct {
	uint8_t code;
	uint8_t opmode;
}__attribute__((packed)) opmodeADCS;

// message name: attitudeADCS code: 21
#define ATTITUDEADCS_CODE 21
typedef struct {
	uint8_t code;
	float omega_x;
	float omega_y;
	float omega_z;
	float b_x;
	float b_y;
	float b_z;
	float DC_x;
	float DC_y;
	float DC_z;
	float P_x;
	float P_y;
	float P_z;
	float D_x;
	float D_y;
	float D_z;
	uint32_t ticktime;
}__attribute__((packed)) attitudeADCS;

// message name: housekeepingADCS code: 22
#define HOUSEKEEPINGADCS_CODE 22
typedef struct {
	uint8_t code;
	float temperature[8];
	uint16_t temperatureRAW[8];
	float current[5];
	uint16_t currentRAW[5];
	uint32_t ticktime;
}__attribute__((packed)) housekeepingADCS;

// message name: setOpmodeADCS code: 0
#define SETOPMODEADCS_CODE 0
typedef struct {
	uint8_t code;
	uint8_t opmode;
}__attribute__((packed)) setOpmodeADCS;

// message name: setAttitudeADCS code: 1
#define SETATTITUDEADCS_CODE 1
typedef struct {
	uint8_t code;
	float P_xx;
	float P_yy;
	float P_zz;
	float D_xx;
	float D_yy;
	float D_zz;
	float DC_xx;
	float DC_yy;
	float DC_zz;
	float dtheta_x;
	float dtheta_y;
	float dtheta_z;
}__attribute__((packed)) setAttitudeADCS;

#endif