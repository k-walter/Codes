// #include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	freopen("Faktor.in", "r", stdin);

	int no, factor;
	scanf("%d %d", &no, &factor);
	printf("%d\n", no * (factor - 1) + 1);
	return 0;
}