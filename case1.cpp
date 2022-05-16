#include "case1.h"
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

void nhapPhimBatKy(){
		printf("\nNhap phim bat ky de tiep tuc!");
        getch();
}
/*Trần Quóc Thịnh 6251071095
*/
