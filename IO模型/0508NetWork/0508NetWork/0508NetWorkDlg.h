
// 0508NetWorkDlg.h : ͷ�ļ�
//

#pragma once
#include "TCPNet.h"

// CMy0508NetWorkDlg �Ի���
class CMy0508NetWorkDlg : public CDialogEx
{
// ����
public:
	CMy0508NetWorkDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY0508NETWORK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	TCPNet  m_net;
};
