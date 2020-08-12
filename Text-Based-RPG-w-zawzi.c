//80's text based style adventure game Works great but not fully done
#include<iostream>
#include <stdio.h>
#include <windows.h>
#include<time.h>

using namespace std;

void stats();
void orman();
void sahil();
void yardim_bekle();
void ormanda_devam_et();

void OLTA();
void AXE();
void LIGHTER();



//ITEM
int OLTA_;
int AXE_;
int LIGHTER_;


//STATS
int HEALTH = 100;
int HUNGRY = 5;
int THIRSTY = 5;
int BOREDOM = 5;
int SHELTER = 5;
int STATUS = 1;
int main()
{

	//variables

	int DECISION;

	srand(time(NULL));




	cout << "Adaya dustun"<<endl;

	while (STATUS)
	{
		cout << "Ne yapacaksin!" << endl;
		Sleep(2000);
		cout << "1:ormana git" << endl;
		cout << "2:sahilde dolas" << endl;
		cout << "3:yardim bekle" << endl;
		cin >> DECISION;
		switch (DECISION)
		{
		case 1:
			orman();
			break;
		case 2:
			sahil();
			break;
		case 3:
			yardim_bekle();
			break;
		}

	}
	return 0;
}

void stats()
{
	cout << HEALTH << endl;
	cout << HUNGRY << endl;
	cout << THIRSTY << endl;
	cout << BOREDOM << endl;
	cout << SHELTER << endl;

}


//1. kararlar
void orman()
{
	int choice1;
	int choice1_1;
	system("CLS");
	cout << "ormanda geziniyorsun ! ! !" << endl;
	Sleep(5000);
	cout << "karsina bir patika ayrimi cikti sagdan(1) mi gitmek istersin  soldan (2) mi ?" << endl;
	cin >> choice1;
	switch (choice1)
	{
	case 1:
		system("CLS");
		cout << " sagdan  gitmeyi sectin " << endl;
		cout << " yuruyorsun " << endl;

		AXE();

		Sleep(5000);
		cout << "karsina bir yilan cikti ";
		Sleep(5000);


		cout << "ne yapmak istersin ?" << endl;
		cout << "1-sesiz kal ve yavasca geri cekil"<<endl;
		cout << "2-saldirmayi dene "<<endl;
		
		cin >> choice1_1;
		system("CLS");
		switch (choice1_1)
		{
		case 1:cout << "yavasca cekiliyorsun !! " << endl;
			Sleep(4000);
			cout << "pacayi kurtardin " << endl;
			HEALTH -= 10;
			HUNGRY -= 1;
			THIRSTY -= 1;
			BOREDOM -= 1;
			SHELTER -= 1;
			cout << "iste son degerlerin" << endl;;
			cout << HEALTH<<endl;
			cout << HUNGRY << endl;
			cout << THIRSTY << endl;
			cout << BOREDOM << endl;
			cout << SHELTER << endl;
			
			
			Sleep(4000);
			system("CLS");
			STATUS = 1;// buna gerek varmı bilmiyorum başa dönsün die ölmedi sonucta
			break;

		case 2:Sleep(5000);
			system("CLS");
			if (AXE_ = 1)
			{
				
				cout << "yilanla bogusuyorsun........ "<<endl;
				Sleep(4000);
				cout << "yilanin kafasina baltayi vurdun ........"<<endl;
				Sleep(2000);
				cout << "yilani oldurmeyi basardin"<<endl;
				
				HEALTH -= 10;
				HUNGRY -= 1;
				THIRSTY -= 1;
				system("CLS");
				
				Sleep(4000);
;				
				cout << "iste son degerlerin" << endl;;
				cout <<"CAN:"<< HEALTH << endl;
				cout <<"ACLIK:" << HUNGRY << endl;
				cout <<"SUSUZLUK"<< THIRSTY << endl;
				

				Sleep(4000);
				system("CLS");
				ormanda_devam_et();




			}
			else
			{
				cout << "yilana karsi saldirin basarisiz oldu " << endl;
				cout << " yilan tarifindan isirildin" << endl;
				cout << "zehirlendin !! " << endl << "can ve  su kaybetmeye basladin" << endl;

				for (int i = 0; i < 5; i++)// burda kahramanimiz damege yiyor yani ekranda onu //belirtmek için
				{
					HEALTH -= 5;
					if (i < 2)
					{
						THIRSTY -= 1;
					}
					cout << "can ve su kaybi yasiyorsun ! ! ! ! !" << endl;
					cout << "can:" << HEALTH << endl;
					cout << "Su degeri:" << THIRSTY;
				}

			}
			break;

		}
		break;
	case 2:


		cout << " soldan  gitmeyi sectin " << endl;
		cout << " yuruyorsun " << endl;
		Sleep(5000);
		cout << "aaaaaaaa o'da NE!!" << endl;
		cout << "TELSİZ Mİ YOKSA " << endl;
		cout << "lan bu kadar bahtlı olunmaz haaaa helede ikinci secimden" << endl;
		cout << "calisiyorda ";
		cout << "telsize dogru yürümeye devam ediyorsin";
		Sleep(5000);
		system("CLS");

		for (int i = 0; i < 5; i++)
		{
			cout << ".....................................................";
			Sleep(5000);
			system("CLS");
		}
		Sleep(5000);
		cout << " aaaaaaaaaaa   bubi tuzagiymis" << endl;
		cout << "oldun cik";
		STATUS = 0;
		break;



	}






}

