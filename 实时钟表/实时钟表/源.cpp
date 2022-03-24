#include<graphics.h>
#include<conio.h>
#include<math.h>

#define High 480        //����ߴ�
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

	int secondEnd_x, secondEnd_y;//�����յ�
	int minuteEnd_x, minuteEnd_y;
	int hourEnd_x, hourEnd_y;
	float secondAngle;
	float minuteAngle;
	float hourAngle;

	SYSTEMTIME ti;//��������洢ϵͳʱ��
	BeginBatchDraw();
	while (1)
	{
		//���Ʊ���
		setlinestyle(PS_SOLID,1);
		setcolor(WHITE);
		circle(center_x,center_y,Width/4);
		//���̶�
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
		GetLocalTime(&ti);//��ȡ��ǰʱ��
		secondAngle = ti.wSecond * 2 * PI / 60;//�����Ӧ�Ƕȱ仯
		minuteAngle = ti.wSecond * 2 * PI / 60;
		hourAngle = ti.wSecond * 2 * PI / 12;
		//�ǶȾ����Ķ˵�����仯
		secondEnd_x = center_x + secondLength * sin(secondAngle);
		secondEnd_y = center_y - secondLength * cos(secondAngle);
		minuteEnd_x = center_x + minuteLength * sin(minuteAngle);
		minuteEnd_y = center_y - minuteLength * cos(minuteAngle);
		hourEnd_x = center_x + hourLength * sin(hourAngle);
		hourEnd_y = center_y - hourLength * cos(hourAngle);
		//����
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
		line(center_x,center_y,secondEnd_x,secondEnd_y);//����ǰһ���ͼ��
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