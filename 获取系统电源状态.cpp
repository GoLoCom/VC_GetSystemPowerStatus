// ��ȡϵͳ��Դ״̬.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	SYSTEM_POWER_STATUS SystemPowerStatus;
	if(GetSystemPowerStatus(&SystemPowerStatus)==0)
	{
		printf("��ȡ��Դ״̬����,������:%d\r\n",GetLastError());
		system("pause>nul");
		exit(0);
	}
	switch(SystemPowerStatus.ACLineStatus)
	{
	case 0:
		{
			printf("������Դ״̬:δ����\r\n");
			break;
		}
	case 1:
		{
			printf("������Դ״̬:������\r\n");
			break;
		}
	case 255:
		{
			printf("������Դ״̬:δ֪״̬\r\n");
			break;
		}
	default:
		{
			printf("������Դ״̬:δ֪����\r\n");
			break;
		}
	}
	/*
	if(SystemPowerStatus.BatteryFlag&0x01)
	{
		printf("��ص�������66%%");
	}
	if(SystemPowerStatus.BatteryFlag&0x02)
	{
		printf("��ص�������33%%");
	}
	if(SystemPowerStatus.BatteryFlag&0x04)
	{
		printf("��ص�������5%%");
	}
	*/
	if(SystemPowerStatus.BatteryFlag&0x08)
	{
		printf("��س��״̬:�����\r\n");
	}
	if(SystemPowerStatus.BatteryFlag&0x80)
	{
		printf("��س��״̬:û�е��\r\n");
	}
	/*
	if(SystemPowerStatus.BatteryFlag&0xFF)
	{
		printf("δ֪״̬\r\n");
	}
	*/
	if(SystemPowerStatus.BatteryLifePercent<=100)
	{
		printf("��ص����ٷֱ�:%d%%\r\n",SystemPowerStatus.BatteryLifePercent);
	}
	else
	{
		printf("��ص����ٷֱ�:δ֪\r\n");
	}
	if(SystemPowerStatus.BatteryLifeTime!=-1)
	{
		printf("�������ʱ��:%d��\r\n",SystemPowerStatus.BatteryLifeTime);
	}
	else
	{
		printf("�������ʱ��:δ֪\r\n");
	}
	if(SystemPowerStatus.BatteryFullLifeTime!=-1)
	{
		printf("�������״̬����ʱ��:%d��\r\n",SystemPowerStatus.BatteryFullLifeTime);
	}
	else
	{
		printf("�������״̬����ʱ��:δ֪\r\n");
	}
	system("pause>nul");
	return 0;
}

