##1. 개요  
- 최초에 다운받은 라즈비안에 개발을 위해 필요한 Setting을 기록한다.  

##2. 진행사항  
- 라즈비안 다운로드  
[https://www.raspberrypi.org/downloads/raspbian/](https://www.raspberrypi.org/downloads/raspbian/)  
링크에서 라즈비안을 다운받을 수 있다.  
참고하는 서적에서 RASPBIAN WHEEZY를 사용해서 나도 이것을 다운 받았다.  

- sd card에 라즈비안 이미지 업로드 하기  
[http://sourceforge.net/projects/win32diskimager/](http://sourceforge.net/projects/win32diskimager/)  
micro sd card를 먼저 컴퓨터에 인식시킨 후에 이미지라이터를 실행한다.  
다운받은 이미지를 선택하고 Write를 눌러서 micro sd card에 라즈비안 이미지를 업로드한다.  

- 라즈베리파이 동작하기  
라즈비안을 업로드 시킨 micro sd card를 라즈베리파이에 장착시키고, 전원 케이블을 연결한다.  
(주의사항!! 구매를 해외에서 하다보니 전원 어댑터의 모양이 국내용(원형)이 아니고 미국용(옛날에 우리나라도 쓰던 납작한거 2개 달린거)이었다... 그래서 전원을 줄 수가 없다 ㅠㅠ)  
생각해보니 어차피 전원이 5pin 갤럭시 충전기랑 똑같다. 그래서 핸드폰 충전기로 전원을 인가하였다.  
라즈비안을 micro sd card에 업로드하고 처음 부팅을하면 로그가 쭈욱 올라가다가 바로 **바란배경의 raspi-config 화면**이 나온다.  
우선 기본적인 설정을 진행한다.  

#####(1) 파일시스템 확장하기  
micro sd card에 이미지를 업로드하면 micro sd card의 용량에 상관없이 라즈베리파이의 파일시스템 크기가 이미지파일 만큼만 설정된다.  
따라서, micro sd card의 모든 용량을 사용하기 위해서 파일시스템을 확장해주어야 한다.  

이 작업을 raspi-config의 1번 옵션에서 진행할수 있다.  ( 1 Expand Filesystem )  
1번 옵션에서 엔터만 치면 바로 완료가 된다.(리눅스에서는 수동으로 파일시스템을 확장하는 방법이 있는데 이 과정을 편리하게 진행해 주는 것 같다.)  

#####(2) 키보드 설정하기  
4번 옵션인 Internationalisation Options에 들어간다.  
그 다음 나타나는 메뉴에서 I3 Change Keyboard Layout을 선택한다. (잠시 멈추는 듯 했는데 그저 많은 옵션들을 불러오는데 시간이 걸린것 같다.)  
Generic 105-key (Intl) PC 를 선택한다.  
그럼 이제 키맵(?)을 선택하라고하는데 Others를 선택하면 더 많은 옵션이 나오고 Korean을 찾을 수 있다.  
그러면 또 Korean이랑 Korean - Korean (101/104 key compatible) 그리고 Other 메뉴가 뜨는데 나는 Korean - Korean (101/104 key compatible) 옵션을 선택했다.  
그 다음은 그냥 The default for the keyboard layout  
또 그 다음은 그냥 No compose key  
마지막으로 X server 재시동 하는 키조합을 사용하겠냐고 하는건데, 교재를 보니 별 의미 없으니 No 를 선택하라고 한다.  
완료하면 맨 처음 메뉴로 복귀한다.  

#####(3) 패스워드 변경하기  
pi 사용자의 계정에 쓰일 패스워드를 변경해준다.  
기본으로 raspberry라고 설정되어 있다는데, 자신이 사용할 패스워드로 변경해준다.  
2번 옵션인 Change User Password를 선택한다.  
Ok를 눌러서 Password를 입력한다.  
대부분의 패스워드가 그렇듯이 2번 입력하면 완료된다.  
참고로 패스워드는 표시가 되지 않으며 대소문자를 구분한다고 한다.  

#####(4) 로케일 설정하기  
사용자의 지역을 설정하는 부분이다.  
4번 옵션인 Internationalisation Options를 선택한다.  
다음, I1 Change Locale을 선택한다.  
여기서 다수 옵션을 선택할 수 있는데(선택은 스페이스바) 나는 en_GB.UTF-8 / en_US.UTF-8 / ko_KR.EUC-KR / ko_KR.UTF-8 을 선택했다.  
그리고 다음 화면은 default를 선택하는 것인데, 난 ko_KR.UTF-8을 선택했다.  
설정하는데 시간이 좀 걸린다.(그래봤자 몇분정도)  

#####(5) 시간대 변경하기  
4번 옵션인 Internationalisation Options를 선택한다.  
다음, I2 Change Timezone을 선택한다.  
Asia를 선택하고, Seoul을 선택한다.  

이제 끝났다. 메인 메뉴에서 Finish를 선택하면 라즈베리파이가 재부팅된다.  
재부팅이 완료되면 raspberrypi login이라고 뜨면서 아이디를 입력하라고 하는데  
이때, 아이디에 pi 를 치고 패스워드는 아까 변경했던 그 패스워드를 입력하면 커맨드라인이 나타난다.  


- Raspberry Pi에 수동으로 무선랜 설정하기  

    1) wpa_supplicant.conf설정  
    sudo nano /etc/wpa_supplicant/wpa_supplicant.conf  
    위의 명령어로 wpa_supplicant.conf 파일을 열어서 연결하려는 AP의 정보를 입력한다.  
    
    만약 비밀번호가 없는 open된 AP의 경우  
    ```
    network={  
        ssid="ssid이름"  
        key_mgmt=NONE  
        auth_alg=OPEN  
    }  
    ```

    비밀번호가 있고 인증방식을 PSK로 사용하면 아래와 같이 입력한다.  
    ```
    network={  
        ssid="ssid이름"  
        key_mgmt=WPA-PSK  
        psk="ssid비밀번호"  
    }  
    ```
    
    2) /etc/network/interfaces 설정  
    sudo nano /etc/network/interfaces  
    기본적으로 초기 설정되어 있는 그대로 두면 되는데 아래 내용이 초기 설정이다.  
    ```
     auto lo
     iface lo inet loopback
     
     auto eth0
     allow-hotplug eth0
     iface eth0 inet manual
     
     auto wlan0
     allow-hotplug wlan0
     iface wlan0 inet manual
     wpa-conf /etc/wpa_supplicant/wpa_supplicant.conf
     
     auto wlan1
     allow-hotplug wlan1
     iface wlan1 inet manual
     wpa-conf /etc/wpa_supplicant/wpa_supplicant.conf
    ```

    이렇게 설정을 완료하고 sudo reboot 으로 재부팅하고 ifconfig 로 무선 ip가 잡힌것을 확인할 수 있다.  
    
