#include<stdio.h>
#include<string.h>

typedef struct{
  char name[30];
  int id;
  float HD, PB, hd1, hd2, hd3;
} sinhVien;

sinhVien sv[20];
int n = 0;

int Ktraid(int m){
  int check = 1;
  int i;
  for( i = 0; i<m;i++){
    if(sv[i].id == sv[m].id){
      check = 0;
      break;
    }
  }
  return check;
}

int try(char s[]){
  int l = strlen(s);
  int check = 1;
  int dem = 0;
  int i;
  for( i =0; i<l ;i++){
    if(s[i] == ' '){
      dem = dem +1;
    }
  }
  if(dem == 0 || s[l-1] == ' ') check = 0;
  return check;
}

void boSung(int them){
	 int i;
  for( i=n; i<n+them; i++){
    printf("sinh vien %d: ", i+1);
   
    do{
      printf("id = ");
      scanf("%d%*c",&sv[i].id);
    }while((sv[i].id <= 0 || sv[i].id >99999) ||  Ktraid(i) == 0);

    do{
      printf("name: ");fflush(stdin); //gets(sv[i].name);
      scanf("%[^\n]%*c", sv[i].name);
    }while(try(sv[i].name) == 0);
    do{
      printf("Diem: \n");
      printf("HD = ");
      scanf("%f",&sv[i].HD);
      printf("PB = ");
      scanf("%f",&sv[i].PB);
      printf("hd1 = ");
      scanf("%f",&sv[i].hd1);
      printf("hd2 = ");
      scanf("%f",&sv[i].hd2);
      printf("hd3 = ");
      scanf("%f",&sv[i].hd3);
    }while(sv[i].HD<0 ||sv[i].PB <0|| sv[i].hd1<0 ||sv[i].hd2<0||sv[i].hd3<0||sv[i].HD>10||sv[i].PB>10||sv[i].hd1>10||sv[i].hd2>10||sv[i].hd3>10);
  }
  n = n + them;
}
    
void dsBaoVe(){
  float Giuaki,Cuoiki;
	int i;
	printf("\n%-10s%-20s%-5s%-5s%-5s%-5s%-5s%-10s%s\n","MSSV","Ho va ten","HD","PB","Hd1","Hd2","Hd3","Giua Ki","Cuoi ki");
	for(i=0;i<n;i++){
		if(sv[i].HD >=5.5 && sv[i].PB >= 5.5 && sv[i].hd1 >=5.5 && sv[i].hd2 >=5.5 && sv[i].hd3 >= 5.5){
			Giuaki = (sv[i].HD + sv[i].PB)/2;
			Cuoiki = (sv[i].hd1 + sv[i].hd2 + sv[i].hd3)/3;
		}else{
			Giuaki = 0;
			Cuoiki = 0;
		}
		if(Giuaki != 0)
			printf("%-10d%-20s%-5.1f%-5.1f%-5.1f%-5.1f%-5.1f%-10.1f%.1f\n",sv[i].id,sv[i].name,sv[i].HD,sv[i].PB,sv[i].hd1,sv[i].hd2,sv[i].hd3,Giuaki,Cuoiki);
	}
}


void tachten(char hoten[],char ten[]){
	 int i;
	for( i=strlen(hoten)-1;i>=0;i--){
		if(hoten[i]==' '){
			strcpy(ten,hoten[1+i]);
			break;
		}
	}
}
void sapxep(){
	 int i,j;
	for(i=0;i<n;i++){
		for( j=i+1;j<n;j++){
			char ten1[30]="",ten2[30]="";
			tachten(sv[i].name,ten1);
			tachten(sv[j].name,ten2);
			int check1=strcmp(ten1,ten2);
			if(check1>0){
				sinhVien temp= sv[i];
				sv[i]= sv[j];
				sv[j]=temp;
			}
			else{
				 if(check1==0){
					int check2=strcmp(sv[i].name , sv[j].name);
					if(check2>0){
					sinhVien temp= sv[i];
					sv[i]= sv[j];
					sv[j]=temp;
					}
				}
			}
		}
	}
}
void Output(){
	int i;
	float Giuaki, Cuoiki;
	printf("\n%-10s%-20s%-5s%-5s%-5s%-5s%-5s%-10s%s\n","MSSV","Ho va ten","HD","PB","Hd1","Hd2","Hd3","Giua Ki","Cuoi ki");
	for(i=0;i<n;i++){
		if(sv[i].HD >=5.5 && sv[i].PB >= 5.5 && sv[i].hd1 >=5.5 && sv[i].hd2 >=5.5 && sv[i].hd3 >= 5.5){
			Giuaki = (sv[i].HD + sv[i].PB)/2;
			Cuoiki = (sv[i].hd1 + sv[i].hd2 + sv[i].hd3)/3;
		}else{
			Giuaki = 0;
			Cuoiki = 0;
		}
		printf("%-10d%-20s%-5.1f%-5.1f%-5.1f%-5.1f%-5.1f%-10.1f%.1f\n",sv[i].id,sv[i].name,sv[i].HD,sv[i].PB,sv[i].hd1,sv[i].hd2,sv[i].hd3,Giuaki,Cuoiki);
	
	}
	
}


int main(){
  int luachon ;
  do{
    printf("\n\nMENU\n\n");
    printf("1. Bo sung sinh vien\n");
    printf("2. Danh sach sinh vien da bao ve thanh cong\n");
    printf("3. Sap xep theo ten sinh vien\n");
    printf("4. Thoat chuong trinh\n\n");
    printf("nhap lua chon cua ban: ");
    scanf("%d",&luachon);
    if(luachon >4 || luachon <= 0)
      printf("Nhap khong dung!\n");
    switch(luachon){
    case 1: {
      
      int them;
      do{
	printf("nhap so sinh vien can them: ");
	scanf("%d",&them);
      }while(them < 0 || them > (20 - n));
      
      boSung(them);
      Output();
      break;
    }
    case 2: {
      dsBaoVe();
      break;
    }
    case 3: {
       sapxep();
       Output();
       break;
       }
    }
  }while(luachon!=4);
  
  
  return 0;
}
