#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fin, *fout;
	
	if ((fin = fopen("imdb250.txt", "r")) == NULL) {
		fprintf(stderr, "Cannot open input file\n");
		exit(1);	
	}

	if ((fout = fopen("imdb250_output.txt", "w")) == NULL) {
		fprintf(stderr, "Cannot open output file\n");
		exit(1);	
	}

	char ch = 0;
	while(ch != EOF) {
		//fread(&ch, sizeof(char), 1, fin);
		ch = getc(fin);
		if (ch != ' ') {
			//fwrite(&ch, sizeof(char), 1, fout);
			fputc(ch, fout);
		}
	}	

	
	if (fclose(fin)) {
		fprintf(stderr, "Cannot close input file\n");
		exit(1);
	}

	if (fclose(fout)) {
		fprintf(stderr, "Cannot close output file\n");
		exit(1);
	}

	return 0;
}