void sahil()
{
	int SECIM;
	int GAME_OVER;
	system("CLS");
	cout << "Sahilde dolasmaya basladin, adanin tum buyuklugunu anlamaya calisiyorsun calisiyorsun" << endl;
	Sleep(6000);

	OLTA();


	cout << "Karnin acikmaya basladi" << endl;
	cout << "1:yengec yemek , 2:bocek yemek, 3: balik tutmak, 4: yola devam" << endl;
	cin >> SECIM;
	system("CLS");
	switch (SECIM)
	{
	case 1:
		Sleep(5000);
		cout << "Yengeci tutmaya calistin elini kistirdi,elin şişti cok aciyor karnin da ac!" << endl;
		HEALTH = HEALTH - 20;
		HUNGRY = HUNGRY + 3;
		stats();
		if (HUNGRY >= 10) { STATUS = 0; }
		break;

	case 2:
		Sleep(5000);
		cout << "Yerde gezinen bocekleri tutmaya calisiyorsun,birkacini tutup direkt yedin tatlari cok kotu ama protein" << endl;
		HEALTH = HEALTH + 40;
		BOREDOM = BOREDOM + 4;
		stats();
		if (BOREDOM >= 10)
		{
			cout << "Atı alan Üsküdar’ı geçti. Biz takibe devam ediyorum merkez. Tamam!." << endl;
			cout << "Aklini kaciriyorsun," << endl;
			Sleep(6000);
			cout << "oldun" << endl;
			cout << "Bir daha oynayacak misin?,1: evet,0: hayir" << endl;
			cin >> GAME_OVER;
			if (GAME_OVER)
			{
				main();
			}
		
			else
			{
				cout << "Thanks for playing noob" << endl;
				Sleep(3000);
				STATUS = 0;
			}
		}
		break;


	case 3:
		Sleep(5000);
		if (OLTA_ = 1)
		{
			cout << "Oltani cikardin bekliyorsun" << endl;
			cout << "Balik tuttun" << endl;
			HEALTH = HEALTH + 40;
			BOREDOM = BOREDOM - 3;
		}
		else
		{
			cout << "Balik tutacak malzemen yok,elini kullaniyorsun babayi aliyorsun" << endl;
			HEALTH = HEALTH - 20;
			BOREDOM = BOREDOM + 1;
			stats();
			if (HUNGRY >= 10) { STATUS = 0; }
			if (BOREDOM >= 10)
			{
				cout << "Aklini kaciriyorsun," << endl;
				Sleep(6000);
				STATUS = 0;

			}
			break;


	case 4:
		Sleep(10000);

		int Game_Over;
		cout << "Karnin cok acikti öldün " << endl;
		cout << "Bir daha oynayacak misin?,1: evet,0: hayir" << endl;
		cin >> Game_Over;
		if (Game_Over)
		{
			main();
		}
		else
		{
			cout << "Thanks for playing noob" << endl;
			Sleep(3000);
			STATUS = 0;
		}
		break;
		}

	}
	cout << "Sahilden bir fayda geldigi yok" << endl;
	cout << "1:yardim bekle,2:orman" << endl;
	cin >> SECIM;
	switch (SECIM)
	{
	case 1:
		yardim_bekle();
		break;
	case 2:
		orman();
		break;
	}

}

