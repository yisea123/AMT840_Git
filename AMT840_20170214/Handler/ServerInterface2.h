#pragma once

typedef struct _INTER_SV_QUEUE_2_
{
	int			m_nRear;
	int			m_nFront;
	int			m_nCount;

	char		m_chMsg[10][5000];
} INTER_SV_QUEUE_2, *P_INTER_SV_QUEUE_2;

class CServerInterface2
{
public:
	HANDLE				m_hMemMapInter2;
	P_INTER_SV_QUEUE_2	m_pQueueInter2;

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
	CServerInterface2(void);
	~CServerInterface2(void);
};

extern CServerInterface2 clsInterS2;

