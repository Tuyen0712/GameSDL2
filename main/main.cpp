#include "function.h"
#include "func.h"

int main(int argc, char* argv[]) {
	if (!init()) {
		printf("Fail to initilize!");
	}
	else {
		if (!loadMedia() && !loadMute()) {
			printf("Fail to load media!");
		}
		else {
			MENU();
			while (mainn) {
				if (isRunning) {
					MenuInside();
				}
				while (isrunning) {
					renderGAme();
					showBroad();


				}
			}
				
			
		}
	}
	close();
	return 0;
}
