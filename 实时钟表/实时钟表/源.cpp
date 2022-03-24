#include<graphics.h>
#include<conio.h>
#include<math.h>

#define High 480        //画面尺寸
#define Width 640
#define PI 3.14159
int main()
{
	initgraph(Width,High);
	int center_x, center_y;
	center_x = Width / 2;
	center_y = High / 2;
	int secondLength = Width / 7;
	int minuteLength = Width / 6;
	int hourLength = Width / 5;

	int secondEnd_x, secondEnd_y;//秒针终点
	int minuteEnd_x, minuteEnd_y;
	int hourEnd_x, hourEnd_y;
	float secondAngle;
	float minuteAngle;
	float hourAngle;

	SYSTEMTIME ti;//定义变量存储系统时间
	BeginBatchDraw();
	while (1)
	{
		//绘制表盘
		setlinestyle(PS_SOLID,1);
		setcolor(WHITE);
		circle(center_x,center_y,Width/4);
		//画刻度
		int x, y, i;
		for (i = 0; i < 60; i++)
		{
			x = center_x + int(Width / 4.3 * sin(PI * 2 * i / 60));
			y = center_y + int(Width / 4.3 * cos(PI * 2 * i / 60));
			if (i % 15 == 0)
				bar(x - 5, y - 5, x + 5, y + 5);
			else if (i % 5 == 0)
				circle(x, y, 3);
			else
				putpixel(x,y,WHITE);
		}
		//outtextxy(center_x-25,center_y+Width/6,"time");
		GetLocalTime(&ti);//获取当前时间
		secondAngle = ti.wSecond * 2 * PI / 60;//秒针对应角度变化
		minuteAngle = ti.wSecond * 2 * PI / 60;
		hourAngle = ti.wSecond * 2 * PI / 12;
		//角度决定的端点坐标变化
		secondEnd_x = center_x + secondLength * sin(secondAngle);
		secondEnd_y = center_y - secondLength * cos(secondAngle);
		minuteEnd_x = center_x + minuteLength * sin(minuteAngle);
		minuteEnd_y = center_y - minuteLength * cos(minuteAngle);
		hourEnd_x = center_x + hourLength * sin(hourAngle);
		hourEnd_y = center_y - hourLength * cos(hourAngle);
		//画针
		setlinestyle(PS_SOLID,2);
		setcolor(YELLOW);
		line(center_x,center_y,secondEnd_x,secondEnd_y);
		setlinestyle(PS_SOLID,4);
		setcolor(BLUE);
		line(center_x,center_y,minuteEnd_x,minuteEnd_y);
		setlinestyle(PS_SOLID,6);
		setcolor(RED);
		line(center_x,center_y,hourEnd_x,hourEnd_y);

		FlushBatchDraw();
		Sleep(10);

		setcolor(BLACK);
		setlinestyle(PS_SOLID,2);
		line(center_x,center_y,secondEnd_x,secondEnd_y);//隐藏前一秒的图形
		setlinestyle(PS_SOLID, 5);
		line(center_x, center_y, minuteEnd_x, minuteEnd_y);
       	setlinestyle(PS_SOLID, 10);
		line(center_x, center_y, hourEnd_x, hourEnd_y);
	}
	EndBatchDraw();
	_getch();
	closegraph();
	return 0;
}