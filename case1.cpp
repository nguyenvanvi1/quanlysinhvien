#include "case1.h"

void ChenSV(SV a[],int &n)
{  
    n++;
    for (int i=n;i>0;i--)
    {
    	a[i].id=a[i-1].id;
    	strcpy(a[i].ten,a[i-1].ten);
    	strcpy(a[i].gioiTinh,a[i-1].gioiTinh);
        a[i].diemKTLT=a[i-1].diemKTLT;
        a[i].diemGT=a[i-1].diemGT;
        a[i].diemXSTK=a[i-1].diemXSTK;
        a[i].ngaySinh.ngay=a[i-1].ngaySinh.ngay;
        a[i].ngaySinh.thang=a[i-1].ngaySinh.thang;
        a[i].ngaySinh.nam=a[i-1].ngaySinh.nam;
        a[i].tuoi=a[i-1].tuoi;
        strcpy(a[i].hocLuc,a[i-1].hocLuc);
        a[i].diemTrungBinh = a[i-1].diemTrungBinh;
        strcpy(a[i].maLop,a[i-1].maLop);
    }
capNhatSinhVien(a[0]);
}
void xoaXuongDong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n'){
		x[len-1]='\0';
	}
}
int dangnhap(int c){
char a[10],b[10];
	textcolor(11);
	printf("					------------- Dang Nhap tai khoan cua ban ------------------ !\n");
	printf("					--------------Nhap tai khoan: ");
	scanf("%s",&a);
	printf("					--------------Nhap mat khau: ");
	scanf("%s",&b);
	if(strcmp(a,"admin")==0 && strcmp(b,"123123")==0){
		return 1;
	}else{
	textcolor(4);
	printf("				Vui Long Dang Nhap Lai !\n");
		c++;
		if(c==3){
			return 0;
		}
	dangnhap(c);
	}
}
void capNhatSVTheoID(SV ds[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (ds[i].id == id) {
            found = 1;
            printf("Cap nhat thong tin sinh vien co id :%d",id);
            capNhatSinhVien(ds[i]);
            printf("Cap nhat sinh vien thanh cong");
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
    }
}
void nhapSinhVien(SV &sv){
	printf("\n\tID: "); scanf("%d", &sv.id);
	printf("\n\tTen: "); fflush(stdin); fgets(sv.ten, sizeof(sv.ten), stdin); xoaXuongDong(sv.ten);
	printf("\n\tGioi tinh: "); fflush(stdin); fgets(sv.gioiTinh, sizeof(sv.gioiTinh), stdin); xoaXuongDong(sv.gioiTinh);
	printf("\n\tNgay sinh:"); scanf("%d%d%d", &sv.ngaySinh.ngay, &sv.ngaySinh.thang, &sv.ngaySinh.nam);
	printf("\n\tDiem Mon KTLT: "); scanf("%f", &sv.diemKTLT);
	printf("\n\tDiem Mon GT: "); scanf("%f", &sv.diemGT);
	printf("\n\tDiem Mon XSTK: "); scanf("%f", &sv.diemXSTK);
	printf("\n\tMa Lop: "); fflush(stdin); fgets(sv.maLop, sizeof(sv.maLop), stdin); xoaXuongDong(sv.maLop);
}


void inSinhVien(SV sv){
	textcolor(11);
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
		printf("\n\tNhap Vao So Luong Sinh Vien:");
		scanf("%d", &n);
	}while(n<=0);
	for(int i=0; i<n ; i++){
		printf("\n\tNhap vao sinh vien thu %d: ", i+1);
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

float timDiemTrungBinhLonNhat(SV ds[], int n){
	float max = ds[0].diemTrungBinh;
	for(int i=0; i<n; i++){
		if(max< ds[i].diemTrungBinh){
			max = ds[i].diemTrungBinh;
		}
	}
	return max;
}
int timTuoiNhoNhat(SV ds[], int n){
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
	int temp=0;
	for(int i=0; i<n ; i++){
		if(strstr(strupr(ds[i].ten), strupr(ten))){
			printf("Sinh vien can tim la: \n");
			inSinhVien(ds[i]);
			temp=1;
		}
	}
	if(temp==0){
		printf("Khong Tim thay sinh vien");
	}
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
			if(strcmp(ds[i].ten, ds[j].ten)>0){
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

