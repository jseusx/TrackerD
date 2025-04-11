#ifndef _common_h_
#define _common_h_

#include "WiFi.h"
#include "EEPROM.h"
#include "Wire.h"
#include "lora.h"
#include "extiButton.h"


#define Pro_model           "LGT92 "
#define Pro_version         "v1.0.0 "
#define EEPROM_DATA_SIZE    512
#define EEPROM_KEY_SIZE     68
#define EEPROM_GPSDATA_SIZE 4096

#define BAT_PIN_READ    35
#define BAT_PIN_LOW     4
#define LED_PIN_RED     13
#define LED_PIN_BLUE    2
#define LED_PIN_GREEN   15

#define DEFAULT_MODE                0x00
#define MOVE_DETECT_MODE            0x01
#define COLLISION_DETECT_MODE       0x02
#define CUSTOM_MOVE_DETECT_MODE     0x03
#define GXHT3x_MODE                 0x04

class SYS:public LORA
{
  public:   
    SYS(uint8_t pin_red=LED_PIN_RED,uint8_t pin_blue=LED_PIN_BLUE,uint8_t pin_green=LED_PIN_GREEN);
    ~SYS(void);
    void eeprom_init(void);
    void DATA_CLEAR(void);
    void config_Write(void);
    void config_Read(void);
    void gps_data_Weite(void);
    void gps_data_Read(void);
    void read_gps_data_on_flash();
    void GPSDATA_CLEAR(void);
    uint8_t     gps_data_buff[15];
    uint32_t    tdc = 1200000;     //uint:ms
    uint8_t     mod = 0;
    uint8_t     lon = 1;      //1:on  2:0ff
    uint32_t    Positioning_time = 180000;
    uint8_t     frame = 0;
    uint8_t     alarm = 0;
    uint8_t     gps_start = 1;
    uint8_t     gps_alarm = 0;
    uint8_t     alarm_count = 0;
    uint8_t     buzzer_flag = 0;
    uint8_t     exti_flag = 1;
    uint8_t     sleep_flag = 0;
    uint8_t     port = 2;
    uint8_t     sensor_mode = 1;
    uint16_t    fire_version=0;
    uint8_t     channel_single = 1;
    uint32_t    addr_gps_write=0;
    uint32_t    addr_gps_read=0;
    uint8_t     frame_ACK =0;
    uint8_t     frame_flag = 0;
    uint8_t     loggpsdata_send = 0;
    int         data_read = 0;
    bool        gps_work_flag = true;
    bool        collect_sensor_flag = false; 
       
  private: 
};
class Devicet
{
  public: 
    uint8_t sensor_type;
    
    uint16_t firm_ver;
    
    uint8_t freq_band;
    
    uint8_t sub_band;
    
    uint16_t battrey;  
};

#include "at.h"
#include "GPS.h"
#include "GXHT30.h"

class Sensor
{
  public:
    int hum=0;
    int tem=0;
    int bat=0;
    int latitude=0;
    int longitude=0;
    int year_gps = 0;
    int month_gps = 0;
    int day_gps = 0;
    int hour_gps = 0;
    int minute_gps = 0;
    int second_gps = 0;
    float pdop_gps ; 
    int Fix_Status;   
    int16_t x=0;
    int16_t y=0;
    int16_t z=0;
};

extern SYS sys;
extern Sensor sensor;
extern Devicet devicet;

int BatGet(void);
void buzzer(void);
void Stop_buzzer(void);
void Device_status();
void I2C_Sent(int addr,uint8_t* buff,uint8_t buff_len);
void I2C_Read(int addr,uint8_t* buff,uint8_t buff_len,int delay_ms);
char *rtrim(char* str);
void StrToHex(uint8_t *pbDest, char *pszSrc, int nLen);
uint16_t string_touint(void);
void Device_status();
#endif
