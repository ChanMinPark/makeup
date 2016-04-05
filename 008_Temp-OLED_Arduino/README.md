(!주의!) 아래 코드는 128x64 OLED에서 SPI방식으로 연결한 예이다!! I2C방식이나 128x32 OLED의 예제는 라이브러리의 예제에 있으니 거기를 참고하길 바랍니다!!!  

##1. 개요  
온도 측정 센서(18B20)에서 측정한 거리값을 아두이노로 받고, 이를 OLED 모듈에 출력한다.  

##2. 구성요소  
- WiDo(Arduino Leonardo + Adafruit Wi-Fi)  
- 18B20 (온도 측정 센서)  
- 128x64 OLED (OLED 디스플레이)  

##3. 필요한 라이브러리  
OLED를 사용하기 위한 라이브러리가 필요하다.  
- Adafruit_SSD1306  
  (https://github.com/adafruit/Adafruit_SSD1306)  
- Adafruit GFX Library  
  (https://github.com/adafruit/Adafruit-GFX-Library)  
  
18B20을 사용하기 위한 라이브러리도 필요하다.  
18B20의 경우 Data선을 한개만 사용한다. 이런 경우 OneWire 라이브러리가 필요하다고 한다.  
OneWire 방식으로 통신하는 센서의 경우, 아두이노 핀 한개에 여러개의 모듈이 연결되어도 각각을 모두 인식 할 수 있다고 한다.  
- OneWire  
http://www.pjrc.com/teensy/td_libs_OneWire.html  

##4. Pin Mapping  
#####(1) 18B20(온도센서)  
| Arduino |  18B20  |
|:-------:|:-------:|
| Gnd     | Gnd     |
| 5V      | Vcc     |
| D2      | Data    |

!!온도 센서 회로 구성에서의 특이점!!  
18B20의 경우 아래 사진의 왼쪽처럼 칩만 있는 경우에는 4.7K 저항을 연결해줘야 한다. 연결 회로 구성은 링크 참조.  
http://www.tweaking4all.com/hardware/arduino/arduino-ds18b20-temperature-sensor/  
하지만 아래 사진의 오른쪽처럼 보드에 붙어 있는 경우는 보드에서 저항을 함께 붙여놓은 제품이 있다. 이 경우엔 바로 아두이노와 연결하면 된다.  
![](https://github.com/ChanMinPark/makeup/blob/master/008_Temp-OLED_Arduino/image/18b20(1).jpg) ![](https://github.com/ChanMinPark/makeup/blob/master/008_Temp-OLED_Arduino/image/18b20(2).jpg)

#####(2) 128x64 OLED (OLED 디스플레이)  
| Arduino | OLED |
|:-------:|:----:|
| D9      | Data |
| D10     | Clk  |
| D11     | DC   |
| D13     | Rst  |
| D12     | CS   |
| -       | 3v3  |
| 5V      | Vin  |
| GND     | Gnd  |

##5. 구성한 모습  
![](https://github.com/ChanMinPark/makeup/blob/master/008_Temp-OLED_Arduino/image/temp-oled.jpg)
