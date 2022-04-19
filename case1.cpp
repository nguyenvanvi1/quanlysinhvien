#include "case1.h"
void xoaXuongDong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n'){
		x[len-1]='\0';
	}
}
void ChenSV(SV a[],int &n)
{  
    n++;
    capNhatSinhVien(a[n]);
    for (int i=n-1;i>=0;i--)
    {
        a[i].id=a[i-1].id;
        a[i].diemGT=a[i-1].diemGT;
        a[i].diemKTLT=a[i-1].diemKTLT;
        strcpy(a[i].ten,a[i-1].ten);
    }
    }
int dangnhap(int c){
char a[10],b[10];
	textcolor(11);
	printf("		------------- Dang Nhap tai khoan cua ban ------------------ !\n");
	printf("		--------------Nhap tai khoan: ");
	scanf("%s",&a);
	printf("		--------------Nhap mat khau: ");
	scanf("%s",&b);
	if(strcmp(a,"admin")==0 && strcmp(b,"123123")==0){
		return 1;
	}else{
	textcolor(4);
	printf("		Vui Long Dang Nhap Lai !\n");
		c++;
		if(c==3){
			return 0;
		}
	dangnhap(c);
	}
}
void capNhatSV(SV a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printf("Cap nhat thong tin sinh vien co id :%d",id);
            capNhatSinhVien(a[i]);
            printf("Cap nhat sinh vien thanh cong");
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
    }
}
void nhapSinhVien(SV &sv){
	printf("		\nID: "); scanf("%d", &sv.id);
	printf("		\nTen: "); fflush(stdin); fgets(sv.ten, sizeof(sv.ten), stdin); xoaXuongDong(sv.ten);
	printf("		\nGioi tinh: "); fflush(stdin); fgets(sv.gioiTinh, sizeof(sv.gioiTinh), stdin); xoaXuongDong(sv.gioiTinh);
	printf("		\nNgay sinh:"); scanf("%d%d%d", &sv.ngaySinh.ngay, &sv.ngaySinh.thang, &sv.ngaySinh.nam);
	printf("		\nDiem Mon KTLT: "); scanf("%f", &sv.diemKTLT);
	printf("		\nDiem Mon GT: "); scanf("%f", &sv.diemGT);
	printf("		\nDiem Mon XSTK: "); scanf("%f", &sv.diemXSTK);
	printf("		\nMa Lop: "); fflush(stdin); fgets(sv.maLop, sizeof(sv.maLop), stdin); xoaXuongDong(sv.maLop);
}


void inSinhVien(SV sv){
	printf("%5d \t %20s \t %10s \t %2d/%d/%d \t %10d \t %6.2f \t %6.2f \t %6.2f \t %6.2f \t %5s \t\t %10s", sv.id, sv.ten, sv.gioiTinh, sv.ngaySinh.ngay, sv.ngaySinh.thang, sv.ngaySinh.nam, sv.tuoi, sv.diemKTLT, sv.diemGT, sv.diemXSTK, sv.diemTrungBinh, sv.hocLuc, sv.maLop);
}

void tinhTuoi(SV &sv){
	time_t TTIME = time(0);
	tm* NOW = localtime(&TTIME);
	int namHienTai = NOW->tm_year+1900;
	sv.tuoi = namHienTai - sv.ngaySinh.nam;
}

void tinhDiemTrungBinh(SV *sv){
	sv->diemTrungBinh = (sv->diemKTLT+sv->diemGT+sv->diemXSTK)/3;
}

void xepLoai(SV &sv){
	if(sv.diemTrungBinh>9){
		strcpy(sv.hocLuc, "XUAT SAC");
	}else if(sv.diemTrungBinh>8){
		strcpy(sv.hocLuc, "GIOI");
	}else if(sv.diemTrungBinh>7){
		strcpy(sv.hocLuc, "KHA");
	}else if(sv.diemTrungBinh>5){
		strcpy(sv.hocLuc, "TRUNG BINH");
	}else{
		strcpy(sv.hocLuc, "YEU");
	}
	
}

void capNhatSinhVien(SV &sv){
	nhapSinhVien(sv);
	tinhTuoi(sv);
	tinhDiemTrungBinh(&sv);
	xepLoai(sv);
}

