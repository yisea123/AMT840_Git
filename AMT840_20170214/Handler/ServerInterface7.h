#pragma once

typedef struct _INTER_SV_QUEUE_7_
{
	int			m_nRear;
	int			m_nFront;
	int			m_nCount;

	char		m_chMsg[10][5000];
} INTER_SV_QUEUE_7, *P_INTER_SV_QUEUE_7;

class CServerInterface7
{
public:
	HANDLE				m_hMemMapInter7;
	P_INTER_SV_QUEUE_7	m_pQueueInter7;

	int					m_nHeader;
	int					m_nHeaderLength;

	CString				m_strHeader;
	CString				m_strData;

	void				OnCommunication();
	void				OnMessageWrite(CString strMsg);
	CString				OnMessageRead();
	CString				OnCharToString(char chData[], int nLength);
	void				OnStringToChar(CString strData, char chData[]);
	void				OnDataReceive(CString strMsg);
	void				OnDataAnalysis(CString strMsg);
	CString				OnDataItemAnalysis(int nOpt, int nPos, CString strMsg, CString strFind);

public:
	CServerInterface7(void);
	~CServerInterface7(void);
};

extern CServerInterface7 clsInterS7;

