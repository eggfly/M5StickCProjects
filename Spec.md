Ucglib modifications:



// M5 modified start
#if ARDUINO >= 10600
      // SPI.begin();
      SPI.begin(13, -1, 15, 5);
      SPI.beginTransaction(SPISettings(1000000000UL/((ucg_com_info_t *)data)->serial_clk_speed, MSBFIRST, SPI_MODE0));
#else
      // SPI.begin();
      SPI.begin(13, -1, 15, 5);
// M5 modified end

* FPS Calculate
* reset问题
* 中文显示问题
* 颜色问题
* Adafruit 有SPI初始化问题还有颜色问题
* Ucglib有偏移量不对的问题和代码不好修改+复杂度比较高的问题（可以通过x y 偏移量绕过，但是旋转怎么办？）

@70Mhz / 4
21:19:04.832 -> Text: 039.1
21:19:16.950 -> Box: 052.0
21:19:29.104 -> Gradient: 042.8
21:19:41.767 -> Text: 039.1
21:19:53.902 -> Box: 052.0
21:20:06.053 -> Gradient: 042.9



@60Mhz / 4
21:24:03.387 -> Text: 039.1
21:24:15.530 -> Box: 052.0
21:24:27.651 -> Gradient: 042.8
21:24:40.318 -> Text: 039.1
21:24:52.478 -> Box: 052.0
21:25:04.618 -> Gradient: 042.9

@20Mhz / 4
21:28:26.966 -> Text: 035.0
21:28:39.123 -> Box: 042.3
21:28:51.330 -> Gradient: 036.1
21:29:03.983 -> Text: 035.0
21:29:16.135 -> Box: 042.3
21:29:28.335 -> Gradient: 036.1