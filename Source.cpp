#include<iostream> 
#include<fstream>
#include<cmath>
using namespace std;
int a = 10;
struct inputchar {
	unsigned char R,G,B;
};

class fileexe {
protected:
	double YUVtoRGBnum[3][3] =
	{
	{1,0,1.402},
	{1,-0.344136,-0.714136} ,
	{1,1.772,0}
	};
	double RGBtoYUVnum[3][3] =
	{
	{0.299,0.587,0.114},
	{-0.1687,-0.331264,0.5} ,
	{0.5,-0.418688,-0.081312}
	};
	string readfilepath= "D:/work/lena.raw";
	string outfilepath= "D:/work/lena2.raw";
public:
	int b = 10;
	void RGB_to_YUV(string readfilepath1= "D:/work/lena.raw",string outfilepath="D:/work/lena2.raw") {
	fstream file;
	inputchar** inputcharr = new inputchar * [512];
	unsigned char RGB[3];

	for (int i = 0; i < 512; ++i) {
		inputcharr[i] = new inputchar[512];
	}


	file.open(readfilepath, ios::in | ios::binary);

	if (!file) {
		cerr << "Can't open file!\n";
		exit(1);
	}

	for (int j = 0; j < 512; j++) {
		for (int i = 0; i < 512; i++) {
			//cout << int(file.get())<<" ";
			inputcharr[j][i].R = file.get();
			inputcharr[j][i].G = file.get();
			inputcharr[j][i].B = file.get();

		}
	}
	file.close();
	for (int j = 0; j < 512; j++) {
		for (int i = 0; i < 512; i++) {
			RGB[0] = inputcharr[j][i].R;
			RGB[1] = inputcharr[j][i].G;
			RGB[2] = inputcharr[j][i].B;
			inputcharr[j][i].R = double(RGB[0]) * RGBtoYUVnum[0][0] + double(RGB[1]) * RGBtoYUVnum[0][1] + double(RGB[2]) * RGBtoYUVnum[0][2];
			inputcharr[j][i].G = double(RGB[0]) * RGBtoYUVnum[1][0] + double(RGB[1]) * RGBtoYUVnum[1][1] + double(RGB[2]) * RGBtoYUVnum[1][2];
			inputcharr[j][i].B = double(RGB[0]) * RGBtoYUVnum[2][0] + double(RGB[1]) * RGBtoYUVnum[2][1] + double(RGB[2]) * RGBtoYUVnum[2][2];
		}
	}

	file.open(outfilepath, ios::out | ios::binary);
	for (int j = 0; j < 512; j++)
		for (int i = 0; i < 512; i++)
		{
			file << inputcharr[j][i].R << inputcharr[j][i].G << inputcharr[j][i].B;
		}

	/*for (int j = 0; j < 512; j++) {
		for (int i = 0; i < 512; i++) {
			for (int k = 0; k < 3; k++) {
				cout << int(file.get());
				//inputchar[j][i][k] = file.get();
			}
		}
	}*/
	for (int i = 0; i < 512; ++i) {
		delete inputcharr[i];
	}
	delete[] inputcharr;
	file.close();

	/*file.open("D:/work/lena2.raw", ios::in | ios::binary);
	for (int j = 0; j < 512; j++)
		for (int i = 0; i < 512; i++) {
			for (int k = 0; k < 3; k++) {
				cout << file.get() << " ";
			}
			cout << endl;
		}
	file.close();
	*/
}
	void YUV_to_RGB(string readfilepath = "D:/work/lena2.raw", string outfilepath = "D:/work/lena3.raw") {
	fstream file;
	inputchar** inputcharr = new inputchar * [512];
	unsigned char RGB[3];

	for (int i = 0; i < 512; ++i) {
		inputcharr[i] = new inputchar[512];
	}


	file.open(readfilepath, ios::in | ios::binary);

	if (!file) {
		cerr << "Can't open file!\n";
		exit(1);
	}

	for (int j = 0; j < 512; j++) {
		for (int i = 0; i < 512; i++) {
			//cout << int(file.get())<<" ";
			inputcharr[j][i].R = file.get();
			inputcharr[j][i].G = file.get();
			inputcharr[j][i].B = file.get();

		}
	}
	file.close();
	for (int j = 0; j < 512; j++) {
		for (int i = 0; i < 512; i++) {
			RGB[0] = inputcharr[j][i].R;
			RGB[1] = inputcharr[j][i].G;
			RGB[2] = inputcharr[j][i].B;
			inputcharr[j][i].R = double(RGB[0]) * YUVtoRGBnum[0][0] + double(RGB[1]) * YUVtoRGBnum[0][1] + double(RGB[2]) * YUVtoRGBnum[0][2];
			inputcharr[j][i].G = double(RGB[0]) * YUVtoRGBnum[1][0] + double(RGB[1]) * YUVtoRGBnum[1][1] + double(RGB[2]) * YUVtoRGBnum[1][2];
			inputcharr[j][i].B = double(RGB[0]) * YUVtoRGBnum[2][0] + double(RGB[1]) * YUVtoRGBnum[2][1] + double(RGB[2]) * YUVtoRGBnum[2][2];
		}
	}

	file.open(outfilepath, ios::out | ios::binary);
	for (int j = 0; j < 512; j++)
		for (int i = 0; i < 512; i++)
		{
			file << inputcharr[j][i].R << inputcharr[j][i].G << inputcharr[j][i].B;
		}

	/*for (int j = 0; j < 512; j++) {
		for (int i = 0; i < 512; i++) {
			for (int k = 0; k < 3; k++) {
				cout << int(file.get());
				//inputchar[j][i][k] = file.get();
			}
		}
	}*/
	for (int i = 0; i < 512; ++i) {
		delete inputcharr[i];
	}
	delete[] inputcharr;
	file.close();

	/*file.open("D:/work/lena2.raw", ios::in | ios::binary);
	for (int j = 0; j < 512; j++)
		for (int i = 0; i < 512; i++) {
			for (int k = 0; k < 3; k++) {
				cout << file.get() << " ";
			}
			cout << endl;
		}
	file.close();
	*/
}
	void inputpath() {
		cout << "請輸入你要開啟的檔案的絕對位置" << endl;
		cin >> readfilepath;
		cout << "請輸入你要輸出的檔案的絕對位置" << endl;
		cin >> outfilepath;
		cout << "完成" << endl;
	}
	double countMSE(string firfilepath = "D:/work/lena.raw", string secfilepath = "D:/work/lena3.raw") {
		fstream file;
		inputchar** inputcharr = new inputchar * [512];
		unsigned char RGB[3];
		double total = 0;
		for (int i = 0; i < 512; ++i) {
			inputcharr[i] = new inputchar[512];
		}


		file.open(firfilepath, ios::in | ios::binary);

		if (!file) {
			cerr << "Can't open file!\n";
			exit(1);
		}

		for (int j = 0; j < 512; j++) {
			for (int i = 0; i < 512; i++) {
				//cout << int(file.get())<<" ";
				inputcharr[j][i].R = file.get();
				inputcharr[j][i].G = file.get();
				inputcharr[j][i].B = file.get();

			}
		}
		file.close();
		file.open(secfilepath, ios::in | ios::binary);

		if (!file) {
			cerr << "Can't open file!\n";
			exit(1);
		}

		for (int j = 0; j < 512; j++) {
			for (int i = 0; i < 512; i++) {
				//cout << int(file.get())<<" ";
				inputcharr[j][i].R -= file.get();
				inputcharr[j][i].G -= file.get();
				inputcharr[j][i].B -= file.get();
				total = inputcharr[j][i].R * inputcharr[j][i].R + inputcharr[j][i].G * inputcharr[j][i].G + inputcharr[j][i].B * inputcharr[j][i].B;
			}
		}
		for (int i = 0; i < 512; ++i) {
			delete inputcharr[i];
		}
		delete[] inputcharr;
		file.close();

		total /= (512 * 512);
		return total;
	}
	double countPSNR(double MSE=1) {
		return 10 * log10(255 * 255 / MSE);
	}
}; 

void main() {
	fileexe file;
	string filepath;
	//cin >> filepath;
	file.RGB_to_YUV();
	file.YUV_to_RGB();
	cout << file.countMSE() << endl;
	cout << file.countPSNR(file.countMSE()) << endl;
}