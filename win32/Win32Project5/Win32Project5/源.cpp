// ���
// HDC        �����豸���            ��ͼ
// HINSTANCE  Ӧ�ó���ʵ���ľ��      ������Դ
// HWND       ���ھ��          

// ��Ϣ       WM_LBUTTONDOWN  WM_KEYDOWN  WM_TIMER   WM_CLOSE  WM_PAINT

#include<windows.h>
#include<stdio.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR pCmdLine,int nCmdShow)
{
	//  1.  ���
	WNDCLASSEX wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wndclass.hCursor = 0;
	wndclass.hIcon = 0;
	wndclass.hIconSm = 0;    //  �������ϵ�Сͼ��
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;   //  ���ڵ���Ϣ������
	wndclass.lpszClassName = "lele";  //  ע�ᴰ��������� 
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_HREDRAW|CS_VREDRAW;

	//  2.  ע��
	if( ::RegisterClassEx(&wndclass) == FALSE)
	{
		::MessageBox(0,"ע��ʧ��","��ʾ",MB_OK);
		return 0;
	}
	// 3. ����
	HWND hwnd = ::CreateWindow("lele","O(��_��)O����~",WS_OVERLAPPEDWINDOW,0,0,500,500,0,0,hInstance,0);
	if(hwnd == 0)
	{
		::MessageBox(0,"����ʧ��","��ʾ",MB_OK);
		return 0;
	}

	// 4. ��ʾ����
	::ShowWindow(hwnd,SW_SHOW);

	// 5. ��Ϣѭ��
	MSG msg;
	while(::GetMessage(&msg,0,0,0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);   // �ַ��� ������Ϣ�Ĵ�����WndProc
	}


	return 0;
}






LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int x;
	int y;

	HBRUSH hBrush;
	char str[15]={0};
	switch (uMsg)
	{
	case WM_PAINT:
		{
			HDC hdc=GetDC(hwnd);
			Rectangle(hdc,0 ,0,50,50);
			ReleaseDC(hwnd,hdc);
		}
		break;
	case WM_KEYDOWN:
		{
			if(wParam==65)
			{
				HDC hdc=GetDC(hwnd); 
				HBRUSH brush;
				brush=CreateSolidBrush(RGB(255,0,0));
				SelectObject(hdc,brush);
				Ellipse(hdc,60,90,90,120);

				ReleaseDC(hwnd,hdc);
			}
		}
		break;
	case WM_LBUTTONDOWN:
		{
			x = LOWORD (lParam) ;

			y = HIWORD (lParam) ;
			//sprintf(str,"(%d,%d)",x,y);
			//MessageBox(hwnd,str,"bbb",MB_YESNOCANCEL );
			
				HDC hdc=GetDC(hwnd); 
				HBRUSH brush;
				brush=CreateSolidBrush(RGB(255,0,0));
				SelectObject(hdc,brush);
				Ellipse(hdc,x-30,y-30,x+30,y+30);

				ReleaseDC(hwnd,hdc);

		}
		break;
		
	case WM_TIMER:
		break;
	case WM_CLOSE:  //  �ر�
		::PostQuitMessage(0);    //  ����һ���˳�����Ϣ
		break;

	}
	return DefWindowProc( hwnd,  uMsg,  wParam,  lParam);
}