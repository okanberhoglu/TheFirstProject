#include<stdio.h>

//Okan Berhoðlu 181501061
void YeniUrun(int[], int[], double[]);
void Listele(int[], int[], double[]);
void Sil(int[], int[], double[]);
void Zam(int[], int[], double[]);
void Indirim(int[], int[], double[]);
void Satis(int[], int[], double[]);
void toplam(int[], int[], double[]);
void sil(int[], int[], double[], int);
int count = 0;

int main() {
	printf("         HOSGELDINIZ\n\n");
	int Id[10];
	int Adet[10];
	double Fiyat[10];
	int k;
	for (k = 1; ; k++) {
		int islem;
		printf("Islem turunu giriniz lutfen \n 1-Urun girisi \n 2-Urunu sil \n 3-Zam yap \n 4-Indirim yap \n 5-Satis yap \n (-1)-Programi sonlandir \n Isleminiz = ");
		scanf_s("%d", &islem);
		if (islem == (-1)) {
			toplam(Id, Adet, Fiyat);
			printf("Bizi tercih ettiginiz icin tesekkur ederiz\n");
			break;
		}
		switch (islem) {
		case 1:
			YeniUrun(Id, Adet, Fiyat);
			break;
		case 2:
			Sil(Id, Adet, Fiyat);
			break;
		case 3:
			Zam(Id, Adet, Fiyat);
			break;
		case 4:
			Indirim(Id, Adet, Fiyat);
			break;
		case 5:
			Satis(Id, Adet, Fiyat);
			break;
		default:
			printf("Gecersiz islem girdiniz\n\n");
			break;
		}



	}



	return 0;
}

