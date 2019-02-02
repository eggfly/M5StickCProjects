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

