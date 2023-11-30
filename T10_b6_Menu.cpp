#include <stdio.h>

void nhapphantumang(int a[], int &n) {
	do {
		printf("Vui long nhap (0<n<=100): ");
		scanf("%d",&n);
	}while (n<0||n>100);
	printf("Nhap phan tu cua mang\n");
	for (int i =0; i<n; i++) {
		printf("Nhap phan tu thu %d: ", i);
		scanf("%d",&a[i]);
	}
}

void xuatmang(int a[], int n) {
	printf("Cac phan tu trong mang hien tai la:\n");
	for (int i = 0; i<n; i++) {
		printf("%d ",a[i]);
	}
}

void xuatphantuduongdau(int a[], int n) {
	for (int i = 0; i<n; i++) {
		if (a[i]>0) {
			printf("Phan tu duong dau tien la: %d\n", a[i]);
			printf("Vi tri phan tu duong: %d",i);
			break;
		}
	}
}

void xuatphantuduongcuoi(int a[], int n) {
	for (int i = n; i>0; i--) {
		if (a[i]>0) {
			printf("Phan tu duong cuoi cung la: %d\n", a[i]);
			printf("Vi tri phan tu duong: %d",i);
			break;
		}
	}
}

int findMAX(int a[], int n) {
	int max = a[0];
	for (int i = 0; i<n; i++) {
		if (a[i]>max) {
			max = a[i];
		}
	}
	return max;
} 

int findCountMAX(int a[], int n) {
	int max = a[0];
	int count = 0;
	for (int i = 0; i<n; i++) {
		if (a[i]>max) {
			max = a[i];
		}
		else if (a[i]==max) {
			count++;
		}
	}
	return count;
} 

int findPositMAX(int a[], int n) {
	int max = a[0];
	int posit = 0;
	for (int i = 1; i<n; i++) {
		if (a[i]>max) {
			max = a[i];
			posit = i;
		}
	}
	return posit;
}

void themdau(int a[], int n, int x) {
	printf("So X can them la: ");
	scanf("%d",&x);
	for (int i = n; i>=0; i--) {
		a[i]=a[i-1];
	}
	a[0]=x;
	n++;
	xuatmang(a,n);
}

void themvt(int a[], int n, int x, int k) {
	
	for (int i = n; i>k; i--) {
		a[i]=a[i-1];
	}
	a[k]=x;
	n++;
	xuatmang(a,n);
}

void xoavt (int a[], int n, int k) {
	printf("Vi tri muon xoa: ");
	scanf("%d",&k);
	for (int i = k; i<n; i++) {
		a[i]=a[i+1];
	}
	n--;
	xuatmang(a,n);
}

bool sole(int a[], int n) {
	for (int i = 0; i<n; i++) {
		if (a[i]%2!=0) {
			return 1;
		}
	}
	return 0;
}
int main() {
	int a[1],n,x,vt,choose;
	nhapphantumang(a,n);
	do {
		printf("\n1. Xuat mang da nhap.");
		printf("\n2. Tim vi tri phan tu va gia tri cua so duong dau tien.");
		printf("\n3. Tim vi tri phan tu va gia tri cua so duong cuoi cung.");
		printf("\n4. Tim so lon nhat trong mang.");
		printf("\n5. Dem so phan tu trung lon nhat.");
		printf("\n6. Vi tri phan tu lon nhat.");
		printf("\n7. Them phan tu X vao dau mang.");
		printf("\n8. Them phan tu X vao vi tri K.");
		printf("\n9. Xoa phan tu X tai vi tri K.");
		printf("\n10. Kiem tra mang co chua so le khong?");
		printf("\nNhap chon: ");
		scanf("%d",&choose);
		switch (choose) {
			case 1: {
				xuatmang(a,n);
				printf("\n");
				break;
			}
			
			case 2: {
				xuatphantuduongdau(a,n);
				printf("\n");
				break;
			}
			
			case 3: {
				xuatphantuduongcuoi(a,n);
				printf("\n");
				break;
			}
			
			case 4: {
				printf("So lon nhat trong mang: %d",findMAX(a,n));
				printf("\n");
				break;
			}
			
			case 5: {
				printf("So phan tu trung lon nhat: %d",findCountMAX(a,n));
				printf("\n");
				break;
			}
			
			case 6: {
				printf("Vi tri phan tu lon nhat: %d", findPositMAX(a,n));
				printf("\n");
				break;
			}
			
			case 7: {
				themdau(a,n,x);
				printf("\n");
				break;
			}
			
			case 8: {
				themvt(a,n,x,vt);
				printf("\n");
				break;
			}
			
			case 9: {
				xoavt(a,n,vt);
				printf("\n");
				break;
			}
			
			case 10: {
				if (sole(a,n)) {
					printf("Mang co so le");
					printf("\n");
				}
				else {
					printf("Mang ko co so le");
					printf("\n");
				}
				break;
			}
		}
	}while(choose!=0);
	return 0;
}
