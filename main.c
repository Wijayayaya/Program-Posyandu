#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define DATAPASIEN "dataPasien.csv"

typedef struct
{
  char nama[50], jenisKelamin[20];
  int usia;
  float tb, bb, imt;
  union
  {
    char keluhan[200];
    int pilihan;
  } info;
} Pasien;

void loadData()
{
  FILE *dp;
  dp = fopen(DATAPASIEN, "r");
  char line[100];
  system("cls");
  printf("\nRekap Pendataan :\n");
  while (fgets(line, sizeof(line), dp) != NULL)
  {
    printf("%s", line);
  }
  fclose(dp);
}

void Timbang()
{
  Pasien pasienBaru;

  printf("\n");
  printf("Nama Anak : ");
  scanf(" %49[^\n]", pasienBaru.nama);
  fflush(stdin);
  printf("Usia : ");
  scanf("%d", &pasienBaru.usia);
  fflush(stdin);
  printf("Tinggi Badan / Panjang Badan (cm) : ");
  scanf("%f", &pasienBaru.tb);
  fflush(stdin);
  printf("Berat Badan (kg): ");
  scanf("%f", &pasienBaru.bb);
  fflush(stdin);

  pasienBaru.tb /= 100;
  pasienBaru.imt = pasienBaru.bb / (pasienBaru.tb * pasienBaru.tb);
  printf("IMT anak Anda: %.2f\n", pasienBaru.imt);

  FILE *dp;
  dp = fopen(DATAPASIEN, "a");

  fprintf(dp, "\nKeperluan : Penimbangan Balita\n");
  fprintf(dp, "Nama : %s\n", pasienBaru.nama);
  fprintf(dp, "Usia : %d tahun\n", pasienBaru.usia);
  fprintf(dp, "Tinggi Badan / Panjang Badan: %.2fm\n", pasienBaru.tb);
  fprintf(dp, "Berat Badan : %.2fkg\n", pasienBaru.bb);
  fprintf(dp, "IMT : %.2f\n", pasienBaru.imt);

  if (pasienBaru.imt < 18.5)
  {
    fprintf(dp, "Status : Kurus\n");
    printf("Kategori : Kurus\n");
  }
  else if (pasienBaru.imt < 24.9)
  {
    fprintf(dp, "Status : Normal\n");
    printf("Kategori : Normal\n");
  }
  else
  {
    fprintf(dp, "Status : Gemuk\n");
    printf("Kategori : Gemuk\n");
  }

  fclose(dp);
}

void Imunisasi()
{
  Pasien pasienBaru;

  printf("\n");
  printf("Nama Anak : ");
  scanf(" %49[^\n]", pasienBaru.nama);
  fflush(stdin);
  printf("Usia : ");
  scanf("%d", &pasienBaru.usia);
  fflush(stdin);

  printf("\n");
  printf("Pilih jenis Imunisasi yang ingin diberikan:\n");
  printf("1. BCG untuk mencegah penyakit TBC\n");
  printf("2. DPT untuk mencegah penyakit difteri, pertusis (batuk rejan), tetanus\n");
  printf("3. Polio untuk mencegah penyakit kelumpuhan.\n");
  printf("4. Hepatitis B untuk mencegah penyakit hepatitis B (penyakit kuning)\n");
  printf("Masukkan Pilihan : ");
  scanf("%d", &pasienBaru.info.pilihan);

  FILE *dp;
  dp = fopen(DATAPASIEN, "a");
  fprintf(dp, "\nKeperluan : Imunisasi\n");
  fprintf(dp, "Nama : %s\n", pasienBaru.nama);
  fprintf(dp, "Usia : %d tahun\n", pasienBaru.usia);

  switch (pasienBaru.info.pilihan)
  {
  case 1:
    fprintf(dp, "Imunisasi yang diberikan : BCG\n");
    printf("Anak anda telah di Imunisasi BCG");
    break;

  case 2:
    fprintf(dp, "Imunisasi yang diberikan : DPT\n");
    printf("Anak anda telah di Imunisasi DPT");
    break;
  case 3:
    fprintf(dp, "Imunisasi yang diberikan : Polio\n");
    printf("Anak anda telah di Imunisasi Polio");
    break;
  case 4:
    fprintf(dp, "Imunisasi yang diberikan : Hepatitis B\n");
    printf("Anak anda telah di Imunisasi Hepatitis B");
    break;

  default:
    printf("Pilihan tidak valid!");
    break;
  }

  fclose(dp);
}

void statusPertumbuhan(float zScore)
{
  printf("Status Gizi :  %.1f ", zScore);
  if (zScore < -2.0)
  {
    printf("Kurang\n");
  }
  else if (zScore >= -2.0 && zScore <= 2.0)
  {
    printf("Normal\n");
  }
  else
  {
    printf("Lebih\n");
  }
}

