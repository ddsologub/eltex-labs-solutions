#include <stdio.h>
#include <stdlib.h>

typedef struct Book{
	char title[255];
	int publish_date;
	int pages_num;
	int price;
} Book;

void read_book(Book *cur_book)
{
	scanf("%s", cur_book->title);
	scanf("%d", &cur_book->publish_date);
	scanf("%d", &cur_book->pages_num);
	scanf("%d", &cur_book->price);
}

void print_book(Book cur_book)
{
	printf("Title:\t%s\n", cur_book.title);
	printf("Published:\t%d\n", cur_book.publish_date);
	printf("Pages:\t%d\n", cur_book.pages_num);
	printf("Price:\t%d\n", cur_book.price);
	printf("\n");
}

int cmp_book(const void *p1, const void *p2)
{
	Book *b1 = (Book*)p1;
	Book *b2 = (Book*)p2;

	return (b1->price - b2->price);
}

int main(void) {
	const int kMaxBookNum = 100;
	Book books[kMaxBookNum];
	
	int n = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		read_book(&books[i]);
	}

	qsort(books, n, sizeof(Book), cmp_book);

	for(int i = 0; i < n; i++)
	{
		print_book(books[i]);
	}

	return 0;
}
