#include <stdio.h>

int main() {
	float feps;
	feps = 1.0f;
	while ( feps + 1.0f > 1.0f ) {
		feps = feps * 0.5f;
	}

	printf("float machine epsilon hat = %e\n", feps);
	return 0;
}
