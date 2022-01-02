#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cctype>

const std::unordered_set<std::string> letras = { "h","he","li","be","b","c","n","o","f","ne","na","mg","al","si","p",
	"s","cl","ar","k","ca","sc","ti","v","cr","mn","fe","co","ni","cu","zn","ga","ge","as","se","br","kr","rb","sr","y",
	"zr","nb","mo","tc","ru","rh","pd","ag","cd","in","sn","sb","te","i","xe","cs","ba","hf","ta","w","re","os","ir","pt",
	"au","hg","tl","pb","bi","po","at","rn","fr","ra","rf","db","sg","bh","hs","mt","ds","rg","cn","nh","fl","mc","lv","ts",
	"og","la","ce","pr","nd","pm","sm","eu","gd","tb","dy","ho","er","tm","yb","lu","ac","th","pa","u","np","pu","am","cm",
	"bk","cf","es","fm","md","no","lr"
};

int main() {
	std::string s, temp;
	char c;
	std::cin >> s;
	std::cin.get(c);
	while (std::cin && c == ' ') {
		std::cin >> temp;
		s += temp;
		std::cin.get(c);
	}
	while (std::cin) {
		for (int i = 0; i < s.size(); ++i) {
			if (isupper(s[i])) s[i] = char(tolower(s[i]));
		}
		if (s.size() == 1) {
			if (letras.count(s.substr(0, 1)) > 0) std::cout << "SI\n";
			else std::cout << "NO\n";
		}
		else {
			std::vector<bool> dp(s.size(), false);
			dp[0] = letras.count(s.substr(0, 1)) > 0;
			dp[1] = (dp[0] && letras.count(s.substr(1, 1)) > 0) || letras.count(s.substr(0, 2)) > 0;
			for (int i = 2; i < s.size(); ++i) {
				dp[i] = (dp[i - 1] && letras.count(s.substr(i, 1)) > 0) || (dp[i - 2] && letras.count(s.substr(i - 1, 2)) > 0);
			}
			if (dp[s.size() - 1])std::cout << "SI\n";
			else std::cout << "NO\n";
		}

	std::cin >> s;
	std::cin.get(c);
	while (std::cin && c == ' ') {
		std::cin >> temp;
		s += temp;
		std::cin.get(c);
	}
	}
return 0;
}