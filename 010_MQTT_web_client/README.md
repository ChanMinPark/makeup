##1. 개요  
MQTT Subscribe Client를 Web에서 구현한다. 즉, MQTT Web Subscribe Client를 구현하는 것이다.  
Javascript에서 웹소켓을 통하여 MQTT Broker에 접속한다. 이때, MQTT Broker는 반드시 Websockets을 지원해야만 가능하다.  
다양한 MQTT Broker의 기능 여부를 아래 링크에서 확인할 수 있다.  
https://github.com/mqtt/mqtt.github.io/wiki/Server%20support  

##2. 개발 환경  
- Windows 7
- STS(Spring Tool Suite 3.7.3.RELEASE)  
- Tomcat 7  
- JDK, JRE 1.8  

##3. 필요한 라이브러리  
Javascript에서 MQTT Client를 구현하기 위해서는 라이브러리가 필요하다.  
여기서는 Paho에서 구현한 라이브러리를 이용한다. Paho는 다양한 플랫폼에서의 MQTT Client 라이브러리를 구현해 놓았다.  
그중에서 Javascript를 위한 라이브러리는 'mqttws31.js'이며 이는 아래 링크에서 다운로드 할 수 있다.  
이 라이브러리를 이용하면 Sub/Pub 모두 가능하다.  

- MQTT Client for Javascript(Paho)  
  (https://www.eclipse.org/downloads/download.php?file=/paho/1.1/paho.javascript-1.0.1.zip)  
  
압축을 해제하면 안에서 'mqttws31.js'를 찾을 수 있다.

##4. 라이브러리 추가 및 설정  
(참고. 필자는 STS에서 프로젝트를 Spring MVC Project로 생성하였다. 프로젝트의 종류에 따라 디렉토리 구성이 조금씩 다른듯 하다.)  
다운받은 라이브러리를 사용하기 위해서 프로젝트에 추가해줘야 하고, 추가적인 설정이 필요하다.  
우선 라이브러리(mqttws31.js)를 아래와 같이 src/main/webapp/resources/js 에 추가하였다.  
![](https://github.com/ChanMinPark/makeup/blob/master/010_MQTT_web_client/image/image1_directory.JPG)  
  
그리고 추가한 라이브러리를 프로젝트가 찾을 수 있게 위치를 알려줘야 한다. 그 작업은 servlet-context.xml에 해준다.  
아래의 그림과 같이 js에 대한 리소스 경로를 추가해준다.  
마지막 줄을 추가한 것이다.  
![](https://github.com/ChanMinPark/makeup/blob/master/010_MQTT_web_client/image/image2_servletcontext.JPG)

##5. 소스코드  
필자가 작성한 소스코드(javascript가 작성된 jsp파일)은 아래 링크에서 확인할 수 있다.  
![](https://github.com/ChanMinPark/makeup/blob/master/010_MQTT_web_client/code/mqttwebclientpage.jsp)  

더 기본적이고 추가적인 설명은 Paho에서 제공하는 예제와 API doc을 확인하는 것이 좋다.  
- Paho의 예제(하단에 예제가 있다.)  
  (https://www.eclipse.org/paho/clients/js/)
- MQTT Client for Javascript(Paho) API doc  
  (http://www.eclipse.org/paho/files/jsdoc/symbols/Paho.MQTT.Client.html#disconnect)  

##6. 구현 페이지  
필자가 작성한 페이지는 아래와 같이 구현된다.  
![](https://github.com/ChanMinPark/makeup/blob/master/010_MQTT_web_client/image/image3_web.JPG)  

동작 테스트는 Paho에서 Web을 이용한 client 구현을 테스트 할 수 있게 제공하는 사이트를 이용한다.  
http://www.eclipse.org/paho/clients/js/utility/index.html  

위의 사이트에서 상단의 Client ID만 대강 수정해주고 Connect를 누르면 Paho쪽의 MQTT Broker에 접속된다.  
아래에서 Sub/Pub 테스트를 모두 할 수 있다.  
