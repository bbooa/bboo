
// 0508NetWork.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy0508NetWorkApp:
// �йش����ʵ�֣������ 0508NetWork.cpp
//

class CMy0508NetWorkApp : public CWinApp
{
public:
	CMy0508NetWorkApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy0508NetWorkApp theApp;