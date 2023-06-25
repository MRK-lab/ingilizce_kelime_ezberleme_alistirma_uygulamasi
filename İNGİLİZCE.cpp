#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*
	CÜMLELERİ DÜZENLEME (tüm cümleler ve sıralamaya gore istediğini seçen algoritma)
	İNG-TUR TEKRAR ALGO	(tür-ing gibi tekrar algoritmsını yapılandır)
	ESKİ KELİMELERİDE BU PROGRAMDA BULUNDURMA	(a harfinden beri tüm kelimeleri ayrı bir dizide tutma)
	UNUTULAN KELİMELERİ AYRI DİZİDE TUTMA	(unutulan kelimeleri en son isteğe bağlı listeleme)
	kelime ekleme
*/

string convert(string ad)
{
	for (int i = 0; i < ad.length(); i++)
		ad[i] = tolower(ad[i]);
	return ad;
}
int main()

{
	system("color B0");
	setlocale(LC_ALL, "Turkish");
	srand(time(0));

	string engl[] = { /*"eagle","early","earn","eclipse","dress","elbow","else","embrace","enduring","enemy","engaged","engine","enjoy","enough","equal","escape","especially","estimate",
		"evaporation","even","ever","everyone","everthing","evidence","exactly","exellent","except","exchanged","excited","exciting","exercise","exhausted","expect","expired","explore","decision",
		"delicate","despite","discover","drum","calm","buried","arrive","convenient","contains"*/  "faith","fall","familiar","famous","fashion","feel","file","fill","find","fingerprint","fire","fishing","fit","fix","flew","floor","flow","foam","follow","fuction","footprint","for","for example","foreign","forever","forget","fork","formal","fox","fragile","frankly","freedom","freeze","frighten","frog","front","frozen","fugitive","fun","fungus","future","storm"};
	string turk[] = { /*"kartal","erken,ilk","kazanmak","tutulma","elbise","dirsek ","baska","kucaklama ","dayanikli","dusman","nisanli","motor","hoslanma","yeter","esit",
		"kacis","ozellikle","tahmin","buharlasma","bile,hatta","hic","herkes","hersey","kanit","tam olarak","mukemmel","haricinde","degistirmek","heyecanli","heyecan verici","egzersiz",
		"tukenmis","ummak","suresi bitmis","kesfetmek","karar","hassas","ragmen","kesfetmek","davul","sakin","gomulu","ulasmak","musait","kapsamak"*/ "inanc","dusmek","tanidik","unlu","moda","his,duygu","dosya","doldurmak","bulmak","parmakizi","yangin","balik tutmak","uygun","duzeltme","ucmak","zemin","akis","kopuk","takip etmek","fonksiyon","ayak izi","icin","ornegin","yabanc?","sonsuza dek","unutmak","catal","resmi","tilki,kurnaz","kirilgan","acikcasi","ozgurluk","donma","korkutmak","kurbaga","on","dondurulmus","kacak","eglenceli","mantar","gelecek","firtina"};

	string engcum[]{ "my sweet darling i miss you so much","i am deadly","there are ten years in a decade","still waters run deep","it is hard to define triangle","when is the departure time",
		"it is very delicate questiob","despite him i won","you dig a deep hole","please clear the dirty floor","you disappear in front of my eye","famous picture is on display","i bought two dozen pencils",
		"i have a dream","i drop her","wash and dry please","it is very important to consider the cultural past of the family","the old bridge is in danger of collapse","my cheecks burn",
		"you owe me an apology for that","america was a mainly agricultural societly","come and see me when it is convenient for you","a small snowball is capable of starting an avalanche",
		"the car crashed because the driver was careless","this book contains forty photographs","milk is a popular beverage","company spends a lot of money on advertising","tom is witty is not he?",
		"he abuse good","i love the beloved","the sooner the better","i dont blame you","it is healthy to breathe deeply","you made a big mistake buddy","we were looking for buried treasure",
		"i would like to pay in cash","my friend is really a clown","the collection is open to the public","the house on the corner is outs","i have a cough","see you soon","at the moment",
		"I would really like to explore this cave","Don't expect others to think for you","Yu must be mentally exhausted","It was very exciting! I'd like to go again","I was a excited that I could not fall asleep",
		"He exchanged seats with the next person","I go to the office by bicycle except on rainy days","I dont't know exactly where Kyoko lives, but it is in the direction of Sannomia","There is no evidence to the contraty",
		"Have you ever traveled in a plane","even though he apologized, I am still furious","can you estimate how late the train will be","this is designed especially for young people","finally my sister got engaged",
		"there are various ways of enduring the pain","turgut asked ertuğrul to embrace her tightly","the joint in my left elbow hurts","did you see the lunar eclipse yesterday night","he doesn't earn enough money to live on",
		"you needn't have hurried you have arrive too early",
	};
	string turcum[]{ "benim tatlı sevgilim seni çok özledim","ben ölümcülüm","on yılda on yıl var","durgun sular derin akar","üçgeni tanımlamak zor","kalkış saati ne zaman","o çok hassas bir soru",
		"ona rağmen kazandım","derin bir çukur kaz","lütfen kirli zemini temizle","gözümün önünden kaybol","ünlü resim sergileniyor","iki düzine kalem aldım","benim bir hayalim var","onu düşürdüm",
		"lütfen yıka ve kurut","ailenin kültürel geçmişini göz önüne almak çok önemlidir","eski kopru yikilma tehlikesi icinde","yanaklarim yaniyor","bana bunun icin bir ozur borclusun",
		"amerika temel olarak bir tarim topmumuydu","senin icin uygun oldugunda gel ve gor beni","kucuk bir kartopu bir cig baslatabilir","surucu dikkatsiz oldugu icin araba carpti","bu kitap kirk fotograf icerir",
		"sut popular bir icecektir","sirket reklama cok para harciyor","tom espirili degil mi","o iyiyi kotuye kullanir","sevgiliyi seviyorum","ne kadar erken o kadar iyi","seni suclamiyorum",
		"derin nefes almak sagliktir","buyuk bir hata yaptin kanka","gomulu hazinryi ariyorduk","nakit olarak odemek istiyorum","arkadasim gercekten bir palyaco","kolleksiyon halka acık",
		"kose basindandaki ev bizim","ben oksuruyorum","sonra görüşürüz","şu anda","Ben gerçekten bu mağarayı keşfetmek istiyorum","başkasının senin için düşünmesini bekleme","Zihinsel olarak yorgun olmalısın",
		"Çok heyecan verici! Tekrar gitmek istiyorum","O kadar heyecanlıyım ki uyuyamadım","Bir sonraki kişiyle koltukları değişti","Yağmurlu günler hariç ben büroya bisikletimle giderim",
		"Ben tam olarak Kyoko'nun nerede yaşadığını bilmiyorum ama Sannomia yönünde","Hiçbir karşıt kanıt yoktur","Hiç bir uçakta seyehat ettin mi?","Özür dilemesine rağmen hala öfkeliyim ","trenin ne kadar geç kalacağını tahmin edebilir misin",
		"bu özellikle genç insanlar için tasarlanmıştır","kız kardeşim sonunda nişanlandı","acıya katlanmanın birçok yolu var","turgur ertuğrul'dan onu sıkıca kucaklamasını istedi","sol dirseğimdeki eklem acıyor",
		"dün geceki ay tutulmasını gördünmü","geçinmek için yeterli para kazanmıyor","acele etmene gerek yoktu çok erken vardın",
	};

	string questions[] = { "ne","ne zaman","nerede","hangi","kim","kimin","neden","nasıl","what","when","where","which","who","whose","why","how" };
	string answers[] = { "what","when","where","which","who","whose","why","how","ne","ne zaman","nerede","hangi","kim","kimin","neden","nasıl" };

	int boy = sizeof(engl) / sizeof(engl[0]);
	int konboy = sizeof(turk) / sizeof(turk[0]);
	int boy2 = boy;
	string answ;
	int doğ = 0, yan = 0, bos = 0;
	int c_e_boy = sizeof(engcum) / sizeof(engcum[0]);
	int c_t_boy = sizeof(turcum) / sizeof(turcum[0]);

	int* dizi;
	dizi = (int*)malloc(boy * sizeof(int));
	int* dizi2;
	dizi2 = (int*)malloc(c_e_boy * sizeof(int));
	int soru_dizi[16];


	// word check
	/*
	if (boy == konboy) {
		cout<<boy <<"  Dizi eleman sayısı birbirine eşit ( The number of elements of array is equal )" << endl<<endl;
	}
	else
		cout << "Dizi eleman sayıları eşit değil ( The numbers of elements of array is not equal )" << endl<<endl;
	*/
	//  sentence check
	/*
	if (c_e_boy == c_t_boy) {
		cout << c_e_boy << "  Dizi eleman sayısı birbirine eşit ( The number of elements of array is equal )" << endl<<endl;
	}
	else
		cout << "Dizi eleman sayıları eşit değil ( The numbers of elements of array is not equal )" << endl<<endl;
	*/
	
	// random kelimeler icin
	for (int i = 0; i < boy2; i++)
	{
		dizi[i] = rand() % boy2;
		for (int j = i; j > 0; j--)
		{
			if (dizi[i] == dizi[j-1])
			{
				i--;
				continue;
			}
		}
	}
	
	// random cumleler için
	for (int i = 0; i < c_e_boy; i++)
	{
		dizi2[i] = rand() % c_e_boy;
		for (int j = i; j > 0; j--)
		{
			if (dizi2[i] == dizi2[j - 1])
			{
				i--;
				continue;
			}
		}
	}

	// random sorular için
	for (int i = 0; i < 16; i++)
	{
		soru_dizi[i] = rand() % 16;
		for (int j = i; j > 0; j--)
		{
			if (soru_dizi[i] == soru_dizi[j - 1])
			{
				i--;
				continue;
			}
		}
	}


	// random için kontroller
	/*
	for (int i = 0; i < boy2; i++)
	{
		cout <<i+1<<" "<< dizi[i]<<endl;
	}
	int dizi3[54];     
	for (int i = 0; i < 54; i++)
		dizi2[i] = 0; // dizi elemanlarını sıfırladık

	for (int i = 0; i < c_e_boy; i++) 
	{
		int sayi = dizi[i];
		dizi2[sayi - 1]++;
	}
	for (int i = 0; i < c_e_boy; i++)  // bir elemandan kaç tane olduğunu bulduk
	{
		cout << i + 1 << " = " << dizi2[i] << endl;
	}
	*/

	int secim = 0;
	int seci[25]; // seçim değerlerini tutmak için
	int s = 0;
	int renk = 2; // gündüz modlu başlıyor
	for (int i = 0; i < 25; i++) {
		seci[i] = 0;
	}

	// yanlış ve boş bırakılan kelimeleri ayrı bir dizide tutup random bir şekilde isteğe bağlı olarak tekrar alınması
	string again_q[75]; // tekrar sorular için
	string again_a[75]; // tekrar cevaplar için
	int sayac_again = 0; // again için sayac;
	int againBoyut = 75; // again dizimizn boyutunu tutar

	do
	{
		cout << "\t\t----- MENU -----" << endl;
		cout << "\t1- Gece modu (Night Mode) \n\t2- Gündüz Modu (Morning Mode)\n\t3- Türkçe/İngilizce Kelimeler (Turlish/English Word)\n\t4- İngilizce/Türkçe Kelimeler (English/Turkish Words)\n\t5- Cümleler (Sentence)\n\t6- Sorular (Questions)\n\t7- Random Again\n\t8- Çıkış (Exit)" << endl;
		cout << "    Seçim (Choose): "; cin >> secim;
		while (secim <= 0 || secim >= 9) {
			cout << "Tekrar seçin (Choose again): "; cin >> secim;
		}
		seci[s] = secim; // seçimi diziye attık
		s++;
		cout << endl << endl;
		switch (secim) {
		case 1: system("color 4"); break;
		case 2: system("color b4"); break;
		case 3: {
			// Türkçe-İngilizce
			doğ = 0; yan = 0; bos = 0;
			// renk kontrolu
			for (int i = 24; i >= 0; i--) {
				if (seci[i] == 1)
				{
					renk = 1; break; // gece modu
				}
				if (seci[i] == 2)
				{
					renk = 2; break; // gündüz modu
				}
			}
			cout << "\tWORDS...\n\tToplam kelime sayısı (Addition word number): " << boy << endl<<endl;
			for (int i = 0; i < boy; i++)
			{
				if (i == 0) {
					getline(cin, answ);
				}
				cout <<  i + 1 << "/" << boy2  << "- " << turk[dizi[i]] << " = ";
				getline(cin, answ);
				if (answ == "exit")
				{
					bos = boy2 - (doğ + yan);
					int temp = i;
					for (int tekrar = sayac_again; tekrar < boy; tekrar++)
					{
						again_q[tekrar] = turk[dizi[temp]];
						again_a[tekrar] = engl[dizi[temp]];
						sayac_again++;
						temp++;
					}
					break;
				}
				else if (answ == "")
				{
					bos++;
					cout << "Answer: " << engl[dizi[i]] << endl;
					again_q[sayac_again] = turk[dizi[i]];
					again_a[sayac_again] = engl[dizi[i]];
					sayac_again++;
				}
				else if (answ == engl[dizi[i]])
				{
					if (renk == 1)
					{
						system("color a4");
						system("color 4");
					}
					else {
						system("color a4");
						system("color b4");
					}
					cout << "TRUE" << endl;
					doğ++;
					sayac_again++;
				}
				else
				{
					if (renk == 1)

					{
						system("color c4");
						system("color 4");
					}
					else {
						system("color c4");
						system("color b4");
					}
					cout << "FALSE--> anw: " << engl[dizi[i]] << endl;
					yan++;
					again_q[sayac_again] = turk[dizi[i]];
					again_a[sayac_again] = engl[dizi[i]];
					sayac_again++;
				}

				cout << endl;
			}
			cout << endl << "\tToplam Soru= " << boy2 << endl;
			cout << "\tDoğru sayısı= " << doğ << endl;
			cout << "\tYanlış sayısı= " << yan << endl;
			cout << "\tBoş sayısı= " << bos << endl;
			string cev = "";
			do
			{
				if (yan + bos == 0) // tekrar edilecek kelime yoksa
				{
					cout << "No words again. CONGRATULATIONS...";
					break;
				}
				cout << "\t\tYanlış ve Boş soruları tekrar görmek istermisin (Yes/No) = ";
			cin >> cev;
			while ((convert(cev)!="yes") && (convert(cev) != "no")) {
				cout << "Yes or No = ";
				cin >> cev;
			}
			cout << endl;
			if (convert(cev) == "yes") // tekrar soruları verip cevapları aldık
			{
				int again_soruSayısı = yan + bos; // tekrar soru sayısı yanlış ve boşların toplamıdır.
				int soru_sayısı = 1; // yazdırırken soru sayısını belrtmek için
				doğ = yan = bos = 0; // doğru yanlış ve boş sayaçlarını sıfırlıyorum ki again fonksiyonundada kullanayım
				if (again_soruSayısı == 0)
				{
					cout << "\tOoooo MRK hepsini yaptın demek helal olsun..." << endl << "\tMRK win ——— The English was eaten :) :)";
					break;
				}
				cout << "\tWORDS AGAIN\n\tToplam kelime sayısı (Addition word number): " << again_soruSayısı << endl<<endl;;
				for (int again = 0; again < 75; again++)
				{
					if (again == 0)
					{
						getline(cin, answ);
					}
					if (again_q[again] == "")
					{
						continue;
					}

					cout << soru_sayısı << "/" << again_soruSayısı << "- " << again_q[again] << " = ";
					getline(cin, answ);
					if (answ == "exit")
					{
						bos = again_soruSayısı - (doğ + yan);
						break;
					}
					if (answ == "")
					{
						cout << "Answer: " << again_a[again]<<endl;
						bos++;
						
					}
					else if (answ == again_a[again])
					{
						if (renk == 1)
						{
							system("color a4");
							system("color 4");
						}
						else {
							system("color a4");
							system("color b4");
						}
						cout << "TRUE" << endl;
						doğ++;
						again_q[again] = "";
						again_a[again] = "";
					}
					else
					{
						if (renk == 1)
						{
							system("color c4");
							system("color 4");
						}
						else {
							system("color c4");
							system("color b4");
						}
						cout << "FALSE--> anw: " << again_a[again] << endl;
						yan++;
					}
					soru_sayısı++;
					cout << endl;
				}
				cout << endl << "\tToplam Soru= " << again_soruSayısı << endl;
				cout << "\tDoğru sayısı= " << doğ << endl;
				cout << "\tYanlış sayısı= " << yan << endl;
				cout << "\tBoş sayısı= " << bos << endl;
			}
			} while (convert(cev)!="no");
				
			cout << endl << endl << endl;
		}break;
		case 4: {
			doğ = 0; yan = 0; bos = 0;
			// renk kontrolu
			for (int i = 25; i > 0; i--) {
				if (seci[i] == 1)
				{
					renk = 1; break; // gece modu
				}
				if (seci[i] == 2)
				{
					renk = 2; break; // gündüz modu
				}
			}
			// ingilizce-Türkçe
			cout << "WORDS...\nToplam kelime sayısı (Addition word number): " << boy << endl;
			for (int i = 0; i < boy; i++)
			{
				if (i == 0) {
					getline(cin, answ);
				}
				cout<< i + 1 << "/" << boy2  <<"- "<< engl[dizi[i]] << " = ";
				getline(cin, answ);
				if (answ == "exit" || answ == "e")
				{
					bos = boy2 - (doğ + yan);
					break;
				}
				else if (answ == "")
				{
					bos++;
					cout << "Answer: " << turk[dizi[i]] << endl;
				}
				else if (answ == turk[dizi[i]])
				{
					if (renk == 1)
					{
						system("color a4");
						system("color 4");
					}
					else {
						system("color a4");
						system("color b4");
					}
					cout << "TRUE" << endl;
					doğ++;
				}
				else
				{
					if (renk == 1)
					{
						system("color c4");
						system("color 4");
					}
					else {
						system("color c4");
						system("color b4");
					}
					cout << "FALSE--> anw: " << turk[dizi[i]] << endl;
					yan++;
				}
				cout << endl;
			}
			cout << "Toplam Soru= " << boy2 << endl;
			cout << "Doğru sayısı= " << doğ << endl;
			cout << "Yanlış sayısı= " << yan << endl;
			cout << "Boş sayısı= " << bos << endl << endl << endl;
		}break;
		case 5: {
			// Cümle şeklindekiler
			cout << "CLAUSES...\nToplam cümle sayısı (Addition sentence number): " << c_e_boy << endl;
			for (int i = 0; i < c_e_boy; i++)
			{
				if (i == 0) {
					getline(cin, answ);
				}
				if (answ == "exit" || answ == "e") break;
				cout << i + 1 << "/" << c_e_boy << "- " << engcum[i] << " = ";
				getline(cin, answ);
				cout << "Cevap: " << turcum[i] << endl <<endl;
			}
			cout << endl << endl << endl;
		}break;
		case 6: {
			doğ = 0; yan = 0; bos = 0;
			// Question
			cout << "Question...\nToplam kelime sayısı (Addition word number): " << boy << endl;
			for (int i = 0; i < 16; i++)
			{
				if (i == 0)
					getline(cin, answ);
				cout << i + 1 << "- " << questions[soru_dizi[i]] << " = ";
				getline(cin, answ);
				if (answ == "exit" || answ == "e")
				{
					bos = 16 - (doğ + yan);
					break;
				}
				else if (answ == "")
				{
					bos++;
					cout << "Answer: " << answers[soru_dizi[i]] << endl;
				}
				else if (answ == answers[soru_dizi[i]])
				{
					cout << "TRUE" << endl;
					doğ++;
				}
				else
				{
					cout << "FALSE--> anw: " << answers[soru_dizi[i]] << endl;
					yan++;
				}
				cout << endl;
			}
			cout << "Toplam Soru= " << 16 << endl;
			cout << "Doğru sayısı= " << doğ << endl;
			cout << "Yanlış sayısı= " << yan << endl;
			cout << "Boş sayısı= " << bos << endl << endl << endl;
		}break;
		case 7: {
			cout << "1- Random for all" << endl;
			cout << "2- Words for all" << endl;
			cout << "3- Sentences for all" << endl;
			cout << "4- Questions for all" << endl;
			cout << "5- Geri" << endl;
			int sec=0;
			while (sec <= 0 || sec >= 6)
			{
				cout << "Seçiniz: "; cin >> sec;
			}
			switch (sec) {
			case 1:
			{
				// kelime random
				for (int i = 0; i < boy2; i++)
				{
					dizi[i] = rand() % boy2;
					for (int j = i; j > 0; j--)
					{
						if (dizi[i] == dizi[j - 1])
						{
							i--;
							continue;
						}
					}
				}
				// cümle random
				for (int i = 0; i < c_e_boy; i++)
				{
					dizi2[i] = rand() % c_e_boy;
					for (int j = i; j > 0; j--)
					{
						if (dizi2[i] == dizi2[j - 1])
						{
							i--;
							continue;
						}
					}
				}
				// soru random
				for (int i = 0; i < 16; i++)
				{
					soru_dizi[i] = rand() % 16;
					for (int j = i; j > 0; j--)
					{
						if (soru_dizi[i] == soru_dizi[j - 1])
						{
							i--;
							continue;
						}
					}
				}
				cout << endl << endl;
			}break;
			case 2:
			{
				for (int i = 0; i < boy2; i++)
				{
					dizi[i] = rand() % boy2;
					for (int j = i; j > 0; j--)
					{
						if (dizi[i] == dizi[j - 1])
						{
							i--;
							continue;
						}
					}
				}
				cout << endl << endl;
			}break;
			case 3:
			{
				for (int i = 0; i < c_e_boy; i++)
				{
					dizi2[i] = rand() % c_e_boy;
					for (int j = i; j > 0; j--)
					{
						if (dizi2[i] == dizi2[j - 1])
						{
							i--;
							continue;
						}
					}
				}
				cout << endl << endl;
			}break;
			case 4:
			{
				for (int i = 0; i < 16; i++)
				{
					soru_dizi[i] = rand() % 16;
					for (int j = i; j > 0; j--)
					{
						if (soru_dizi[i] == soru_dizi[j - 1])
						{
							i--;
							continue;
						}
					}
				}
				cout << endl << endl;
			}break;
			case 5:
			{
				cout << endl << endl;
				break;
			}break;
			}
		}break;
		case 8: break; break;
		}
	} while (secim!=8);

	

	cout << endl;
	system("pause");
	return 0;
}