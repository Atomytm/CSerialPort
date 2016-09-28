#include "SerialPort.h"
#include "PushPin.h"
#include "afxwin.h"
#ifndef _MAINDLG_H_
#define _MAINDLG_H_
#pragma once


class CMainDlg : public CDialog
{
public:
	CMainDlg(CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CMainDlg)
	enum { IDD = IDD_MAIN_DIALOG };

	CComboBox m_ctrlComId;
	CComboBox m_ctrlSpeed;
	CComboBox m_ctrlParity;
	CComboBox m_ctrlDataBits;
	CComboBox m_ctrlStopBits;
	CStatic	m_ctrlPortStatus;
	CButton	m_ctrlOpenPort;
	
	CButton m_ctrlRecvFilePath;
	CButton	m_ctrlRecvNotShow;
	CButton	m_ctrRecvHex;
	CEdit m_ctrRecvText;
	CString	m_strRecvText;
	
	CButton m_ctrlSendFilePath;
	CButton	m_ctrlSendHex;
	CButton	m_ctrlSendAuto;
	CEdit m_ctrlSendCycleTime;
	UINT m_nSendCycleTime;
	CButton	m_ctrlSendClear;
	CEdit	m_ctrlSendText;
	CString	m_strSendText;
	CButton m_ctrlSend;

	CPushPinButton m_ctrlDesktop;
	CStatic	m_ctrlStatus;
	CStatic	m_ctrlTXCount;
	CStatic	m_ctrlRXCount;
	CButton	m_ctrlResetCount;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON	m_hIcon;
	BOOL	m_bOpenedPort;
	int		m_nComId;			//���ں�
	int		m_nBaud;			//������
	char	m_cParity;			//У��
	int		m_nDatabits;		//����λ
	int		m_nStopbits;		//ֹͣλ
	DWORD	m_dwCommEvents;
	HICON m_hIconOn;			//���ڴ�ʱ�ĺ��ͼ����
	HICON m_hIconOff;			//���ڹر�ʱ��ָʾͼ����
	CSerialPort m_Port;			//CSerialPort�����
	
	BOOL m_bOnTop;				//�����ö�

	CString	m_strRecvFile;		//�����ļ�·��
	BOOL	m_bRecvFile;		//�Ƿ�����ļ�
	CFile	m_RecvFile;

	CString	m_strSendFile;		//�����ļ���·��
	BOOL	m_bSendFile;		//�Ƿ����ļ�
	CFile	m_SendFile;
	ULONGLONG m_uSendFileTotal;	//Ҫ���ļ����ܳ���
	ULONGLONG m_uSendFileSent;	//�ļ��ѷ����ܳ���
	ULONGLONG m_uPartFileSend;	//�ļ���ǰ���ͳ���
	BOOL	m_bAutoSendText;	//�Զ������ı�����

	ULONGLONG m_uRecvCount;
	ULONGLONG m_uSendCount;

	int Str2Hex(CString str, char *data);
	char HexChar(char c);

	void OnOK();
	void OnCancel();
	void SendText();
	void SendFile();

	//{{AFX_MSG(CMainDlg)
	afx_msg void OnDestroy();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnTimer(UINT nIDEvent);
	
	afx_msg LONG OnCommRecvChar(WPARAM wParam, LPARAM port);
	afx_msg LONG OnCommRecvString(WPARAM wString, LPARAM lLength);
	afx_msg LONG OnCommBufferSent(WPARAM wParam,LPARAM port);
	
	afx_msg void OnButtonOpenPort();

	afx_msg void OnButtonRecvClear();
	afx_msg void OnButtonRecvDisplay();
	afx_msg void OnButtonSend();
	afx_msg void OnChangeSendCycleTime();
	afx_msg void OnChangeSendText();
	afx_msg void OnButtonSendClear();
	afx_msg void OnButtonRecvSaveData();
	afx_msg void OnCheckRecvFilePath();
	afx_msg void OnCheckSendFilePath();

	afx_msg void OnButtonDesktop();
	afx_msg void OnButtonResetCount();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	//DECLARE_DYNAMIC_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif
