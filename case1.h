#include "DoHoa.h"
// khai bao doi tuong date
struct date{
	int ngay;
	int thang;
	int nam;
};

// Khai bao 1 doi tuong sinh vien

struct SinhVien{
	int id;
	char ten[50];
	char gioiTinh[5];
	date ngaySinh;
	int tuoi;
	float diemKTLT;
	float diemGT;
	float diemXSTK;
	float diemTrungBinh;
	char hocLuc[10];
	char maLop[30];
};
typedef SinhVien SV;

//Ham xoa xuong dong
void xoaXuongDong(char x[]);

// Ham Nhap sinh vien
void nhapSinhVien(SV &sv);

// Ham in sinh vien ra man hinh
void inSinhVien(SV sv);

// Ham tinh tuoi 
void tinhTuoi(SV &sv);

//Ham tinh diem trung binh
void tinhDiemTrungBinh(SV *sv);

//Ham xep loai theo diem trung binh
void xepLoai(SV &sv);
int dangnhap();
void capNhatSV(SV a[], int id, int n);

void ChenSV(SV a[],int &n);
// Ham cap nhat sinh vien
void capNhatSinhVien(SV &sv);

//Ham nhap 1 danh sach sinh vien
void nhapDanhSachSinhVien(SV ds[], int &n);

//Ham Xuat 1 danh sach sinh vien
void xuatDanhSachSinhVien(SV ds[], int n);

// Ham tim  diem trung binh lon nhat
float timMax_DiemTrungBinh(SV ds[], int n);

// Ham tinh tuoi nho nhat
int timMin_Tuoi(SV ds[], int n);

// Ham xuat ra 1 danh sach sinh vien xep loai
void xuatDanhSachSinhVienXepLoai(SV ds[], int n);

// Ham xuat danh sach sinh vien theo lop
void xuatDanhSachSinhVienTheoLop(SV ds[], int n, char lop[]);

//Ham tim sinh vien theo Ten
int timSinhVienTheoTen(SV ds[], int n, char ten[]);

//Ham xoa sinh vien theo ID
void xoaSinhVienTheoId(SV ds[], int &n, int id);

//Ham sap xep sinh vien theo diem trung binh
void sapXepDanhSachSinhVienTheoDTB(SV ds[], int n);

//Ham Sap xep sinh vien theo ten
void sapXepDanhSachSinhVienTheoTen(SV ds[], int n);


