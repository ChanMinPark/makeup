(!주의!) 아래 코드는 128x64 OLED에서 SPI방식으로 연결한 예이다!! I2C방식이나 128x32 OLED의 예제는 라이브러리의 예제에 있으니 거기를 참고하길 바랍니다!!!  

##1. 개요  
온도 측정 센서(18B20)에서 측정한 거리값을 아두이노로 받고, 이를 OLED 모듈에 출력한다.  
그리고 온도값이 28도를 넘어가면 적외선 송신기를 통해서 외부기기(ex.에어컨) 전원을 켠다.  

##2. 구성요소  
- WiDo(Arduino Leonardo + Adafruit Wi-Fi)  
- 18B20 (온도 측정 센서)  
- 128x64 OLED (OLED 디스플레이)  
- KY-005 (IR Emission)  

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

IR 송신기를 사용하기 위한 라이브러리가 필요하다.  
- https://github.com/z3t0/Arduino-IRremote  

##4. Pin Mapping  
#####(1) 18B20(온도센서)  
| Arduino |  18B20  |
|:-------:|:-------:|
| Gnd     | Gnd     |
| 5V      | Vcc     |
| D2      | Data    |

#####(2) 128x64 OLED (OLED 디스플레이)  
| Arduino | OLED |
|:-------:|:----:|
| D9      | Data |
| D10     | Clk  |
| D11     | DC   |
| D5      | Rst  |
| D12     | CS   |
| -       | 3v3  |
| 5V      | Vin  |
| GND     | Gnd  |

#####(3) KY-005 (IR Emission)  
| Arduino |  KY-005  |
|:-------:|:--------:|
| Gnd     | Gnd      |
| 5V      | Vcc      |
| D13     | Signal   |

##5. 구성한 모습  
![](https://github.com/ChanMinPark/makeup/blob/master/009_IR-Temp-OLED_Arduino/image/pic.jpg)
