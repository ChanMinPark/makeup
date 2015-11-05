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
(1) 파일시스템 확장하기  
micro sd card에 이미지를 업로드하면 micro sd card의 용량에 상관없이 라즈베리파이의 파일시스템 크기가 이미지파일 만큼만 설정된다.  
따라서, micro sd card의 모든 용량을 사용하기 위해서 파일시스템을 확장해주어야 한다.  

이 작업을 raspi-config의 1번 옵션에서 진행할수 있다.  ( 1 Expand Filesystem )  
1번 옵션에서 엔터만 치면 바로 완료가 된다.(리눅스에서는 수동으로 파일시스템을 확장하는 방법이 있는데 이 과정을 편리하게 진행해 주는 것 같다.)  

(2) 키보드 설정하기  
4번 옵션인 Internationalisation Options에 들어간다.  
그 다음 나타나는 메뉴에서 I3 Change Keyboard Layout을 선택한다. (잠시 멈추는 듯 했는데 그저 많은 옵션들을 불러오는데 시간이 걸린것 같다.)  
Generic 105-key (Intl) PC 를 선택한다.  
그럼 이제 키맵(?)을 선택하라고하는데 Others를 선택하면 더 많은 옵션이 나오고 Korean을 찾을 수 있다.  
그러면 또 Korean이랑 Korean - Korean (101/104 key compatible) 그리고 Other 메뉴가 뜨는데 나는 Korean - Korean (101/104 key compatible) 옵션을 선택했다.  
그 다음은 그냥 The default for the keyboard layout  
또 그 다음은 그냥 No compose key  
마지막으로 X server 재시동 하는 키조합을 사용하겠냐고 하는건데, 교재를 보니 별 의미 없으니 No 를 선택하라고 한다.  

