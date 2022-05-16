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
int check(SV ds[],int n){
	for(int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if(ds[j].id==ds[i].id){
				return 1;
			}
		}
    }
	return 0;
}
void nhapDanhSachSinhVien(SV ds[], int &n){
	do{
		printf("\n\tNhap Vao So Luong Sinh Vien:");
		scanf("%d", &n);
	}while(n<=0);
	for(int i=0; i<n ; i++){
		printf("\n\tNhap vao sinh vien thu %d: ", i+1);
		do{
			printf("\n\tID: "); scanf("%d", &ds[i].id);
		}while (check(ds,n)==1);
		printf("\n\tTen: "); fflush(stdin); fgets(ds[i].ten, sizeof(ds[i].ten), stdin); xoaXuongDong(ds[i].ten);
	printf("\n\tGioi tinh: "); fflush(stdin); fgets(ds[i].gioiTinh, sizeof(ds[i].gioiTinh), stdin); xoaXuongDong(ds[i].gioiTinh);
	do{
		printf("\n\tNgay sinh: ");
		scanf("%d",&ds[i].ngaySinh.ngay);
	}while(ds[i].ngaySinh.ngay > 31||ds[i].ngaySinh.ngay <1 );
	do{
		printf("\n\tThang sinh: ");
		scanf("%d",&ds[i].ngaySinh.thang);
	}while(ds[i].ngaySinh.thang > 12|| ds[i].ngaySinh.thang<1);
	do{
		printf("\n\tNam sinh: ");
		scanf("%d",&ds[i].ngaySinh.nam);
	}while(ds[i].ngaySinh.nam > 2022 || ds[i].ngaySinh.nam<1);
	printf("\n\tDiem Mon KTLT: "); scanf("%f", &ds[i].diemKTLT);
	printf("\n\tDiem Mon GT: "); scanf("%f", &ds[i].diemGT);
	printf("\n\tDiem Mon XSTK: "); scanf("%f", &ds[i].diemXSTK);
	printf("\n\tMa Lop: "); fflush(stdin); fgets(ds[i].maLop, sizeof(ds[i].maLop), stdin); xoaXuongDong(ds[i].maLop);
	    tinhTuoi(ds[i]);
	    tinhDiemTrungBinh(&ds[i]);
	    xepLoai(ds[i]);
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
void chuyendoi(char x[]){
	for(int i=0;i<strlen(x);i++){
		if(i==0||(i>0&&x[i-1]==32)){
			if(x[i]>=97&&x[i]<=122)
			    x[i]=x[i]-32;
		}else{
			if(x[i]>=65&&x[i]<=90)
			    x[i]=x[i]+32;
		}
	}
}
void nhapSinhVien(SV &sv){
	printf("\n\tID: "); scanf("%d", &sv.id);
	printf("\n\tTen: "); fflush(stdin); fgets(sv.ten, sizeof(sv.ten), stdin); //xoaXuongDong(sv.ten);
	printf("\n\tGioi tinh: "); fflush(stdin); fgets(sv.gioiTinh, sizeof(sv.gioiTinh), stdin); xoaXuongDong(sv.gioiTinh);
	printf("\n\tNgay sinh:"); scanf("%d%d%d", &sv.ngaySinh.ngay, &sv.ngaySinh.thang, &sv.ngaySinh.nam);
	printf("\n\tDiem Mon KTLT: "); scanf("%f", &sv.diemKTLT);
	printf("\n\tDiem Mon GT: "); scanf("%f", &sv.diemGT);
	printf("\n\tDiem Mon XSTK: "); scanf("%f", &sv.diemXSTK);
	printf("\n\tMa Lop: "); fflush(stdin); fgets(sv.maLop, sizeof(sv.maLop), stdin); xoaXuongDong(sv.maLop);
}
void inSinhVien(SV sv){
	printf("%5d \t  %10s \t %2d/%d/%d \t %10d \t %6.2f \t %6.2f \t %6.2f \t %6.2f \t \t %10s", sv.id, sv.gioiTinh, sv.ngaySinh.ngay, sv.ngaySinh.thang, sv.ngaySinh.nam,sv.tuoi , sv.diemKTLT, sv.diemGT, sv.diemXSTK, sv.diemTrungBinh,  sv.maLop);
	chuyendoi(sv.ten);printf("\nHo ten: %20s ",sv.ten);
}

void tinhDiemTrungBinh(SV *sv){
	sv->diemTrungBinh = (sv->diemKTLT+sv->diemGT+sv->diemXSTK)/3;
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
void tinhTuoi(SV &sv){
	time_t TTIME = time(0);
	tm* NOW = localtime(&TTIME);
	int namHienTai = NOW->tm_year+1900;
	sv.tuoi = namHienTai - sv.ngaySinh.nam;
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
void capNhatSinhVien(SV &sv){
	nhapSinhVien(sv);
	tinhTuoi(sv);
	tinhDiemTrungBinh(&sv);
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
		printf("%5s \t  %10s \t %10s \t %10s\t  %6s \t %6s \t %6s \t %6s  \t %10s", "ID",  "Gioi Tinh","Ngay Sinh", "Tuoi", "Diem KTLT", "Diem GT", "Diem XSTK", "Diem TB", "Ma Lop");
		printf("\n");
	for(int i=0; i<n ; i++){
		inSinhVien(ds[i]);
		printf("\n");
	}
}
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
void xuatFile(SV ds[], int n, char fileName[]){
    FILE * fp;
    fp = fopen (fileName,"w");
    fprintf(fp,"%5s%20s%20s%6s\n", "ID", "Ten", "Gioi Tinh","Tuoi");
    for(int i = 0;i < n;i++){
        fprintf(fp,"%5d%20s%20s%6d\n", ds[i].id,ds[i].ten,ds[i].gioiTinh,ds[i].tuoi);
    }
    fclose (fp);
}
