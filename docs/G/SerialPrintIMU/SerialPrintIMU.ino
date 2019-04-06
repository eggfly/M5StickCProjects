#include "Wire.h"

#define SH200I_ADDRESS 0x6C //7bit i2c address 
#define SH200I_WHOAMI 0x30
#define SH200I_ACC_CONFIG 0x0E
#define SH200I_GYRO_CONFIG 0x0F
#define SH200I_GYRO_DLPF 0x11
#define SH200I_FIFO_CONFIG 0x12
#define SH200I_ACC_RANGE 0x16
#define SH200I_GYRO_RANGE 0x2B
#define SH200I_OUTPUT_ACC_X 0x00
#define SH200I_OUTPUT_GYRO_X 0x06
#define SH200I_OUTPUT_TEMP 0x0C
#define SH200I_REG_SET1 0xBA
#define SH200I_REG_SET2 0xCA   //ADC reset
#define SH200I_ADC_RESET  0xC2   //drive reset
#define SH200I_SOFT_RESET 0x7F
#define SH200I_RESET 0x75


//i2c读写函数说明：
//读函数
//I2C_Read_NBytes(uint8_t driver_Addr, uint8_t start_Addr, uint8_t number_Bytes, uint8_t *read_Buffer)
///**
//  * @brief  I2C读函数，可以读取单个或者多个连续的字节。
//  * @param  driver_Addr(I2c器件的Slave地址，注意实际I2C驱动中7位地址和8位地址的区分)
//  * @param  start_Addr(需要读取的寄存器的起始地址)
//  * @param  number_Bytes(需要读取的数据的字节数)
//  * @param  read_Buffer(所读取寄存器的值)
//  */

void I2C_Read_NBytes(uint8_t driver_Addr, uint8_t start_Addr, uint8_t number_Bytes, uint8_t *read_Buffer);
void I2C_Write_NBytes(uint8_t driver_Addr, uint8_t start_Addr, uint8_t number_Bytes, uint8_t *write_Buffer);

void I2C_Read_NBytes(uint8_t driver_Addr, uint8_t start_Addr, uint8_t number_Bytes, uint8_t *read_Buffer) {
  Wire.beginTransmission(driver_Addr);
  Wire.write(start_Addr);
  Wire.endTransmission();
  Wire.requestFrom(driver_Addr, 1);
  byte buf = Wire.read();
  //Serial.printf("I2C Read OP, ADDR: 0x%02x, ADS: 0x%02x, NumBytes: %u, result: 0x%02x\n\r", driver_Addr, start_Addr, number_Bytes, buf);
  *read_Buffer = buf;
}

void I2C_Write_NBytes(uint8_t driver_Addr, uint8_t start_Addr, uint8_t number_Bytes, uint8_t *write_Buffer) {
  Wire.beginTransmission(driver_Addr);
  Wire.write(start_Addr);
  Wire.write(*write_Buffer);
  Wire.endTransmission();
  //Serial.printf("I2C Write OP, ADDR: 0x%02x, ADS: 0x%02x, NumBytes: %u, Data: 0x%02x\n\r", driver_Addr, start_Addr, number_Bytes, *write_Buffer);
}

void sh200i_ADCReset(void)
{
  unsigned char tempdata[1];
  //set 0xC2 bit2 1-->0
  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_ADC_RESET, 1, tempdata);

  tempdata[0] = tempdata[0] | 0x04;
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_ADC_RESET, 1, tempdata);
  delay(1);

  tempdata[0] = tempdata[0] & 0xFB;
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_ADC_RESET, 1, tempdata);
}

void sh200i_Reset(void)
{
  unsigned char tempdata[1];

  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_RESET, 1, tempdata);

  //SH200I_RESET
  tempdata[0] = tempdata[0] | 0x80;
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_RESET, 1, tempdata);

  delay(1);

  tempdata[0] = tempdata[0] & 0x7F;
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_RESET, 1, tempdata);
}




//初始化
void sh200i_init(void)
{
  unsigned char tempdata[1];

  while (tempdata[0] != 0x18)
  {
    I2C_Read_NBytes(SH200I_ADDRESS, SH200I_WHOAMI, 1, tempdata);
  }

  sh200i_ADCReset();

  I2C_Read_NBytes(SH200I_ADDRESS, 0xD8, 1, tempdata);

  tempdata[0] = tempdata[0] | 0x80;
  I2C_Write_NBytes(SH200I_ADDRESS, 0xD8, 1, tempdata);

  delay(1);

  tempdata[0] = tempdata[0] & 0x7F;
  I2C_Write_NBytes(SH200I_ADDRESS, 0xD8, 1, tempdata);

  tempdata[0] = 0x61;
  I2C_Write_NBytes(SH200I_ADDRESS, 0x78, 1, tempdata);

  delay(1);

  tempdata[0] = 0x00;
  I2C_Write_NBytes(SH200I_ADDRESS, 0x78, 1, tempdata);

  //set acc odr 256hz
  tempdata[0] = 0x91; //0x81 1024hz   //0x89 512hz    //0x91  256hz
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_ACC_CONFIG, 1, tempdata);

  //set gyro odr 500hz
  tempdata[0] = 0x13; //0x11 1000hz    //0x13  500hz   //0x15  256hz
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_GYRO_CONFIG, 1, tempdata);

  //set gyro dlpf 50hz
  tempdata[0] = 0x03; //0x00 250hz   //0x01 200hz   0x02 100hz  0x03 50hz  0x04 25hz
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_GYRO_DLPF, 1, tempdata);

  //set no buffer mode
  tempdata[0] = 0x00;
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_FIFO_CONFIG, 1, tempdata);

  //set acc range +-8G
  tempdata[0] = 0x01;
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_ACC_RANGE, 1, tempdata);

  //set gyro range +-2000¶È/s
  tempdata[0] = 0x00;
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_GYRO_RANGE, 1, tempdata);

  tempdata[0] = 0xC0;
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_REG_SET1, 1, tempdata);

  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_REG_SET2, 1, tempdata);

  //ADC Reset
  tempdata[0] = tempdata[0] | 0x10;
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_REG_SET2, 1, tempdata);

  delay(1);

  tempdata[0] = tempdata[0] & 0xEF;
  I2C_Write_NBytes(SH200I_ADDRESS, SH200I_REG_SET2, 1, tempdata);

  delay(10);
}


void setup() {
  Wire.begin();

  Serial.begin(115200);
  while (!Serial);             // Leonardo: wait for serial monitor

  Wire.beginTransmission(0x34);
  Wire.write(0x10);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x82);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x33);
  Wire.write(0xC0);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0x33);
  Wire.write(0xC3);
  Wire.endTransmission();

  Wire.beginTransmission(0x34);
  Wire.write(0xB8);
  Wire.write(0x80);
  Wire.endTransmission();
  sh200i_init();

}

int16_t accX = 0;
int16_t accY = 0;

void loop(void) {

  unsigned char tempdata[1];
  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X, 1, tempdata);
  accX = tempdata[0];
  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 1, 1, tempdata);
  accX |= tempdata[0] << 8;


  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 2, 1, tempdata);
  accY = tempdata[0];
  I2C_Read_NBytes(SH200I_ADDRESS, SH200I_OUTPUT_ACC_X + 3, 1, tempdata);
  accY |= tempdata[0] << 8;

  Serial.printf("%ld,%ld\r\n", accX, accY);

}