void PengukuranGizi()
{
  Pasien pasienBaru;

  printf("\n");
  printf("Nama Anak : ");
  scanf(" %49[^\n]", pasienBaru.nama);
  fflush(stdin);
  printf("Usia : ");
  scanf("%d", &pasienBaru.usia);
  fflush(stdin);
  printf("Jenis Kelamin : ");
  scanf(" %19[^\n]", pasienBaru.jenisKelamin);
  printf("Berat Badan (kg): ");
  scanf("%f", &pasienBaru.bb);
  fflush(stdin);

  float berat, SD;

  berat = 10.0;
  SD = 2.0;

  float zScore = (pasienBaru.bb - berat) / SD;

  FILE *dp;
  dp = fopen(DATAPASIEN, "a");

  fprintf(dp, "\nKeperluan : Pengukuran Gizi\n");
  fprintf(dp, "Nama : %s\n", pasienBaru.nama);
  fprintf(dp, "Usia : %d tahun\n", pasienBaru.usia);
  fprintf(dp, "Jenis Kelamin : %s\n", pasienBaru.jenisKelamin);
  fprintf(dp, "Berat Badan : %.2fkg\n", pasienBaru.bb);
  fprintf(dp, "Nilai Z-Score : %.2f\n", zScore);

  statusPertumbuhan(zScore);

  fclose(dp);
}

void PenanggulanganDiare()
{
  Pasien pasienBaru;

  printf("\n");
  printf("Nama Anak : ");
  scanf(" %49[^\n]", pasienBaru.nama);
  fflush(stdin);
  printf("Usia : ");
  scanf("%d", &pasienBaru.usia);
  fflush(stdin);
  printf("Berat Badan (kg): ");
  scanf("%f", &pasienBaru.bb);
  fflush(stdin);
  printf("Masukkan keluhan anak Anda: ");
  scanf(" %199[^\n]", pasienBaru.info.keluhan);
  fflush(stdin);

  printf("Obat : Oralite\n");

  FILE *dp;
  dp = fopen(DATAPASIEN, "a");

  fprintf(dp, "\nKeperluan : Penanggulangan Diare\n");
  fprintf(dp, "Nama : %s\n", pasienBaru.nama);
  fprintf(dp, "Usia : %d tahun\n", pasienBaru.usia);
  fprintf(dp, "Berat Badan : %dkg\n", pasienBaru.bb);
  fprintf(dp, "Keluhan : %s\n", pasienBaru.info.keluhan);

  if (pasienBaru.bb >= 3.0 && pasienBaru.bb <= 4.5)
  {
    fprintf(dp, "Obat : Oralite\n");
    fprintf(dp, "Dosis yang diberikan 60 ml per satu jam sekali\n");
    printf("Dosis: 60 ml per satu jam sekali\n");
  }
  else if (pasienBaru.bb > 4.5 && pasienBaru.bb <= 7.0)
  {
    fprintf(dp, "Obat : Oralite\n");
    fprintf(dp, "Dosis yang diberikan 70 ml per satu jam sekali\n");
    printf("Dosis: 70 ml per satu jam sekali\n");
  }
  else if (pasienBaru.bb > 7.0 && pasienBaru.bb <= 9.0)
  {
    fprintf(dp, "Obat : Oralite\n");
    fprintf(dp, "Dosis yang diberikan 100 ml per satu jam sekali\n");
    printf("Dosis: 100 ml per satu jam sekali\n");
  }
  else if (pasienBaru.bb > 9.0 && pasienBaru.bb <= 18.0)
  {
    fprintf(dp, "Obat : Oralite\n");
    fprintf(dp, "Dosis yang diberikan 190 ml per satu jam sekali\n");
    printf("Dosis: 190 ml per satu jam sekali\n");
  }
  else if (pasienBaru.bb > 18.0 && pasienBaru.bb < 27.0)
  {
    fprintf(dp, "Obat : Oralite\n");
    fprintf(dp, "Dosis yang diberikan 300 ml per satu jam sekali\n");
    printf("Dosis: 300 ml per satu jam sekali\n");
  }
  else
  {
    fprintf(dp, "Obat : Oralite\n");
    fprintf(dp, "Tidak dapat menentukan dosis untuk berat badan ini.\n");
    printf("Tidak dapat menentukan dosis untuk berat badan ini.\n");
  }

  fclose(dp);
}

int main()
{
  int choice;

  while (1)
  {
    printf("\n=============================\n");
    printf("||         POSYANDU        ||\n");
    printf("=============================\n");
    printf("1. Penimbangan Balita\n");
    printf("2. Imunisasi\n");
    printf("3. Pengukuran Gizi\n");
    printf("4. Penanggulangan Diare\n");
    printf("5. Lihat Rekap\n");
    printf("6. Keluar\n");
    printf("Enter your choice: ");
    scanf("%i", &choice);

    switch (choice)
    {
    case 1:
      Timbang();
      break;

    case 2:
      Imunisasi();
      break;

    case 3:
      PengukuranGizi();
      break;

    case 4:
      PenanggulanganDiare();
      break;

    case 5:
      loadData();
      break;

    case 6:
      printf("Terima kasih telah datang ke Posyandu!\n");
      exit(0);
      break;

    default:
      printf("\nPilihan tidak valid. Silakan coba lagi.\n");
      break;
    }
  }

  return 0;
}
