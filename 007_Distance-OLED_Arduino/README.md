(!주의!) 아래 코드는 128x64 OLED에서 SPI방식으로 연결한 예이다!! I2C방식이나 128x32 OLED의 예제는 라이브러리의 예제에 있으니 거기를 참고하길 바랍니다!!!  

##1. 개요  
초음파 거리 측정 센서에서 측정한 거리값을 아두이노로 받고, 이를 OLED 모듈에 출력한다.  

##2. 구성요소  
- WiDo(Arduino Leonardo + Adafruit Wi-Fi)  
- HC-SR04 (초음파 거리 측정 센서)  
- 128x64 OLED (OLED 디스플레이)  

##3. 필요한 라이브러리  
OLED를 사용하기 위한 라이브러리가 필요하다.  
- Adafruit_SSD1306  
  (https://github.com/adafruit/Adafruit_SSD1306)  
- Adafruit GFX Library  
  (https://github.com/adafruit/Adafruit-GFX-Library)  

##4. Pin Mapping  
#####(1) HS-SR04(초음파거리센서)  
| Arduino | HC-SR04 |
|:-------:|:-------:|
| 5V      | Vcc     |
| D2      | Trig    |
| D3      | Echo    |
| GND     | Gnd     |

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
![](https://github.com/ChanMinPark/makeup/blob/master/007_Distance-OLED_Arduino/image/pic.jpg)
