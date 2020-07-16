#pragma once
#include <vector>

class CTReflection{
private:
	const double soundVelocity = 1.54;
	long* CTValueData;//�洢CTֵ
	double* AcousticImpedanceValueData;//�洢���迹ϵ��

	
public:
	CTReflection();
	virtual ~CTReflection();
	bool pixelToCT(long* PixelValueData, int xSize, int ySize, int slope, int intercept);
	//�����ӿڣ��õ����迹����
	bool getAcousticImpedance(CDCMImage* pImage);
	bool getAcousticImpedance(int* arrays, CDCMImage* pImage);//ͨ��λ�÷ֲ�����������迹
	//ͨ����ʽ�����迹ϵ��
	double computeAcousticImpedance(int dataCT);
	//��÷���������
	bool getNormalMatrix()

	void Reflection();
	double reflectivity(int x, int y, int z);
};

