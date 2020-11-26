#ifndef _DFROBOT_WIFI_IOT_H
#define _DFROBOT_WIFI_IOT_H
#include "usart.h"
#include "system.h"
#include "SysTick.h"

/**
 * @brief ����MQTT����
 * @param url  ����������
 * @param port  �������˿ں�
 * @param iotid �������˺�
 * @param iotpwd �������˺�����
 * @param topic  ����Ƶ��
 */
void mqtt(const char* url, const char *port, const char *iotid, const char *iotpwd , const char *topic);
/**
 * @brief �������͵�������ƽ̨����
 */
void loop(void);
/**
 * @brief �������ݵ�MQTT������ 
 * @param data ��������
 */
void publish(const char *topic,const char *masag);
/**
 * @brief ʹ��HTTP postЭ�鷢�����ݵ�IFTTT
 * @param data ��������
 */
void IFTTTSendMasage(const char *data1, const char *data2, const char *data3);
/**
 * @brief ʹ��HTTP getЭ�鷢�����ݵ�ThingSpeak
 * @param key  ���ӷ�������Կ
 * @param data ��������
 */
void thingSpeakSendMasage(const char *data1, const char *data2);
/**
 * @brief ������յ�����
 */
void splitString(void);
/**
 * @brief wifi���Ӻ���
 * @param ssid wifi����
 * @param pwd  wifi����
 */
void connectWifi(const char *ssid , const char *pwd);
/**
 * @brief ����IFTTT
 * @param event �¼�
 * @param key   ��Կ
 */
void configIFTTT(const char *event , const char *key);
/**
 * @brief ����thingSpeak
 * @param key   ��Կ
 */
void configThingSpeak(const char *key);

#endif
