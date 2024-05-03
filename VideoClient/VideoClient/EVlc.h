#pragma once
#include<string>
#include "vlc.h"
class VlcSize {
public:
	int nWidth;
	int nHeight;
	VlcSize(int width = 0, int height = 0) {
		nWidth = width;
		nHeight = height;
	}
	VlcSize(const VlcSize& size) {
		nWidth = size.nWidth;
		nHeight = size.nHeight;
	}
	VlcSize& operator=(const VlcSize& size) {
		if (this != &size) {
			nWidth = size.nWidth;
			nHeight = size.nHeight;
		}
	}
};
class EVlc
{
public:
	EVlc();
	~EVlc();
	//strUrl如果包含中文，请传入utf_8的编码格式字符串
	int SetMedia(const std::string& strUrl);
#ifdef WIN32
	int SetHwnd(HWND hWnd);
#endif
	int Play();
	int Pause();
	int Stop();
	float GetPostion();
	void SetPostion(float pos);
	int GetVolume();
	int SetVolume(int volume);
	VlcSize GetMediaInfo();
	float GetLength();
	std::string Unicode2Utf8(const std::wstring& strIn);
protected:
	libvlc_instance_t* m_instance;
	libvlc_media_t* m_media;
	libvlc_media_player_t* m_player;
	std::string m_url;
#ifdef WIN32
	HWND m_hwnd;
#endif
};

