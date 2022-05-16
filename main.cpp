#include "case1.cpp"
#include "DoHoa.cpp"
int main(){
	SV ds[100];
	int n,b[100];
	int chon;
	char fileName[] = "DSSV1.txt";
	if(dangnhap(0)==1){
		do{
		textcolor(9);
		printf("\n");
		printf("\t									CHUONG TRINH QUAN LY SINH VIEN \n");
		textcolor(11);
		printf("					-----------------------------------------------------------------------------------------------------------\n");
		printf("					|       1- Nhap danh sach sinh vien\t 		|	2- Xuat danh sach sinh vien		  |\n");
			printf("					-----------------------------------------------------------------------------------------------------------\n");
		printf("					|       3- Tim diem trung binh lon nhat\t 		|	4- Tim Tuoi nho nhat			  |\n");
			printf("					-----------------------------------------------------------------------------------------------------------\n");
		printf("					|  	5- Xuat danh sach sinh vien theo lop\t 	|	6- Xuat danh sach sinh vien hoc luc	  |\n");
			printf("					-----------------------------------------------------------------------------------------------------------\n");
		printf("					| 	7- Sap xep sinh vien theo diem trung binh\t|	8- Sap xep sinh vien theo ten		  |\n");
			printf("					-----------------------------------------------------------------------------------------------------------\n");
		printf("					|	9- Tim sinh vien theo ten\t 		|	10-Xoa sinh vien theo ID		  |\n");
			printf("					-----------------------------------------------------------------------------------------------------------\n");
		printf("					| 	11-Cap Nhat sinh vien theo ID\t 		|	12-Them sinh vien			  |\n");
			printf("					-----------------------------------------------------------------------------------------------------------\n");
		printf("					|  	13-Xuat danh sach sinh vien vao file\t 	|	0- Thoat                                  |\n");
			printf("					-----------------------------------------------------------------------------------------------------------\n");
		printf("									--------      Nhap lua chon cua ban!     --------\n");
		scanf("%d", &chon);
		switch(chon){
			case 1:
					nhapDanhSachSinhVien(ds, n); 
					nhapPhimBatKy();
					break;
			case 2:
					xuatDanhSachSinhVien(ds,n);
					nhapPhimBatKy();
					break;	
			case 3:
					printf("\n Max DTB = %.2f", timDiemTrungBinhLonNhat(ds, n));
					nhapPhimBatKy();
					break;
			case 4:
					printf("\n Min Tuoi = %d", timTuoiNhoNhat(ds, n));
					nhapPhimBatKy();
					break;
			case 5:
					char lop[20];
					printf("\nNhap Ma Lop can hien thi: "); fflush(stdin); fgets(lop, sizeof(lop), stdin); xoaXuongDong(lop); 
					xuatDanhSachSinhVienTheoLop(ds, n,lop);
					nhapPhimBatKy();
					break;
			case 6:
					char xepLoai[20];
					printf("\nNhap xep loai can hien thi: "); fflush(stdin); fgets(xepLoai, sizeof(xepLoai), stdin); xoaXuongDong(xepLoai); 
					xuatDanhSachSinhVienXepLoai(ds, n, xepLoai);
					nhapPhimBatKy();
					break;
					
			case 7:
					printf("\nDanh sach sau khi sap xep theo DTB\n");
					sapXepDanhSachSinhVienTheoDTB(ds, n);
					xuatDanhSachSinhVien(ds, n);
					nhapPhimBatKy();
					break;
			case 8:
					printf("\nDanh sach sau khi sap xep theo ten\n");
					sapXepDanhSachSinhVienTheoTen(ds,n);
					xuatDanhSachSinhVien(ds,n);
					nhapPhimBatKy();
					break;
			case 9:
					char tensv[20];
					printf("\nNhap ten sinh vien can tim: "); fflush(stdin); fgets(tensv, sizeof(tensv), stdin); xoaXuongDong(tensv); 
					timSinhVienTheoTen(ds,n,tensv);
					nhapPhimBatKy();
					break;
			case 10:
					int id;
					printf("\nNhap id can xoa"); scanf("%d", &id);
					printf("\nDanh sach sau khi xoa\n");
					xoaSinhVienTheoId(ds, n, id);
					xuatDanhSachSinhVien(ds, n);
					nhapPhimBatKy();
					break;
			case 11:
					int tem;
					printf("\nNhap id can sua thong tin: "); scanf("%d", &tem);
					capNhatSVTheoID(ds,tem,n);
					nhapPhimBatKy();
					break;
			case 12: 
					printf("Them sinh vien");
					ChenSV(ds,n);
					nhapPhimBatKy();
					break;
					
			case 13:
			        xuatFile(ds, n, fileName);
                    printf("\nXuat DSSV thanh cong vao file %s!", fileName);
					break;
		}
	} while(n!=0);
	}else{
		printf("					Ban da dang nhap qua so lan !\n");
		textcolor(11);
		printf("					Nhan Phim Bat Ki De Thoat Chuong Trinh");
	}

}