- 라즈베리파이에 고정 ip 설정하기  
라즈베리파이가 붙어있는 AP가 dhcp를 운영하더라고 라즈베리파이에서 고정 ip를 지정할 수 있다.  
유/무선 모두 가능하다.  
방법은 /etc/network/interfaces 의 내용을 아래와 같이 수정해 주면 된다.  
```
기존에 아래와 같이 되어 있는데
1 auto wlan0
2 allow-hotplug wlan0
3 iface wlan0 inet manual
4 wpa-conf /etc/wpa_supplicant/wpa_supplicant.conf

이렇게 3번줄을 manual에서 static으로 수정하고, 4~6번 줄을 추가 한다.
1 auto wlan0
2 allow-hotplug wlan0
3 iface wlan0 inet static
4 address "원하는 ip (ex. 192.168.0.123)"
5 netmask 255.255.255.0**
6 gateway "접속한 AP의 gateway주소 (ex. 192.168.0.1)"
7 wpa-conf /etc/wpa_supplicant/wpa_supplicant.conf
```
나는 무선을 사용하기 때문에 wlan0에 설정하였는데 유선을 사용하면 eth0에 수정/추가 하면된다.  
변경된 내용을 저장하고  
```
sudo /etc/init.d/networking restart
```
를 해서 네트워킹을 재시작한다. 그냥 재부팅해도 된다.  
재부팅하고 ifconfig로 변경 사항을 확인할 수 있다.  


- 다음에는 한글 설정을 해야겠다.  
