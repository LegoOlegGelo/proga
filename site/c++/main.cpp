#include <iostream>
#include <fstream>
#include "cgi_requests.h"

using namespace std;

int recursive_call_count = 0;

struct nft {
	int id;
	const char* name;
	const char* image;
	int price;
};

nft cards[] = {
	nft { 1, "Мельбурн", "https://avatars.mds.yandex.net/get-zen_doc/5130440/pub_6117c35677c7ad7281c77683_6117c3add3f0df256407f38a/scale_1200", 123 },
	nft { 2, "Страус", "images/image2.jpg", 234 },
	nft { 3, "Сова", "https://s1.1zoom.ru/big7/888/Eyes_Owls_Bubo_502568.jpg", 345 },
	nft { 4, "Поп-арт", "https://kartinkin.net/uploads/posts/2021-10/1635257318_45-kartinkin-net-p-peizazh-v-stile-pop-art-krasivo-45.jpg", 456 },
	nft { 5, "Lamborghini", "https://img.fonwall.ru/o/96/lamborjdini-tyuning-sportkar-kupe.jpg?route=mid&amp;h=750", 567 },
	nft { 6, "Драгон фрукт", "https://i.pinimg.com/originals/fb/dd/77/fbdd778540d34b800cac2a8947411d02.jpg", 678 },
	nft { 7, "Салют", "https://placepic.ru/wp-content/uploads/2019/07/ushanov-15.jpg", 789 },
	nft { 8, "Морская свинка", "https://likehamster.ru/wp-content/uploads/2018/09/906_result.jpg", 890 },
	nft { 9, "Золотые ворота", "https://trip-guru.ru/images/easyblog_articles/117/trip-guru.ru0075.jpg", 10 }
};

void read_card(nft& card)
{
	cout << "<div class = 'nft-card'>";
	cout << "<a href = '/card.cgi?id=" << card.id << "'>";
	cout << "<img class = 'nft-card-image' src = '" << card.image << "' / >";
	cout << "<h3 class='nft-card-text'>" << card.name << "</h2>";
	cout << "<h3 class='nft-card-text'>" << card.price << " ETH</h2>";
	cout << "</a>";

	cout << "<form action='/put_to_cart.php' method='POST'>";
	cout << "<input type='hidden' name='card_id' value='" << card.price << "'>";
	cout << "<input type='submit' class='buy-btn' value='В корзину' />";
	cout << "</form>";
	cout << "</div>";
}

void read_block(const char* filename, char* data = 0)	
{
	recursive_call_count++;

	if (recursive_call_count > 1000)
	{
		cout << "1000th recursive call. Exit.";
		return;
	}

	ifstream f(filename);

	if (f.is_open())
	{
		auto sz = 65536;
		auto buf = new char[sz];

		while (!f.eof()) {
			f.getline(buf, sz);

			cout << endl;

			if (!strcmp(buf, "<!--###LIST###-->"))
			{
				char* text = nullptr;
				get_param_value(text, "text", data);
				if (text) cout << "<h1>" << text << "</h1>";

				for (size_t i = 0; i < sizeof(cards) / sizeof(nft); i++)
				{
					if (i % 4 == 0) cout << "<div class='content-row'>";
					cout << "<div class='content-item'>";
					
					read_card(cards[i]);
					
					cout << "</div>";
					if (i % 4 == 3) cout << "</div>";
				}
			}

			else if (!strcmp(buf, "<!--###HEADER###-->"))
				read_block("blocks/header.php", data);

			else if (!strcmp(buf, "<!--###FOOTER###-->"))
				read_block("blocks/footer.php", data);

			else if (!strcmp(buf, "<!--###HEAD_META###-->"))
				read_block("blocks/head_meta.php", data);

			else if (!strcmp(buf, "<!--###TASKS_MENU###-->"))
				read_block("blocks/tasks_menu.php", data);

			else
				cout << buf;
		}

		delete[] buf;
	}
	else
		cout << "read error with " << filename << endl;

	f.close();
}

int main()
{
	cout << "Content-type: text/html; charset=Windows-1251\n\n";

	char* data = nullptr;
	get_form_data(data);
	
	recursive_call_count = 0;
	read_block("_index", data);

	return 0;
}