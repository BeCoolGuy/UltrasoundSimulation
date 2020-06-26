#pragma once

#include "afxtempl.h"


typedef long			int32;
typedef unsigned long	uint32;
typedef short			int16;
typedef unsigned short	uint16;
typedef char			int8;
typedef unsigned char	uint8;
typedef  enum {
	unknown,
	AE, AS, CS, DA, DS, DT, IS, LO, LT, PN, SH, ST,
	TM, UI,
	AT,//uint32
	FL,//int32
	FD,//int64
	OB,//
	OW,//
	SL,//int32
	SQ,//
	SS,//int16
	UL,//uint32
	US//uint16
} vType;
class CDCMImage
{
public:
	CDCMImage();
	virtual ~CDCMImage();
	CDC m_memdc;
	int    HandleItem(FILE*& fp, int group, int element);
	int    GetPixelData(CString FilePath);
	int     read16(FILE* fp);
	int     read32(FILE* fp);
	int little_endian_specified;
	int explicit_specified;
	BOOL   m_pixel_success;
	int    HandleDataSet(FILE*& fp, int group, int element);
	int slope_and_intercept_specified;
	int number_of_frames_specified;
	int frame_time_specified;
	int frame_time_vector_specified;
	int photometric_specified;
	int window_center_specified;           /*  1 windowCenter is given        */
										  /*  0 windowCenter not given       */
	int window_width_specified;            /*  1 windowsWidth  is given       */
										  /*  0 windowsWidth  not given      */

	void    flip_16bit_data(uint8* buff, int width, int height);
	int32* to_32bit_data(uint8* buff, int width, int height);
	int32* to_32bit_data(int8* buff, int width, int height);
	int32* to_32bit_data(uint16* buff, int width, int height);
	int32* to_32bit_data(int16* buff, int width, int height);
	void    handle_photometric_interpretation(int32* tmp, int width, int height);
	void   apply_slope_intercept(int32* buff, int width, int height, double slope, double intercept);
	//��������ʾ�йصı���
	int		PixelRepresentation;      /*if 0 unsigned integer,1 2's complement*/
	int		PhotometricInterpretation;/*if 1 MONOCHROME1,2 MONOCHROME2,3 others*/
	char	TransferSyntax[100];      /*1.2.840.10008.1.2 Default Implicit VR little Endian*/
									  /*1.2.840.10008.1.2.1       Explicit VR little Endian*/
									  /*1.2.840.10008.1.2.2       Explicit VR Big    Endian*/
	int		BitsAllocated;
	int		BitsStored;
	int		HighBit;
	float  	WindowCenter;             /*��λ*/
	float	WindowWidth;			  /*����*/
	int     SamplesPerPixel;         /*bytes  per Pixel*/
	int     MaxPixelValue;
	int     MinPixelValue;
	int     m_Slope, m_Intercept;

	//��һ��ͼ�����ʾ��صı���
	int		Rows;
	int		Colums;
	int		ImageWidth;               /*ͼ��Ŀ��=Colums*/
	int		ImageHeight;			  /*ͼ��ĸ߶�=Rows*/
	int     BoxWidth, BoxHeight, BoxXpos, BoxYpos;
	int     WatchXpos, WatchYpos;//��ʾͼ������Ͻ�����
	int     WatchWidth, WatchHeight;//Watch���ڵĿ�͸�
	int     SltXpos, SltYpos, SltWidth, SltHeight;
	int     SltImgCenX, SltImgCenY;//ѡ��������ͼ�������//
	//���֡ͼ����ʾ��صı���
	int		NumberOfFrames;
	float	FrameTime;
	int     FrameTimeVector;
	int		RepetitionTime;
	int		EchoTime;
	float   FrameDelay;
	//==========================��������ʾ��Ϣ====================//
	//Image��Ϣ
	char    ImageNumber[100];
	char	ImageDate[100];
	char	ImageTime[100];
	char	ImageType[100];
	//������Ϣ
	char	PatientName[100];
	char	PatientID[100];
	char	PatientAge[100];
	char	PatientSex[100];

	//Study��Ϣ
	char	StudyID[100];
	char    StudyTime[100];
	char	StudyDate[100];

	//Series
	char    SeriesNumber[100];
	char    SeriesDate[100];
	char    SeriesTime[100];

	char    AcquisitionDate[100];
	char    AcquisitionTime[100];

	//others
	char	Modality[100];
	char	Manufacturer[100];
	char    ManufacturerMode[100];
	char	InstitutionAddress[100];
	char	InstitutionName[100];

	char    DFOV[100];
	char    KVP[100];//��ѹ
	char    TubeCurrent[100];//����
	char    DetectorTilt[100];
	char    BodyPart[100];
	char    SliceLocation[100];
	char    SliceThickness[100];

	double    ImageOrientation[6];
	char      OrientMark[4];
	char      SaveOrientMark[4];
	//==========================��ʾ��Ϣĩβ==========================//
	//Pixel DATA IS STORED HERE!
	int32* PixelValueData;//the true value,int 16 bits
	int32* SavePixelValueData;
	int32* WatchData;

	int            OW_specified;/*if 1 OW,o OB*/
	int            Selected;//�⸱ͼ���Ƿ�ѡ��
	int          Deleted;
	int          StateChanged;//�Ƿ�ı䣬�Ƿ�Ҫ����
	COLORREF     BoxColor;//�߿��Ⱦɫ
	int          DisplayMethod;
	int          NoRegionX, NoRegionY, NoRegionWidth, NoRegionHeight;

	double       m_PixelSizeX, m_PixelSizeY;
	int          m_TopValue;
	BOOL         m_bShowInfo;
	BOOL         m_bContrast;
	//============����ĶԻָ�ԭ״̬����=========================//
	float         SaveWinWidth, SaveWinCenter;
	double        m_SavePixelSizeX, m_SavePixelSizeY;
	int           m_SaveImageWidth, m_SaveImageHeight;
	int           m_RotateState;
	BOOL          m_bUpDown, m_bLeftRight;
	int           SaveSltXpos, SaveSltYpos, SaveSltWidth, SaveSltHeight;
	//=============���㶨λ��===================================//
	CArray<int, int&> m_ImageNum_Array;//��λ�߶�Ӧ��ͼ���
	CArray<int, int&> m_SeriesNum_Array;//��λ�߶�Ӧ�����к�
	int             m_Highlight_ImageNum;
	int             m_Highlight_SeriesNum;
	double          ImagePosition[3];
	BOOL            m_bLocalizer;
	BOOL            m_bLocalizerOK;
	BOOL            m_bShow_One_Localizer;
	int             m_NumOfLocalizers;
	int             m_bShowLocalizers;
	//=============���==========================================//
	CObArray        NotationArray;
	int             m_NumberOfNo;//��ǵ�����//
	int             m_CurrentNo;
	BOOL            m_bShowNo;
};

