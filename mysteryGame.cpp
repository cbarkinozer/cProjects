//A fully random rpg console game based on League Of Legends, called Mystery. This game is old unfinished and cancelled. I made it with my friend Zawzi for joke
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

//Helmet bro
float HEALTH = 1000;
float MANA = 1000;
float ARMOR = 100;
float BASE_ATTACK = 5;
float MAGIC_RESIST = 5;
float AGILITY = 5;
float COIN = 0;
float AP;
float AD;

void SINGED();
void TEEMO();
void SONA();


int main()
{
	AP = AP + BASE_ATTACK;
	AD = AD + BASE_ATTACK;
	while (1)
	{

		printf("HEALTH: %f", HEALTH);
		printf(" MANA: %f           #\n", MANA);
		printf("ATTACK: %f", BASE_ATTACK);
		printf("ARMOR: %f", ARMOR);
		printf(" MAGIC RESIST: %f        #\n", MAGIC_RESIST);
		printf("AGILITY: %f", AGILITY);
		printf(" COINS: %f               #\n\n", COIN);
		printf("###################################\n\n");
		Sleep(1000);
		srand(time(NULL));
		int r = rand() % 2;
		switch (r)
		{
		case 0:
			TEEMO();
			break;
		case 1:
			SINGED();
			break;
		case 2:
			SONA();
			break;

		}
	}
	system("CLS");

}



void TEEMO()
{

	int r = rand() % 5;
	switch (r)
	{
	case 0:
		printf("Teemo :Kaptan Teemo göreve hazir!\n");
		Sleep(6000);
		printf("Yetenek:Kor eden dart[AP:100]\n");
		Sleep(3000);
		AP = 50;
		HEALTH = HEALTH - AP / MAGIC_RESIST;
		break;
	case 1:
		printf("Teemo :Kaptan Teemo goreve hazir!\n");
		Sleep(6000);
		printf("Yetenek: Cevik hareket, paranı caldı [COIN: -1]\n");
		Sleep(3000);
		COIN--;
		break;
	case 2:
		printf("Teemo :Kaptan Teemo goreve hazir!\n");
		Sleep(6000);
		printf("Yetenek: zehirleyen mantar[AP:200]\n");
		Sleep(3000);
		AP = 200;
		HEALTH = HEALTH - AP / MAGIC_RESIST;
		break;
	case 3:
		printf("Teemo :Kaptan Teemo goreve hazir!\n");
		Sleep(6000);
		printf("Yetenek: Kaptan Teemonun kor eden darti bogazina kactı[Health : +100]\n");
		Sleep(3000);
		printf("Teemo: ohohoho \n");
		HEALTH = HEALTH + 100;

		COIN++;
		MANA = MANA + 50;
		break;
	case 4:
		printf("Teemo :Kaptan Teemo goreve hazır!\n");
		Sleep(6000);
		printf("Yetenek: cevik hareket ederken rakip kuleye daldi\n");
		Sleep(3000);
		printf("Teemo: Aman aman nereye geldik bi anda bura neresi\n");
		Sleep(3000);
		HEALTH = HEALTH + 50;
		COIN++;
		MANA = MANA + 50;
		break;
	case 5:
		printf("Teemo :Kaptan Teemo goreve hazir!\n");
		Sleep(6000);
		printf("Yetenek: Teemo'nun ayagı kaydı, mantara bastı\n");
		Sleep(3000);
		printf("Teemo: ah bu acidi \n");
		Sleep(3000);
		HEALTH = HEALTH + 200;
		COIN++;
		MANA = MANA + 50;
		break;
		
	}
  system("CLS");
	main();
}





void SINGED()
{
	int r;
	r = rand() % 5;
	switch (r)
	{
	case 0:
		printf("Singed ile karsilastin\n");
		Sleep(6000);
		printf("Singed gaza boguyor\n");
		Sleep(3000);
		AP = 100;
		HEALTH = HEALTH - AP / MAGIC_RESIST;
		break;
	case 1:
		printf("Singed ile karsilastin:\n");
		Sleep(6000);
		printf("Singed tukurdu\n");
		Sleep(3000);
		AP = 150;
		HEALTH = HEALTH - AP / MAGIC_RESIST;
		break;
	case 2:
		printf("Singed ile karsilastin:\n");
		Sleep(6000);
		printf("Singed meydan okudu\n");
		Sleep(3000);
		AP = 250;
		HEALTH = HEALTH - AP / MAGIC_RESIST;
		break;
	case  3:
		printf("Singed ile karsilastin:\n");
		Sleep(6000);
		printf("Fastfood gaz yaptı,bagirsaklari dugumlendi\n");
		Sleep(3000);
		break;
	case 4:
		printf("Singed ile karsilastin:\n");
		Sleep(6000);
		printf("Nezle olmuş bu çok igrenc\n");
		Sleep(3000);
		break;
	case 5:
		printf("Singed ile karsilastin:\n");
		Sleep(6000);
		printf(" her yeri batti\n");
		Sleep(3000);
		break;
	}
	system("CLS");
	main();
}





void SONA()
{

	int r = rand() % 5;
	
	switch (r) {
		//1. Senaryo
		int LEFT_SECONDS;
	case 0:
		LEFT_SECONDS = 10;
		printf("SONA: Beni sadece sen duyabiliyorsun, bugun hangi basyapiti calalim?\n");
		printf("Yetenek Kullanılıyor: Cesaret İlahisi\nTahmini savas süresi 10 sn..\n");

		for (int hJk873s = 0; hJk873s <= 10; hJk873s++) {
			Sleep(1000);
			printf("%d saniye kaldi. Sona hicbir sey yapmadan sana bakiyor, bu gercekten ilginc..\n", LEFT_SECONDS);
			LEFT_SECONDS = LEFT_SECONDS - 1;
			system("CLS");
		}

		if (HEALTH >= 1000) {
			printf("Sona heybetin karsisinda cesaretini kaybetti. Cekismeden dolayi bir miktar hasar aldin.\nEtkiler:\nBASE ATTACK +%f\nHEALTH -%f\nMANA +%f", (HEALTH / 100) + AGILITY + MAGIC_RESIST, 100 - ARMOR - AGILITY, 5 * MAGIC_RESIST);
			BASE_ATTACK = BASE_ATTACK + 25;
			HEALTH = HEALTH - 50;
			MANA = MANA + 150;
      Sleep(5000);
		}
		system("CLS");
		main();
		break;

		//2. Senaryo
	case 2:
		printf("Sonanin kalan son duyu organi olan gozleri lanetlendi. Gozleri ruhun varligini tuketerek onu hiclige gonderir.\nEtkiler:\nHEALTH -%f", HEALTH = HEALTH - (450 - AGILITY * 2));
    Sleep(6000);
	}
}
