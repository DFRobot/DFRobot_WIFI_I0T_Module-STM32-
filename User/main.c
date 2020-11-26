/*!
 * @file 
 * @brief ������ʹ�ô��ں�IOTģ��ͨ�ţ���ͬ��IOTƽ̨��������
 * @copyright    Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence      The MIT License (MIT)
 * @author       [tang](jie.tang@dfrobot.com)
 * @version      V1.0
 * @eGDAte       2020-08-21
 * @get          from https://www.dfrobot.com
 * @url          https://github.com/DFRobot/DFRobot_WiFi_IOT_Module(STM32)
 */
#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "DFRobot_wifi_iot.h"

//wifi 
#define WIFISSID     "hitest"  //WiFi����
#define WIFIPWS      "12345678" //wifi����

//MQTT
//#define MQTT
#ifdef MQTT
#define SERVER        "iot.dfrobot.com.cn"  //��������ַ
#define PORT          "1883"                //�˿ں�
#define DEVICENAME    "rHpr0RcWR"           //�û�����
#define DEVICESECRET  "9NtrAg5ZRz"          //�û���¼����
#define TOPIC         "OSpwrHHMg"           //����Ƶ��
#endif

//IFTTT
#define IFTTT
#ifdef IFTTT
#define IFTTTKEY      "dtpfTlU3Wqa8y0HRh77xXE"
#define IFTTTEVENT    "BBB"
#endif

//ThingSpeak
//#define THINGSPEAK
#ifdef THINGSPEAK
#define THINGSPEAKKEY "U01NPZTC2G9WTDNY"
#endif

int main()
{
	u8 i=0;  
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
	LED_Init();
	//USB��ӡ���� �����ڶ�Ӧ����:RX��ӦPA10��TX��Ӧ����PA9
	USART1_Init(9600);
	//IOTͨ�Ŵ��� �����ڶ�Ӧ���ţ�RX��ӦPB11��TX��Ӧ����PB10
	USART3_Init(9600);
	//����wifi
	connectWifi(WIFISSID,WIFIPWS);
	
	//����EASYIOT
	#ifdef MQTT
	mqtt(SERVER,PORT,DEVICENAME,DEVICESECRET,TOPIC);
	#endif
	
	#ifdef IFTTT
	configIFTTT(IFTTTEVENT,IFTTTKEY);
	#endif
	
	#ifdef THINGSPEAK
	configThingSpeak(THINGSPEAKKEY);
	#endif
	while(1){
		
		#ifdef MQTT
		//ʹ��MQTTʱ������
		publish(TOPIC,"HI TANG");
		#endif
		#ifdef IFTTT
		//����IFTTT ��IFTTTע���¼�������Ϣ
		IFTTTSendMasage("100","78","78");
		#endif
		#ifdef THINGSPEAK
		//����thingSpeak  ��thingSpeak������Ϣ
		thingSpeakSendMasage("5000", "100");
		#endif
		i+=10;
		if(i%20==0)
		{
			i=0;
			led1=!led1;
		}
		
		delay_ms(100);
		loop();
	}
}

