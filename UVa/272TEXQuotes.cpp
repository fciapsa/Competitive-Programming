#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	char c;
	bool left = true;

	while (scanf("%c", &c) != EOF) {
		switch (c) {
		case '"': 
			if (left) printf("%s", "``");
			else printf("%s", "''");
			left = !left; break;
		case '\n': printf("%c", '\n'); break;
		default: printf("%c", c);
		}
	}
return 0;
}