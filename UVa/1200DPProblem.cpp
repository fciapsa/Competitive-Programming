#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>//floor

int main() {
	int n;
	scanf("%d", &n);

	char s[502];
	bool eq, sum;
	int coef, num;
	while(n--){
		eq = false; sum = true;
		coef = 0; num = 0;

		scanf("%s", &s);
		for(int i =0; s[i];) {
			if (s[i] == 'x') {
				if ((eq && sum) || (!eq && !sum)) coef -= 1;
				else coef += 1;
				++i;
			}
			else if (s[i] == '=') {
				eq = true;
				sum = true;
				++i;
			}
			else if (s[i] == '+') {
				sum = true;
				++i;
			}
			else if (s[i] == '-') {
				sum = false;
				++i;
			}
			else {
				int aux = int(s[i]) - int('0');
				++i;
				while (s[i] && s[i] >= '0' && s[i] <= '9') {
					aux *= 10;
					aux += (int(s[i]) - int('0'));
					++i;
				}

				if (s[i] && s[i] == 'x') {
					if ((eq && sum) || (!eq && !sum)) coef -= aux;
					else coef += aux;
					++i;
				}
				else {
					if ((eq && sum) || (!eq && !sum)) num -= aux;
					else num += aux;
				}

			}
		}

		num = -num;//pasar al otro lado

		if (coef == 0 && num != 0) puts("IMPOSSIBLE");
		else if (coef == 0 && num == 0) puts("IDENTITY");
		else  printf("%d\n", (int)floor((double)num / coef));
	}
return 0;
}