void YeniUrun(int i[], int a[], double f[]) {

	int c2 = 0, w;

	int id, ad;
	double fi;
	printf("Urun Id giriniz = ");
	scanf_s("%d", &id);
	if (id <= 0) {
		printf("Gecersiz deger girdiniz\n");
		return;
	}
	for (w = 0; w < count; w++) {
		if (i[w] == id)
			c2++;
	}
	if (c2 || count < 10) {
		printf("Urun adedini giriniz = ");
		scanf_s("%d", &ad);
		printf("Urunun birim fiyatini giriniz = ");
		scanf_s("%lf", &fi);
		int k = 0;
		while (k < count) {
			if (i[k] == id) {
				a[k] += ad;
				f[k] = fi;
				printf("Urun guncellendi...\n");
				Listele(i, a, f);
				return;
			}
			k++;
		}
		i[count] = id;
		a[count] = ad;
		f[count] = fi;
		printf("Urun kaydedildi...\n");
		count++;
		Listele(i, a, f);
	}
	else {
		printf("Urun listesi doludur,yeni urun girisi yapilamaz\n");
		Listele(i, a, f);
	}

}
void Listele(int i[], int a[], double f[]) {
	printf("\nkayitli urunler \n");
	int k, b, d, temp, adet;
	double fiyyat;
	for (b = 0; b < count; b++) {
		for (d = 0; d < count; d++) {
			if (i[b] < i[d]) {
				temp = i[b];
				i[b] = i[d];
				i[d] = temp;
				adet = a[b];
				a[b] = a[d];
				a[d] = adet;
				fiyyat = f[b];
				f[b] = f[d];
				f[d] = fiyyat;
			}
		}
	}
	for (k = 0; k < count; k++) {
		printf("(%d)--> %d  %d  %.2lf\n\n", k + 1, i[k], a[k], f[k]);
	}

}
void Sil(int i[], int a[], double f[]) {
	int c2 = 0, co = 0;
	if (count == 0)
		printf("Listede Urun yoktur\n");
	else {
		int id;
		printf("Silmek istediginiz urunun Id'sini giriniz = ");
		scanf_s("%d", &id);

		int k;
		for (k = 0; k <= count; k++) {
			if (i[k] == id) {
				c2++;
				break;
			}
		}
		if (c2 == 1) {

			for (k = 0; k < count; k++) {
				if (i[k] == id) {
					i[k] = i[k + 1];
					a[k] = a[k + 1];
					f[k] = f[k + 1];
					count--;
					co++;
					printf("Urun silindi...\n");
				}
				if (co) {
					i[k] = i[k + 1];
					a[k] = a[k + 1];
					f[k] = f[k + 1];

				}
			}
		}
		else
			printf("Gecersiz Id girdiniz\n");

		Listele(i, a, f);
	}
}
void Zam(int i[], int a[], double f[]) {
	int c2 = 0;
	if (count == 0)
		printf("Listede Urun yoktur\n");
	else {
		int id, z, k;
		printf("Zam yapmak istediginiz urunun Id'sini giriniz = ");
		scanf_s("%d", &id);
		for (k = 0; k <= count; k++) {
			if (i[k] == id) {
				c2++;
				break;
			}
		}
		if (c2 == 1) {
			printf("Zam yapmak istediginiz orani giriniz = ");
			scanf_s("%d", &z);
			for (k = 0; k < count; k++) {
				if (i[k] == id) {
					f[k] += (f[k] * z) / 100;
					printf("Zam yapildi...\n");
				}
			}
		}
		else
			printf("Gecersiz Id girdiniz\n");

		Listele(i, a, f);
	}

}
void Indirim(int i[], int a[], double f[]) {
	int c2 = 0;
	if (count == 0)
		printf("Listede Urun yoktur\n");
	else {
		int id, z, k;
		printf("Indirim yapmak istediginiz urunun Id'sini giriniz = ");
		scanf_s("%d", &id);
		for (k = 0; k <= count; k++) {
			if (i[k] == id) {
				c2++;
				break;
			}
		}
		if (c2 == 1) {

			printf("Indirim yapmak istediginiz orani giriniz = ");
			scanf_s("%d", &z);

			for (k = 0; k < count; k++) {
				if (i[k] == id) {
					f[k] -= (f[k] * z) / 100;
					printf("Indirim yapildi...\n");
				}
			}
		}
		else
			printf("Gecersiz Id girdiniz\n");
		Listele(i, a, f);
	}

}
void Satis(int i[], int a[], double f[]) {
	int c2 = 0;
	if (count == 0)
		printf("Listede Urun yoktur\n");
	else {
		int id, s, k;
		printf("Satis yapmak istediginiz urunun Id'sini giriniz = ");
		scanf_s("%d", &id);
		for (k = 0; k <= count; k++) {
			if (i[k] == id) {
				c2++;
				break;
			}
		}
		if (c2 == 1) {

			printf("Satis yapmak istediginiz adedi giriniz = ");
			scanf_s("%d", &s);
			int j;
			for (k = 0; k < count; k++) {

				if (i[k] == id) {
					if (a[k] > s) {
						a[k] -= s;
						printf("Satis yapiliyor...\n");
					}
					if (a[k] < s) {
						printf("Girdiginiz adet kadar urun yoktur\n");
					}
					if (a[k] == s) {
						sil(i, a, f, k);
						printf("Satis yapiliyor...\n");
					}

				}
			}
		}
		else
			printf("Gecersiz Id girdiniz\n");

		Listele(i, a, f);
	}

}
void sil(int i[], int a[], double f[], int k) {
	int n = k;
	while (n < count) {
		i[n] = i[n + 1];
		a[n] = a[n + 1];
		f[n] = f[n + 1];
		n++;
	}
	count--;

}

void toplam(int i[], int a[], double f[]) {
	if (count == 0)
		printf("Listede Urun yoktur\n");
	else {
		int k, D = 0;
		double F = 0.00;
		for (k = 0; k < count; k++) {
			D += a[k];
			F += f[k];
		}
		printf("Toplam urun sayisi = %d\n", count);
		printf("Toplam urun adeti = %d\n", D);
		printf("Toplam urun fiyati = %.2lf\n", F);
	}
}