void nhapDanhSachSinhVien(SV ds[], int &n){
	do{
		printf("\nNhap Vao So Luong Sinh Vien:");
		scanf("%d", &n);
	}while(n<=0);
	for(int i=0; i<n ; i++){
		printf("\nNhap vao sinh vien thu %d: ", i+1);
		capNhatSinhVien(ds[i]);
	}
}
void xuatDanhSachSinhVien(SV ds[], int n){
		printf("%5s \t %20s \t %10s \t %10s \t %10s \t %6s \t %6s \t %6s \t %6s \t %5s \t %10s", "ID", "Ten", "Gioi Tinh", "Ngay Sinh", "Tuoi", "Diem KTLT", "Diem GT", "Diem XSTK", "Diem TB", "XepLoai", "Ma Lop");
		printf("\n");
	for(int i=0; i<n ; i++){
		inSinhVien(ds[i]);
		printf("\n");
	}
}

float timMax_DiemTrungBinh(SV ds[], int n){
	float max = ds[0].diemTrungBinh;
	for(int i=0; i<n; i++){
		if(max< ds[i].diemTrungBinh){
			max = ds[i].diemTrungBinh;
		}
	}
	return max;
}
int timMin_Tuoi(SV ds[], int n){
	int min = ds[0].tuoi;
	for(int i=0; i<n; i++){
		if(min> ds[i].tuoi){
			min = ds[i].tuoi;
		}
	}
	return min;
}

void xuatDanhSachSinhVienXepLoai(SV ds[], int n, char xepLoai[]){
	printf("\n Danh sach sinh vien xep loai %s\n",xepLoai);
	printf("%5s \t %20s \t %10s \t %10s \t %10s \t %6s \t %6s \t %6s \t %6s \t %5s \t %10s", "ID", "Ten", "Gioi Tinh", "Ngay Sinh", "Tuoi", "Diem KTLT", "Diem GT", "Diem XSTK", "Diem TB", "XepLoai", "Ma Lop");
	printf("\n");
	for(int i=0; i<n ; i++){
		if (strcmp(strupr(ds[i].hocLuc),strupr(xepLoai))==0){
			inSinhVien(ds[i]);
			printf("\n");
		}
	}
}
void xuatDanhSachSinhVienTheoLop(SV ds[], int n, char lop[]){
	printf("\n Danh sach sinh vien thuoc lop %s\n", lop);
	printf("%5s \t %20s \t %10s \t %10s \t %10s \t %6s \t %6s \t %6s \t %6s \t %5s \t %10s", "ID", "Ten", "Gioi Tinh", "Ngay Sinh", "Tuoi", "Diem KTLT", "Diem GT", "Diem XSTK", "Diem TB", "XepLoai", "Ma Lop");
	printf("\n");
	for(int i=0; i<n ; i++){
		if (strcmp(strupr(ds[i].maLop), strupr(lop))==0){
			inSinhVien(ds[i]);
			printf("\n");
		}
	}
}

int timSinhVienTheoTen(SV ds[], int n, char ten[]){
	// 0 => false
	// 1 => true
	for(int i=0; i<n ; i++){
		if(strstr(strupr(ds[i].ten), strupr(ten))){
			inSinhVien(ds[i]);
		}
	}
	return 0;
}
void xoaSinhVienTheoId(SV ds[], int &n, int id){
	for(int i=0; i<n ; i++){
		if(ds[i].id == id){
			for(int j=i; j<n; j++){
				ds[j] = ds[j+1];
			}
			n-=1;
			return;
		}
	}
}
void themSinhVien(SV ds[],int &n){
	ds[n+1]=ds[n+2];
	n++;
	nhapSinhVien(ds[n]);
	capNhatSinhVien(ds[n]);
}
void sapXepDanhSachSinhVienTheoDTB(SV ds[], int n){
	SV temp;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(ds[i].diemTrungBinh>ds[j].diemTrungBinh){
				//SV temp;
				temp = ds[i];
				ds[i] = ds[j];
				ds[j]=temp;
			}
		}
	}
}
void sapXepDanhSachSinhVienTheoTen(SV ds[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(strcmp(strupr(ds[i].ten), strupr(ds[j].ten))>0){
				SV temp;
				temp = ds[i];
				ds[i] = ds[j];
				ds[j]=temp;
			}
		}
	}
}
void xuatFile(SV ds[], int n, char fileName[]){
    FILE * fp;
    fp = fopen (fileName,"w");
    fprintf(fp,"%5s%10s%10s%6s\n", "ID", "Ten", "Gioi Tinh","Tuoi");
    for(int i = 0;i < n;i++){
        fprintf(fp,"%5d%10s%10s%6d\n", ds[i].id,ds[i].ten,ds[i].gioiTinh,ds[i].tuoi);
    }
    fclose (fp);
}
void nhapPhimBatKy(){
		printf("\nNhap phim bat ky de tiep tuc!");
        getch();
}