void yardim_bekle()
{
	cout << "Millete el sallıyon,agactan sos yazıyon, bi halta yaramıyor" << endl;
	cout << "acliktan oldun" << endl;
	STATUS = 0;
}

void OLTA()
{
	int r = 0;
	r = rand() % 2;
	if (r = 1)
	{
		cout << "Kutu buldun,sansli gunundesin " << endl;
		cout << "Vayy Olta buldun " << endl;
		OLTA_ = 1;
	}

}

void LIGHTER()
{
	

	int r = 0;
	r = rand() % 2;
	if (r = 1)
	{
		cout << "Kutu buldun,sansli gunundesin " << endl;
		cout << "Vayy cakmak buldun " << endl;
		LIGHTER_ = 1;
	}
}

void AXE()
{
	

	int r = 0;
	r = rand() % 2;
	if (r = 1)
	{
		cout << "Kutu buldun,sansli gunundesin " << endl;
		cout << "Vayy balta buldun " << endl;
		AXE_ = 1;
	}
}
void ormanda_devam_et()
{
	string cozum;
	int deneme = 3;

	cout << "yurumeye devam ediyorsun" << endl;
	Sleep(4000);
	cout << "agaclarin arasindan siyriliyorsun" << endl;
	Sleep(2000);
	cout << "aaaaa o da ne !!!! bir tapinak mi yoksa"<<endl;
	Sleep(2000);
	cout << "kapisina dogru yuruyorsun " << endl;
	Sleep(4000);
	cout << "ayagin bir cukura girdi " << endl;
	Sleep(2000);
	cout << "kalcana zehirli bir ok geldi " << endl;
	Sleep(2000);
	cout << " yavasca uykuya daliyorsun" << endl;
	Sleep(2000);
	Sleep(10000);
	cout << "gozunu araliyorsun" << endl;
	Sleep(2000);
	cout << "karsinda adanin yerlileri" << endl;
	Sleep(2000);
	cout << "yerlilerin reisi sana dogru geliyor" << endl;
	Sleep(2000);
	cout << "onunde diz cokuyor  " << endl;
	Sleep(2000);
	cout << "galiba tanrilarina benzettiler";
	Sleep(2000);
	cout << "ama emin olabilmek icin  bir bulmaca cozmen gerekiyor cozemesen olecekin !!!!!!!!!!!!" << endl;

	system("CLS");
	char bulmaca[4][4] = { 's','y','r','k',
									 'i' ,'s','a','b',
									  'k','b','y','a',
									  'l','i','a','e' };

	for (int i = 0; i < 4; i++)
	{

		for (int j = 0; j < 4; j++)
		{
			cout << " " << bulmaca[i][j];
		}

		cout << endl;

	}

	cout << " bu bulmacacada 3 farkli kelime karisik halde yazili" << endl << "herhangi birini bulursan 'yerli'ler seni tanri kabul edecek bulamasan oleceksin 3 hakkin var" << endl << "ilk hakkini dene bakalim"<<endl;

	cin >> cozum;
	if (cozum == "sikaka" || cozum == "yarasa" || cozum == "yerli")
	{
		cout << "dogru bildin  arttık onlarin gozunde bir tanrısın ne istersen onu yapcaklar" << endl;;

		// devam etcek
		
	}
	else
	{
		
		while (cozum != "sikaka" || cozum != "yarasa" || cozum != "yerli")
		{
			deneme -= 1;
			cout << "ahhhh yanlis neyse korkma " << deneme << "bir sans daha veriyorlar"<<endl;
			cin >> cozum;
			if (cozum == "sikaka" || cozum == "yarasa" || cozum == "yerli")
			{
				cout << "dogru bildin  arttik onlarin gozunde bir tanrisin ne istersen onu yapcaklar";

				// devam etcek
				break;
			}
		}

	}
