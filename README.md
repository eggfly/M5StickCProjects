# M5StickC demo projects
* Gauge: 官方最早的demo
* 8563_RTC: RTC
* StickWatch2: 2代手表demo
* StickWatch2PowerManagment、AXP192: 电源管理
* docs: 一些datasheet和文档
* tools: 一些工具
* StickWatch2AdafruitGRAM: BadApple串口接收端代码（BadApple切图打包下载：链接：https://pan.baidu.com/s/1W5UOgj8KgGAxLwByfdQRkw 提取码：49pz）
* python: 一些python脚本，包括BadApple串口发送端代码（Python3+pyserial）

## 图形库
一些项目中的src/Adafruit_GFX目录，是我对Adafruit_GFX进行了一些修改后，对80x160彩屏适配的GFX的18位的图形库，经过测试基本上fps可以达到50到60fps，人眼观察完全无闪烁。思路是把所有绘图操作通过canvas进行，canvas是在esp32内存中开辟的一块GRAM，然后SPI把GRAM数据传输到ST7735驱动芯片。

link: https://item.taobao.com/item.htm?id=588710395351
