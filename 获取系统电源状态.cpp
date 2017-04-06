// 获取系统电源状态.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	SYSTEM_POWER_STATUS SystemPowerStatus;
	if(GetSystemPowerStatus(&SystemPowerStatus)==0)
	{
		printf("获取电源状态错误,错误码:%d\r\n",GetLastError());
		system("pause>nul");
		exit(0);
	}
	switch(SystemPowerStatus.ACLineStatus)
	{
	case 0:
		{
			printf("交流电源状态:未连接\r\n");
			break;
		}
	case 1:
		{
			printf("交流电源状态:已连接\r\n");
			break;
		}
	case 255:
		{
			printf("交流电源状态:未知状态\r\n");
			break;
		}
	default:
		{
			printf("交流电源状态:未知参数\r\n");
			break;
		}
	}
	/*
	if(SystemPowerStatus.BatteryFlag&0x01)
	{
		printf("电池电量高于66%%");
	}
	if(SystemPowerStatus.BatteryFlag&0x02)
	{
		printf("电池电量低于33%%");
	}
	if(SystemPowerStatus.BatteryFlag&0x04)
	{
		printf("电池电量低于5%%");
	}
	*/
	if(SystemPowerStatus.BatteryFlag&0x08)
	{
		printf("电池充电状态:充电中\r\n");
	}
	if(SystemPowerStatus.BatteryFlag&0x80)
	{
		printf("电池充电状态:没有电池\r\n");
	}
	/*
	if(SystemPowerStatus.BatteryFlag&0xFF)
	{
		printf("未知状态\r\n");
	}
	*/
	if(SystemPowerStatus.BatteryLifePercent<=100)
	{
		printf("电池电量百分比:%d%%\r\n",SystemPowerStatus.BatteryLifePercent);
	}
	else
	{
		printf("电池电量百分比:未知\r\n");
	}
	if(SystemPowerStatus.BatteryLifeTime!=-1)
	{
		printf("电池续航时间:%d秒\r\n",SystemPowerStatus.BatteryLifeTime);
	}
	else
	{
		printf("电池续航时间:未知\r\n");
	}
	if(SystemPowerStatus.BatteryFullLifeTime!=-1)
	{
		printf("电池满电状态续航时间:%d秒\r\n",SystemPowerStatus.BatteryFullLifeTime);
	}
	else
	{
		printf("电池满电状态续航时间:未知\r\n");
	}
	system("pause>nul");
	return 0;
}

